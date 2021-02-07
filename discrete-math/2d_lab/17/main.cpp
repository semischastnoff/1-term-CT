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

ifstream fin;
ofstream fout;

string get(int n, ll k, vector<vector<ll>> &d) {
    int depth = 0;
    string ans;
    int len = 2 * n;
    for (int i = 0; i < len; i++) {
        if (depth < n && d[len - i - 1][depth + 1] >= k) {
            ans += '(';
            depth++;
        } else {
            if (depth < n) {
                k -= d[len - i - 1][depth + 1];
            }
            ans += ')';
            depth--;
        }
    }
    return ans;
}

int main() {
    kek();

    fin.open("num2brackets.in");
    fout.open("num2brackets.out");
    int n;
    ll k;
    fin >> n >> k;
    k++;
    int len = 2 * n;
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
    /*
    for (auto line : d) {
        for (auto x : line) {
            cout << x << " ";
        }
        cout << endl;
    }
     */
    fout << get(n, k, d);

    return 0;
}
