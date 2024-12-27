package j04_dollarToEuroInterfaces;

public interface Waehrung {
    public String symbol();
    public Waehrung mult(double f);
}
