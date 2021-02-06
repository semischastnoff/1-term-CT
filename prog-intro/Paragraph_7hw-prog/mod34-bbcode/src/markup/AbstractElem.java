package markup;

import java.util.List;

public abstract class AbstractElem implements Element {
    private List<Element> list;
    private String getMarkdown;
    private String getBB;

    protected AbstractElem(List<Element> list, String getMarkDown, String getBB) {
        this.list = list;
        this.getMarkdown = getMarkDown;
        this.getBB = getBB;
    }

    @Override
    public void toMarkdown(StringBuilder sb) {
        sb.append(getMarkdown);
        for (Element x : list) {
            x.toMarkdown(sb);
        }
        sb.append(getMarkdown);
    }

    @Override
    public void toBBCode(StringBuilder sb) {
        sb.append("[").append(getBB).append("]");
        for (Element x : list) {
            x.toBBCode(sb);
        }
        sb.append("[").append("/").append(getBB).append("]");
    }
}
