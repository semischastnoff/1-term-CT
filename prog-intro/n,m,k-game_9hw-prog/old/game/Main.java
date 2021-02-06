package game;

import java.util.Map;
import java.util.Scanner;


public class Main {
    private static final Map<Integer, Character> RES = Map.of(1, 'X', 2, 'O');

    public static void main(String[] args) {
        //input
        Scanner sc = new Scanner(System.in);
        int n, m, k = 0;
        System.out.println("Enter number of rows (n) and columns (m): ");
        n = sc.nextInt();
        m = sc.nextInt();
        boolean correctK = false;
        while (!correctK) {
            System.out.println("Enter number of cells in a row to win (k): ");
            k = sc.nextInt();
            if (isCorrect(n, m, k)) {
                correctK = true;
            } else {
                System.out.println("Parameter k is incorrect, try again");
            }
        }

        //game
        final Game game = new Game(new HumanPlayer(), new RandomPlayer(n, m));
        int result;
        NMKBoard board = new NMKBoard(n, m, k);
        do {
            result = game.play(board);
        } while (result == 0);

        //output result
        System.out.println("Current position: \n" + board.toString());
        if (result == 3) {
            System.out.println("Draw!");
        } else {
            System.out.println("n_m_k_game.Player " + RES.get(result) + " won!");
        }
    }

    private static boolean isCorrect(int n, int m, int k) {
        return (k <= n || k <= m);
    }
}
