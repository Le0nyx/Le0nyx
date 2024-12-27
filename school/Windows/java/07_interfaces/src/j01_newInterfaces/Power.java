package j01_newInterfaces;

public class Power implements Expr {
    private Expr basis;
    private Expr exponent;


    public Power(final Expr basis, final Expr exponent) {
        this.basis = basis;
        this.exponent = exponent;
    }

    public double eval() {
        return Math.pow(basis.eval(), exponent.eval());
    }
}
