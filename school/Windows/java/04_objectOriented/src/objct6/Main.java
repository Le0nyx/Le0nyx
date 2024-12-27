package objct6;
import java.util.Scanner;


public class Main {
    public static void main(String[] args) {
        int max_books = 200;

        Book[] books = new Book[max_books];

        books[0] = new Book("Book 1", "Author 1", 2000);
        books[1] = new Book("Book 2", "Author 2", 2000);
        books[2] = new Book("Book 3", "Author 3", 2000);
        books[3] = new Book("Book 4", "Author 2", 5000);


        Scanner sc = new Scanner(System.in);
        System.out.println("Author to search: ");
        String to_search = sc.nextLine();

        boolean found = false;
        for (Book book : books) {
            if(book == null){ break; }
            if(book.getAuthor().equals(to_search)) {
                System.out.println("---------");
                System.out.println(book.getTitle());
                System.out.println(book.getAuthor());
                System.out.println(book.getPages());
                found = true;
            }
        }
        if(!found){ System.out.println("\n\n ------ \nNo such author found in library"); }
        sc.close();
    }
}
