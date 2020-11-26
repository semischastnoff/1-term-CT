package expressions.expression;

public class Divide extends AbstractExpression {
    public Divide(BaseExpression obj1, BaseExpression obj2) {
        super(obj1, obj2, '/');
    }

    @Override
    protected int eval(int x, int y) {
        return x / y;
    }
}
