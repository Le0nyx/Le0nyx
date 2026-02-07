package j03_RMI_Uebung2;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class AnswerServiceImpl extends UnicastRemoteObject implements AnswerService {

    protected AnswerServiceImpl() throws RemoteException {
        super();
    }

    @Override
    public String answerQuestion(String question) throws RemoteException {
        try { Thread.sleep(3000); } catch (InterruptedException ignored) {}
        return "Die Antwort auf deine Frage: \"" + question + "\" ist wahrscheinlich 61";
    }

    @Override
    public void submitQuestionAsync(String question, ClientCallback callback) throws RemoteException {
        System.out.println("submitQuestionAsync received: " + question);
        new Thread(() -> {
            try {
                Thread.sleep(5000); // simulate long work
                String result = "Die Antwort auf deine Frage: \"" + question + "\" ist wahrscheinlich 61";
                System.out.println("Computed result doing client callback");
                callback.receiveAnswer(result);
                System.out.println("Callback done");
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            } catch (RemoteException re) {
                System.err.println("Callback failed: " + re);
                re.printStackTrace();
            }
        }).start();
    }
}
