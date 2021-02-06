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

const int inf = 1e9;

int main() {
    kek();

    int n;
    cin >> n;
    vector<vector<ll>> dp(n, vector<ll> (10, 0));
    for (int i = 0; i < 10; i++) {
        dp[0][i] = 1;
    }
    dp[0][0] = 0;
    dp[0][8] = 0;
    for (int i = 1; i < n; i++) {
        dp[i][0] = (dp[i - 1][4] + dp[i - 1][6]) % inf;
        dp[i][1] = (dp[i - 1][6] + dp[i - 1][8]) % inf;
        dp[i][2] = (dp[i - 1][7] + dp[i - 1][9]) % inf;
        dp[i][3] = (dp[i - 1][4] + dp[i - 1][8]) % inf;
        dp[i][4] = (dp[i - 1][0] + dp[i - 1][3] + dp[i - 1][9]) % inf;
        dp[i][5] = 0;
        dp[i][6] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][7]) % inf;
        dp[i][7] = (dp[i - 1][2] + dp[i - 1][6]) % inf;
        dp[i][8] = (dp[i - 1][1] + dp[i - 1][3]) % inf;
        dp[i][9] = (dp[i - 1][4] + dp[i - 1][2]) % inf;
    }
    ll ans = 0;
    for (auto x : dp[n - 1]) {
        ans = (ans + x) % inf;
    }
    cout << ans;

    return 0;
}
