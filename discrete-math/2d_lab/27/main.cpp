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

string next_brackets(string s) {
    int closed = 0, opened = 0;
    int n = s.size();
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '(') {
            opened++;
            if (closed > opened) {
                break;
            }
        } else {
            closed++;
        }
    }
    s.resize(n - opened - closed);
    if (s.empty()) {
        return "-";
    }
    s += ')';
    s.insert(n - opened - closed + 1, opened, '(');
    s.insert(n - closed + 1, closed - 1, ')');
    return s;
}

int main() {
    kek();

    fin.open("nextbrackets.in");
    fout.open("nextbrackets.out");
    string brackets;
    fin >> brackets;
    fout << next_brackets(brackets);

    return 0;
}
