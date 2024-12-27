package obcjt5String;

import obct2.Car;

public class Main {
    public static void main(String[] args) {
        String str1 = new String("Hallo");
        String str2 = new String("Hallo");

        String[] penis = new String[50];

        if (str1 == str2) { // memory location is not the same
            System.out.println("Die Strings sind gleich.");
        } else {
            System.out.println("Die Strings sind nicht gleich.");
        }
    }
}
