package j01_Exprs_from_interface_to_abstractClass;

public class Number extends Expr {
    private double value;

    public Number(double value) {
        this.value = value;
    }


    @Override
    public double eval() {
        return value;
    }
}
