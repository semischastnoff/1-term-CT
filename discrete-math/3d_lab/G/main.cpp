#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
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
map<char, pair<ld, ld>> letters;

pair<ld, ld> find_bounds(string & s, map<char, ld> & p) {
    ld l = 0, r = 1;
    for (auto x : p) {
        letters[x.first].first = l;
        letters[x.first].second = l + x.second;
        l = letters[x.first].second;
    }
    l = 0;
    for (char i : s) {
        l = l + (r - l) * letters[i].first;
        r = l + (r - l) * letters[i].second;
    }
    return {l, r};
}

ld to_bin(ll x) {
    ll bin = 0, k = 1;
    while (x) {
        bin += (x % 2) * k;
        k *= 10;
        x /= 2;
    }
    return bin;
}

ll get_binary_code(pair<ld, ld> & bounds) {
    if (bounds.first == 0) {
        return 0;
    }
    for (int q = 0; q < 20; q++) {
        ll znam = 1 << q;
        for (ll c = 1; c < znam; c++) {
            ld val = c * 1.0 / znam;
            if (val >= bounds.first && val < bounds.second) {
                cout << c << " " << znam << '\n';
                return to_bin(c);
            }
        }
    }
    return -1;
}

int main() {
    kek();

    cin >> n;
    string s;
    cin >> s;
    map<char, ld> p;
    for (auto x : s) {
        if (p.find(x) == p.end()) {
            p.insert({x, 1});
            continue;
        }
        p[x]++;
    }
    for (int i = 0; i < n; i++) {
        if (p.find('a' + i) == p.end()) {
            cout << 0 << " ";
        } else {
            cout << p['a' + i] << " ";
        }
        p['a' + i] /= s.size();
    }
    cout << '\n';
    pair<ld, ld> bounds = find_bounds(s, p);
    cout << get_binary_code(bounds);

    return 0;
}
