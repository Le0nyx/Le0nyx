package j03_RMI_Uebung2;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface ClientCallback extends Remote {
    void receiveAnswer(String answer) throws RemoteException;
}
