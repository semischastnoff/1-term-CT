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
    cin.tie(nullptr);
    cout.tie(nullptr);
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

int main() {
    kek();

    int n;
    cin >> n;
    stack s;
    stack cnt;
    ll ans = 0;
    int num = 1;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (s.isEmpty()) {
            s.add(x);
        } else {
            if (x == s.get()) {
                num++;
            } else {
                cnt.add(num);
                num = 1;
                if (cnt.get() >= 3) {
                    for (int j = 0; j < cnt.get(); j++) {
                        ans++;
                        s.pop();
                    }
                    cnt.pop();
                    if (x == s.get()) {
                        num = cnt.pop() + 1;
                    }
                }
            }
            s.add(x);
        }
    }
    if (num >= 3) {
        for (int j = 0; j < num; j++) {
            ans++;
            s.pop();
        }
    }
    cout << ans;

    return 0;
}
