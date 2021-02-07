package bbCode;


import java.util.List;

public class Strikeout extends Node {
    public Strikeout(List<BBCode> list) {
        super(list);
    }

    @Override
    public void toHtml(StringBuilder sb) {
        super.toHtml(sb);
    }

    public String getOpenedHtml() {
        return "<del>";
    }

    public String getClosedHtml() {
        return "</del>";
    }
}