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

bool isOne(vector<int> &x) {
    int cnt = 0;
    for (int i : x) {
        if (i != -1) {
            cnt++;
        }
    }
    return (cnt == 1);
}

bool ifClause(vector<vector<int>> &x, int k, int n) {
    for (int dis = 0; dis < k; dis++) {
        if (isOne(x[dis])) {
            return true;
        }
    }
    return false;
}

vector<int> makeEmpty(vector<int> &x) {
    for (int & i : x) {
        i = -1;
    }
    return x;
}

int main() {
    kek();

    int n, k;
    bool ans = false;
    cin >> n >> k;
    vector<vector<int>> x(k, vector<int> (n, 0));
    for (int dis = 0; dis < k; dis++) {
        for (int i = 0; i < n; i++) {
            cin >> x[dis][i];
        }
    }

    while (ifClause(x, k, n)) {
        for (int dis = 0; dis < k; dis++) {
            if (isOne(x[dis])) {
                for (int i = 0; i < n; i++) {
                    if (x[dis][i] == 1) {
                        for (int elem = 0; elem < k; elem++) {
                            if (x[elem][i] == 1) {
                                x[elem] = makeEmpty(x[elem]);
                            } else if (x[elem][i] == 0) {
                                if (isOne(x[elem])) {
                                    ans = true;
                                    //cout << " + " << ans << endl;
                                }
                                x[elem][i] = -1;
                            }
                        }
                    } else if (x[dis][i] == 0) {
                        for (int elem = 0; elem < k; elem++) {
                            if (x[elem][i] == 0) {
                                x[elem] = makeEmpty(x[elem]);
                            } else if (x[elem][i] == 1) {
                                if (isOne(x[elem])) {
                                    ans = true;
                                    //cout << " - " << ans << endl;
                                }
                                x[elem][i] = -1;
                            }
                        }
                    }
                }
            }
        }
    }

    if (ans) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}

/*
3 3
1 0 -1
0 1 0
-1 0 1

2 4
1 0
0 -1
0 1
1 -1
 */
