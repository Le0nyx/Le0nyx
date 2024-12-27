public class ifStatements {
    public static void main(String[] args) {
        int x, y, z;
        x = 6;
        y = 3;
        z = 4;

        if (x == 2)
            y=x;
        else if(x == 4)
            y=2*x;
        else if(x == 6)
            y=4*x;

        System.out.printf(x+" "+y+" "+z);

        // if statements still follow the rules of if and then going to if else but without brackets only does the next line
    }
}
