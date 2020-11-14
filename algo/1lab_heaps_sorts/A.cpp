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

void algosiki() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

vector<ll> merge(vector<ll> &a, vector<ll> &b) {
    int n = a.size();
    int m = b.size();
    int i = 0, j = 0;
    vector<ll> c;
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            c.push_back(a[i]);
            i++;
        } else {
            c.push_back(b[j]);
            j++;
        }
    }
    while (i < n) {
        c.push_back(a[i]);
        i++;
    }
    while (j < m) {
        c.push_back(b[j]);
        j++;
    }
    return c;
}

vector<ll> merge_sort(vector<ll> &a) {
    int n = a.size();
    if (n <= 1) {
        return a;
    } else {
        int m = n / 2;
        vector<ll> al;
        vector<ll> ar;
        for (int i = 0; i < m; i++) {
            al.push_back(a[i]);
        }
        for (int i = m; i < n; i++) {
            ar.push_back(a[i]);
        }
        al = merge_sort(al);
        ar = merge_sort(ar);
        return merge(al, ar);
    }
}

int main() {
    algosiki();
    
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    a = merge_sort(a);
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }

    return 0;
}
