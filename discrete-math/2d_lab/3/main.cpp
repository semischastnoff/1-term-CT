#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
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
vector<string> p;

void gen(string pref) {
    if (pref.size() == n) {
        p.push_back(pref);
        return;
    }
    gen(pref + '0');
    gen(pref + '1');
    gen(pref + '2');
}

string increase(string s) {
    string ans;
    for (auto x : s) {
        if (x == '0') {
            ans += '1';
        } else if (x == '1') {
            ans += '2';
        } else {
            ans += '0';
        }
    }
    return ans;
}

int main() {
    kek();

    fin.open("antigray.in");
    fout.open("antigray.out");
    fin >> n;
    gen("");
    vector<string> antigray;
    p.resize(pow(3, n - 1));
    for (auto x : p) {
        string inc = increase(x);
        antigray.push_back(x);
        antigray.push_back(inc);
        antigray.push_back(increase(inc));
    }
    for (auto x : antigray) {
        fout << x << '\n';
    }

    return 0;
}
