package Sparrschwein;

public class Main {
    public static void main(String[] args) {

        Piggybank a = new Piggybank();

        a.init_piggybank(20);

        System.out.println(a.is_empty());

        System.out.println(a);

        System.out.println(a.add1Cents(12));
        System.out.println(a.add1Cents(24));
        System.out.println(a.add1Cents(24));
        System.out.println(a.add1Cents(24));

        System.out.println(a.is_empty());
        System.out.println(a.is_full());

        System.out.println(a.breakInto());
    }
}
