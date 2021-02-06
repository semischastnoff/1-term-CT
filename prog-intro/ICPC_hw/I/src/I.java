import java.util.Scanner;

public class I {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long xl = Long.MAX_VALUE;
        long xr = Long.MIN_VALUE;
        long yl = Long.MAX_VALUE;
        long yr = Long.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            long x = sc.nextLong();
            long y = sc.nextLong();
            long h = sc.nextLong();
            if (x - h < xl) {
                xl = x - h;
            }
            if (x + h > xr) {
                xr = x + h;
            }
            if (y - h < yl) {
                yl = y - h;
            }
            if (y + h > yr) {
                yr = y + h;
            }
        }
        System.out.println((xl + xr) / 2 + " " + (yl + yr) / 2 + " " + (long) Math.ceil((double) Math.max(xr - xl, yr - yl) / 2));
    }
}
