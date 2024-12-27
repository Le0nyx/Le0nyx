package obcjt7W;

public class Library {
    private int capacity;
    private int count;
    private Book[] books;

    public Library(int capacity) {
        this.capacity = capacity;
        this.books = new Book[capacity];
        this.count = 0;
    }

    public boolean addBook(String title, String author, int pageCount) {
        if (capacity>count) {
            for (int i=0;i<books.length;i++) {
                if (books[i]==null) {
                    books[i]=new Book(title, author, pageCount);
                    count++;
                    break;
                }
            }
            return true;
        }else
            return false;
    }
    public boolean removeBook(String title) {
        for(int i=0;i<books.length;i++) {
            if(books[i].getTitle().equals(title)) {
                books[i]=null;
                count--;
                return true;
            }
        }
        return false;
    }
    public int searchBook(String author) {
        for(int i=0;i<books.length;i++) {
            if(books[i].getAuthor().equals(author)) {
                return i;
            }
        }
        return -1;
    }
    public int getBookCount() {
        return count;
    }
}
