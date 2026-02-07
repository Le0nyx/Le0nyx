package j02_RMI_Uebung1;

import java.io.Serializable;
import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Task extends Remote, Serializable {
    /**
     * op must be one of '+', '-', '*', '/'.
     */
    double execute(double a, double b, char op) throws RemoteException;
}
