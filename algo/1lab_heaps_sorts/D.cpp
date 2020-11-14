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

void insert(vector<ll> &a, int x) {
	a.push_back(x);
	int n = a.size();
	int i = n - 1;
	while (i > 0 && a[i] > a[(i - 1) / 2]) {
		swap(a[i], a[(i - 1) / 2]);
		i = (i - 1) / 2;
	}
}

int extract(vector<ll> &a) {
	int res = a[0];
	int n = a.size();
	a[0] = a[n - 1];
	a.resize(n - 1);
	int i = 0;
	while (true) {
		int j = i;
		if (2 * i + 1 < n && a[2 * i + 1] > a[j]) {
			j = 2 * i + 1;
		}
		if (2 * i + 2 < n && a[2 * i + 2] > a[j]) {
			j = 2 * i + 2;
		}
		if (i == j) {
			break;
		}
		swap(a[i], a[j]);
		i = j;
	}
	return res;
}

int main() {
	algosiki();
	
	int n;
	cin >> n;
	vector<ll> a;
	vector<ll> ans;
	for (int i = 0; i < n; i++) {
		bool fl;
		cin >> fl;
		if (!fl) {
			ll x;
			cin >> x;
			insert(a, x);
		} else {
			ans.push_back(extract(a));
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}