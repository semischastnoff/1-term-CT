package expression;

import expression.parser.*;

public class Main {
    public static void main(String[] args) {
        System.out.println(new Xor(new Const(3), new Const(5)
        ).evaluate(5));
        System.out.println(
                new Multiply(new Const(2), new Variable("x"))
                        .equals(new Multiply(new Const(2), new Variable("x")))
        );

        ExpressionParser parser = new ExpressionParser();
        System.out.println(parser.parse("x*y+(z-1   )/10").evaluate(0, 0, 1));
    }
}
