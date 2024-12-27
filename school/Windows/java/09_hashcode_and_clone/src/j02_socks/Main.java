package j02_socks;
import java.awt.*;

public class Main {
    /*
    Füge in der Klasse Wäscheleine einen Kopierkonstruktor ein sowie eine Methode clone()
    - Implementiere dafür clone() in alle verwendeten Klassen

    */
    public static void main(String[] args) {
        Clothes s1 = new Sock("red", true);
        Washable s2 = new Sock("GrEen", false);

        System.out.println(s1 + "\n" + s2);
        System.out.println(s1.getColor() + ", " + s2.getColor());
        System.out.println(s1.check_if_dry() + ", " + s2.check_if_dry());
        s1.wash();
        s1.wash();
        s1.wash();

        System.out.println(s1.getColor() + ", " + s2.getColor());
        s2.dry();
        System.out.println(s1.check_if_dry() + ", " + s2.check_if_dry());
        s1.setColor(" blue ");
        System.out.println(s1.getColor() + ", " + s2.getColor());

        Pants p1 = new Pants(1.20, "Jeans", true, 8);


        Waescheleine w1 = new Waescheleine();

        p1.wash();
        s1.wash();

        w1.addClothes(s1);
        w1.addClothes(p1);


        w1.dryClothes();
        
    }
}
