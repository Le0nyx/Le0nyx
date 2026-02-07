package j01_repeatOfTCP_UDP;

import java.io.*;
import java.net.*;

public class Server {
    public static void main(String[] args) {
        try (ServerSocket serverSocket = new ServerSocket(800)) {
            System.out.println("Server gestartet. Warte auf Clients...");

            while (true) {
                Socket connection = serverSocket.accept();
                System.out.println("Client verbunden: " + connection.getInetAddress());

                // Streams
                ObjectOutputStream out = new ObjectOutputStream(connection.getOutputStream());
                out.flush();
                ObjectInputStream in = new ObjectInputStream(connection.getInputStream());

                String message = (String) in.readObject();
                System.out.println("Empfangen: " + message);

                String response;
                switch (message.toLowerCase()) {
                    case "help":
                        response = "Befehle:\n- help: zeigt diese Hilfe\n- time: aktuelle Uhrzeit\n- bye: Verbindung schließen";
                        break;
                    case "time":
                        response = "Serverzeit: " + new java.util.Date();
                        break;
                    case "bye":
                        response = "Tschüss! Verbindung wird geschlossen.";
                        break;
                    default:
                        response = "Unbekannter Befehl. Tippe 'help' für Hilfe.";
                }

                out.writeObject(response);
                out.flush();

                in.close();
                out.close();
                connection.close();

                // Bei "bye" könnte man break setzen, damit der Server auch stoppt.
            }

        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}
