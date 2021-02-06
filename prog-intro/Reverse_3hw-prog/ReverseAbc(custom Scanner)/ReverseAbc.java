import java.io.IOException;
import java.util.Arrays;

public class ReverseAbc {
    public static void main(String[] args) {
        try {
            String[] ans = new String[1];
            int[] lines = new int[1];
            Scanner scL = new Scanner(System.in);
            int cntL = 0, cntN = 0, numInLine = 0;
            while (scL.hasNextLine()) {
                String s = scL.nextLine();
                Scanner scN = new Scanner(s);
                while (scN.hasNext()) {
                    if (cntN == ans.length) {
                        ans = Arrays.copyOf(ans, ans.length * 2);
                    }
                    ans[cntN] = scN.next();
                    cntN++;
                    numInLine++;
                }
                if (cntL == lines.length) {
                    lines = Arrays.copyOf(lines, lines.length * 2);
                }
                lines[cntL] = numInLine;
                numInLine = 0;
                cntL++;
            }
            cntN--;
            for (int i = cntL - 1; i >= 0; i--) {
                while (lines[i] != 0) {
                    if (cntN >= 0) {
                        System.out.print(ans[cntN] + " ");
                    }
                    lines[i]--;
                    cntN--;
                }
                System.out.println();
            }
        } catch (IOException e) {
            System.out.println("IOException caught : " + e.getMessage());
        }
    }
}