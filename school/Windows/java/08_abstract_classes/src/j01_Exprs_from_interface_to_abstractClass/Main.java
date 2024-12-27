package j01_Exprs_from_interface_to_abstractClass;

public class Main {
    public static void main(String[] args) {

        System.out.println(new Addition(new Number(3), new Number(5)).eval());
        System.out.println(new Subtraction(new Number(3), new Number(5)).eval());
        System.out.println(new Multiplication(new Number(3), new Number(5)).eval());
        System.out.println(new Division(new Number(3), new Number(5)).eval());
        System.out.println(new Power(new Number(3), new Number(5)).eval());
        System.out.println("---------------");

        Number x = new Number(2);
        Number y = new Number(5);
        Number z = new Number(3);

        Expr rechnung = new Division(
                new Power(
                        new Subtraction(
                                new Addition(
                                        new Multiplication(
                                                new Power(x, new Number(3)),
                                                new Number(3)
                                        ),
                                        new Multiplication(
                                                new Number(3),
                                                new Power(y, new Number(2))
                                        )
                                ),
                                new Multiplication(new Number(2), z)
                        ),
                        new Number(0.5)
                ),
                new Subtraction(
                        new Addition(
                                x,
                                new Multiplication(new Number(5),y)
                        ),
                        new Multiplication(new Number(8),z)
                )
        );

        System.out.println("Calculated: " + rechnung.eval());




    }
}

