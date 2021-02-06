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
    private boolean hasChar = false, used = true;
    private char sym;

    public Scanner(String file, String uncoding) throws IOException {
        reader = new BufferedReader(new InputStreamReader(new FileInputStream(file), uncoding));
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
        return Character.DASH_PUNCTUATION == Character.getType(sym) ||
                Character.isLetter(sym) ||
                sym == '\'';
    }

    public boolean isEmpty() throws IOException {
    	//пропускаю пробельные символы
        while (hasRead() && !isCorrect()) {
            hasChar = false;
        }
        return !hasRead();
    }

    public boolean hasNextLine() throws IOException {
        return hasRead();
    }

    public boolean hasNext() throws IOException {
    	//пропускаю пробельные символы
        while (hasRead() && !isCorrect()) {
            hasChar = false;
        }
        return hasRead();
    }

    public String next() throws IOException {
        if (used) {
            word.setLength(0);
            //пропускаю пробельные символы
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

    public boolean hasNextInt() throws IOException {
        String num = next();
        used = false;
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
        if (used) {
            word.setLength(0);
        }
        while (hasRead() && !Character.toString(sym).equals(System.lineSeparator())) {
            word.append(sym);
            hasChar = false;
        }
        hasChar = false;
        hasRead();
        return word.toString();
    }
}