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

ifstream fin;
ofstream fout;

void print(const vector<int>& v) {
    for (auto x : v) {
        fout << x << " ";
    }
}

vector<int> next_choose(int n, int k, vector<int>& v) {
    v.resize(k + 1);
    v[k] = n + 1;
    int ind = k - 1;
    while (ind >= 0 && v[ind + 1] - v[ind] < 2) {
        ind--;
    }
    if (ind >= 0) {
        v[ind]++;
        for (int i = ind + 1; i < k; i++) {
            v[i] = v[i - 1] + 1;
        }
        v.resize(k);
        return v;
    }
    return vector<int> {-1};
}

int main() {
    kek();

    fin.open("nextchoose.in");
    fout.open("nextchoose.out");
    int n, k;
    fin >> n >> k;
    vector<int> choose(k);
    for (int i = 0; i < k; i++) {
        fin >> choose[i];
    }
    print(next_choose(n, k, choose));

    return 0;
}
