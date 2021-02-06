package markup;

import java.util.List;

public abstract class AbstractElem implements MkDown{
    private List<MkDown> list;

    protected AbstractElem(List<MkDown> list) {
        this.list = list;
    }

    @Override
    public void toMarkdown(StringBuilder sb) {
        sb.append(getMarkdown());
        for (MkDown x : list) {
            x.toMarkdown(sb);
        }
        sb.append(getMarkdown());
    }

    public abstract String getMarkdown();
}
