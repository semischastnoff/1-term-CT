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

    public String getMarkdown() {
        return "~";
    }
}