import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class DateiSchreiben {
    public static void main(String[] args) {
        String dateiname = "ausgabe.txt";
        BufferedWriter bw = null;

        try {
            bw = new BufferedWriter(new FileWriter(dateiname));

            LocalDateTime now = LocalDateTime.now();
            DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd-MM-yyyy HH:mm:ss");
            bw.write("Aktuelles Datum und Uhrzeit: " + now.format(formatter));
            bw.newLine();

            // mult 0-10
            bw.write("Kleines Einmaleins:");
            bw.newLine();
            for (int i = 1; i <= 10; i++) {
                for (int j = 1; j <= 10; j++) {
                    bw.write(i + " * " + j + " = " + (i * j) + "\t");
                }
                bw.newLine();
            }

            System.out.println("Datei erfolgreich geschrieben!");
        } catch (IOException e) {
            System.out.println("Fehler beim Schreiben in die Datei: " + e.getMessage());
        } finally {
            try {
                if (bw != null) {
                    bw.close();
                }
            } catch (IOException e) {
                System.out.println("Fehler beim Schließen der Datei.");
            }
        }
    }
}
