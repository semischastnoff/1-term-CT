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

void gen(string prefix, int opened, int closed) {
    if (opened + closed == 2 * n) {
        fout << prefix << '\n';
        return;
    }
    if (opened < n) {
        gen(prefix + '(', opened + 1, closed);
    }
    if (opened > closed) {
        gen(prefix + ')', opened, closed + 1);
    }
}

int main() {
    kek();

    fin.open("brackets.in");
    fout.open("brackets.out");
    fin >> n;
    gen("", 0, 0);

    return 0;
}
