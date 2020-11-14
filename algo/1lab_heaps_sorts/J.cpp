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

const ld EPS = 1e-6;

int vp, vf;
ld a;

ld time(ld x) {
	ld hyp1 = pow((pow(1 - a, 2) + pow(x, 2)), 0.5);
	ld hyp2 = pow((pow(a, 2) + pow(1 - x, 2)), 0.5);
	return hyp1 / vp + hyp2 / vf;
}

ld tern_search() {
	ld l = 0;
	ld r = 1;
	while (r - l > EPS) {
		ld m1 = (2 * l + r) / 3;
		ld m2 = (2 * r + l) / 3;
		if (time(m1) < time(m2)) {
			r = m2;
		} else {
			l = m1;
		}
	}
	return r;
}

int main() {
	algosiki();

	cin >> vp >> vf >> a;
	cout << fixed;
	cout.precision(4);
	cout << tern_search();

	return 0;
}