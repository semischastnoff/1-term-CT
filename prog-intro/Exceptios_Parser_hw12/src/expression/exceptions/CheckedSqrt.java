package expression.exceptions;

import expression.BaseExpression;

public class CheckedSqrt implements BaseExpression {
    private final BaseExpression expr;

    public CheckedSqrt(BaseExpression expr) {
        this.expr = expr;
    }

    @Override
    public int evaluate(int x) {
        int res = expr.evaluate(x);
        if (res < 0) {
            throw new NegativeArgumentException("Argument for square root should be positive");
        }
        return (int) Math.sqrt(res);
    }

    @Override
    public int evaluate(int x, int y, int z) {
        int res = expr.evaluate(x, y, z);
        if (res < 0) {
            throw new NegativeArgumentException("Argument for square root should be positive");
        }
        return (int) Math.sqrt(res);
    }
}
