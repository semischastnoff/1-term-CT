package markup;

public class Text implements MkDown{
    private String text;

    public Text(String s) {
        this.text = s;
    }

    @Override
    public void toMarkdown(StringBuilder sb) {
        sb.append(text);
    }
}