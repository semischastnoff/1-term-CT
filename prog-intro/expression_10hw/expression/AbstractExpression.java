package expression;

public abstract class AbstractExpression implements Expression {
    private final Expression expr1, expr2;
    private final char operation;

    public AbstractExpression(Expression expr1, Expression expr2, char operation) {
        this.expr1 = expr1;
        this.expr2 = expr2;
        this.operation = operation;
    }

    abstract protected int eval(int x, int y);

    public boolean equals(Object obj) {
        if (obj == null || obj.getClass() != this.getClass()) {
            return false;
        }
        AbstractExpression newExpr = (AbstractExpression) obj;
        return this.expr1.equals(newExpr.expr1) && this.expr2.equals(newExpr.expr2);
    }

    @Override
    public int evaluate(int x) {
        return eval(expr1.evaluate(x), expr2.evaluate(x));
    }

    @Override
    public String toString() {
        return "(" + expr1 + " " + operation + " " + expr2 + ")";
    }

    @Override
    public int hashCode() {
        return ((31 * expr1.hashCode() + expr2.hashCode()) * 31 + getClass().hashCode()) * 31;
    }
}
