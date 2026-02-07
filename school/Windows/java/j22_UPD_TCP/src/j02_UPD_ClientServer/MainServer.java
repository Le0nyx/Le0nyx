package j02_UPD_ClientServer;

import java.io.*;
import java.net.*;
import java.util.*;
import java.util.concurrent.*;

/**
 * MainServer:
 * - TCP server on port 8888
 * - handles Clients and SubServers
 * - simple auth: /auth <user> <pass>
 * - clients after auth should send: /udpport <port> to register UDP listener
 * - commands: /help, /quit, /auth <user> <pass>, /userlist, /msg [u1,u2] text, /send [user] filepath
 * - forwards /<command> to subservers that registered the command (EXEC ...)
 * - supports /getaddr for peer UDP address lookup
 */
public class MainServer {
    private static final int TCP_PORT = 8888;
    private static final String SERVER_PASSWORD = "secret"; // demo password

    private final Map<String, ClientInfo> clients = new ConcurrentHashMap<>();
    private final Map<String, SubServerInfo> subServers = new ConcurrentHashMap<>();
    private final ExecutorService pool = Executors.newCachedThreadPool();

    public static void main(String[] args) throws IOException {
        new MainServer().start();
    }

    private void start() throws IOException {
        ServerSocket server = new ServerSocket(TCP_PORT);
        System.out.println("MainServer listening on TCP port " + TCP_PORT);
        while (true) {
            Socket s = server.accept();
            pool.submit(() -> handleInitialConnection(s));
        }
    }

    private void handleInitialConnection(Socket socket) {
        String remote = socket.getRemoteSocketAddress().toString();
        System.out.println("Connection from " + remote);

        BufferedReader in = null;
        PrintWriter out = null;
        boolean handedOff = false;

        try {
            in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            out = new PrintWriter(socket.getOutputStream(), true);

            out.println("WELCOME MainServer. Use /auth <user> <pass> or /subregister <name> to register a SubServer.");

            String line;
            while ((line = in.readLine()) != null) {
                line = line.trim();
                if (line.isEmpty()) continue;

                if (line.startsWith("/subregister ")) {
                    String subname = line.substring("/subregister ".length()).trim();
                    if (subname.isEmpty()) { out.println("ERROR missing subserver name"); return; }
                    if (subServers.containsKey(subname)) { out.println("ERROR subserver name already exists"); return; }

                    SubServerInfo ss = new SubServerInfo(subname, socket);
                    subServers.put(subname, ss);
                    out.println("SUBREGISTERED " + subname);
                    System.out.println("SubServer registered: " + subname + " from " + remote);

                    pool.submit(() -> handleSubServer(ss));
                    handedOff = true;
                    return;
                }

                handleClientConnection(socket, in, out, line);
                handedOff = true;
                return;
            }

        } catch (IOException e) {
            System.err.println("Initial connection error: " + e.getMessage());
            try { socket.close(); } catch (IOException ignored) {}
        } finally {
            if (!handedOff) {
                try { if (in != null) in.close(); } catch (IOException ignored) {}
                if (out != null) out.close();
                try { socket.close(); } catch (IOException ignored) {}
            }
        }
    }

    private void handleSubServer(SubServerInfo ss) {
        System.out.println("SubServer handler started for " + ss.name);
        try (BufferedReader in = ss.reader; PrintWriter out = ss.writer) {
            String l;
            while ((l = in.readLine()) != null) {
                l = l.trim();
                if (l.isEmpty()) continue;
                if (l.startsWith("/registercmd ")) {
                    String cmd = l.substring("/registercmd ".length()).trim();
                    if (!cmd.startsWith("/")) cmd = "/" + cmd;
                    ss.commands.add(cmd);
                    out.println("CMD_REGISTERED " + cmd);
                    System.out.println("SubServer " + ss.name + " registered command " + cmd);
                    continue;
                }
                ss.responses.offer(l);
            }
        } catch (IOException e) {
            System.out.println("SubServer " + ss.name + " connection closed or error: " + e.getMessage());
        } finally {
            subServers.remove(ss.name);
            ss.close();
            System.out.println("SubServer disconnected: " + ss.name);
        }
    }

    private void handleClientConnection(Socket socket, BufferedReader in, PrintWriter out, String initialFirstLine) {
        String remote = socket.getRemoteSocketAddress().toString();
        String username = null;
        try (BufferedReader reader = in; PrintWriter writer = out) {
            String line = initialFirstLine;
            while (line != null) {
                line = line.trim();
                if (line.isEmpty()) { line = reader.readLine(); continue; }

                // Authentication
                if (line.startsWith("/auth ")) {
                    String[] parts = line.split("\\s+", 3);
                    if (parts.length < 3) { writer.println("ERROR usage: /auth <user> <pass>"); }
                    else {
                        String user = parts[1];
                        String pass = parts[2];
                        if (!SERVER_PASSWORD.equals(pass)) {
                            writer.println("AUTH FAILED");
                        } else {
                            ClientInfo existing = clients.get(user);
                            if (existing != null) {
                                try { Socket s = existing.socket; if (s != null && s.isClosed()) { clients.remove(user); existing = null; } }
                                catch (Exception ignored) { clients.remove(user); existing = null; }
                            }
                            if (existing != null) {
                                writer.println("ERROR user already logged in");
                            } else {
                                username = user;
                                ClientInfo ci = new ClientInfo(username, socket, reader, writer);
                                clients.put(username, ci);
                                writer.println("AUTH OK");
                                System.out.println("User authenticated: " + username + " from " + remote);
                            }
                        }
                    }
                    line = reader.readLine();
                    continue;
                }

                if (line.equals("/help")) {
                    writer.println("COMMANDS: /help /quit /auth <user> <pass>");
                    writer.println("After auth: /userlist /msg [u1,u2] text /send [user] filepath /udpport <port>");
                    writer.println("SubServer commands available:");
                    for (SubServerInfo ss : subServers.values()) writer.println(" - " + ss.name + " : " + ss.commands);
                    line = reader.readLine();
                    continue;
                }

                if (line.equals("/quit")) { writer.println("BYE"); break; }

                // require auth for the following
                if (username == null) { writer.println("ERROR not authenticated. Use /auth <user> <pass>"); line = reader.readLine(); continue; }

                // client registered their UDP port
                if (line.startsWith("/udpport ")) {
                    try {
                        int udpPort = Integer.parseInt(line.substring("/udpport ".length()).trim());
                        ClientInfo ci = clients.get(username);
                        if (ci != null) {
                            ci.udpPort = udpPort;
                            ci.udpAddress = socket.getInetAddress();
                            writer.println("UDP_REGISTERED " + udpPort);
                            System.out.println("Client " + username + " udp " + socket.getInetAddress() + ":" + udpPort);
                        } else writer.println("ERROR internal");
                    } catch (NumberFormatException e) { writer.println("ERROR bad port"); }
                    line = reader.readLine();
                    continue;
                }

                if (line.equals("/userlist")) { writer.println("USERS " + clients.keySet()); line = reader.readLine(); continue; }

                if (line.startsWith("/msg ")) {
                    int firstSpace = line.indexOf(' ',5);
                    if (firstSpace == -1) { writer.println("ERROR usage: /msg [u1,u2] text"); line = reader.readLine(); continue; }
                    String targetSpec = line.substring(5, firstSpace).trim().replaceAll("[\\[\\]]", "");
                    String text = line.substring(firstSpace+1);
                    String[] targets = targetSpec.split(",");
                    for (String t : targets) {
                        t = t.trim();
                        ClientInfo dest = clients.get(t);
                        if (dest != null) {
                            dest.writer.println("MSG FROM " + username + ": " + text);
                        } else {
                            writer.println("USER_NOT_FOUND " + t);
                        }
                    }
                    writer.println("MSG_SENT");
                    line = reader.readLine();
                    continue;
                }

                // /send [user] filepath
                if (line.startsWith("/send ")) {
                    String[] parts = line.split("\\s+", 3);
                    if (parts.length < 3) { writer.println("ERROR usage: /send [user] filepath"); line = reader.readLine(); continue; }
                    String target = parts[1].replaceAll("[\\[\\]]", "");
                    String filepath = parts[2];
                    ClientInfo dest = clients.get(target);
                    if (dest == null) { writer.println("ERROR user not found: " + target); line = reader.readLine(); continue; }
                    ClientInfo sender = clients.get(username);
                    if (sender.fileServerPort <= 0) { writer.println("ERROR you must register a file server port with /filesrv <port> before sending"); line = reader.readLine(); continue; }
                    dest.writer.println("FILE_OFFER FROM " + username + " " + sender.socket.getInetAddress().getHostAddress()
                            + " " + sender.fileServerPort + " " + filepath);
                    writer.println("FILE_OFFER_SENT to " + target);
                    line = reader.readLine();
                    continue;
                }

                // clients can register a file server port
                if (line.startsWith("/filesrv ")) {
                    try {
                        int p = Integer.parseInt(line.substring("/filesrv ".length()).trim());
                        clients.get(username).fileServerPort = p;
                        writer.println("FILESERV_REGISTERED " + p);
                        System.out.println("Client " + username + " file server port " + p);
                    } catch (NumberFormatException e) { writer.println("ERROR bad port"); }
                    line = reader.readLine();
                    continue;
                }

                // /getaddr <user>
                if (line.startsWith("/getaddr ")) {
                    String target = line.substring("/getaddr ".length()).trim();
                    ClientInfo dest = clients.get(target);
                    if (dest == null) {
                        writer.println("ERROR no_such_user " + target);
                    } else if (dest.udpPort <= 0 || dest.udpAddress == null) {
                        writer.println("ERROR no_udp " + target);
                    } else {
                        writer.println("ADDR " + target + " " + dest.udpAddress.getHostAddress() + " " + dest.udpPort);
                    }
                    line = reader.readLine();
                    continue;
                }

                // Forward commands to SubServers (synchronous)
                if (line.startsWith("/")) {
                    String cmd = line.split("\\s+")[0];
                    boolean handled = false;
                    for (SubServerInfo ss : subServers.values()) {
                        if (ss.commands.contains(cmd)) {
                            synchronized (ss.forwardLock) {
                                try {
                                    ss.writer.println("EXEC " + line + " FROM " + username);
                                    String resp = ss.responses.poll(5, TimeUnit.SECONDS);
                                    if (resp == null) resp = "NO_RESPONSE";
                                    writer.println("SUBSERVER_RESPONSE " + resp);
                                } catch (Exception e) {
                                    writer.println("ERROR contacting subserver " + ss.name);
                                }
                            }
                            handled = true;
                            break;
                        }
                    }
                    if (!handled) writer.println("UNKNOWN_COMMAND " + cmd);
                    line = reader.readLine();
                    continue;
                }

                writer.println("UNKNOWN_INPUT");
                line = reader.readLine();
            }

        } catch (IOException e) {
            System.err.println("Client connection error: " + e.getMessage());
        } finally {
            if (username != null) {
                clients.remove(username);
                System.out.println("User disconnected: " + username);
            }
            try { socket.close(); } catch (IOException ignored) {}
        }
    }

    // helpers
    static class ClientInfo {
        final String name;
        final Socket socket;
        final BufferedReader reader;
        final PrintWriter writer;
        InetAddress udpAddress = null;
        int udpPort = -1;
        int fileServerPort = -1;
        ClientInfo(String name, Socket s, BufferedReader r, PrintWriter w) {
            this.name = name; this.socket = s; this.reader = r; this.writer = w;
        }
    }

    static class SubServerInfo {
        final String name;
        final Socket socket;
        final BufferedReader reader;
        final PrintWriter writer;
        final Set<String> commands = ConcurrentHashMap.newKeySet();
        final BlockingQueue<String> responses = new LinkedBlockingQueue<>();
        final Object forwardLock = new Object();

        SubServerInfo(String name, Socket sock) throws IOException {
            this.name = name;
            this.socket = sock;
            this.reader = new BufferedReader(new InputStreamReader(sock.getInputStream()));
            this.writer = new PrintWriter(sock.getOutputStream(), true);
        }

        void close() {
            try { socket.close(); } catch (IOException ignored) {}
        }
    }
}
