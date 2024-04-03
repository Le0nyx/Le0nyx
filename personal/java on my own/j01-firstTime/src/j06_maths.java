public class j06_maths {
    public static void main(String[] args){
        double x = 3.1415;
        double y = -5;

        System.out.println("Min = "+Math.min(y, x));
        System.out.println("Max = "+Math.max(y, x));
        System.out.println("Absolute of y = "+Math.abs(y));
        System.out.println("Sqrt of 25 = "+Math.sqrt(25));
        System.out.println("x rounded = "+Math.round(x));
        System.out.println("x rounded up = "+Math.ceil(x)); // ceil rounds always up to the full num (also floor exists to do opposite)
    }
}
