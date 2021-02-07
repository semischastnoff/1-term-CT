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

    map<string, int> code;
    string s;
    cin >> s;
    for (char i = 97; i < 123; i++) {
        string val;
        val += i;
        code.insert({val, i - 'a'});
    }
    int last_code = 25;
    string t;
    t += s[0];
    for (int i = 1; i < s.size(); i++) {
        if (code.find(t + s[i]) != code.end()) {
            t += s[i];
        } else {
            cout << code[t] << " ";
            last_code++;
            code.insert({t + s[i], last_code});
            t = s[i];
        }
    }
    cout << code[t];
    /*
    for (auto x : code) {
        cout << x.first << " " << x.second << endl;
    }
     */

    return 0;
}
