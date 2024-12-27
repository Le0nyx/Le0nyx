package j02_Pizza;

public class Sonderangebot extends Pizza {
    private float rabatt;

    public Sonderangebot(String name, double price) {
        super(name, price);
    }

    public Sonderangebot(String name, double price, float rabatt) {
        super(name, price);
        this.rabatt = rabatt;
    }

    @Override
    public double getPrice() {
        return Math.round(super.getPrice()*(1.0f-(rabatt/100.0f))* 100.0)/100.0;
    }

    public float getRabatt() {
        return rabatt;
    }
    public void setRabatt(float rabatt) {
        this.rabatt = rabatt;
    }
}
