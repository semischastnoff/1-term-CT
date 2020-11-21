package game;

import java.util.Scanner;

public class Main {
    protected static int[] ans;
    protected static int numberOfPlayers;
    protected static int n, m, k;

    public static void main(String[] args) {
        //input
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of laps");
        int c = sc.nextInt();
        System.out.println("Enter number of players");
        numberOfPlayers = sc.nextInt();
        ans = new int[numberOfPlayers];
        System.out.println("Enter type of players ('Random', 'Human' or 'Sequential')");
        String type = sc.next();
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

        //creating tournament
        for (int i = 0; i < c; i++) {
            Tournament tour = new Tournament(type, n, m, k);
            tour.tournament(i + 1);
        }

        //results of the tournament
        System.out.println("Here are the results of the tournament: ");
        for (int i = 0; i < numberOfPlayers; i++) {
            int num = i + 1;
            System.out.println("Player " + num + ": " + ans[i]);
        }
    }

    private static boolean isCorrect(int n, int m, int k) {
        return (k <= n || k <= m);
    }
}
