package obct2;

public class Car {
    private String brand;
    private int mileage;

    public void honk(){
        System.out.println("HUPEN");
    }

    Car(String brand, int mileage){
        this.brand = brand;
        this.mileage = mileage;
    }

    public String getBrand() {
        return brand;
    }

    public void setBrand(String brand) {
        this.brand = brand;
    }

    public int getMileage() {
        return mileage;
    }

    public void setMileage(int mileage) {
        this.mileage = mileage;
    }

}
