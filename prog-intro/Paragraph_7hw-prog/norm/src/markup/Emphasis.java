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

    public String getMarkdown() {
        return "*";
    }
}