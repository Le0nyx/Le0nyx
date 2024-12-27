package j02_Pizza;

public class PizzaSpecial2012 extends Pizza {
    private String pizzaSauce;
    private int spice;

    public PizzaSpecial2012(String name, double price, String pizzaSauce, int spice) {
        super(name, price);
        this.pizzaSauce = pizzaSauce;
        this.spice = spice;
    }

    public String getPizzaSauce() {
        return pizzaSauce;
    }
    public void setPizzaSauce(String pizzaSauce) {
        this.pizzaSauce = pizzaSauce;
    }
    public int getSpice() {
        return spice;
    }
    public void setSpice(int spice) {
        this.spice = spice;
    }
}
