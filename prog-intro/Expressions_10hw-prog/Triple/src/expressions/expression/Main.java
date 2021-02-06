package expressions.expression;

public class Main {
    public static void main(String[] args) {
        System.out.println(new Subtract(
                new Multiply(
                        new Const(2),
                        new Variable("x")
                ),
                new Const(3)
        ).evaluate(5));
        System.out.println(
                new Multiply(new Const(2), new Variable("x"))
                        .equals(new Multiply(new Const(2), new Variable("x")))
        );
    }
}
