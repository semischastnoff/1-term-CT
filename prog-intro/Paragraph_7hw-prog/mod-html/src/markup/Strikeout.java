package markup;


import java.util.List;

public class Strikeout extends AbstractElem {
    public Strikeout(List<MkDown> list) {
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
        return "~";
    }

    public String getOpenedHtml() {
        return "<s>";
    }

    public String getClosedHtml() {
        return "</s>";
    }
}