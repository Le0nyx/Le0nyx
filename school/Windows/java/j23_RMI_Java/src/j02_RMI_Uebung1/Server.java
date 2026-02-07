package j02_RMI_Uebung1;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Server {
    public static void main(String[] args) {
        try {
            try { LocateRegistry.createRegistry(1099); }
            catch (Exception e) { }
            Registry reg = LocateRegistry.getRegistry(1099);


            // Quadrat
            QuadratImpl qImpl = new QuadratImpl();
            reg.rebind("Quadrat", qImpl);

            // Task
            TaskImpl tImpl = new TaskImpl();
            reg.rebind("Task", tImpl);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
