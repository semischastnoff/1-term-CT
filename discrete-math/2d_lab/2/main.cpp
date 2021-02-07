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

void gen(vector<string> &v) {
    if (v[0].size() == n) {
        return;
    }
    for (int i = v.size() - 1; i >= 0; i--) {
        v.push_back('1' + v[i]);
    }
    int mid = v.size() / 2;
    for (int i = 0; i < mid; i++) {
        v[i] = '0' + v[i];
    }
    gen(v);
}

int main() {
    kek();

    fin.open("gray.in");
    fout.open("gray.out");
    fin >> n;
    vector<string> gray;
    gray.emplace_back("0");
    gray.emplace_back("1");
    gen(gray);
    for (auto x : gray) {
        fout << x << '\n';
    }

    return 0;
}
