#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>

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

    int n;
    cin >> n;
    stack<int> st;
    int minn = 1;
    stack<int> min_prev;
    min_prev.push(1e9);
    vector<string> ans;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.push(x);
        ans.emplace_back("push");
        if (x < min_prev.top() && x != minn) {
            min_prev.push(x);
            //cout << min_prev << endl;
        }
        if (x == minn) {
            while (!st.empty() && st.top() == minn) {
                int last = st.top();
                st.pop();
                minn++;
                ans.emplace_back("pop");
                if (!min_prev.empty() && last == min_prev.top()) {
                    min_prev.pop();
                }
            }
            if (minn == min_prev.top()) {
                cout << "impossible";
                return 0;
            }
        }
    }
    for (const auto& x : ans) {
        cout << x << '\n';
    }

    return 0;
}

/*
6
3 4 2 1 5 6
 */