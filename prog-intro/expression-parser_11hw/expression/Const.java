package expression;

public class Const implements BaseExpression {
    private final int constant;

    public Const(int constant) {
        this.constant = constant;
    }

    @Override
    public int evaluate(int x, int y, int z) {
        return this.constant;
    }

    @Override
    public String toString() {
        return Integer.toString(this.constant);
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null || obj.getClass() != Const.class) {
            return false;
        }
        return this.toString().equals(obj.toString());
    }

    @Override
    public int hashCode() {
        return this.constant;
    }

    @Override
    public int evaluate(int x) {
        return this.constant;
    }
}
