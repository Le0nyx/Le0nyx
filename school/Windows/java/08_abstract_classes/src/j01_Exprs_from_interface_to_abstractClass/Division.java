package j01_Exprs_from_interface_to_abstractClass;

public class Division extends Expr {
    private Expr dividend;
    private Expr divisor;

    public Division(final Expr dividend, final Expr divisor) {
        this.dividend = dividend;
        this.divisor = divisor;
    }

    @Override
    public double eval() {
        return dividend.eval() / divisor.eval();
    }
}
