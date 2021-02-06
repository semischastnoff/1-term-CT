import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Scanner;

public class H {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            if (a[i] > max) {
                max = a[i];
            }
        }
        int[] prefSum = new int[n];
        prefSum[0] = a[0];
        for (int i = 1; i < n; i++) {
            prefSum[i] = prefSum[i - 1] + a[i];
        }
        int m = sc.nextInt();
        Map<Integer, Integer> map = new LinkedHashMap<>();
        for (int i = 0; i < m; i++) {
            int t = sc.nextInt();
            if (t < max) {
                System.out.println("Impossible");
            } else if (map.get(t) != null) {
                System.out.println(map.get(t));
            } else {
                int j = 0, answer = 0;
                while (j < n) {
                    int left = j;
                    int right = n;
                    while (right - left > 1) {
                        int middle = (left + right) / 2;
                        int current;
                        if (j > 0) {
                            current = prefSum[middle] - prefSum[j - 1];
                        } else {
                            current = prefSum[middle];
                        }
                        if (current <= t) {
                            left = middle;
                        } else {
                            right = middle;
                        }
                    }
                    answer++;
                    j = right;
                }
                map.put(t, answer);
                System.out.println(answer);
            }
        }
    }
}

/*
6
4 2 3 1 3 4
8
10 2 5 4 6 7 8 8
 */
