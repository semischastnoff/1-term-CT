#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

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

int main() {
    kek();

    map<int, string> code;
    for (char i = 97; i < 123; i++) {
        string val;
        val += i;
        code.insert({i - 'a', val});
    }
    int last_code = 26;
    int n;
    cin >> n;
    string out, s;
    int t;
    cin >> t;
    cout << code[t];
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        if (code.find(x) != code.end()) {
            out = code[x];
        } else {
            out = code[t] + s;
        }
        cout << out;
        s = out.substr(0, 1);
        code.insert({last_code, out + s});
        last_code++;
        t = x;
    }
    cout << out;

    return 0;
}

/*
8
0 26 26 1 27 1 31 29
 */