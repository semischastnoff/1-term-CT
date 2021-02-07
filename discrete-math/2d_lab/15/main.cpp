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
vector<vector<ll>> cnt_choose;

void gen(ll n, ll k, ll number) {
    ll next = 1;
    while (k > 0) {
        ll cnt = cnt_choose[n - 1][k - 1];
        if (cnt > number) {
            fout << next << " ";
            k--;
        } else {
            number -= cnt;
        }
        n--;
        next++;
    }
}

int main() {
    kek();

    fin.open("num2choose.in");
    fout.open("num2choose.out");
    ll n, k, m;
    fin >> n >> k >> m;
    cnt_choose.resize(n + 1);
    for (ll i = 0; i <= n; i++) {
        cnt_choose[i].resize(n + 1);
    }
    cnt_choose[0][0] = 1;
    for (ll i = 1; i <= n; i++) {
        cnt_choose[i][0] = cnt_choose[i - 1][0];
        for (ll j = 1; j <= n; j++) {
            cnt_choose[i][j] = cnt_choose[i - 1][j] + cnt_choose[i - 1][j - 1];
        }
    }
    gen(n, k, m);

    return 0;
}
