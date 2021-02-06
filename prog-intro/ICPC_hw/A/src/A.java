import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();
        long n = sc.nextLong();
        System.out.println((long) (2 * Math.ceil((double) (n - b) / (b - a))) + 1);
    }
}
