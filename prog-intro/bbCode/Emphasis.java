package bbCode;

import java.util.List;

public class Emphasis extends Node {
    public Emphasis(List<BBCode> list) {
        super(list);
    }

    @Override
    public void toHtml(StringBuilder sb) {
        super.toHtml(sb);
    }

    public String getOpenedHtml() {
        return "<em>";
    }

    public String getClosedHtml() {
        return "</em>";
    }
}