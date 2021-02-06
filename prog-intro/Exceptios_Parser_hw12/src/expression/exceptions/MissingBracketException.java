package expression.exceptions;

public class MissingBracketException extends ParseException {
    public MissingBracketException(String message, int position) {
        super(message, position);
    }
}
