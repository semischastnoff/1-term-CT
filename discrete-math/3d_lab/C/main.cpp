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

void kek() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    kek();

    string s;
    cin >> s;
    vector<string> cycle(s.size(), "");
    for (int t = 0; t < s.size(); t++) {
        for (int i = 0; i < s.size(); i++) {
            cycle[i] = s[i] + cycle[i];
        }
        sort(all(cycle));
    }
    cout << cycle[0];

    return 0;
}
