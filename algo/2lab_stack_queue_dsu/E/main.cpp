#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
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

struct stack {
    vector<ll> st;

    void add(ll x) {
        st.push_back(x);
    }

    ll pop() {
        ll ans = st[st.size() - 1];
        st.resize(st.size() - 1);
        return ans;
    }

    ll get() {
        return st[st.size() - 1];
    }

    bool isEmpty() const {
        return (st.empty());
    }

    void print() {
        for (auto x : st) {
            cout << x << " ";
        }
        cout << endl;
    }
};

ll to_ll(string s) {
    ll res = s[0] - '0';
    for (int i = 1; i < s.size(); i++) {
        res = res * 10 + (s[i] - '0');
        //cout << " - " << res << endl;
    }
    return res;
}

int main() {
    kek();

    string c;
    stack s;
    while (cin >> c) {
        if (c == "+") {
            ll x = s.pop();
            ll y = s.pop();
            s.add(x + y);
        } else if (c == "-"){
            ll x = s.pop();
            ll y = s.pop();
            s.add(y - x);
        } else if (c == "*"){
            ll x = s.pop();
            ll y = s.pop();
            s.add(x * y);
        } else {
            s.add(to_ll(c));
        }
        //s.print();
    }
    cout << s.get();

    return 0;
}
