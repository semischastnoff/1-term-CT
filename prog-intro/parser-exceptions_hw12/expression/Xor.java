package expression;

public class Xor extends AbstractExpression {

    public Xor(BaseExpression expr1, BaseExpression expr2) {
        super(expr1, expr2, '^');
    }

    @Override
    protected int eval(int x, int y) {
        return x ^ y;
    }

    @Override
    protected int checkOverflow(int x, int y) throws Exception {
        return 0;
    }

    @Override
    protected int checkDivisionByZero(int x, int y) throws Exception {
        return 0;
    }
}
