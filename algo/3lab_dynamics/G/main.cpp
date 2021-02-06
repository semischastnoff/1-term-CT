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
string brackets;

void print(vector<vector<int>> &dp, vector<vector<int>> &ind, int left, int right) {
    if (dp[left][right] == 0) {
        cout << brackets.substr(left, right - left + 1);
        return;
    }
    if (dp[left][right] == right - left + 1) {
        return;
    }
    if (ind[left][right] == -INF) {
        cout << brackets[left];
        print(dp, ind, left + 1, right - 1);
        cout << brackets[right];
        return;
    }
    print(dp, ind, left, ind[left][right]);
    print(dp, ind, ind[left][right] + 1, right);
}

int main() {
    kek();

    map<char, char> brac;
    brac['('] = ')';
    brac['['] = ']';
    brac['{'] = '}';
    cin >> brackets;
    int n = brackets.size();
    vector<vector<int>> dp(n, vector<int> (n, 0)), ind(n, vector<int> (n, 0));
    for (int right = 0; right < n; right++) {
        for (int left = right; left >= 0; left--) {
            if (right == left) {
                dp[right][left] = 1;
                continue;
            }
            int t;
            int f = -INF;
            if (brackets[right] == brac[brackets[left]]) {
                t = dp[left + 1][right - 1];
            } else {
                t = INF;
            }
            for (int pos = left; pos < right; pos++) {
                if (dp[left][pos] + dp[pos + 1][right] < t) {
                    t = dp[left][pos] + dp[pos + 1][right];
                    f = pos;
                }
            }
            dp[left][right] = t;
            ind[left][right] = f;
        }
    }
    print(dp, ind, 0, n - 1);

    return 0;
}
