package obcjt7W;

public class Main {
    public static void main(String[] args) {
        Library banane = new Library(3);
        System.out.println(banane.addBook("Gelb","Guenter",100));
        System.out.println(banane.addBook("rot","pferd",100));
        System.out.println(banane.addBook("blau","halt",100));
        System.out.println(banane.addBook("blau","halt",100));

        System.out.println(banane.getBookCount());
    }
}
