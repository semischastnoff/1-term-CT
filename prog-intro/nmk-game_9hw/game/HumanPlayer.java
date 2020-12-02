package game;

import java.io.PrintStream;
import java.util.Scanner;


public class HumanPlayer implements Player {
    private final PrintStream out;
    private final CReader rd = new CReader();

    public HumanPlayer(final PrintStream out) {
        this.out = out;
    }

    public HumanPlayer() {
        this(System.out);
    }

    @Override
    public Move move(final Position position, final Cell cell) {
        while (true) {
            out.println("Current position: ");
            out.println(position);
            out.println(cell + "'s move");
            out.println("Enter row");
            int r = rd.readInt("move");
            out.println("Enter column");
            int c = rd.readInt("move");
            final Move move = new Move(r, c, cell);
            if (position.isValid(move)) {
                return move;
            }
        }
    }
}
