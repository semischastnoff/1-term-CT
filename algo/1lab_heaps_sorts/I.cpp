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

void algosiki() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

const ld EPS = 1e-10;

ld c;

bool good(ld x) {
	return (pow(x, 2) + pow(x, 0.5) >= c);
}

ld find(ld x) {
	ld l = 0;
	ld r = 1e10;
	while (r - l > EPS) {
		ld m = (r + l) / 2;
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
	
	cin >> c;
	cout << fixed;
	cout.precision(6);
	cout << find(c);

	return 0;
}