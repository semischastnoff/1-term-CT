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

int n;
ifstream fin;
ofstream fout;
set<int> used;

ll cnt_p(ll x) {
    ll ans = 1;
    for (int i = 1; i <= x; i++) {
        ans *= i;
    }
    return ans;
}

ll get_num(vector<int> &v) {
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < v[i]; j++) {
            if (used.find(j) == used.end()) {
                ans += cnt_p(n - i - 1);
            }
        }
        used.insert(v[i]);
    }
    return ans;
}

int main() {
    kek();

    fin.open("perm2num.in");
    fout.open("perm2num.out");
    fin >> n;
    vector<int> perm(n);
    for (int i = 0; i < n; i++) {
        fin >> perm[i];
    }
    fout << get_num(perm);

    return 0;
}
