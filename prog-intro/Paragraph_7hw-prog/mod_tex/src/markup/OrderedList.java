package markup;

import java.util.List;

public class OrderedList extends AbstractElem {
    public OrderedList(List<Element> list) {
        super(list, null, null, "\\begin{enumerate}", "\\end{enumerate}");
    }
}
