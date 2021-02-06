package expression;

import expression.exceptions.CheckedMultiply;
import expression.exceptions.ExpressionParser;

public class Main {
    public static void main(String[] args) {
        System.out.println(new Xor(new Const(3), new Const(5)
        ).evaluate(5));
        System.out.println(
                new CheckedMultiply(new Const(2), new Variable("x"))
                        .equals(new CheckedMultiply(new Const(2), new Variable("x")))
        );

        ExpressionParser parser = new ExpressionParser();
        System.out.println(parser.parse("-(-3 - (-5))").toString());
        System.out.println(parser.parse("-(-3 - (-5))").evaluate(0, 0, 0));
    }
}

//   (-((-((-(-(-5)) + ((16 * x) * y))) + (1 * z))) - -(-11))
//   (-((-((-(-(-5)) + ((16 * x) * y))) + (1 * z))) - -(-11))