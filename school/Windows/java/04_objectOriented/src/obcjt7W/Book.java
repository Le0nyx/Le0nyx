package obcjt7W;

public class Book {
    private String Author;
    private String Title;
    private int pageCount;

    public Book(String author, String title, int pageCount) {
        this.Author = author;
        this.Title = title;
        this.pageCount = pageCount;
    }
    public String getAuthor() {
        return Author;
    }
    public String getTitle() {
        return Title;
    }
    public int getPageCount() {
        return pageCount;
    }
    public void setAuthor(String author) {
        this.Author = author;
    }
    public void setTitle(String title) {
        this.Title = title;
    }
    public void setPageCount(int pageCount) {
        this.pageCount = pageCount;
    }
}
