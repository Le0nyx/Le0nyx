public class j04_expressions {
    public static void main(String[] args){ // behavior similar to coding in C
        float num = 0.01F; //has to put F because of float. not necessary with double

        num = num +1; //normal writing
        num++;
        num--;
        num *= 2; //shortened version
        System.out.println(num);
        System.out.println(num % 2); //another great example of coding with %2 since it should be 0.02 and not that

        int a = 5;
        System.out.println(a/2); //the 0.5 gets cut off
        System.out.println((double) a/2); //the 0.5 doesn't get cut off since it got cast as double
    }
}