package bbCode;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        BufferedReader rd = null;
        // :NOTE: * утечка ресурсов при ошибках
        try {

            rd = new BufferedReader(new FileReader("input.txt"));
        } catch (FileNotFoundException e) {
            System.out.println("Problems during opening: " + e.getMessage());
        }
        String input = null;
        try {
            if (rd != null) {
                input = rd.readLine();
            }
        } catch (IOException e) {
            System.out.println("Problems during reading: " + e.getMessage());
        }
        BBCodeParser parser = new BBCodeParser();
        //System.out.println(input);
        List<List<BBCode>> expr = parser.parse(input);
        StringBuilder ans = new StringBuilder();
        HTMLWriter wr = new HTMLWriter();
        for (List<BBCode> l : expr) {
            Paragraph paragraph = new Paragraph(l);
            paragraph.toHtml(ans);
            wr.writeHtml(ans.toString());
        }
    }
}
