package j03_RMI_Uebung2;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Server {
    public static void main(String[] args) {
        final int registryPort = 1099;
        try {
            try { LocateRegistry.createRegistry(registryPort); } catch (Exception ignored) {}
            Registry reg = LocateRegistry.getRegistry(registryPort);

            AnswerServiceImpl impl = new AnswerServiceImpl();
            reg.rebind("AnswerService", impl);

            System.out.println("Server running; AnswerService bind");

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
