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

bool find(string s, char c) {
    for (auto x : s) {
        if (x == c) {
            return true;
        }
    }
    return false;
}

void gen(string prefix) {
    if (prefix.size() == 2 * n) {
        fout << prefix << '\n';
    }
    for (int i = 1; i <= n; i++) {
        if (!find(prefix, i + '0')) {
            gen(prefix + to_string(i) + " ");
        }
    }
}

int main() {
    kek();

    fin.open("permutations.in");
    fout.open("permutations.out");
    fin >> n;
    gen("");

    return 0;
}
