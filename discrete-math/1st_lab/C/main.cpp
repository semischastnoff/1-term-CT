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

int depth = 0;

string resizeBin(string s, int len) {
    int cnt = len - s.size();
    string res = s;
    while (cnt > 0) {
        res = '0' + res;
        cnt--;
    }
    return res;
}

string toBin(ll x) {
    string res;
    while (x) {
        res = to_string(x % 2) + res;
        x /= 2;
    }
    return res;
}

void dfs(int u, int height, vector<vector<int>> &tree) {
    if (height > depth) {
        depth = height;
    }
    for (int v : tree[u]) {
        dfs(v, height + 1, tree);
    }
}

void solution() {
    int n;
    cin >> n;
    vector<vector<int>> tree(n), input(n);
    vector<vector<bool>> func(n);
    vector<int> m(n);
    int leaves = 0;
    for (int i = 0; i < n; i++) {
        cin >> m[i];
        if (m[i] == 0) {
            leaves++;
        } else {
            for (int j = 0; j < m[i]; j++) {
                int x;
                cin >> x;
                input[i].push_back(--x);
                tree[x].push_back(i);
            }
            reverse(all(input[i]));
            int len = 1 << m[i];
            for (int j = 0; j < len; j++) {
                int x;
                cin >> x;
                func[i].push_back(x);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (m[i] == 0) {
            dfs(i, 0, tree);
        }
    }

    cout << depth << endl;

    int size = 1 << leaves;
    for (int val = 0; val < size; val++) {
        int ind = leaves - 1;
        vector<bool> ans(n);
        for (int i = 0; i < n; i++) {
            if (m[i] == 0) {
                string value = resizeBin(toBin(val), ind);
                int el = 1 << ind;
                //cout << " - " << toBin(val) << " " << toBin(el) << endl;
                ans[i] = val & el;
                ind--;
            } else {
                int k = 0, num = 0;
                for (int v : input[i]) {
                    int el = ans[v] << num;
                    //cout << " + " << toBin(k) << " " << toBin(el) << endl;
                    k = k | el;
                    num++;
                }
                ans[i] = func[i][k];
            }
        }
        cout << ans[n - 1];
    }
}

int main() {
    kek();

    solution();

    return 0;
}

/*
5
0
0
2 1 2
1 1 0 1
0
2 3 4
1 0 0 1
 */