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

int max_len = 0;
int n;
vector<vector<int>> operations;

string toBin(ll x) {
    string res;
    while (x) {
        res = to_string(x % 2) + res;
        x /= 2;
    }
    return res;
}

int get_number(vector<int> &x, string oper) {
    if (oper.size() != 0) {
        oper += ' ';
        int res = x[oper[0] - 1];
        int i = 1;
        while (i < oper.size() - 2) {
            int next_el = x[oper[i + 1] - 1];
            if (oper[i] == '&') {
                if (oper[i + 1] == '~') {
                    next_el = ~x[oper[i + 2] - 1];
                    cout << "func " << next_el << endl;
                    i++;
                }
                res &= next_el;
                i++;
            }
            i++;
        }
    } else {
        return 1;
    }
}

string resizeBin(string x) {
    int cnt = max_len - x.size();
    while (cnt > 0) {
        x = '0' + x;
        cnt--;
    }
    return x;
}

int main() {
    kek();

    cin >> n;
    vector<ll> x(n);
    vector<string> bin_x;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        string bin = toBin(x[i]);
        int len = bin.size();
        bin_x.push_back(bin);
        if (len > max_len) {
            max_len = len;
        }
    }
    ll s;
    cin >> s;
    string number = toBin(s);
    for (int i = 0; i < n; i++) {
        bin_x[i] = resizeBin(bin_x[i]);
    }
    /*
    for (auto el : bin_x) {s
        cout << el << endl;
    }
    cout << number << endl;
     */
    if (number.size() > max_len) {
        cout << "Impossible";
        return 0;
    }
    number = resizeBin(number);
    if (s == 0) {
        cout << "1&~1";
        return 0;
    }
    string res;
    string ans;
    ll func_res = 0;
    set<string> used;
    for (int i = 0; i < number.size(); i++) {
        if (number[i] == '1') {
            ll clause_res;
            if (bin_x[0][i] == '0') {
                clause_res = ~x[0];
                res.append("~1");
                //cout << " - " << res << endl;
            } else {
                clause_res = x[0];
                res.append("1");
                //cout << " -- " << res << endl;
            }
            for (int ind = 1; ind < n; ind++) {
                if (bin_x[ind][i] == '0') {
                    clause_res = clause_res & (~x[ind]);
                    res.append("&~" + to_string(ind + 1));
                    //cout << " --- " << res << endl;
                } else {
                    clause_res = clause_res & (x[ind]);
                    res.append("&" + to_string(ind + 1));
                    //cout << " ---- " << res << endl;
                }
            }
            func_res = func_res | clause_res;
            if (ans.size() != 0) {
                ans.append("|");
            }
            ans.append("(");
            ans.append(res);
            ans.append(")");
            res = "";
        }
        if (func_res == s) {
            cout << ans;
            return 0;
        }
    }
    if (func_res == s) {
        cout << ans;
    } else {
        cout << "Impossible";
    }

    return 0;
}

/*
4
13 8 15 38
34

4
5 6 8 9
12

5
45 87 23 76 90
86

5
16 17 18 19 20
5
 */