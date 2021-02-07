package bbCode;

import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;

public class HTMLWriter {
    public void writeHtml(String ans) {
        Writer wr = null;
        try {
            // :NOTE: * указание кодировки
            wr = new FileWriter("output.html");
            wr.write(ans);
        } catch (IOException e) {
            System.out.println("Problems during writing: " + e.getMessage());
        } finally {
            try {
                if (wr != null) {
                    wr.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
