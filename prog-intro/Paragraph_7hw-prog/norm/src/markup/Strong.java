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

    public String getMarkdown() {
        return "__";
    }
}