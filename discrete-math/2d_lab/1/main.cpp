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

void gen(string pref) {
    if (pref.size() == n) {
        fout << pref << '\n';
        return;
    }
    gen(pref + '0');
    gen(pref + '1');
}

int main() {
    kek();

    fin.open("allvectors.in");
    fout.open("allvectors.out");
    fin >> n;
    gen("");

    return 0;
}
