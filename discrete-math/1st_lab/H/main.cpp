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

int main() {
    kek();

    int n;
    cin >> n;
    string ans = "";
    if (n != 1) {
        for (int i = 0; i < n - 1; i++) {
            ans += "(";
        }
    }
    ans += "((A0|B0)|(A0|B0))";
    for (int i = 1; i < n; i++) {
        string num = to_string(i);
        ans = "(" + ans;
        string AorB = "((A" + num + "|A" + num + ")|(B" + num + "|B" + num + "))";
        ans += "|" + AorB + ")|(A" + num + "|B" + num + "))";
    }
    cout << ans;

    return 0;
}