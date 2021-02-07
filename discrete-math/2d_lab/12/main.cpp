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

void print(vector<vector<int>> &v, vector<int> &cnt) {
    for (int i = 0; i < k; i++){
        for (int j = 0; j < cnt[i]; ++j) {
            fout << v[i][j] << " ";
        }
        fout << endl;
    }
    fout << endl;
}

void gen(vector<vector<int>> &v, vector<int> &cnt, int sets, int elements) {
    if (sets == k && elements == n) {
        print(v, cnt);
        return;
    }
    if (sets < k) {
        cnt[sets]++;
        v[sets][0] = elements + 1;
        gen(v, cnt, sets + 1, elements + 1);
        cnt[sets]--;
    }
    if (k - sets < n - elements) {
        for (int i = 0; i < sets; i++) {
            cnt[i]++;
            v[i][cnt[i] - 1] = elements + 1;
            gen(v, cnt, sets, elements + 1);
            cnt[i]--;
        }
    }
}


int main() {
    kek();

    fin.open("part2sets.in");
    fout.open("part2sets.out");
    fin >> n >> k;
    vector<vector<int>> v(k, vector<int> (n));
    vector<int> cnt(k);
    gen(v, cnt, 0, 0);

    return 0;
}