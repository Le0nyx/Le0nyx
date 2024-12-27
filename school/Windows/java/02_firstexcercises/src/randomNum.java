import java.util.Arrays;
import java.util.List;

public class randomNum {
    public static void main(String[] args) {
        /*
        Schreibe ein Java-Programm, das 3 Zufallszahlen im Bereich 1-10 erzeugt und dann diese Zahlen in
        aufsteigender Reihenfolge ausgibt. Erzeuge die Zufallszahlen mit Math.random(). Diese Methode
        der Hilfsklasse Math liefert eine Zahl x mit 0 ≤ x < 1 vom Typ double zurück.
         */


        int[] arr = new int[3];

        arr[0] = (int)(Math.random()*10) + 1;
        arr[1] = (int)(Math.random()*10) + 1;
        arr[2] = (int)(Math.random()*10) + 1;

        System.out.println("Unsorted: " + arr[0] + ", " + arr[1] + ", " + arr[2]);

        Arrays.sort(arr);
        System.out.println("Sorted: " + arr[0] + ", " + arr[1] + ", " + arr[2]);
    }
}
