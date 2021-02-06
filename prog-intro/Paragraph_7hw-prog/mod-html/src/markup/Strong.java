package markup;

import java.util.List;

public class Strong extends AbstractElem{
    public Strong(List<MkDown> list) {
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
        return "__";
    }

    public String getOpenedHtml() {
        return "<strong>";
    }

    public String getClosedHtml() {
        return "</strong>";
    }
}