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

void kek() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    kek();

    int n;
    cin >> n;
    int len = pow(2, n);
    vector<string> a(len);
    vector<vector<bool> > cf(len);
    for (int i = 0; i < len; i++) {
        int f;
        string s;
        cin >> s >> f;
        a[i] = s;
        cf[0].push_back((bool) f);
    }

    for (int i = 1; i < len; i++) {
        for (int j = 0; j < cf[i - 1].size() - 1; j++) {
            bool f1 = cf[i - 1][j], f2 = cf[i - 1][j + 1];
            cf[i].push_back(f1 xor f2);
        }
    }
    for (int i = 0; i < len; i++) {
        cout << a[i] << " " << cf[i][0] << '\n';
    }
    return 0;
}
