package bbCode;

import java.util.List;

public interface Parser {
    List<List<BBCode>> parse(String expression);
}
