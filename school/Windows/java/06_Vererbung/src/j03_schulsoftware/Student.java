package j03_schulsoftware;

public class Student extends Mensch {
    private int klassenstufe;
    private boolean is_klassensprecher;

    public Student(String name, int age, int klassenstufe, boolean is_klassensprecher) {
        super(name, age);
        this.klassenstufe = klassenstufe;
        this.is_klassensprecher = is_klassensprecher;
    }

    public Student(String name, int age, int klassenstufe) {
        this(name, age, klassenstufe, false);
    }


    public double getschulkasseToPay(){
        if(!is_klassensprecher){
            return (double) super.getAge()/this.klassenstufe * 5;
        }else{
            return (double) super.getAge()/this.klassenstufe * 3;
        }
    }
}
