package game;

public class Game {
    private final Player player1, player2;

    public Game(final Player player1, final Player player2) {
        this.player1 = player1;
        this.player2 = player2;
    }

    public int play(Board board) {
        while (true) {
            final int result1 = move(board, player1, 1);
            if (result1 != 0) {
                return result1;
            }
            final int result2 = move(board, player2, 2);
            if (result2 != 0) {
                return result2;
            }
            return 0;
        }
    }

    private int move(final Board board, final Player player, final int no) {
        final Move move = player.move(board.getPosition(), board.getCell());
        final Result result = board.makeMove(move);
        //log("n_m_k_game.Player " + no + " move: " + move);
        //log("Current position: \n" + board);
        if (result == Result.WIN) {
            return no;
        } else if (result == Result.LOSE) {
            return 3 - no;
        } else if (result == Result.DRAW) {
            return 3;
        } else if (result == Result.UNKNOWN) {
            //log("Next turn: ");
            return 0;
        } else {
            throw new AssertionError("Impossible");
        }
    }

    private void log(final String message) {
        System.out.println(message);
    }
}
