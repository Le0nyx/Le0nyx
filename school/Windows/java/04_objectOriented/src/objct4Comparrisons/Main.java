package objct4Comparrisons;

public class Main {
    public static void main(String[] args) {
        Person person1 = new Person("Anna");
        Person person2 = new Person("Anna");


        if (person1 == person2) { // checks the memory location since its not a num
            System.out.println("Die Personen sind gleich.");
        } else {
            System.out.println("Die Personen sind nicht gleich.");
        }
    }

}