package j01_loggerFirst;

import java.io.FileWriter;
import java.io.IOException;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class Logger {
    private static Logger instance;
    private String logFile;
    private final DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");

    private Logger() {} // private logger

    public static Logger getInstance() {
        if (instance == null) {
            instance = new Logger();
        }
        return instance;
    }

    public void setLogFile(String filename) {
        this.logFile = filename;
    }

    private String formatMessage(String message) {
        return "[" + LocalDateTime.now().format(formatter) + "] " + message;
    }

    public void logToConsole(String message) {
        System.out.println(formatMessage(message));
    }

    public void logToFile(String message) {
        if (logFile == null) {
            System.err.println("no logfile");
            return;
        }

        try (FileWriter writer = new FileWriter(logFile, true)) {
            writer.write(formatMessage(message) + System.lineSeparator());
        } catch (IOException e) {
            System.err.println("Error writing" + e.getMessage());
        }
    }

    public void log(String message) {
        logToConsole(message);
        if (logFile != null) {
            logToFile(message);
        }
    }
}
