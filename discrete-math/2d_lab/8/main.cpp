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

int n, k;
ifstream fin;
ofstream fout;

void print(vector<int> &v) {
    for (auto x : v) {
        fout << x << " ";
    }
    fout << '\n';
}

void gen(vector<int> &v, int len, int it) {
    if (len == k) {
        print(v);
        return;
    }
    for (int next = it; next <= n; next++) {
        v[len] = next;
        gen(v, len + 1, next + 1);
    }
}

int main() {
    kek();

    fin.open("choose.in");
    fout.open("choose.out");
    fin >> n >> k;
    vector<int> choose(k);
    gen(choose, 0, 1);

    return 0;
}
