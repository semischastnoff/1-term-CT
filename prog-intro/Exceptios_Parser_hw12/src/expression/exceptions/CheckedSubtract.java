package expression.exceptions;

import expression.AbstractExpression;
import expression.BaseExpression;

public class CheckedSubtract extends AbstractExpression {
    public CheckedSubtract(BaseExpression obj1, BaseExpression obj2) {
        super(obj1, obj2, "-");
    }

    @Override
    protected int eval(int x, int y) {
        int res = x - y;
        if (((x ^ y) & (x ^ res)) < 0) {
            throw new OverflowException("Integer overflow");
        }
        return res;
    }
}
