import java.io.*;

public class DateiLesen {
    public static void main(String[] args) {
        String dateiname = "test.txt";

        dateiLesen(dateiname);
    }


    public static void dateiLesen(String dateiname) {
        BufferedReader br = null;
        try {
            br = new BufferedReader(new FileReader(dateiname));

            String line;
            int lineCount = 0;

            String firstLine = null;
            String thirdLine = null;

           // read lines
            while ((line = br.readLine()) != null) {
                lineCount++;

                if (lineCount == 1) {
                    firstLine = line;
                } else if (lineCount == 3) {
                    thirdLine = line;
                    break; // stop cuz only 1 and 3
                }
            }


            System.out.println("Erste Zeile: " + (firstLine != null ? firstLine : "Keine Zeile"));
            System.out.println("Dritte Zeile: " + (thirdLine != null ? thirdLine : "Keine Zeile"));

        } catch (FileNotFoundException e) {
            System.out.println("Datei nicht gefunden: " + dateiname);
        } catch (IOException e) {
            System.out.println("Fehler beim Lesen der Datei.");
        } finally {
            try {
                if (br != null) {
                    br.close();
                }
            } catch (IOException e) {
                System.out.println("Fehler beim Schließen der Datei.");
            }
        }
    }
}
