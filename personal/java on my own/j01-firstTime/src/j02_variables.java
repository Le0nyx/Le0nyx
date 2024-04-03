public class j02_variables {
    public static void main(String[] args) {
        int a = 23;
        double b = 0.003;
        float c = 0.021F;
        boolean d = true;
        char e  = 'x';
        String keyword = "Hello there";

        System.out.println(c+"\ni say: "+keyword+" and "+e);

        // swapping variables around
        String key1 = "Hello";
        String key2 = "there";
        String temp;

        temp = key1;
        key1 = key2;
        key2 = temp;

        System.out.println(key1+" "+key2);
    }
}