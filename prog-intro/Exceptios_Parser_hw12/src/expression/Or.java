package expression;

public class Or extends AbstractExpression {

    public Or(BaseExpression expr1, BaseExpression expr2) {
        super(expr1, expr2, "|");
    }

    @Override
    protected int eval(int x, int y) {
        return x | y;
    }
}
