package n_m_k_game;

public interface Board {
    Position getPosition();
    Cell getCell();
    Result makeMove(Move move);
}
