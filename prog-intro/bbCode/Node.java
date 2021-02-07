package bbCode;

import java.util.List;

public abstract class Node implements BBCode {
    private List<BBCode> list;

    protected Node(List<BBCode> list) {
        this.list = list;
    }

    @Override
    public void toHtml(StringBuilder sb) {
        sb.append(getOpenedHtml());
        for (BBCode x : list) {
            x.toHtml(sb);
        }
        sb.append(getClosedHtml());
    }

    public abstract String getOpenedHtml();

    public abstract String getClosedHtml();
}
