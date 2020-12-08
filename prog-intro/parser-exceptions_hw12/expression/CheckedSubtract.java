package expression;

public class CheckedSubtract extends AbstractExpression {
    public CheckedSubtract(BaseExpression obj1, BaseExpression obj2) {
        super(obj1, obj2, '-');
    }

    @Override
    protected int eval(int x, int y) throws Exception {
        return checkOverflow(x, y);
    }

    @Override
    protected int checkOverflow(int x, int y) throws Exception {
        int res = x - y;
        if (((x ^ y) & (x ^ res)) < 0) {
            throw new ArithmeticException("overflow");
        }
        return res;
    }

    @Override
    protected int checkDivisionByZero(int x, int y) throws Exception {
        return 0;
    }
}
