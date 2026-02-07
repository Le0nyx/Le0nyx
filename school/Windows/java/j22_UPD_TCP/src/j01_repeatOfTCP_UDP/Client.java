package j01_repeatOfTCP_UDP;

import java.io.*;
import java.net.Socket;

public class Client {
    public static void main(String[] args) {
        try (Socket clientSocket = new Socket("localhost", 800);
             ObjectOutputStream out = new ObjectOutputStream(clientSocket.getOutputStream());
             ObjectInputStream in = new ObjectInputStream(clientSocket.getInputStream());
             BufferedReader console = new BufferedReader(new InputStreamReader(System.in))) {

            System.out.println("Verbunden mit Server.");
            System.out.println("Tippe einen Befehl (z.B. 'help'):");

            String input = console.readLine();
            out.writeObject(input);
            out.flush();

            String response = (String) in.readObject();
            System.out.println("Antwort vom Server: " + response);

        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}
