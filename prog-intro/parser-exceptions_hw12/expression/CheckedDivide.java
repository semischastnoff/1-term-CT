package expression;

public class CheckedDivide extends AbstractExpression {
    public CheckedDivide(BaseExpression obj1, BaseExpression obj2) {
        super(obj1, obj2, '/');
    }

    @Override
    protected int eval(int x, int y) {
        return checkDivisionByZero(x, y);
    }

    @Override
    protected int checkOverflow(int x, int y) {
        return 0;
    }

    @Override
    protected int checkDivisionByZero(int x, int y) {
        if (y == 0 || (x == Integer.MIN_VALUE && y == -1)) {
            throw new ArithmeticException("division by zero");
        }
        return x / y;
    }
}
