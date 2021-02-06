package expression;

public class Minus implements BaseExpression {
    private final BaseExpression expr;

    public Minus(BaseExpression expr) {
        this.expr = expr;
    }

    @Override
    public int evaluate(int x) {
        return -expr.evaluate(x);
    }

    @Override
    public int evaluate(int x, int y, int z) {
        return -expr.evaluate(x, y, z);
    }

    @Override
    public String toString() {
        return "-(" + expr.toString() + ")";
    }
}
