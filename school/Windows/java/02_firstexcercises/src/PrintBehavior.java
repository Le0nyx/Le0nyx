public class PrintBehavior {
    public static void main(String[] args) {
        short s = 10;
        float f = 100.5f;
        double d = 200.6, sum;
        boolean flag = true;
        char c = 'x';
        System.out.println("s = " + s + " f = " + f + " d = " + d);
        sum = s + f + d;
        System.out.println(flag);
        System.out.println(c);
        System.out.println("sum = " + sum);
        System.out.println(2 + "test" + 3);
        System.out.println(2 + 3 + "test"); // goes from left to right and respects math rules
        System.out.println("test" + 2 + 3); // meaning takes left and adds the right
        System.out.println("test" + 2 * 3); // but still respects the math rule of point before line
    }
}
