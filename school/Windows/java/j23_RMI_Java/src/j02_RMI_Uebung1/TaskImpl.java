package j02_RMI_Uebung1;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class TaskImpl extends UnicastRemoteObject implements Task {

    public TaskImpl() throws RemoteException {
        super();
    }

    @Override
    public double execute(double a, double b, char op) throws RemoteException {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/':
                if (b == 0.0) throw new RemoteException("div by zero");
                return a / b;
            default:
                throw new RemoteException("what dis " + op);
        }
    }
}
