package markup;

public interface Element {
    void toMarkdown(StringBuilder sb);

    void toBBCode(StringBuilder sb);
}
