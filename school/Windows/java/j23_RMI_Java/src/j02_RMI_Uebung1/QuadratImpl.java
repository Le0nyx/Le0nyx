package j02_RMI_Uebung1;

import java.rmi.RemoteException;

public class QuadratImpl implements Quadrat {

    public QuadratImpl() throws RemoteException {
    }

    public long quadrat(long x) throws RemoteException {
        return x * x;
    }
}
