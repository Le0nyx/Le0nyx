package j01_RMI_Try;

import java.rmi.AlreadyBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;

public class Server {
    public static void main(String[] args) {
        try{
            HelloImpl h = new HelloImpl("Hello World");
            Hello h_stub = (Hello) UnicastRemoteObject.exportObject(h, 1099);
            LocateRegistry.createRegistry(1099);

            Registry registry = LocateRegistry.getRegistry();
            registry.bind("Hello1", h_stub);
            System.out.println("Server started");


        }catch(RemoteException e){
            e.printStackTrace();
        }catch(AlreadyBoundException e){
            e.printStackTrace();
        }
    }


}
