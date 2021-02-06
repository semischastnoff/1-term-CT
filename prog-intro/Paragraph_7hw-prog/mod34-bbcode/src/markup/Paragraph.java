package markup;

import java.util.List;

public class Paragraph implements Element {
    private List<Element> list;

    public Paragraph(List<Element> list) {
        this.list = list;
    }

    public void toMarkdown(StringBuilder sb) {
        for (Element x : list) {
            x.toMarkdown(sb);
        }
    }

    public void toBBCode(StringBuilder sb) {
        for (Element x : list) {
            x.toBBCode(sb);
        }
    }
}