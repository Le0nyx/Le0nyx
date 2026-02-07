package j01_RMI_Try;

import java.rmi.RemoteException;

public class HelloImpl implements Hello {
    private String message;

    public HelloImpl(String message) {
        this.message = message;
    }

    public String sayHello() throws RemoteException {
        return message;
    }
}
