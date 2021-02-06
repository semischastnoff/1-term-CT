import java.io.Reader;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.InputStream;
import java.io.FileInputStream;
import java.io.StringReader;
import java.io.File;
import java.util.HashSet;
import java.util.Set;


public class Scanner {

    private Reader reader;
    private StringBuilder word = new StringBuilder();
    private boolean hasChar = false, used = true;
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

    private boolean isCorrect() throws IOException {
        hasRead();
        return Character.isLetter(sym) || !Character.isWhitespace(sym);
    }

    public boolean isEmpty() throws IOException {
        while (hasRead() && !isCorrect()) {
            hasChar = false;
        }
        return !hasRead();
    }

    public boolean hasNext() throws IOException {
        while (hasRead() && !isCorrect()) {
            hasChar = false;
        }
        return hasRead();
    }

    public String next() throws IOException {
        if (used) {
            word.setLength(0);
            while (hasRead() && !isCorrect()) {
            hasChar = false;
        }
        }
        while (used && hasRead() && isCorrect()) {
            word.append(sym);
            hasChar = false;
        }
        used = true;
        return word.toString();
    }

    public boolean hasNextLine() throws IOException {
        return hasRead();
    }

    public String nextLine() throws IOException {
        if (used) {
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