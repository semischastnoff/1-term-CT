package markup;

public class Text implements Element {
    private String text;

    public Text(String s) {
        this.text = s;
    }

    @Override
    public void toMarkdown(StringBuilder sb) {
        sb.append(text);
    }

    @Override
    public void toBBCode(StringBuilder sb) {
        sb.append(text);
    }

    @Override
    public void АнтонЕбалоЧекни(StringBuilder sb) {
        sb.append(text);
    }
}