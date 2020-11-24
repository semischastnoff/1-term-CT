package game;

public class Tournament extends Main{
    private int numberOfGames;
    private int lap;

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
        System.out.println("Game number: " + lap + "." + numberOfGames);
        System.out.println("Between players " + num1 + " and " + num2);
        final Game game = new Game(players.get(num1), players.get(num2));
        int result;
        NMKBoard board = new NMKBoard(n, m, k);
        do {
            result = game.play(board);
        } while (result == 0);

        //output result of the game
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

    public void printRes() {
        System.out.println("Here are the results of the tournament: ");
        for (int i = 0; i < numberOfPlayers; i++) {
            int num = i + 1;
            System.out.println("Player " + num + ": " + ans[i]);
        }
    }
}
