import java.util.Scanner;

public class B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long begin = -710 * 25_000;
        long end = 710 * 25_000;
        long i = 1;
        for (long y = begin; y < end; y += 710) {
            System.out.println(y);
            if (i >= n) {
                break;
            }
            i++;
        }
    }
}