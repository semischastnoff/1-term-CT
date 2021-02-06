package markup;

import java.util.List;

public class Emphasis extends AbstractElem {
    public Emphasis(List<Element> list) {
        super(list, "*", "i");
    }
}