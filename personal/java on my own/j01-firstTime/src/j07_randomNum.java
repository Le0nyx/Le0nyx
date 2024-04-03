import java.util.Random;

public class j07_randomNum {
    public static void main(String[] args){
        Random randomIG = new Random(); //gives sudo random numbers

        int x = randomIG.nextInt(6)+1; //without +1 would generate from 0 to 5
        System.out.println("random num is "+x);

        double y = randomIG.nextDouble(); //random number between 0 and 1
        System.out.println("Random num of double is "+y);

        boolean z = randomIG.nextBoolean();
        System.out.println("Random boolean is "+z);
    }
}