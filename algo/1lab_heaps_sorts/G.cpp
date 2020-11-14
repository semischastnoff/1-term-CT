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

ll n, x, y;

bool good(ll m) {
	return (m / x + m / y >= n - 1);
}

ll find() {
	ll l = 0;
	ll r = 1e10;
	while (r - l > 1) {
		ll m = (r + l) / 2;
		if (good(m)) {
			r = m;
		} else {
			l = m;
		}
	}
	return r;
}

int main() {
	algosiki();
	
	cin >> n >> x >> y;
	if (n == 1) {
		cout << min(x, y);
	} else {
		cout << find() + min(x, y);
	}

	return 0;
}