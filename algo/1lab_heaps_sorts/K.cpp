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

const ll INF = 1e9;

bool good(vector<ll> &a, ll m, int k, ll maxa) {
	int n = a.size();
	int i = 0;
	int cnt = 0;
	if (m < maxa) {
		return 0;
	} else {
		while (i < n) {
			ll sum = 0;
			while (i < n && sum + a[i] <= m) {
				sum += a[i];
				i++;
			}
			cnt++;
		}
		return !(cnt > k);
	}
}

ll find(vector<ll> &a, int k, ll maxa) {
	ll l = 0;
	ll r = maxa * a.size();
	while (r - l > 1) {
		ll m = (r + l) / 2;
		if (good(a, m, k, maxa)) {
			r = m;
		} else {
			l = m;
		}
	}
	return r;
}

int main() {
	algosiki();
	
	int n, k;
	cin >> n >> k;
	vector<ll> a(n);
	ll maxa = -INF;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > maxa) {
			maxa = a[i];
		}
	}
    //cout << good(a, 11, 4, maxa);
	cout << find(a, k, maxa);

	return 0; 
}