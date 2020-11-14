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

void algosiki() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

bool good(ll x, ll w, ll h, ll n) {
	return ((x / h) * (x / w) >= n);
}

ll find(ll w, ll h, ll n) {
	ll l = 0;
	ll r = max(w, h) * n;
	while (r - l > 1) {
		ll m = (r + l) / 2;
		if (good(m, w, h, n)) {
			r = m;
		} else {
			l = m;
		}
	}
	return r;
}

int main() {
	algosiki();
	
	ll w, h, n;
	cin >> w >> h >> n;
	cout << find(w, h, n);

	return 0;
}