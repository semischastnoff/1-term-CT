package expression.exceptions;

import expression.BaseExpression;

public class CheckedAbs implements BaseExpression {
    private final BaseExpression expr;

    public CheckedAbs(BaseExpression expr) {
        this.expr = expr;
    }

    @Override
    public int evaluate(int x, int y, int z) {
        int res = expr.evaluate(x, y, z);
        return (res < 0) ? -res: res;
    }

    @Override
    public int evaluate(int x) {
        int res = expr.evaluate(x);
        return (res < 0) ? -res : res;
    }
}
