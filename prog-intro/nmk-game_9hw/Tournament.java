package game;

import java.util.Scanner;

public class Tournament extends Main{
    private int numberOfGames;
    private Player player1, player2;
    private int n, m, k;
    private int lap;

    public Tournament(String typeOfPlayers, int n, int m, int k) {
        this.n = n;
        this.m = m;
        this.k = k;
        switch (typeOfPlayers) {
            case "Human" -> {
                this.player1 = new HumanPlayer();
                this.player2 = new HumanPlayer();
            }
            case "Random" -> {
                this.player1 = new RandomPlayer(n, m);
                this.player2 = new RandomPlayer(n, m);
            }
            case "Sequential" -> {
                this.player1 = new SequentialPlayer(n, m);
                this.player2 = new SequentialPlayer(n, m);
            }
        }
    }

    public void tournament(int lap) {
        this.lap = lap;
        for (int i = 0; i < numberOfPlayers; i++) {
            for (int j = i; j < numberOfPlayers; j++) {
                if (i != j) {
                    numberOfGames++;
                    play(i + 1, j + 1);
                }
            }
        }
    }

    private void play(int num1, int num2) {
        //game
        final Game game = new Game(this.player1, this.player2);
        int result;
        NMKBoard board = new NMKBoard(n, m, k);
        do {
            result = game.play(board);
        } while (result == 0);

        //output result
        System.out.println("Game number: " + lap + "." + numberOfGames);
        System.out.println("Between players " + num1 + " and " + num2);
        System.out.println("Current position: \n" + board.toString());
        if (result == 3) {
            System.out.println("Draw!");
            ans[num1 - 1]++;
            ans[num2 - 1]++;
        } else {
            if (result == 1) {
                System.out.println("Player number " + num1 + " won!");
                ans[num1 - 1] += 3;
            } else {
                System.out.println("Player number " + num2 + " won!");
                ans[num2 - 1] += 3;
            }
        }
    }
}
