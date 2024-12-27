package j02_Pizza;

public class Main {
    public static void main(String[] args) {
        Sonderangebot pizza1 = new Sonderangebot("Tiroler", 8.70);
        System.out.println(pizza1.getName() + ", " + pizza1.getPrice());

        Sonderangebot pizza2 = new Sonderangebot("Pizza2", 8.00, 24.30f);
        System.out.println(pizza2.getName() + ", " + pizza2.getPrice());

        PizzaSpecial2012 pizza3 = new PizzaSpecial2012("Pizza3", 8.30, "Yogurt-Salsa", 2);
        System.out.println(pizza3.getName() + ", " + pizza3.getPrice()+ ", " + pizza3.getSpice());
    }
}
