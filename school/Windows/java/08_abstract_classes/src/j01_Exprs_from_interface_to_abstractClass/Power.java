package j01_Exprs_from_interface_to_abstractClass;

public class Power extends Expr {
    private Expr basis;
    private Expr exponent;


    public Power(final Expr basis, final Expr exponent) {
        this.basis = basis;
        this.exponent = exponent;
    }

    @Override
    public double eval() {
        return Math.pow(basis.eval(), exponent.eval());
    }
}
