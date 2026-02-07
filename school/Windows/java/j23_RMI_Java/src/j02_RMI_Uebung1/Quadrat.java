package j02_RMI_Uebung1;

import java.io.Serializable;
import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Quadrat extends Remote, Serializable {
    long quadrat(long x) throws RemoteException;
}
