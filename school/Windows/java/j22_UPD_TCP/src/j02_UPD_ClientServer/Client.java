package j02_UPD_ClientServer;

import java.io.*;
import java.net.*;
import java.util.Scanner;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.concurrent.TimeUnit;

/**
 * Client:
 * - connects to MainServer on TCP 8888 (hardcoded)
 * - authenticates with /auth <user> <pass>
 * - registers UDP listening port with /udpport <port>
 * - opens UDP socket and listens for P2P messages
 * - /msg <user> <text> will attempt P2P via UDP by asking server /getaddr <user>
 *   and then sending datagram; falls back to sending /msg to server for TCP forwarding
 * - /filesrv <port> starts a local TCP file server and registers with MainServer
 */
public class Client {
    private static final String SERVER_HOST = "127.0.0.1";
    private static final int SERVER_PORT = 8888;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Username: ");
        String username = sc.nextLine().trim();
        System.out.print("Password: ");
        String password = sc.nextLine().trim();

        while (true) {
            try (Socket tcp = new Socket(SERVER_HOST, SERVER_PORT);
                 BufferedReader in = new BufferedReader(new InputStreamReader(tcp.getInputStream()));
                 PrintWriter out = new PrintWriter(tcp.getOutputStream(), true)) {

                System.out.println("Connected to server " + SERVER_HOST + ":" + SERVER_PORT);

                // Authenticate synchronously before starting the background reader
                out.println("/auth " + username + " " + password);
                String resp;
                boolean authed = false;
                long authStart = System.currentTimeMillis();
                // wait up to 5 seconds for auth response
                while ((System.currentTimeMillis() - authStart) < 5000 && (resp = in.readLine()) != null) {
                    System.out.println("[SERVER] " + resp);
                    if (resp.startsWith("AUTH OK")) {
                        authed = true;
                        break;
                    } else if (resp.startsWith("AUTH FAILED") || resp.startsWith("ERROR")) {
                        break;
                    }
                    // other server lines printed and keep waiting
                }
                if (!authed) {
                    System.out.println("Authentication failed or timed out. Will retry connection.");
                    // let socket close via try-with-resources, then retry loop
                    continue;
                }

                // start UDP listener
                DatagramSocket udpSocket = new DatagramSocket();
                int udpPort = udpSocket.getLocalPort();
                System.out.println("UDP listening on port " + udpPort);
                // register udp port with server
                out.println("/udpport " + udpPort);

                // queue to receive server TCP lines for synchronous requests
                BlockingQueue<String> serverQueue = new LinkedBlockingQueue<>();

                Thread udplistener = new Thread(() -> {
                    byte[] buf = new byte[2048];
                    DatagramPacket p = new DatagramPacket(buf, buf.length);
                    try {
                        while (!udpSocket.isClosed()) {
                            udpSocket.receive(p);
                            String s = new String(p.getData(), 0, p.getLength());
                            System.out.println("[UDP from " + p.getAddress() + ":" + p.getPort() + "] " + s);
                        }
                    } catch (IOException e) {
                        System.out.println("UDP listener closed.");
                    }
                }, "udp-listener");
                udplistener.setDaemon(true);
                udplistener.start();

                // background reader for server messages (reads all TCP lines, enqueues them)
                Thread reader = new Thread(() -> {
                    try {
                        String l;
                        while ((l = in.readLine()) != null) {
                            // always offer to queue for synchronous callers
                            serverQueue.offer(l);
                            // also print for user
                            System.out.println("[SERVER] " + l);

                            // handle FILE_OFFER specially
                            if (l.startsWith("FILE_OFFER FROM ")) {
                                // FILE_OFFER FROM <user> <ip> <port> <filepath>
                                String[] p = l.split("\\s+", 6);
                                if (p.length >= 6) {
                                    String from = p[2];
                                    String ip = p[3];
                                    int port = Integer.parseInt(p[4]);
                                    String path = p[5];
                                    System.out.println("Incoming file offer from " + from + ": " + path + " -> connecting to " + ip + ":" + port);
                                    downloadFile(ip, port, path);
                                }
                            }
                        }
                    } catch (IOException e) {
                        System.out.println("Disconnected from server (reader).");
                    }
                }, "server-reader");
                reader.setDaemon(true);
                reader.start();

                // main input loop
                System.out.println("Type commands. /quit to exit. Use /filesrv <port> to register local file server for sending.");
                while (!tcp.isClosed() && tcp.isConnected()) {
                    if (!sc.hasNextLine()) break;
                    String cmd = sc.nextLine();
                    if (cmd == null) break;
                    cmd = cmd.trim();
                    if (cmd.isEmpty()) continue;

                    if (cmd.equals("/quit")) {
                        out.println("/quit");
                        System.out.println("Client requested quit; exiting.");
                        try { udpSocket.close(); } catch (Exception ignored) {}
                        return;
                    }
                    if (cmd.startsWith("/udpsend ")) {
                        String[] p = cmd.split("\\s+",4);
                        if (p.length<4) { System.out.println("usage: /udpsend ip port message"); continue; }
                        try {
                            InetAddress addr = InetAddress.getByName(p[1]);
                            int port = Integer.parseInt(p[2]);
                            String msg = p[3];
                            byte[] data = msg.getBytes();
                            DatagramPacket dp = new DatagramPacket(data, data.length, addr, port);
                            udpSocket.send(dp);
                            System.out.println("UDP message sent.");
                        } catch (Exception e) {
                            e.printStackTrace();
                        }
                        continue;
                    }
                    if (cmd.startsWith("/filesrv ")) {
                        // start a file server thread that sends files when someone connects
                        String[] p = cmd.split("\\s+",2);
                        try {
                            int port = Integer.parseInt(p[1]);
                            startFileServer(port);
                            // also register with MainServer
                            out.println("/filesrv " + port);
                        } catch (Exception e) {
                            System.out.println("Invalid port for /filesrv.");
                        }
                        continue;
                    }

                    // === P2P /msg over UDP ===
                    if (cmd.startsWith("/msg ")) {
                        int firstSpace = cmd.indexOf(' ',5);
                        if (firstSpace == -1) { System.out.println("usage: /msg [u1,u2] text"); continue; }
                        String targetSpec = cmd.substring(5, firstSpace).trim().replaceAll("[\\[\\]]", "");
                        String text = cmd.substring(firstSpace+1);

                        String[] targets = targetSpec.split(",");
                        for (String t : targets) {
                            t = t.trim();
                            // ask server for UDP address
                            out.println("/getaddr " + t);
                            String addrLine = null;
                            try {
                                addrLine = waitForPrefix(serverQueue, "ADDR " + t + " ", 2000);
                            } catch (InterruptedException e) {
                                // ignore
                            }
                            if (addrLine == null) {
                                System.out.println("No UDP address for " + t + " — falling back to server delivery.");
                                // fallback: send to server (so server will forward via TCP)
                                out.println("/msg " + t + " " + text);
                                continue;
                            }
                            // addrLine format: "ADDR <user> <ip> <port>"
                            String[] parts = addrLine.split("\\s+");
                            if (parts.length >= 4) {
                                try {
                                    String ip = parts[2];
                                    int port = Integer.parseInt(parts[3]);
                                    byte[] data = ("MSG FROM " + username + ": " + text).getBytes();
                                    DatagramPacket dp = new DatagramPacket(data, data.length, InetAddress.getByName(ip), port);
                                    udpSocket.send(dp);
                                    System.out.println("UDP message sent to " + t + "@" + ip + ":" + port);
                                } catch (Exception e) {
                                    System.out.println("Failed to send UDP to " + t + ": " + e.getMessage());
                                    // fallback to server delivery
                                    out.println("/msg " + t + " " + text);
                                }
                            } else {
                                System.out.println("Malformed ADDR reply, falling back.");
                                out.println("/msg " + t + " " + text);
                            }
                        }
                        continue;
                    }

                    // forward any other commands (/send, /userlist, /help, etc.)
                    out.println(cmd);
                }

                // cleanup
                try { udpSocket.close(); } catch (Exception ignored) {}
                try { tcp.close(); } catch (Exception ignored) {}

                // If user typed /quit we exit fully
                System.out.println("Client exiting.");
                return;

            } catch (IOException e) {
                System.out.println("Connection lost / failed: " + e.getMessage());
                try { Thread.sleep(3000); } catch (InterruptedException ignored) {}
                System.out.println("Retrying connection...");
            }
        }
    }

    // helper: wait for a line with given prefix from serverQueue with timeout
    private static String waitForPrefix(BlockingQueue<String> q, String prefix, long timeoutMs) throws InterruptedException {
        long deadline = System.currentTimeMillis() + timeoutMs;
        while (true) {
            long wait = deadline - System.currentTimeMillis();
            if (wait <= 0) return null;
            String line = q.poll(wait, TimeUnit.MILLISECONDS);
            if (line == null) return null;
            if (line.startsWith(prefix)) return line;
            // otherwise ignore and keep waiting
        }
    }

    // small file server used when user runs /filesrv <port>
    private static void startFileServer(int port) {
        Thread t = new Thread(() -> {
            try (ServerSocket ss = new ServerSocket(port)) {
                System.out.println("File server listening on " + port);
                while (true) {
                    try (Socket s = ss.accept();
                         DataInputStream dis = new DataInputStream(s.getInputStream());
                         DataOutputStream dos = new DataOutputStream(s.getOutputStream())) {
                        String filepath = dis.readUTF();
                        File f = new File(filepath);
                        if (!f.exists()) {
                            dos.writeLong(-1);
                            System.out.println("Requested file not found: " + filepath);
                            continue;
                        }
                        long len = f.length();
                        dos.writeLong(len);
                        try (FileInputStream fis = new FileInputStream(f)) {
                            byte[] buf = new byte[8192];
                            int r;
                            while ((r = fis.read(buf)) != -1) dos.write(buf,0,r);
                        }
                        System.out.println("Sent file: " + filepath);
                    } catch (IOException e) {
                        System.out.println("File server connection error: " + e.getMessage());
                    }
                }
            } catch (IOException e) {
                System.out.println("File server failed: " + e.getMessage());
            }
        }, "file-server-" + port);
        t.setDaemon(true);
        t.start();
    }

    // download file from a remote file server (used when receiving FILE_OFFER)
    private static void downloadFile(String ip, int port, String remotePath) {
        new Thread(() -> {
            try (Socket s = new Socket(ip, port);
                 DataOutputStream dos = new DataOutputStream(s.getOutputStream());
                 DataInputStream dis = new DataInputStream(s.getInputStream())) {
                dos.writeUTF(remotePath);
                long len = dis.readLong();
                if (len < 0) { System.out.println("Remote file not found."); return; }
                String local = new File(remotePath).getName();
                try (FileOutputStream fos = new FileOutputStream(local)) {
                    byte[] buf = new byte[8192];
                    long remaining = len;
                    while (remaining > 0) {
                        int read = dis.read(buf, 0, (int)Math.min(buf.length, remaining));
                        if (read == -1) break;
                        fos.write(buf, 0, read);
                        remaining -= read;
                    }
                }
                System.out.println("Downloaded file to " + local);
            } catch (IOException e) {
                System.out.println("Download error: " + e.getMessage());
            }
        }, "file-downloader").start();
    }
}
