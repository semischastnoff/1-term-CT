package expression;

import expression.parser.*;

public class Main {
    public static void main(String[] args) throws Exception {
        System.out.println(new Xor(new Const(3), new Const(5)
        ).evaluate(5));
        System.out.println(
                new CheckedMultiply(new Const(2), new Variable("x"))
                        .equals(new CheckedMultiply(new Const(2), new Variable("x")))
        );

        ExpressionParser parser = new ExpressionParser();
        System.out.println(parser.parse("- -654445706 - (y) / z)").evaluate(0, 0, 1));
    }
}
