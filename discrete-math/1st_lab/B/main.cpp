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

//correct
bool isLinear(vector<bool> &f, vector<vector<bool>> &x, int n) {
    int len = 1 << n;
    int q = x[0].size();
    vector<vector<bool>> cf(len);
    vector<bool> jeg(len);
    cf[0] = f;
    jeg[0] = cf[0][0];
    for (int i = 1; i < len; i++) {
        for (int j = 0; j < cf[i - 1].size() - 1; j++) {
            bool f1 = cf[i - 1][j], f2 = cf[i - 1][j + 1];
            cf[i].push_back(f1 xor f2);
        }
        jeg[i] = cf[i][0];
    }

    for (int i = 0; i < len; i++) {
        int cnt = 0;
        for (int j = 0; j < q; j++) {
            if (x[i][j] == 1) {
                cnt++;
            }
        }
        if (jeg[i] == 1 && cnt > 1) {
            return 0;
        }
    }
    return 1;
}

//correct
bool isSelfDual(vector<bool> &f, int n) {
    if (n == 0) {
        return 0;
    }
    int len = 1 << n;
    for (int i = 0; i < len; i++) {
        if (f[i] == f[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

//correct
bool isMono(vector<bool> &f, vector<vector<bool>> &x, int n) {
    int len = 1 << n;
    if (n == 0) {
        return 1;
    }
    for (int d = 0; d < len; d++) {
        for (int i = d; i < len; i++) {
            bool fl = 1;
            for (int j = 0; j < n; j++) {
                if (x[d][j] > x[i][j]) {
                    fl = 0;
                }
            }
            if (f[d] > f[i] && fl) {
                return 0;
            }
        }
    }
    return 1;
}

bool isZero(vector<bool> &f) {
    if (f[0] != 0) {
        return 0;
    }
    return 1;
}

bool isOne(vector<bool> &f) {
    if (f[f.size() - 1] != 1) {
        return 0;
    }
    return 1;
}

int main() {
    kek();

    int n;
    cin >> n;
    vector<bool> isPost(n);
    for (int t = 0; t < n; t++) {
        int q;
        cin >> q;
        int len = 1 << q;

        //получение таблицы истинности
        vector<vector<bool>> x(len, vector<bool> (q, 0)); //таблица истинности для переменных
        for (int i = 0; i < len; i++) {
            //получение значений переменных
            int ind = q - 1;
            int num = i;
            vector<bool> line(q);
            while (num) {
                line[ind] = (bool) (num % 2);
                num /= 2;
                ind--;
            }
            x[i] = line;
        }
        vector<bool> f(len, 0);
        for (int i = 0; i < len; i++) {
            char c;
            cin >> c;
            if (c == '1') {
                f[i] = 1;
            }
        }
        if (!isZero(f)) {
            isPost[0] = 1;
        }
        if (!isOne(f)) {
            isPost[4] = 1;
        }
        if (!isSelfDual(f, q)) {
            isPost[1] = 1;
        }
        if (!isMono(f, x, q)) {
            isPost[2] = 1;
        }
        if (!isLinear(f, x, q)) {
            isPost[3] = 1;
        }
        /*
        cout << isZero(f) << " " << isOne(f) << " " << isSelfDual(f, q) << " " << isMono(f, x, q) << " " << isLinear(f, x, q);
        cout << endl;
        */
    }
    bool fl = true;
    for (int i = 0; i < 5; i++) {
        if (!isPost[i]) {
            fl = false;
            break;
        }
    }

    if (fl) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}

/*
16
2 0000
2 0001
2 0010
2 0011
2 0100
2 0101
2 0110
2 0111
2 1000
2 1001
2 1010
2 1011
2 1100
2 1101
2 1110
2 1111
*/