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

struct deque {
    vector<int> deq;
    int size = deq.size();

    void push_back(int x) {
        deq.push_back(x);
    }

    int pop_back() {
        int ans = deq[deq.size() - 1];
        deq.resize(deq.size() - 1);
        return ans;
    }

    int pop_front() {
        int ans = deq[0];
        for (int i = 0; i < deq.size() - 1; i++) {
            deq[i] = deq[i + 1];
        }
        deq.resize(deq.size() - 1);
        return ans;
    }

    int front() {
        return deq[0];
    }

    int size_before(int x) {
        int ans = 0;
        for (int i : deq) {
            if (i != x) {
                ans++;
            } else {
                return ans;
            }
        }
    }
};

int main() {
    kek();

    int n;
    cin >> n;
    deque d;
    for (int i = 0; i < n; i++) {
        int fl;
        cin >> fl;
        if (fl == 1) {
            int x;
            cin >> x;
            d.push_back(x);
        } else if (fl == 2) {
            d.pop_front();
        } else if (fl == 3) {
            d.pop_back();
        } else if (fl == 4) {
            int x;
            cin >> x;
            cout << d.size_before(x) << endl;
        } else if (fl == 5) {
            cout << d.front() << endl;
        }
    }

    return 0;
}
