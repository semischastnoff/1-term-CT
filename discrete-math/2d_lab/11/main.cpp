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
set<string> used;

void gen(const string& prefix, int next) {
    if (used.find(prefix) == used.end() && !prefix.empty()) {
        fout << prefix << '\n';
        used.insert(prefix);
    }
    if (next > n) {
        return;
    }
    if (next <= n) {
        gen(prefix + to_string(next) + " ", next + 1);
    }
    gen(prefix, next + 1);
}

int main() {
    kek();

    fin.open("subsets.in");
    fout.open("subsets.out");
    fin >> n;
    fout << '\n';
    gen("", 1);

    return 0;
}
