package game;

import java.util.HashMap;
import java.util.Map;

public class Main {
    protected static int[] ans;
    protected static int numberOfPlayers;
    protected static int n, m, k;
    protected static Map<Integer, Player> players = new HashMap<>();
    protected static Map<String, Player> PLAYER;

    public static void main(String[] args) {
        //input
        CReader rd = new CReader();
        System.out.println("Enter number of laps");
        int c = rd.readInt(false);
        System.out.println("Enter number of players");
        numberOfPlayers = rd.readInt(false);
        ans = new int[numberOfPlayers];
        System.out.println("Enter number of rows (n)");
        n = rd.readInt(false);
        System.out.println("Enter number of columns (m)");
        m = rd.readInt(false);
        System.out.println("Enter number of cells in a row to win (k)");
        k = rd.readInt(true);
        PLAYER = Map.of("Human", new HumanPlayer(),
                "Random", new RandomPlayer(n, m),
                "Sequential", new SequentialPlayer(n, m));
        for (int i = 0; i < numberOfPlayers; i++) {
            int num = i + 1;
            System.out.println("Enter " + num + " player's type");
            String typeOfPlayer = rd.readPlayer();
            players.put(i + 1, PLAYER.get(typeOfPlayer));
        }

        //creating tournament
        Tournament tour = null;
        for (int i = 0; i < c; i++) {
            tour = new Tournament();
            tour.tournament(i + 1);
        }

        //results of the tournament
        if (tour != null) {
            tour.printRes();
        } else {
            throw new NullPointerException("Something went wrong during the game");
        }
    }
}
