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

ll ans = 0;

bool cmp(ll a, ll b) {
    return a > b;
}

void print(const vector<ll>& v) {
    for (auto x : v) {
        cout << x << " ";
    }
    cout << endl;
}

void solve(int n, vector<ll> &p) {
    if (n == 1) {
        return;
    }
    sort(all(p), cmp);
    //print(p);
    p[p.size() - 2] += p[p.size() - 1];
    ans += p[p.size() - 2];
    p.resize(p.size() - 1);
    solve(n - 1, p);
}

int main() {
    kek();

    int n;
    cin >> n;
    vector<ll> p(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    solve(n, p);
    cout << ans;

    return 0;
}
