public class DataTypes {
    public static void main(String[] args) {
        /*
        4*7/3   Integer.MIN_VALUE-1     (double) 41/17      (double) (41/17)
        41/(double)17       7e2D     6!=7       "AB" + 'C' + 5
         */
        double x = 4*7/3; // prints out int because its not casted as double
        int y = Integer.MIN_VALUE-1;
        double i = (double) 41/17;
        String a = "(41/17)";
        double j = 41/(double)17;
        System.out.println(7e2D); // 7 * 10^2 Decimal
        System.out.println(6!=7); // true
        String c = "AB" + 'C' + 5;

        System.out.println(x+", "+y+", "+i+", "+a+", "+c);
    }
}
