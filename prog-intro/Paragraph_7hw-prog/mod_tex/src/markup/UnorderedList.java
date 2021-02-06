package markup;

import java.util.List;

public class UnorderedList extends AbstractElem {
    public UnorderedList(List<Element> list) {
        super(list, null, null, "\\begin{itemize}", "\\end{itemize}");
    }
}
