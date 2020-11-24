package expression;

public class Subtract extends AbstractExpression {
    public Subtract(Expression obj1, Expression obj2) {
        super(obj1, obj2, '-');
    }

    @Override
    protected int eval(int x, int y) {
        return x - y;
    }
}
