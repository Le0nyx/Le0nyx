package j01_newInterfaces;

public class Division implements Expr {
    private Expr dividend;
    private Expr divisor;

    public Division(final Expr dividend, final Expr divisor) {
        this.dividend = dividend;
        this.divisor = divisor;
    }

    public double eval() {
        return dividend.eval() / divisor.eval();
    }
}
