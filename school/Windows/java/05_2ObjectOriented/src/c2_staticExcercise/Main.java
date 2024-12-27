package c2_staticExcercise;

public class Main {
    public static void main(String[] args) {
        Rechnerei.einenSpruchSagen("Ich bin klug.");
        double zahl = 16;

        System.out.println("Die Wurzel aus " + zahl + " ist " + Rechnerei.wurzelZiehen(zahl));
        int z1 = 144;
        int z2 = 513;
        System.out.println(z1 + " + " + z2 + " = " + Rechnerei.zweiZahlenAddieren(13, 2));

    }
}
