package j01_VererbungMenschJob;

public class Sportler extends Mensch {
    private double size_meters;
    private double how_fat;

    public Sportler(String name, int age, double size_meters, double how_fat) {
        super(name, age);
        this.size_meters = size_meters;
        this.how_fat = how_fat;
    }

    public void gainWeight (double weight) {
        this.how_fat += weight;
    }



    public double getWeight() {
        return this.how_fat;
    }

    public double getSizeMeters() {
        return this.size_meters;
    }
}
