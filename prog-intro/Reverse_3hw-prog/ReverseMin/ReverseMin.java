import java.util.*;


public class ReverseMin {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] minR = {Integer.MAX_VALUE, Integer.MAX_VALUE};
		int[] minC = {Integer.MAX_VALUE, Integer.MAX_VALUE};
		int[] lines = new int[1];
		int cntR = 0, cntC = 0;
		int rows = 0;
		while (sc.hasNextLine()) {
			String s = sc.nextLine();
			Scanner scan = new Scanner(s);
			int numInLine = 0;
			int number = 0;

			while (scan.hasNextInt()) {
				//считываем следующее число в строке
				int x = scan.nextInt();
				number = x;
				numInLine++;    //количество чисел в строке 
				//уведичиваем длину массива, если надо
				if (minR.length <= cntC) {
					minR = Arrays.copyOf(minR, cntC * 2);
					for (int i = cntC; i < minR.length; i++) {
						minR[i] = Integer.MAX_VALUE;
					}
				}
				if (number < minR[cntC]) {
					minR[cntC] = number;
				}
				//увеличиваеи размер массива
				if (minC.length <= numInLine) {
					minC = Arrays.copyOf(minC, numInLine * 2);
					for (int i = numInLine; i < minC.length; i++) {
						minC[i] = Integer.MAX_VALUE;
					}
				}
				if (number < minC[numInLine - 1]) {
					minC[numInLine - 1] = number;
				}
				

				cntR++;
			}

			if (lines.length == cntC) {
				lines = Arrays.copyOf(lines, lines.length * 2);
			}
			
			
			if (rows < numInLine) {
				rows = numInLine;
			}
			lines[cntC] = numInLine;
			numInLine = 0;
			cntC++;
		}/*
		//debug
		System.out.println();
		for (int i = 0; i < cntC; i++) {
			System.out.print(minR[i] + " ");
		}
		System.out.println();
		for (int i = 0; i < rows; i++) {
			System.out.print(minC[i] + " ");
		}
		System.out.println();
		//debug
		*/
		for (int i = 0; i < cntC; i++) {
			int j = 0;
			while (lines[i] != 0) {
				if(j < rows) {
					if (minC[j] < minR[i]) {
						System.out.print(minC[j] + " ");
					} else {
						System.out.print(minR[i] + " ");
					}
					j++;
				}
				lines[i]--;
			}
			System.out.println();
		}
	}
}