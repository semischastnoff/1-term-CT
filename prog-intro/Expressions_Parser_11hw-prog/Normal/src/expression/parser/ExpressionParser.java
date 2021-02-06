package expression.parser;

import expression.*;

public class ExpressionParser extends BaseParser implements Parser {
    private char operation;
    private int constant;
    private String variable;

    public ExpressionParser() {
        super(new StringSource(""));
    }

    public TripleExpression parse(String expr) {
        source = new StringSource(expr);
        return parseExpression();
    }

    private TripleExpression parseExpression() {
        if (!source.hasNext()) {
            throw error("Expression is empty");
        }
        nextChar();
        return parseOr();
    }

    private BaseExpression parseOr() {
        BaseExpression first = parseXor();
        while (true) {
            if (operation == '|') {
                BaseExpression second = parseXor();
                first = new Or(first, second);
            } else {
                return first;
            }
        }
    }

    private BaseExpression parseXor() {
        BaseExpression first = parseAnd();
        while (true) {
            if (operation == '^') {
                BaseExpression second = parseAnd();
                first = new Xor(first, second);
            } else {
                return first;
            }
        }
    }

    private BaseExpression parseAnd() {
        BaseExpression first = parseAddAndSub();
        while (true) {
            if (operation == '&') {
                BaseExpression second = parseAddAndSub();
                first = new And(first, second);
            } else {
                return first;
            }
        }
    }

    private BaseExpression parseAddAndSub() {
        BaseExpression first = parseMulAndDiv();
        while (true) {
            if (operation == '+') {
                BaseExpression second = parseMulAndDiv();
                first = new Add(first, second);
            } else if (operation == '-') {
                BaseExpression second = parseMulAndDiv();
                first = new Subtract(first, second);
            } else {
                return first;
            }
        }
    }

    private BaseExpression parseMulAndDiv() {
        BaseExpression first = parseElement();
        while (true) {
            if (operation == '*') {
                BaseExpression second = parseElement();
                first = new Multiply(first, second);
            } else if (operation == '/') {
                BaseExpression second = parseElement();
                first = new Divide(first, second);
            } else {
                return first;
            }
        }
    }

    private BaseExpression parseElement() {
        parseValue(true);
        if (operation == 'c') {
            BaseExpression expr = new Const(constant);
            parseValue(false);
            return expr;
        } else if (operation == 'v') {
            BaseExpression expr = new Variable(variable);
            parseValue(false);
            return expr;
        } else if (operation == '-') {
            BaseExpression expr = parseElement();
            return new Minus(expr);
        } else if (operation == '(') {
            BaseExpression expr = parseOr();
            parseValue(false);
            return expr;
        }
        throw error("Invalid expression");
    }

    private void parseValue(boolean minus) {
        skipWhitespace();
        if (test('-')) {
            if (minus && isNum()) {
                constant = parseConst(true);
                operation = 'c';
            } else {
                operation = '-';
            }
        } else if (test('(')) {
            operation = '(';
        } else if (test(')')) {
            operation = ')';
        } else if (test('+')) {
            operation = '+';
        } else if (test('*')) {
            operation = '*';
        } else if (test('/')) {
            operation = '/';
        } else if (test('|')) {
            operation = '|';
        } else if (test('^')) {
            operation = '^';
        } else if (test('&')) {
            operation = '&';
        } else if (Character.isLetter(ch)) {
            variable = parseVariable();
            operation = 'v';
        } else if (isNum()) {
            operation = 'c';
            constant = parseConst(false);
        }
    }

    private String parseVariable() {
        StringBuilder res = new StringBuilder();
        while (Character.isLetter(ch)) {
            res.append(ch);
            nextChar();
        }
        return res.toString();
    }

    private int parseConst(boolean minus) {
        final StringBuilder res = new StringBuilder();
        if (minus) {
            res.append('-');
        }
        while (isNum()) {
            res.append(ch);
            nextChar();
        }
        return Integer.parseInt(res.toString());
    }

    private boolean isNum() {
        return between('0', '9');
    }

    private void skipWhitespace() {
        while (Character.isWhitespace(ch)) {
            nextChar();
        }
    }
}
