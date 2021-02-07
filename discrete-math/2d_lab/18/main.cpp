#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <fstream>
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

int len, n;
ifstream fin;
ofstream fout;

ll get_num(const string &s, vector<vector<ll>> &d) {
    int depth = 0;
    ll ans = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            depth++;
        } else {
            if (depth < n) {
                ans += d[len - i - 1][depth + 1];
            }
            depth--;
        }
    }
    return ans;
}

int main() {
    kek();

    fin.open("brackets2num.in");
    fout.open("brackets2num.out");
    string brackets;
    fin >> brackets;

    len = brackets.size();
    n = len / 2;
    vector<vector<ll>> d(len + 1, vector<ll> (n + 1, 0));
    d[0][0] = 1;
    for (int i = 1; i <= len; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                d[i][j] = 0;
                continue;
            }
            if (j > 0) {
                d[i][j] += d[i - 1][j - 1];
            }
            if (j < n) {
                d[i][j] += d[i - 1][j + 1];
            }
        }
    }

    fout << get_num(brackets, d);

    return 0;
}
