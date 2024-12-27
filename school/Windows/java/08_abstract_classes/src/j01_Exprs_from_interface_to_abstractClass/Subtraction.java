package j01_Exprs_from_interface_to_abstractClass;

public class Subtraction extends Expr {
    private Expr minuend;
    private Expr subtrahend;
    public Subtraction(final Expr minuend, final Expr subtrahend) {
        this.minuend = minuend;
        this.subtrahend = subtrahend;
    }

    @Override
    public double eval() {
        return minuend.eval() - subtrahend.eval();
    }
}
