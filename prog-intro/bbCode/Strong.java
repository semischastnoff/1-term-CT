package bbCode;

import java.util.List;

public class Strong extends Node {
    public Strong(List<BBCode> list) {
        super(list);
    }

    @Override
    public void toHtml(StringBuilder sb) {
        super.toHtml(sb);
    }

    public String getOpenedHtml() {
        return "<strong>";
    }

    public String getClosedHtml() {
        return "</strong>";
    }
}