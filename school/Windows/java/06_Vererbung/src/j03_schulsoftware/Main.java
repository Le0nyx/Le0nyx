package j03_schulsoftware;

public class Main {
    public static void main(String[] args) {

        Teacher mutsch = new Teacher("Herr Mutschlechner", 34, "Informatik");
        System.out.println(mutsch.getName() + " " + mutsch.getAge());

        Student person1 = new Student("Samuel", 17, 4);
        System.out.println(person1.getName() + " " + person1.getAge() + ", " + person1.getschulkasseToPay());

        Student person2 = new Student("Leonie", 17, 4, true);
        System.out.println(person2.getName() + " " + person2.getAge() + ", " + person2.getschulkasseToPay());

        Student person3 = new Student("Waleed", 18, 4, false);
        System.out.println(person3.getName() + " " + person3.getAge() + ", " + person3.getschulkasseToPay());

        Student person4 = new Student("Julian", 18, 5, true);
        System.out.println(person4.getName() + " " + person4.getAge() + ", " + person4.getschulkasseToPay());
    }
}
