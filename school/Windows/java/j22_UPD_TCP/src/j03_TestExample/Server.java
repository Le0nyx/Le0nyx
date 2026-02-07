package j03_TestExample;

import java.io.*;
import java.net.*;
import java.util.concurrent.*;

public class Server {
    private static final int UDP_PORT = 50000;
    private static final int MAX_CLIENTS = 5;

    private static final Object lock = new Object();
    private static boolean busy = false; //lock for jus one user

    public static void main(String[] args) throws Exception {
        ExecutorService pool = Executors.newFixedThreadPool(MAX_CLIENTS);

        //upd p50000
        DatagramSocket udpSocket = new DatagramSocket(UDP_PORT);
        System.out.println("updServer " + UDP_PORT);

        while (true) { //recieve stuff from client
            byte[] buffer = new byte[1024];
            DatagramPacket packet = new DatagramPacket(buffer, buffer.length);
            udpSocket.receive(packet);

            InetAddress clientAddress = packet.getAddress();
            int clientPort = packet.getPort();
            System.out.println("upd von " + clientAddress + ":" + clientPort);

            int tcpPort = 60000;
            String response = InetAddress.getLocalHost().getHostAddress() + ":" + tcpPort;

            //send back ip and port
            byte[] responseBytes = response.getBytes();
            DatagramPacket responsePacket = new DatagramPacket(
                    responseBytes, responseBytes.length, clientAddress, clientPort);
            udpSocket.send(responsePacket);

            new Thread(() -> startTcpServer(tcpPort, pool)).start();
        }
    }

    private static void startTcpServer(int tcpPort, ExecutorService pool) {
        try (ServerSocket serverSocket = new ServerSocket(tcpPort)) {
            System.out.println("tcpServer port " + tcpPort);

            while (true) {
                Socket clientSocket = serverSocket.accept();
                System.out.println("tcpClientNew: " + clientSocket);
                pool.execute(new ClientHandler(clientSocket));
            }
        } catch (IOException e) { e.printStackTrace(); }
    }


    private static class ClientHandler implements Runnable {
        private Socket socket;

        ClientHandler(Socket socket) {
            this.socket = socket;
        }

        public void run() {
            synchronized (lock) {
                while (busy) {
                    try {
                        lock.wait(); //wait until server is free
                    } catch (InterruptedException e) { e.printStackTrace(); }
                }
                busy = true; //get server
            }

            try (
                    BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                    PrintWriter out = new PrintWriter(socket.getOutputStream(), true)
            ) {
                out.println("serverConnected, 'quit' to exit");
                String line;
                while ((line = in.readLine()) != null) {
                    System.out.println("recieved: " + socket + ": " + line);

                    if (line.equalsIgnoreCase("quit")) {
                        out.println("bye");
                        break;
                    }

                    //try "a+b"
                    try {
                        String[] parts = line.split("\\+");
                        if (parts.length == 2) {
                            int a = Integer.parseInt(parts[0].trim());
                            int b = Integer.parseInt(parts[1].trim());
                            int sum = a + b;
                            out.println("result: " + sum);
                        } else {
                            out.println("wrng do \"a+b\"");
                        }
                    } catch (Exception e) {
                        out.println("error input");
                    }
                }
            } catch (IOException e) { e.printStackTrace(); }
            finally {
                try { socket.close(); } catch (IOException e) {}
                System.out.println("disconnected: " + socket);

                synchronized (lock) {
                    busy = false;
                    lock.notifyAll(); // allow next client
                }
            }
        }
    }
}
