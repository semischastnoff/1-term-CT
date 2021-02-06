package expression.exceptions;

import expression.AbstractExpression;
import expression.BaseExpression;

public class CheckedMultiply extends AbstractExpression {
    public CheckedMultiply(BaseExpression obj1, BaseExpression obj2) {
        super(obj1, obj2, "*");
    }

    @Override
    protected int eval(int x, int y) {
        int res = x * y;
        if ((y != 0 && res / y != x) || (x == Integer.MIN_VALUE && y == -1)) {
            throw new OverflowException("Integer overflow");
        }
        return res;
    }
}
