package game;

public class SequentialPlayer implements Player {
    private final int n, m;

    public SequentialPlayer(int n, int m) {
        this.n = n;
        this.m = m;
    }

    @Override
    public Move move(final Position position, final Cell cell) {
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                final Move move = new Move(r, c, cell);
                if (position.isValid(move)) {
                    //System.out.println("Computer's sequential move: ");
                    //System.out.println("row=" + r + " col=" + c);
                    return move;
                }
            }
        }
        throw new IllegalStateException("No valid moves");
    }
}
