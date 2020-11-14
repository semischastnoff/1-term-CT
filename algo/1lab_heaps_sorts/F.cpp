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

int b_right(vector<ll> &a, int x) {
	int n = a.size();
	int l = -1;
	int r = n;
	while(r - l > 1) {
		int m = (r + l) / 2;
		if (a[m] < x) {
			l = m;
		} else {
			r = m;
		}
	}
	return (r == n) ? a[n - 1] : a[r];
}

int b_left(vector<ll> &a, int x) {
	int n = a.size();
	int l = -1;
	int r = n;
	while(r - l > 1) {
		int m = (r + l) / 2;
		if (a[m] <= x) {
			l = m;
		} else {
			r = m;
		}
	}
	return (l == -1) ? a[0] : a[l];
}

int main() {
	algosiki();
	
	int n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for (int i = 0 ; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		int left = b_left(a, x);
		int right = b_right(a, x);

		if (abs(x - left) <= abs(x - right)) {
			cout << left << '\n';
		} else {
			cout << right << '\n';
		}
	}

	return 0;
}