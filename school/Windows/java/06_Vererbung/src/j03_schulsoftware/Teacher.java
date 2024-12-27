package j03_schulsoftware;

public class Teacher extends Mensch {
    private String subject;


    public Teacher(String name, int age, String subject) {
        super(name, age);
        this.subject = subject;
    }
}
