package expression;

public class And extends AbstractExpression {

    public And(BaseExpression expr1, BaseExpression expr2) {
        super(expr1, expr2, '&');
    }

    @Override
    protected int eval(int x, int y) {
        return x & y;
    }
}
