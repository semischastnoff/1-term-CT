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

int find_inc(string s) {
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '0') {
            return i;
        }
    }
    return -1;
}

int find_dec(string s) {
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '1') {
            return i;
        }
    }
    return -1;
}

void next_perm(string vect) {
    int pos = find_inc(vect);
    if (pos == -1) {
        fout << '-' << '\n';
        return;
    }
    vect[pos] = '1';
    for (int i = pos + 1; i < n; i++) {
        vect[i] = '0';
    }
    fout << vect << '\n';
}

void prev_perm(string vect) {
    int pos = find_dec(vect);
    if (pos == -1) {
        fout << '-' << '\n';
        return;
    }
    vect[pos] = '0';
    for (int i = pos + 1; i < n; i++) {
        vect[i] = '1';
    }
    fout << vect << '\n';
}

int main() {
    kek();

    fin.open("nextvector.in");
    fout.open("nextvector.out");
    string vect;
    fin >> vect;
    n = vect.size();
    prev_perm(vect);
    next_perm(vect);

    return 0;
}
