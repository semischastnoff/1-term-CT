package expression;

import java.util.List;

public enum Operation {
    ADD, SUB, MUL, DIV, CONST, VAR, ABS, SQRT;

    public static final List<List<Operation>> OPERATION_FROM_PRIORITY = List.of(
            List.of(ADD, SUB),
            List.of(MUL, DIV),
            List.of(ABS, SQRT),
            List.of(CONST, VAR)
    );
}
