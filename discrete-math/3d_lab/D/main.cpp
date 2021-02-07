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

void mtf(vector<char> & v, int ind) {
    while (ind != 0) {
        swap(v[ind - 1], v[ind]);
        ind--;
    }
}

int main() {
    kek();

    string s;
    cin >> s;
    vector<char> alphabet;
    for (char & i : s) {
        if (find(all(alphabet), i) == alphabet.end()) {
            alphabet.push_back(i);
        }
    }
    sort(all(alphabet));
    for (char & i : s) {
        auto it = find(all(alphabet), i);
        int ind = distance(alphabet.begin(), it);
        cout << ind + 1 << " ";
        mtf(alphabet, ind);
        /*
        for (auto x : alphabet) {
            cout << x;
        }
        cout << endl;
        */
    }

    return 0;
}
