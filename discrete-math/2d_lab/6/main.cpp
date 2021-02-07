#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <fstream>
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

int n;
ifstream fin;
ofstream fout;
vector<string> ans;

void gen(string pref) {
    if (pref.size() == n) {
        ans.push_back(pref);
        return;
    }
    gen(pref + '0');
    if (pref[pref.size() - 1] != '1') {
        gen(pref + '1');
    }
}

int main() {
    kek();

    fin.open("vectors.in");
    fout.open("vectors.out");
    fin >> n;
    gen("");
    fout << ans.size() << '\n';
    for (auto x : ans) {
        fout << x << '\n';
    }

    return 0;
}
