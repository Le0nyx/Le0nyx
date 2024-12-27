package j01_newInterfaces;

public class Number implements Expr {
    private double value;

    public Number(double value) {
        this.value = value;
    }


    @Override
    public double eval() {
        return value;
    }
}
