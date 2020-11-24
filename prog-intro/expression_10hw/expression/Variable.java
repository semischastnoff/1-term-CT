package expression;

public class Variable implements Expression{
    private final String name;

    public Variable(String variable) {
        this.name = variable;
    }

    @Override
    public int evaluate(int x) {
        return x;
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
