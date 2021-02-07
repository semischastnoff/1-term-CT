package bbCode;

import java.util.List;

public class BBList extends Node {
    protected BBList(List<BBCode> list) {
        super(list);
    }

    @Override
    public String getOpenedHtml() {
        return "<li>";
    }

    @Override
    public String getClosedHtml() {
        return "</li>";
    }
}
