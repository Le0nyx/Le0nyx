public class TestCode {
    static int func1(int a, int b) {
        while (a != b) {
            if (a > b) {
                a = a - b;
            } else {
                b = b - a;
            }
        }
        return a;
    }

    public static void main(final String[] args){
        System.out.println(func1(Integer.parseInt(args[1]), Integer.parseInt(args[0])));
    }
}