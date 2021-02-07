package bbCode;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

// :NOTE: *2 обработка ошибок при парсинге

public class BBCodeParser extends BaseParser implements Parser {

    private final Map<String, Character> c = Map.of("b", 'b', "i", 'i', "s", 's', "u", 'u', "list", 'l');

    public BBCodeParser() {
        super(new StringSource(""));
    }

    public List<List<BBCode>> parse(String expr) {
        source = new StringSource(expr);
        return parseExpression();
    }

    private List<List<BBCode>> parseExpression() {
        if (!source.hasNext()) {
            System.out.println("Expression is empty");
            System.exit(1);
        }
        nextChar();
        return parseElement(EOF);
    }

    private List<List<BBCode>> parseElement(char lastTag) {
        skipWhitespace();
        List<List<BBCode>> list = new ArrayList<>();
        while (ch != EOF) {
            if (test('[')) {
                String tag = parseTag();
                if (tag.charAt(0) == '/') {
                    List<BBCode> t = new ArrayList<>();
                    if (lastTag == 'b') {
                        for (List<BBCode> l : list) {
                            t.add(l.get(l.size() - 1));
                        }
                        return List.of(List.of(new Strong(t)));
                    } else if (lastTag == 'i') {
                        for (List<BBCode> l : list) {
                            t.add(l.get(l.size() - 1));
                        }
                        return List.of(List.of(new Emphasis(t)));
                    } else if (lastTag == 's') {
                        for (List<BBCode> l : list) {
                            t.add(l.get(l.size() - 1));
                        }
                        return List.of(List.of(new Strikeout(t)));
                    } else if (lastTag == 'u') {
                        for (List<BBCode> l : list) {
                            t.add(l.get(l.size() - 1));
                        }
                        return List.of(List.of(new Underlined(t)));
                    } else if (lastTag == 'l') {
                        for (List<BBCode> l : list) {
                            t.add(new BBList(l));
                        }
                    }
                    return List.of(t);
                }
                list.addAll(parseElement(c.get(tag)));
            } else {
                String text = parseText();
                list.add(List.of(new Text(text)));
            }
        }
        return list;
    }

    private String parseTag() {
        StringBuilder sb = new StringBuilder();
        while (ch != ']') {
            sb.append(ch);
            nextChar();
        }
        nextChar();
        return sb.toString();
    }

    private String parseText() {
        StringBuilder res = new StringBuilder();
        while (ch != '[') {
            res.append(ch);
            nextChar();
        }
        return res.toString();
    }

    private void skipWhitespace() {
        while (Character.isWhitespace(ch)) {
            nextChar();
        }
    }
}
