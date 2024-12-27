package obcjt1_withoutConstructor.obcjt1;

public class Main {
    public static void main(String[] args) {
        Rectangle rechteck = new Rectangle();

        rechteck.length = 5;
        rechteck.width = 3;

        System.out.println("Area is: " + rechteck.getArea());
        System.out.println("Length around: " + rechteck.getCircumference());
    }
}
