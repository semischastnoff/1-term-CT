package bbCode;

public class Text implements BBCode {
    private String text;

    public Text(String s) {
        this.text = s;
    }

    @Override
    public void toHtml(StringBuilder sb) {
        sb.append(text);
    }
}