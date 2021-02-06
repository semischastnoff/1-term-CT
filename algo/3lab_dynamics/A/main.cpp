#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;

typedef long long ll;
typedef long double ld;

void kek() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

const int INF = 1e9;

int main() {
    kek();

    int n, k;
    cin >> n >> k;
    vector<int> cost(n, 0);
    for (int i = 1; i < n - 1; i++) {
        cin >> cost[i];
    }
    vector<int> dp(n, -INF);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0 && dp[i] < dp[i - j] + cost[i]) {
                dp[i] = dp[i - j] + cost[i];
            }
        }
    }
    cout << dp[n - 1] << '\n';
    int ind = n - 1;
    vector<int> way;
    while (ind > 0) {
        int i = 1;
        while (i <= k && ind - i >= 0 && dp[ind] - cost[ind] != dp[ind - i]) {
            i++;
        }
        way.push_back(ind - i);
        ind -= i;
    }
    cout << way.size() << '\n';
    for (int i = way.size() - 1; i >= 0; i--) {
        cout << way[i] + 1 << " ";
    }
    cout << n;

    return 0;
}

