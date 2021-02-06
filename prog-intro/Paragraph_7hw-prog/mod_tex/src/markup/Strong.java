package markup;

import java.util.List;

public class Strong extends AbstractElem{
    public Strong(List<Element> list) {
        super(list, "__", "b", "\\textbf{", "}");
    }
}