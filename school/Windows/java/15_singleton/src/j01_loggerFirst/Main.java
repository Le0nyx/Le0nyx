package j01_loggerFirst;

public class Main {
    public static void main(String[] args) {
        Logger l = Logger.getInstance();

        l.setLogFile("application.log");

        l.logToConsole("Anwendung gestartet");
        l.logToFile("Anwendung gestartet");

        l.log("Ein kombinierter Logeintrag");

        Logger l2 = Logger.getInstance();
        l2.logToFile("Dies wird fehlschlagen");
    }
}