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

    int n, m;
    cin >> n >> m;
    vector<vector<int>> cost(n, vector<int> (m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cost[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int> (m, 0));
    vector<vector<int>> prev(n, vector<int> (m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0) {
                if (j > 0) {
                    dp[i][j] = dp[i][j - 1] + cost[i][j];
                } else {
                    dp[i][j] = cost[i][j];
                }
                prev[i][j] = 1;
            }
            if (j == 0) {
                if (i > 0) {
                    dp[i][j] = dp[i - 1][j] + cost[i][j];
                } else {
                    dp[i][j] = cost[i][j];
                }
                prev[i][j] = 2;
            }
            if (i != 0 && j != 0) {
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    dp[i][j] = dp[i - 1][j] + cost[i][j];
                    prev[i][j] = 2;
                } else {
                    dp[i][j] = dp[i][j - 1] + cost[i][j];
                    prev[i][j] = 1;
                }
            }
        }
    }
    cout << dp[n - 1][m - 1] << '\n';
    pair<int, int> cur = {n - 1, m - 1};
    string way;
    while (cur.first != 0 || cur.second != 0) {
        if (prev[cur.first][cur.second] == 1) {
            way += 'R';
            cur.second--;
        } else {
            way += 'D';
            cur.first--;
        }
    }
    for (int i = way.size() - 1; i >= 0; i--) {
        cout << way[i];
    }

    return 0;
}
