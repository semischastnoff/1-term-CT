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

ll get_num(int n, int k, vector<int> &choose) {
    ll number = 0;
    for (int i = 1; i <= k; i++) {
        int prev = choose[i - 1] + 1;
        for (int j = prev; j < choose[i]; j++) {
            number += cnt_choose[n - j][k - i];
        }
    }
    return number;
}

int main() {
    kek();

    fin.open("choose2num.in");
    fout.open("choose2num.out");
    ll n, k;
    fin >> n >> k;
    vector<int> choose(k + 1);
    choose[0] = 0;
    for (int i = 1; i <= k; i++) {
        fin >> choose[i];
    }

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

    fout << get_num(n, k, choose);

    return 0;
}

/*
 * 4 2
 * 1 3
 *
 * 1 2
 * 1 3
 */