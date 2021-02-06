package expression.parser;

import expression.exceptions.ParseException;
import expression.exceptions.UnexpectedArgumentException;

/**
 * @author Georgiy Korneev (kgeorgiy@kgeorgiy.info)
 */
public class BaseParser {
    public static final char EOF = '\0';
    protected CharSource source;
    protected char ch = 0xffff;

    protected BaseParser(final CharSource source) {
        this.source = source;
    }

    protected void nextChar() {
        ch = source.hasNext() ? source.next() : EOF;
    }

    protected boolean test(char expected) {
        if (ch == expected) {
            nextChar();
            return true;
        }
        return false;
    }

    protected void expect(final char c) {
        if (ch != c) {
            throw new ParseException("Expected '" + c + "', found '" + ch + "'", source.getPos());
        }
        nextChar();
    }

    protected void expect(final String value) {
        for (char c : value.toCharArray()) {
            expect(c);
        }
    }

    protected boolean eof() {
        return test(EOF);
    }

    protected boolean between(final char from, final char to) {
        return from <= ch && ch <= to;
    }
}
