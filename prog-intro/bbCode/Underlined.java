package bbCode;

import java.util.List;

public class Underlined extends Node {

    protected Underlined(List<BBCode> list) {
        super(list);
    }

    @Override
    public String getOpenedHtml() {
        return "<ins>";
    }

    @Override
    public String getClosedHtml() {
        return "</ins>";
    }
}
