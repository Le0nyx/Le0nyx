package j03_RMI_Uebung2;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.util.Scanner;

public class Client {
    public static void main(String[] args) {
        final String host = "127.0.0.1";
        final int registryPort = 1099;
        final int callbackPort = 20000; // fixed port for callback export

        Scanner sc = new Scanner(System.in);
        System.out.print("Frage: ");
        String question = sc.nextLine().trim();

        Object lock = new Object();
        ClientCallbackImpl callback = null;

        try {
            Registry reg = LocateRegistry.getRegistry(host, registryPort);
            AnswerService svc = (AnswerService) reg.lookup("AnswerService");

            callback = new ClientCallbackImpl(lock, callbackPort);
            svc.submitQuestionAsync(question, callback);

            System.out.println("request gesendet. Warte auf Callback vom Server");

            synchronized (lock) {
                lock.wait(); // wait till callback did notify()
            }
            System.out.println("Callback empfangen; Client close");


            try {
                UnicastRemoteObject.unexportObject(callback, true);
                System.out.println("Callback undone");
            } catch (Exception e) { System.err.println("some off with callback: " + e); }
        } catch (Exception e) { e.printStackTrace(); }
        finally { sc.close(); }
    }
}
