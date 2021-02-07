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

bool checkTrans(vector<vector<int>> &a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int h = 0; h < n; h++) {
                if (a[i][h] == 1 && a[h][j] == 1) {
                    if (a[i][j] == 0) {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

bool checkRef(vector<vector<int>> &a, int n) {
    for (int i = 0; i < n; i++) {
        if (a[i][i] != 1) {
            return 0;
        }
    }
    return 1;
}

bool checkARef(vector<vector<int>> &a, int n) {
    for (int i = 0; i < n; i++) {
        if (a[i][i] == 1) {
            return 0;
        }
    }
    return 1;
}

bool checkSym(vector<vector<int>> &a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != a[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

bool checkASym(vector<vector<int>> &a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 1 && a[j][i] == 1 && i != j) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    kek();

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int> (n, 0)), b(n, vector<int> (n, 0)), c(n, vector<int> (n, 0));
    vector<int> ans_a(5), ans_b(5);
    int cnt_r_a = 0, cnt_r_b = 0;
    //ввод
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b[i][j];
        }
    }
    //рефлексивность
    ans_a[0] = (int) checkRef(a, n);
    ans_b[0] = (int) checkRef(b, n);
    ans_a[1] = (int) checkARef(a, n);
    ans_b[1] = (int) checkARef(b, n);
    //симметричность
    ans_a[2] = (int) checkSym(a, n);
    ans_b[2] = (int) checkSym(b, n);
    ans_a[3] = (int) checkASym(a, n);
    ans_b[3] = (int) checkASym(b, n);
    //транзитивность
    ans_a[4] = (int) checkTrans(a, n);
    ans_b[4] = (int) checkTrans(b, n);
    //композиция
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int h = 0; h < n; h++) {
                if (a[i][h] == 1 && b[h][j] == 1) {
                    c[i][j] = 1;
                }
            }
        }
    }
    //ответ
    for (auto x : ans_a) {
        cout << x << " ";
    }
    cout << '\n';
    for (auto x : ans_b) {
        cout << x << " ";
    }
    cout << '\n';
    for (auto line : c) {
        for (auto x : line) {
            cout << x << " ";
        }
        cout << '\n';
    }

    return 0;
}