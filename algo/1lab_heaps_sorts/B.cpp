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

void cnt_sort(vector<ll> &a) {
	int n = a.size();
	vector<ll> cnt(101);
	for (int i = 0; i < n; i++) {
		cnt[a[i]]++;
	}
	for (int i = 0; i < 101; i++) {
		while (cnt[i] != 0) {
			cout << i << " ";
			cnt[i]--;
		}
	}
}

int main() {
	algosiki();
	
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cnt_sort(a);

	return 0;
}