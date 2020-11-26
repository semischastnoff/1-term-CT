package expressions.expression;

public class Multiply extends AbstractExpression {
    public Multiply(BaseExpression obj1, BaseExpression obj2) {
        super(obj1, obj2, '*');
    }

    @Override
    protected int eval(int x, int y) {
        return x * y;
    }
}
