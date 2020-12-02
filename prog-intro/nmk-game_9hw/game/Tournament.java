package game;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class Tournament {
    private final int[] ans;
    private int numberOfGames;
    private final int numberOfPlayers;
    private int lap;
    private final int n, m, k;
    private final List<Player> players;

    public Tournament(int numberOfPlayers, List<Player> players, int n, int m, int k) {
        this.n = n;
        this.m = m;
        this.k = k;
        this.numberOfPlayers = numberOfPlayers;
        this.players = players;
        ans = new int[numberOfPlayers];
    }

    public void tournament(int lap) {
        this.lap = lap;
        this.numberOfGames = 0;
        for (int i = 0; i < numberOfPlayers; i++) {
            for (int j = i; j < numberOfPlayers; j++) {
                if (i != j) {
                    numberOfGames++;
                    play(i, j);
                }
            }
        }
    }

    private void play(int num1, int num2) {
        //game
        System.out.println("Game number: " + lap + "." + numberOfGames);
        System.out.println("Between players " + (num1 + 1) + " and " + (num2 + 1));
        int result;
        NMKBoard board = new NMKBoard(n, m, k);
        final Game game = new Game(players.get(num1), players.get(num2));
        do {
            result = game.play(board);
        } while (result == 0);

        //output result of the game
        System.out.println("Current position: \n" + board.toString());
        if (result == 3) {
            System.out.println("Draw!");
            ans[num1]++;
            ans[num2]++;
        } else if (result == 1) {
            System.out.println("Player number " + (num1 + 1) + " won!");
            ans[num1] += 3;
        } else {
            System.out.println("Player number " + (num2 + 1) + " won!");
            ans[num2] += 3;
        }
    }

    public void printRes() {
        System.out.println("Here are the results of the tournament: ");
        for (int i = 0; i < numberOfPlayers; i++) {
            int num = i + 1;
            System.out.println("Player " + num + ": " + ans[i]);
        }
    }
}
