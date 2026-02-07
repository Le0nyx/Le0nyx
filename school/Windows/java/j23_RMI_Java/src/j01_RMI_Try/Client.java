package j01_RMI_Try;

import java.rmi.AlreadyBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;

public class Client {
    public static void main(String[] args) {
        try{
            Registry registry = LocateRegistry.getRegistry("127.0.0.1");
            Hello h = (Hello) registry.lookup("Hello1");
            String res = h.sayHello();
            System.out.println(res);

        }catch (Exception e){
            e.printStackTrace();
        }
    }



}
