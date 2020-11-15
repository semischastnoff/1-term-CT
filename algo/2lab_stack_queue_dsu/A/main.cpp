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

const ll INF = 1e10;

vector<ll> stack;
vector<ll> minn;

void add(ll x) {
    stack.push_back(x);
    if (x <= minn[minn.size() - 1]) {
        minn.push_back(x);
    }
}

ll pop() {
    ll ans = stack[stack.size() - 1];
    stack.resize(stack.size() - 1);
    if (ans == minn[minn.size() - 1]) {
        minn.resize(minn.size() - 1);
    }
    return ans;
}

ll getMin() {
    return minn[minn.size() - 1];
}

int main() {
    kek();

    ll n;
    cin >> n;
    minn.push_back(INF);
    for (ll i = 0; i < n; i++) {
        int fl;
        cin >> fl;
        if (fl == 1) {
            ll x;
            cin >> x;
            add(x);
        } else if (fl == 2) {
            pop();
        } else if (fl == 3) {
            cout << getMin() << '\n';
        }
    }

    return 0;
}

/*
5
1 -4
1 -4
3
2
3
 */