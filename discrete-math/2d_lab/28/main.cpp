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

void print(const vector<int> &v) {
    for (auto x : v) {
        fout << x << " ";
    }
}

void reverse(vector<int> &v, int first, int last) {
    while (first != last && first < last) {
        swap(v[first], v[last]);
        first++;
        last--;
    }
}

vector<int> next_multiperm(vector<int> &v, int n) {
    int pos_first = n - 2;
    while (pos_first >= 0 && v[pos_first + 1] <= v[pos_first]) {
        pos_first--;
    }
    if (pos_first >= 0) {
        int pos_second = pos_first + 1;
        while (pos_second < n - 1 && v[pos_second + 1] > v[pos_first]) {
            pos_second++;
        }
        swap(v[pos_first], v[pos_second]);
        reverse(v, pos_first + 1, n - 1);
        return v;
    }
    return vector<int> (n, 0);
}

int main() {
    kek();

    fin.open("nextmultiperm.in");
    fout.open("nextmultiperm.out");
    int n;
    fin >> n;
    vector<int> multiperm(n);
    for (int i = 0; i < n; i++) {
        fin >> multiperm[i];
    }
    print(next_multiperm(multiperm, n));

    return 0;
}
