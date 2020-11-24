package game;

import java.util.Scanner;

public class CReader extends Main {
    public Scanner sc = new Scanner(System.in);

    private boolean checkK;

    int readInt(boolean check) {
        String s = sc.next();
        this.checkK = check;
        while (!isNum(s)) {
            System.out.println("Your input is incorrect, please try again");
            s = sc.next();
        }
        return Integer.parseInt(s);
    }

    String readPlayer() {
        String s = sc.next();
        while (!s.equals("Human") && !s.equals("Sequential") && !s.equals("Random")) {
            System.out.println("Player type is incorrect, please tyr again");
            s = sc.next();
        }
        return s;
    }

    private boolean isNum(String s) {
        int x;
        try {
            x = Integer.parseInt(s);
        } catch (NumberFormatException e) {
            return false;
        }
        if (this.checkK) {
            return (x <= game.Main.n && x <= game.Main.m) && x > 0;
        }
        return (x > 0);
    }
}
