package game;

import java.util.Random;

public class RandomPlayer implements Player {
    private final Random random = new Random();

    private int n, m;

    public RandomPlayer(int n, int m) {
        this.n = n;
        this.m = m;
    }

    @Override
    public Move move(final Position position, final Cell cell) {
        while (true) {
            int r = random.nextInt(n);
            int c = random.nextInt(m);
            System.out.println("Computer's random move: ");
            System.out.println("row=" + r + " col=" + c);
            final Move move = new Move(r, c, cell);
            if (position.isValid(move)) {
                return move;
            }
        }
    }
}
