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

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> dp(n, -INF);
    vector<int> prev(n, -INF);
    dp[0] = 0;
    prev[0] = 0;
    int ans = 0;
    int ind = 0;
    for (int i = 1; i < n; i++) {
        int maxx = -1;
        int pos = 0;
        for (int j = i; j >= 0; j--) {
            if (dp[j] > maxx && a[j] < a[i]) {
                maxx = dp[j];
                pos = j;
            }
        }
        dp[i] = maxx + 1;
        if (dp[i] > ans) {
            ans = dp[i];
            ind = i;
        }
        prev[i] = pos;
    }
    /*
    for (int i = 0; i < n; i++) {
        cout << i << " ";
    }
    cout << endl;
    for (auto x : dp) {
        cout << x << " ";
    }
    cout << endl;
    for (auto x : prev) {
        cout << x << " ";
    }
    cout << endl;
     */
    vector<int> way;
    way.push_back(a[ind]);
    while (ind != 0) {
        if (a[prev[ind]] < a[ind]) {
            way.push_back(a[prev[ind]]);
        }
        ind = prev[ind];
    }
    cout << ans + 1 << '\n';
    for (int i = way.size() - 1; i >= 0; i--) {
        cout << way[i] << " ";
    }

    return 0;
}

/*
8
8 7 1 5 2 4 3 4
 */