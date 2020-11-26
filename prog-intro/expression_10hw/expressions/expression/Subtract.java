package expressions.expression;

public class Subtract extends AbstractExpression {
    public Subtract(BaseExpression obj1, BaseExpression obj2) {
        super(obj1, obj2, '-');
    }

    @Override
    protected int eval(int x, int y) {
        return x - y;
    }
}
