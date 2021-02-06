package expression.exceptions;

import expression.*;
import expression.parser.BaseParser;
import expression.parser.StringSource;

public class ExpressionParser extends BaseParser implements Parser {

    public ExpressionParser() {
        super(new StringSource(""));
    }

    public TripleExpression parse(String expr) {
        source = new StringSource(expr);
        nextChar();
        BaseExpression res = parseExpression();
        if (source.hasNext() && ch != '\0') {
            throw new MissingBracketException("'(' excpected: ", source.getPos());
        }
        return res;
    }

    private BaseExpression parseExpression() {
        skipWhitespace();
        return parseTerm(0);
    }

    private BaseExpression parseTerm(int priority) {
        skipWhitespace();
        if (priority == 3) {
            return parseElement();
        }
        BaseExpression first = parseTerm(priority + 1);
        while (true) {
            Operation operation = getBinaryOperation(priority);
            if (operation == null) {
                return first;
            }
            first = buildBinaryExpression(first, parseTerm(priority + 1), operation);
        }
    }

    private BaseExpression buildBinaryExpression(BaseExpression first, BaseExpression second, Operation operation) {
        return switch (operation) {
            case ADD -> new CheckedAdd(first, second);
            case SUB -> new CheckedSubtract(first, second);
            case MUL -> new CheckedMultiply(first, second);
            case DIV -> new CheckedDivide(first, second);
            default -> null;
        };
    }

    private BaseExpression buildUnaryExpression(BaseExpression expr, Operation operation) {
        return switch (operation) {
            case ABS -> new CheckedAbs(expr);
            case SQRT -> new CheckedSqrt(expr);
            default -> null;
        };
    }

    private Operation getBinaryOperation(int priority) {
        skipWhitespace();
        for (Operation elem : Operation.OPERATION_FROM_PRIORITY.get(priority)) {
            char operation = switch (elem) {
                case ADD -> '+';
                case SUB -> '-';
                case DIV -> '/';
                case MUL -> '*';
                default -> '0';
            };
            if (test(operation)) {
                return elem;
            }
        }
        return null;
    }

    private BaseExpression parseElement() {
        skipWhitespace();
        if (test('(')) {
            BaseExpression expr = parseExpression();
            skipWhitespace();
            if (ch != ')') {
                throw new MissingBracketException("')' expected: ", source.getPos());
            }
            nextChar();
            return expr;
        } else if (test('-')) {
            if (between('0', '9')) {
                return parseNegativeConst();
            }
            return new CheckedNegate(parseElement());
        } else if (between('0', '9')) {
            return parseConst();
        } else {
            String token = parseToken();
            Operation operation = switch (token) {
                case "abs" -> Operation.ABS;
                case "sqrt" -> Operation.SQRT;
                default -> null;
            };
            if (operation != null) {
                BaseExpression expr = parseElement();
                return buildUnaryExpression(expr, operation);
            }
            return parseVariable(token);
        }
    }

    private String parseToken() {
        StringBuilder sb = new StringBuilder();
        while (between('a', 'z')) {
            sb.append(ch);
            nextChar();
        }
        return sb.toString();
    }

    private BaseExpression parseVariable(String token) {
        if (token.equals("x") || token.equals("y") || token.equals("z")) {
            return new Variable(token);
        }
        throw new UnexpectedArgumentException("Unsupported variable name; 'x', 'y' or 'z' expected: ", source.getPos());
    }

    private BaseExpression parseConst() {
        String res = parseDigits();
        try {
            return new Const(Integer.parseInt(res));
        } catch (NumberFormatException e) {
            throw new UnexpectedArgumentException("Argument should be number: ", source.getPos());
        }
    }

    private BaseExpression parseNegativeConst() {
        String res = parseDigits();
        try {
            return new CheckedNegate(new Const(Integer.parseInt("-" + res)));
        } catch (NumberFormatException e) {
            throw new UnexpectedArgumentException("Argument should be number: ", source.getPos());
        }
    }

    private String parseDigits() {
        final StringBuilder res = new StringBuilder();
        while (between('0', '9')) {
            res.append(ch);
            nextChar();
        }
        return res.toString();
    }

    private void skipWhitespace() {
        while (test(' ') || test('\n') || test('\r') || test('\t')) {
        }
    }
}
