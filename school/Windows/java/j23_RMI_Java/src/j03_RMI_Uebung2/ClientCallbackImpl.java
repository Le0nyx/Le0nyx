package j03_RMI_Uebung2;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class ClientCallbackImpl extends UnicastRemoteObject implements ClientCallback {
    // lock is the object the client main thread waits on
    private final Object lock;

    public ClientCallbackImpl(Object lock, int exportPort) throws RemoteException {
        super(exportPort); // export on fixed port (20000)
        this.lock = lock;
    }

    @Override
    public void receiveAnswer(String answer) throws RemoteException {
        System.out.println("Callback erhalten vom Server: " + answer);
        // notify the client main thread
        synchronized (lock) {
            lock.notify();
        }
    }
}
