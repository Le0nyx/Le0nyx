import java.util.Scanner;
public class j01_whileLoop {
    public static void main(String[] args){
        Scanner inputIG = new Scanner(System.in);

        System.out.println("Enter a name: ");
        String name = inputIG.nextLine();

        while (!name.equals("World")){
            System.out.println("you are wrong, "+name+"\nEnter a new name: ");
            name = inputIG.nextLine();
        }
        System.out.println("You escaped for now");

        int age = 0;
        do {
            System.out.println("\nEnter a number (0-10): ");
            age = inputIG.nextInt();
            inputIG.nextLine(); //clear the \n
        }while (age != 17);

        System.out.println("I guess you managed to fully escape");
        inputIG.close(); //close the second aswell (good habit)
    }
}