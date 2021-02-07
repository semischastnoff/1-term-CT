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
    vector<string> cycle;
    for (int i = 0; i < s.size(); ++i) {
        if (i == 0) {
            cycle.push_back(s.substr(1) + s[0]);
        } else {
            cycle.push_back(cycle.back().substr(1) + cycle.back()[0]);
        }
    }
    /*
    for (const auto& x : cycle) {
        cout << x << endl;
    }
    cout << " -- \n";
     */
    sort(all(cycle));
    for (const auto& x : cycle) {
        cout << x[x.size() - 1];
    }


    return 0;
}
