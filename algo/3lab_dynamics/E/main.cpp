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

    string s, t;
    cin >> s >> t;
    vector<vector<int>> dp(s.size() + 1, vector<int> (t.size() + 1, 0));
    for (int i = 0; i <= s.size(); i++) {
        for (int j = 0; j <= t.size(); j ++) {
            if (i == 0 || j == 0) {
                dp[i][j] = i + j;
                continue;
            }
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
            }
        }
    }
    /*
    for (auto line : dp) {
        for (auto x : line) {
            cout << x << " ";
        }
        cout << endl;
    }
     */
    cout << dp[s.size()][t.size()];

    return 0;
}