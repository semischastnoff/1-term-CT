#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <fstream>
#include <set>

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

ll n;
ifstream fin;
ofstream fout;
map<string, string> ans;

void gen(string first) {
    string cur = first;
    ans.insert({cur, cur});
    fout << cur << '\n';
    while (true) {
        string pref = cur.substr(1);
        if (ans.find(pref + '1') == ans.end()) {
            cur = pref + '1';
        } else if (ans.find(pref + '0') == ans.end()) {
            cur = pref + '0';
        } else {
            break;
        }
        ans.insert({cur, cur});
        fout << cur << '\n';
    }
}

int main() {
    kek();

    fin.open("chaincode.in");
    fout.open("chaincode.out");
    string first;
    fin >> n;
    for (int i = 0; i < n; i++) {
        first += '0';
    }
    gen(first);

    return 0;
}
