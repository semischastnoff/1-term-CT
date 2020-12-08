package expression;

public class CheckedMultiply extends AbstractExpression {
    public CheckedMultiply(BaseExpression obj1, BaseExpression obj2) {
        super(obj1, obj2, '*');
    }

    @Override
    protected int eval(int x, int y) throws Exception {
        return checkOverflow(x, y);
    }

    @Override
    protected int checkOverflow(int x, int y) throws Exception {
        int res = x * y;
        if ((y != 0 && res / y != x) || (x == Integer.MIN_VALUE && y == -1)) {
            throw new ArithmeticException("overflow");
        }
        return res;
    }

    @Override
    protected int checkDivisionByZero(int x, int y) throws Exception {
        return 0;
    }
}
