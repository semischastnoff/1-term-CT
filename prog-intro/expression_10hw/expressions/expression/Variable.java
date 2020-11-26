package expressions.expression;

public class Variable implements BaseExpression {
    private final String name;

    public Variable(String variable) {
        this.name = variable;
    }

    @Override
    public int evaluate(int x) {
        return x;
    }

    @Override
    public int evaluate(int x, int y, int z) {
        if (name.equals("x")) {
            return x;
        } else if (name.equals("y")) {
            return y;
        } else {
            return z;
        }
    }

    @Override
    public String toString() {
        return this.name;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null || obj.getClass() != Variable.class) {
            return false;
        }
        return name.equals(obj.toString());
    }

    @Override
    public int hashCode() {
        return name.hashCode();
    }
}
