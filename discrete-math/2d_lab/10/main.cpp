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

void gen(const string& prefix, int next, int sum) {
    if (sum >= n) {
        if (sum == n) {
            fout << prefix.substr(0, prefix.size() - 1) << '\n';
        }
        return;
    }
    gen(prefix + to_string(next) + "+", next, sum + next);
    for (int i = next; i <= n; i++) {
        gen(prefix + to_string(i + 1) + "+", i + 1, sum + i + 1);
    }
}

int main() {
    kek();

    fin.open("partition.in");
    fout.open("partition.out");
    fin >> n;
    gen("", 1, 0);

    return 0;
}
