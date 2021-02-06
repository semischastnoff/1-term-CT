package markup;

import java.util.List;

public class Paragraph {
    private List<MkDown> list;

    public Paragraph(List<MkDown> list) {
        this.list = list;
    }

    public void toMarkdown(StringBuilder sb) {
        for (MkDown x : list) {
            x.toMarkdown(sb);
        }
    }
}