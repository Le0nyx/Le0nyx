package j01_VererbungMenschJob;

public class Mensch {
    private String name;
    private int age;

    public Mensch(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public void years_aged(int years) {
        if (years > 0) {
            this.age += years;
        }
    }




    public String getName() {
        return name;
    }
    public int getAge() {
        return age;
    }
}
