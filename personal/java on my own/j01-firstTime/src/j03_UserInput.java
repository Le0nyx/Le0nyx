import java.util.Scanner;
public class j03_UserInput {
    public static void main(String[] args){ //doesnt include exceptions yet
        Scanner inputIG = new Scanner(System.in); //create a scanner object (objects get explained later)

        System.out.println("Please enter your name: ");
        String name = inputIG.nextLine();
        System.out.println("Please enter your age: ");
        int age = inputIG.nextInt(); // leaves a remaining \n in the buffer for input
        inputIG.nextLine(); // clears the \n remaining
        System.out.println("Enter your favorite food: ");
        String food = inputIG.nextLine();

        inputIG.close(); //not necessary but should do

        System.out.println("You entered your name: "+name);
        System.out.println("You entered as age: "+age);
        System.out.println("You entered for food: "+food);
    }
}