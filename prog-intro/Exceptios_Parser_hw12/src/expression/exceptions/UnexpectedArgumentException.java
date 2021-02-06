package expression.exceptions;

public class UnexpectedArgumentException extends ParseException {
    public UnexpectedArgumentException(String message, int position) {
        super(message, position);
    }
}
