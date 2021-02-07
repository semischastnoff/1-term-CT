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

void print(vector<int> v) {
    for (auto x : v) {
        fout << x << " ";
    }
    fout << '\n';
}

void reverse(vector<int> &v, int first, int last) {
    while (first != last && first < last) {
        swap(v[first], v[last]);
        first++;
        last--;
    }
}

vector<int> prev_perm(int n, vector<int> v) {
    for (int i = n - 2; i >= 0; i--) {
        if (v[i] > v[i + 1]) {
            int pos = i + 1;
            for (int j = i + 1; j < n; j++) {
                if (v[i] > v[pos] && v[j] < v[i]) {
                    pos = j;
                }
            }
            swap(v[pos], v[i]);
            reverse(v, i + 1, n - 1);
            return v;
        }
    }
    return vector<int> (n, 0);
}

vector<int> next_perm(int n, vector<int> v) {
    for (int i = n - 2; i >= 0; i--) {
        if (v[i] < v[i + 1]) {
            int pos = i + 1;
            for (int j = i + 1; j < n; j++) {
                if (v[i] < v[pos] && v[j] > v[i]) {
                    pos = j;
                }
            }
            swap(v[pos], v[i]);
            reverse(v, i + 1, n - 1);
            return v;
        }
    }
    return vector<int> (n, 0);
}

int main() {
    kek();

    fin.open("nextperm.in");
    fout.open("nextperm.out");
    int n;
    fin >> n;
    vector<int> perm(n);
    for (int i = 0; i < n; i++) {
        fin >> perm[i];
    }
    print(prev_perm(n, perm));
    print(next_perm(n, perm));

    return 0;
}
