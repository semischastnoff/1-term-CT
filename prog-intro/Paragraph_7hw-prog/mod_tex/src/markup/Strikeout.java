package markup;


import java.util.List;

public class Strikeout extends AbstractElem {
    public Strikeout(List<Element> list) {
        super(list, "~", "s", "\\textst{", "}");
    }
}