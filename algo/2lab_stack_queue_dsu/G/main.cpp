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

ll n;

struct dsu {
    vector<ll> p, minn, maxx, size;

    void initialize() {
        p.resize(n);
        minn.resize(n);
        maxx.resize(n);
        size.resize(n);
        for (ll i = 0; i < n; i++) {
            p[i] = i;
            minn[i] = i;
            maxx[i] = i;
            size[i] = (i == 0) ? 0 : 1;
        }
    }

    int find(ll x) {
        if (p[x] == x) {
            return x;
        }
        p[x] = find(p[x]);
        return p[x];
    }

    void add(ll u, ll v) {
        ll x = find(u);
        ll y = find(v);
        if (size[x] >= size[y]) {
            swap(x, y);
        }
        p[x] = y;
        if (x != y) {
            size[y] += size[x];
        }
        maxx[y] = max(maxx[x], maxx[y]);
        minn[y] = min(minn[x], minn[y]);
    }

    ll get_min(ll x) {
        return minn[x];
    }

    ll get_max(ll x) {
        return maxx[x];
    }

    ll get_size(ll x) {
        return size[x];
    }

    void print() {
        for (ll i = 0; i < n; i++) {
            cout << p[i] << " ";
        }
        cout << endl;
        for (ll i = 0; i < n; i++) {
            cout << minn[i] << " ";
        }
        cout << endl;
        for (ll i = 0; i < n; i++) {
            cout << maxx[i] << " ";
        }
        cout << endl;
        for (ll i = 0; i < n; i++) {
            cout << size[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    kek();

    cin >> n;
    n++;
    dsu g;
    g.initialize();
    string fl;
    while (cin >> fl) {
        if (fl == "union") {
            ll x, y;
            cin >> x >> y;
            g.add(x, y);
        } else if (fl == "get") {
            ll x;
            cin >> x;
            ll parent = g.find(x);
            cout << g.get_min(parent) << " " << g.get_max(parent) << " " << g.get_size(parent) << '\n';
        }
        //g.print();
    }

    return 0;
}
