package j01_newInterfaces;

public class Addition implements Expr {
    private Expr addend1;
    private Expr addend2;

    public Addition(final Expr addend, final Expr addend2) {
        this.addend1 = addend;
        this.addend2 = addend2;
    }

    public double eval() {
        return addend1.eval() + addend2.eval();
    }
}
