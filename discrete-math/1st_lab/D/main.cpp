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

void getNeg(vector<vector<int>> &ans, int n, int ind) {
    for (int i = 0; i < n; i++) {
        ans.push_back({1, i + 1});
    }
}

int main() {
    kek();

    int n;
    cin >> n;
    int len = 1 << n;
    vector<vector<bool>> elem(len, vector<bool> (n, 0));
    vector<bool> f(len, 0);
    vector<vector<int>> ans;
    vector<int> clause_ind;
    bool constZero = true;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            if (c == '1') {
                elem[i][j] = 1;
            }
        }
        char c;
        cin >> c;
        if (c == '1') {
            f[i] = 1;
            constZero = false;
        }
    }
    int last_pos = 2 * n;
    if (constZero) {
        cout << n + 2 << '\n';
        cout << 1 << " " << 1 << '\n';
        cout << 2 << " " << 1 << " " << n + 1;
    } else {
        getNeg(ans, n, last_pos);
        //cout << " + " << last_pos << endl;
        for (int i = 0; i < len; i++) {
            if (f[i]) {
                int element;
                if (elem[i][0]) {
                    element = 0;
                } else {
                    element = n;
                }
                for (int j = 1; j < n; j++) {
                    if (elem[i][j]) {
                        ans.push_back({2, element + 1, j + 1});
                        /*
                        cout << " - " << element << endl;
                        cout << " -- " << 2 << " " << element + 1 << " " << j + 1 << endl;
                         */
                    } else {
                        ans.push_back({2, element + 1, j + 1 + n});
                        /*
                        cout << " - " << element << endl;
                        cout << " -- " << 2 << " " << element + 1 << " " << j + 1 + n << endl;
                         */
                    }
                    element = last_pos;
                    last_pos++;
                }
                clause_ind.push_back(last_pos);
            }
        }
        int element = clause_ind[0] - 1;
        for (int i = 1; i < clause_ind.size(); i++) {
            ans.push_back({3, element + 1, clause_ind[i]});
            element = last_pos;
            last_pos++;
        }

        cout << ans.size() + n << '\n';
        for (auto line : ans) {
            for (auto x : line) {
                cout << x << " ";
            }
            cout << '\n';
        }
    }

    return 0;
}

/*
3
000 0
001 0
010 0
011 0
100 0
101 0
110 0
111 0
 */