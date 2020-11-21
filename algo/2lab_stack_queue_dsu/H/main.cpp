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

struct tree {
    ll parent;
    ll inc;
    ll level;
};

struct dsu {
    vector<tree> v;

    void initialize() {
        v.resize(n);
        for (ll i = 0; i < n; i++) {
            v[i].parent = i;
            v[i].inc = 0;
            v[i].level = 0;
        }
    }

    ll find(ll u) {
        ll parent = v[u].parent;
        if (v[u].parent != u) {
            v[u].parent = find(v[u].parent);
        }
        v[u].inc += v[parent].inc;
        return v[u].parent;
    }

    void join(ll u, ll t) {
        ll x = find(u);
        ll y = find(t);
        if (x != y) {
            if (x < y) {
                swap(x, y);
            }
            v[x].parent = y;
            v[x].inc = v[x].level - v[y].level;
        }
    }

    ll get_level(ll u) {
        ll parent = find(u);
        return v[parent].level + v[u].inc;
    }

    void print() {
        for (ll i = 0; i < n; i++) {
            cout << v[i].parent << " ";
        }
        cout << endl;
        for (ll i = 0; i < n; i++) {
            cout << v[i].inc << " ";
        }
        cout << endl;
        for (ll i = 0; i < n; i++) {
            cout << v[i].level << " ";
        }
        cout << endl;
    }
};

int main() {
    kek();

    ll m;
    cin >> n >> m;
    n++;
    dsu g;
    g.initialize();
    for (int i = 0; i < m; i++) {
        string fl;
        cin >> fl;
        if (fl == "join") {
            ll x, y;
            cin >> x >> y;
            g.join(x, y);
        } else if (fl == "add") {
            ll u, x;
            cin >> u >> x;
            ll parent = g.find(u);
            g.v[parent].level += x;
        } else if (fl == "get") {
            ll x;
            cin >> x;
            cout << g.get_level(x) << '\n';
        }
        //g.print();
    }

    return 0;
}

/*
4 6
join 1 2
join 1 4
add 4 10
join 4 3
add 2 60
get 1

2 2
join 1 2
join 1 2
 */
