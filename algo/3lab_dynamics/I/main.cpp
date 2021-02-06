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

int n;
vector<ll> a;

bool check(ll p, ll q, int i) {
    ll t = (p ^ q) + a[i];
    ll cnt = 0, pos = 0;
    if ((a[i] & q) == 0 && (a[i + 1] & q) == 0 && (p & q) == 0) {
        for (int k = 0; k < n; k++) {
            if (t % 2 == 0) {
                t /= 2;
                cnt++;
            } else {
                if (cnt % 2 != 0) {
                    pos = 1;
                }
                t = (t - 1) / 2;
                cnt = 0;
            }
        }
        return cnt % 2 == 0 && pos == 0;
    }
    return false;
}

void kek() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    kek();

    int m;
    ll size;
    cin >> n >> m;
    a.resize(m + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == 'X') {
                a[j] += (1 << i);
            }
        }
    }
    size = 1 << n;
    a[m] = size - 1;
    /*
    for (auto x : a) {
        cout << x << " ";
    }
    cout << endl;
     */
    vector<vector<ll>> dp(size, vector<ll>(m + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < m; i++) {
        for (ll p = 0; p < size; p++) {
            for (ll q = 0; q < size; q++) {
                ll t = (p ^ q) + a[i];
                ll cnt = 0, pos = 0;
                if ((a[i] & q) == 0 && (a[i + 1] & q) == 0 && (p & q) == 0) {
                    for (int k = 0; k < n; k++) {
                        if (t % 2 == 0) {
                            t /= 2;
                            cnt++;
                        } else {
                            if (cnt % 2 != 0) {
                                pos = 1;
                            }
                            t = (t - 1) / 2;
                            cnt = 0;
                        }
                    }
                    if (cnt % 2 == 0 && pos == 0) {
                        dp[q][i + 1] += dp[p][i];
                    }
                }
            }
        }
    }
    cout << dp[0][m];

    return 0;
}

/*
12 12
............
............
............
............
............
............
............
............
............
............
............
............
 */