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

bool check(ll p, ll q, ll size) {
    ll t = (size + ~p) % size;
    ll f = (size + ~q) % size;
    ll x = p & q;
    if ((x & (x << 1)) != 0) {
        return false;
    }
    ll y = t & f;
    if ((y & (y << 1)) != 0) {
        return false;
    }
    return true;
}

void kek() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    kek();

    int n, m;
    ll size;
    cin >> n >> m;
    if (n > m) {
        swap(n, m);
    }
    size = 1 << n;
    vector<vector<int>> dp(size, vector<int>(m, 0));
    for (int i = 0; i < size; i++) {
        dp[i][0] = 1;
    }
    for (int i = 0; i < m - 1; i++) {
        for (ll p = 0; p < size; p++) {
            for (ll q = 0; q < size; q++) {
                if (check(p, q, size)) {
                    dp[q][i + 1] += dp[p][i];
                }
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
    ll ans = 0;
    for (int i = 0; i < size; i++) {
        ans += dp[i][m - 1];
    }
    cout << ans;

    return 0;
}
