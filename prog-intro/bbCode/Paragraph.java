package bbCode;

import java.util.List;

public class Paragraph {
    private List<BBCode> list;

    public Paragraph(List<BBCode> list) {
        this.list = list;
    }

    public void toHtml(StringBuilder sb) {
        for (BBCode x : list) {
            x.toHtml(sb);
        }
    }
}