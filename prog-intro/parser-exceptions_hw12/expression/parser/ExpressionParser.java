package expression.parser;

import expression.*;

public class ExpressionParser extends BaseParser implements Parser {
    private char operation;
    private int constant;
    private String variable;
    private int balance;

    public ExpressionParser() {
        super(new StringSource(""));
    }

    public TripleExpression parse(String expr) {
        source = new StringSource(expr);
        TripleExpression res = parseExpression();
        if (eof()) {
            return res;
        }
        throw error("End of file expected");
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
                first = new CheckedAdd(first, second);
            } else if (operation == '-') {
                BaseExpression second = parseMulAndDiv();
                first = new CheckedSubtract(first, second);
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
                first = new CheckedMultiply(first, second);
            } else if (operation == '/') {
                BaseExpression second = parseElement();
                first = new CheckedDivide(first, second);
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
            if (eof()) {
                throw error("Invalid expression: constant, variable or '(' expected. Found: End of file");
            }
            BaseExpression expr = parseElement();
            return new CheckedNegate(expr);
        } else if (operation == '(') {
            BaseExpression expr = parseOr();
            if (operation != ')') {
                throw error("Invalid expression: ')' expected");
            }
            parseValue(false);
            return expr;
        }
        throw error("Invalid expression: constant, variable or '(' expected");
    }

    private void parseValue(boolean minus) {
        skipWhitespace();
        if (test('-')) {
            if (minus && between('0', '9')) {
                constant = parseNegativeConst();
                operation = 'c';
            } else {
                operation = '-';
            }
        } else if (test('(')) {
            operation = '(';
            balance++;
        } else if (test(')')) {
            operation = ')';
            balance--;
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
        } else if (between('a', 'z')) {
            operation = 'v';
            variable = parseVariable();
        } else if (between('0', '9')) {
            operation = 'c';
            constant = parseConst();
        }
    }

    private String parseVariable() {
        StringBuilder res = new StringBuilder();
        while (between('a', 'z')) {
            res.append(ch);
            nextChar();
        }
        String ans = res.toString();
        if (ans.equals("x") || ans.equals("y") || ans.equals("z")) {
            return ans;
        }
        throw error("Unsupported variable name: x, y or z expected");
    }

    private int parseConst() {
        String res = parseDigits();
        return Integer.parseInt(res);
    }

    private int parseNegativeConst() {
        String res = parseDigits();
        return Integer.parseInt("-" + res);
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
