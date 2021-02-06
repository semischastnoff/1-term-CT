package markup;

import java.util.List;

public class ListItem extends AbstractElem {
    public ListItem(List<Element> list) {
        super(list, null, null, "\\item ", "");
    }
}
