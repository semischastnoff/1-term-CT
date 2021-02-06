package expression.exceptions;

import expression.BaseExpression;

public class CheckedNegate implements BaseExpression {
    private final BaseExpression expr;

    public CheckedNegate(BaseExpression expr) {
        this.expr = expr;
    }

    @Override
    public int evaluate(int x) {
        int res = expr.evaluate(x);
        if (res == Integer.MIN_VALUE) {
            throw new OverflowException("Integer overflow");
        }
        return -res;
    }

    @Override
    public int evaluate(int x, int y, int z) {
        int res = expr.evaluate(x, y, z);
        if (res == Integer.MIN_VALUE) {
            throw new OverflowException("Integer overflow");
        }
        return -res;
    }

    @Override
    public String toString() {
        return "-(" + expr.toString() + ")";
    }
}
