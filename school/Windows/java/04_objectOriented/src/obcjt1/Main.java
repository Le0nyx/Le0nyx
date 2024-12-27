package obcjt1;

public class Main {
    public static void main(String[] args) {
        Rectangle rechteck = new Rectangle(5, 3);

        rechteck.setLength(23);

        System.out.println("Area is: " + rechteck.getArea());
        System.out.println("Length around: " + rechteck.getCircumference());
    }
}
