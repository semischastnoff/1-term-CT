#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <fstream>

#define int long long
#define all(a) a.begin(), a.end()
using namespace std;

void speedup() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int binpow(int a, int n) {
	if (n == 0) return 1;
	if (n & 1)
		return binpow(a, n - 1) * a;
	else {
		int b = binpow(a, n / 2);
		return b * b;
	}
}

void solve(ifstream fin, ofstream fout) {
	int n, s;
	fin >> n;
	vector <int> a(n);

	for (int i = 0; i < n; i++) {
		fin >> a[i];
	}

	fin >> s;
	string res, bin_res;
	int cnt = s;
	do {
		bin_res.push_back((cnt & 1) + '0');
	} while (cnt >>= 1);
	reverse(all(bin_res));

	if (s == 0) {
		fout << "1&~1";
		return;
	}

	int check = 0, byte = 1;
	for (int i = bin_res.length() - 1; i >= 0; --i) {
		if (bin_res[i] - '0') {
			int cur;
			string str;
			if (a[0] & byte) {
				cur = a[0];
				str.append("1");
			}
			else {
				cur = (~a[0]);
				str.append("~1");
			}
			for (int j = 1; j < n; ++j) {
				string tmp = to_string(j + 1);
				if (a[j] & byte) {
					cur &= a[j];
					str.append("&" + tmp);
				}
				else {
					cur &= ~a[j];
					str.append("&~" + tmp);
				}
			}
			check |= cur;
			if (!res.empty())
				res.append("|");
			res.append(str);
		}
		byte <<= 1;
	}

	if (check == s) fout << res;
	else fout << "Impossible";
}

signed main() {
	speedup();
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	fout.open("correct.txt");
	solve(fin, fout);
	int q;
	fin >> q;
	for (int i = 0; i < q; i++) {

	}
	return 0;
}
/*
5
45 87 23 76 90
86
 */