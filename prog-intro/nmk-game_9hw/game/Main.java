package game;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class Main {
    protected static int n, m, k;
    private static final List<Player> players = new ArrayList<>();

    public static void main(String[] args) {
        //input
        CReader rd = new CReader();
        System.out.println("Enter number of laps");
        int c = rd.readInt("nothing");
        System.out.println("Enter number of players");
        int numberOfPlayers = rd.readInt("nothing");
        System.out.println("Enter number of rows (n)");
        n = rd.readInt("nothing");
        System.out.println("Enter number of columns (m)");
        m = rd.readInt("nothing");
        System.out.println("Enter number of cells in a row to win (k)");
        k = rd.readInt("K");
        Map<String, Player> PLAYER = Map.of("Human", new HumanPlayer(),
                "Random", new RandomPlayer(),
                "Sequential", new SequentialPlayer());
        for (int i = 0; i < numberOfPlayers; i++) {
            int num = i + 1;
            System.out.println("Enter " + num + " player's type");
            String typeOfPlayer = rd.readPlayer();
            players.add(PLAYER.get(typeOfPlayer));
        }

        //creating tournament
        Tournament tour = new Tournament(numberOfPlayers, players, n, m, k);
        for (int i = 0; i < c; i++) {
            tour.tournament(i + 1);
        }

        //results of the tournament
        tour.printRes();
    }
}
