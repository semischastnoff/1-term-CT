package n_m_k_game;

public interface Position {
    boolean isValid(Move move);

    Cell getCell(int r, int c);
}
