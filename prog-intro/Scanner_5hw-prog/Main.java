import java.io.IOException;
import java.util.NoSuchElementException;


public class Main {
	public static void main(String[] args) {
		try {
			Scanner sc = new Scanner(System.in);
			String s = sc.nextLine();
			int[] a = new int[100];
			Scanner num = new  Scanner(s);
			int i = 0;
			while (num.hasNextInt()) {
				a[i] = num.nextInt();
				i++;
			}
			for (int j = 0; j < i; j++) {
				System.out.println(a[j] + " ");
			}
		} catch (IOException e) {
			System.err.println(e);
		}
	}
}