import java.util.*;

public class M {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            int n = sc.nextInt();
            solve(n);
        }
    }

    private static void solve(int n) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        int ans = 0;
        for (int j = n - 1; j >= 0; j--) {
            for (int i = 0; i < j; i++) {
                int ak = 2 * arr[j] - arr[i];
                ans += map.getOrDefault(ak, 0);
            }
            int val = map.getOrDefault(arr[j], 0);
            map.put(arr[j], val + 1);
        }
        System.out.println(ans);
    }
}

/*
4
5
1 2 1 2 1
3
30 20 10
5
1 2 2 3 4
9
3 1 4 1 5 9 2 6 5
 */