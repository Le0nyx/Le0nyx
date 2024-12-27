public class IntegerBehavior {
    public static void main(String[] args) {
        int x = 10;
        int z = (x / 3) * 2; // java rundet gleich wie C ab mit Kommastellen
        int y = (x * 2) / 3; // auch wenn man Mathematisch aufrundet rundet Java immer ab bei Kommastellen mit Integern

        System.out.println(x+" "+y+" "+z);
    }
}
