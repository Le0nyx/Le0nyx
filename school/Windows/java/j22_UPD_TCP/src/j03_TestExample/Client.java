package j03_TestExample;

import java.io.*;
import java.net.*;
import java.util.Scanner;

public class Client {
    private static final String BROADCAST_ADDR = "127.0.0.255";
    private static final int UDP_PORT = 50000;
    private static final int TIMEOUT_MS = 30000; // 30 Sekunden

    public static void main(String[] args) {
        try {
            //udp finding
            DatagramSocket udpSocket = new DatagramSocket();
            udpSocket.setBroadcast(true);
            udpSocket.setSoTimeout(2000); //2sec interval

            byte[] sendData = "DISCOVER_SERVER".getBytes();
            InetAddress broadcast = InetAddress.getByName(BROADCAST_ADDR);
            long startTime = System.currentTimeMillis();
            String serverIpPort = null;

            while ((System.currentTimeMillis() - startTime) < TIMEOUT_MS && serverIpPort == null) {
                DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, broadcast, UDP_PORT);
                udpSocket.send(sendPacket);
                System.out.println("tryna find server");

                try {
                    byte[] recvBuffer = new byte[1024];
                    DatagramPacket recvPacket = new DatagramPacket(recvBuffer, recvBuffer.length);
                    udpSocket.receive(recvPacket);

                    serverIpPort = new String(recvPacket.getData(), 0, recvPacket.getLength());
                    System.out.println("fromServer: " + serverIpPort);
                } catch (SocketTimeoutException e) {
                    System.out.println("waitin");
                }
            }

            udpSocket.close();
            if (serverIpPort == null) {
                System.out.println("30seconds no response. shutdonw");
                return;
            }

            String[] parts = serverIpPort.split(":");
            String serverIp = parts[0];
            int tcpPort = Integer.parseInt(parts[1]);

            //tcpConnect
            try (Socket tcpSocket = new Socket(serverIp, tcpPort);
                 BufferedReader in = new BufferedReader(new InputStreamReader(tcpSocket.getInputStream()));
                 PrintWriter out = new PrintWriter(tcpSocket.getOutputStream(), true);
                 Scanner scanner = new Scanner(System.in)) {

                System.out.println("connectedServer: " + serverIp + ":" + tcpPort);

                System.out.println("server: " + in.readLine());

                while (true) {
                    System.out.print("Enter calc (a+b) or 'quit': ");
                    String userInput = scanner.nextLine();
                    out.println(userInput);

                    if (userInput.equalsIgnoreCase("quit")) {
                        System.out.println("client closed");
                        break;
                    }

                    String response = in.readLine();
                    if (response == null) break; // server closed
                    System.out.println("ServerResp: " + response);
                }
            }
        } catch (IOException e) { e.printStackTrace(); }
    }
}
