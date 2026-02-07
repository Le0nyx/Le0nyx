package j03_RMI_Uebung2;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface AnswerService extends Remote {
    String answerQuestion(String question) throws RemoteException;
    void submitQuestionAsync(String question, ClientCallback callback) throws RemoteException;
}
