import java.util.*;

public class Reverse {
	public static void main(String[] args) {
		int[] ans = new int[1];
		int[] lines = new int[1];
		Scanner scL = new Scanner(System.in);
		int cntL = 0, cntN = 0, numInLine = 0;
		while (scL.hasNextLine()) {
			String s = scL.nextLine();
			Scanner scN = new Scanner(s);
			while (scN.hasNextInt()) {
				if (cntN == ans.length) {
					ans = Arrays.copyOf(ans, ans.length * 2);
				}
				ans[cntN] = scN.nextInt();
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
	}
}