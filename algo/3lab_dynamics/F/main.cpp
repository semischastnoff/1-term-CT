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

int main() {
    kek();

    int n;
    cin >> n;
    vector<int> meal(n);
    for (int i = 0; i < n; i++) {
        cin >> meal[i];
    }
    vector<vector<int>> dp(n + 1, vector<int> (n + 3, 0));
    dp[0][0] = meal[0];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n + 2; j++) {
            if (meal[i] > 100) {
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j + 1]) + meal[i];
            } else {
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + meal[i];
            }
        }
    }

    cout << dp[n][n - 2];

    return 0;
}
