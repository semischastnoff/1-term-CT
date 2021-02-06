import java.io.Reader;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.InputStream;
import java.io.FileInputStream;
import java.io.StringReader;
import java.io.File;
//Custom Scanner

public class Scanner {

    private Reader reader;
    private StringBuilder word = new StringBuilder();
    private boolean hasChar = false, useWord = true;
    private char sym;

    public Scanner(String file, String decoder) throws IOException {
        reader = new BufferedReader(new InputStreamReader(new FileInputStream(new File(file)), decoder));
    }

    public Scanner(InputStream in) throws IOException {
        reader = new BufferedReader(new InputStreamReader(in));
    }

    public Scanner(String s) {
        reader = new StringReader(s);
    }

    public void close() throws IOException {
        reader.close();
    }

    private boolean hasRead() throws IOException {
        if (!hasChar) {
            int ch = reader.read();
            if (ch == -1) {
                sym = 0;
                return false;
            }
            sym = (char) ch;
            hasChar = true;
        }
        return true;
    }

    private boolean isNotSpace() throws IOException {
        hasRead();
        return Character.DASH_PUNCTUATION == Character.getType(sym) ||
                Character.isLetter(sym) ||
                sym == '\'';
    }

    public boolean isEmpty() throws IOException {
        skipWhitespace();
        return !hasRead();
    }

    public boolean hasNextLine() throws IOException {
        return hasRead();
    }

    private void skipWhitespace() throws IOException {
        while (hasRead() && !isNotSpace()) {
            hasChar = false;
        }
    }

    public boolean hasNext() throws IOException {
        skipWhitespace();
        return hasRead();
    }

    public String next() throws IOException {
        if (useWord) {
            word.setLength(0);
            skipWhitespace();
        }
        while (useWord && hasRead() && isNotSpace()) {
            word.append(sym);
            hasChar = false;
        }
        useWord = true;
        return word.toString();
    }

    public boolean hasNextInt() throws IOException {
        String num = next();
        useWord = false;
        if (num.isEmpty()) {
            return false;
        }
        try {
            Integer.parseInt(num);
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public String nextLine() throws IOException {
        if (useWord) {
            word.setLength(0);
        }
        while (hasRead() && sym != '\n') {
            word.append(sym);
            hasChar = false;
        }
        hasChar = false;
        hasRead();
        return word.toString();
    }
}