package markup;

import java.util.List;

public class Emphasis extends AbstractElem {
    public Emphasis(List<MkDown> list) {
        super(list);
    }

    @Override
    public void toMarkdown(StringBuilder sb) {
        super.toMarkdown(sb);
    }

    @Override
    public void toHtml(StringBuilder sb) {
        super.toHtml(sb);
    }

    public String getMarkdown() {
        return "*";
    }

    public String getOpenedHtml() {
        return "<em>";
    }

    public String getClosedHtml() {
        return "</em>";
    }
}