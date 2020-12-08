package expression;

public abstract class AbstractExpression implements BaseExpression {
    private final BaseExpression expr1, expr2;
    private final char operation;

    public AbstractExpression(BaseExpression expr1, BaseExpression expr2, char operation) {
        this.expr1 = expr1;
        this.expr2 = expr2;
        this.operation = operation;
    }

    abstract protected int eval(int x, int y) throws Exception;

    public boolean equals(Object obj) {
        if (obj == null || obj.getClass() != this.getClass()) {
            return false;
        }
        AbstractExpression newExpr = (AbstractExpression) obj;
        return this.expr1.equals(newExpr.expr1) && this.expr2.equals(newExpr.expr2);
    }

    abstract protected int checkOverflow(int x, int y) throws Exception;

    abstract protected int checkDivisionByZero(int x, int y) throws Exception;

    @Override
    public int evaluate(int x) throws Exception {
        return eval(expr1.evaluate(x), expr2.evaluate(x));
    }

    @Override
    public int evaluate(int x, int y, int z) throws Exception {
        return eval(expr1.evaluate(x, y, z), expr2.evaluate(x, y, z));
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
