#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <deque>

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
    deque<int> first_half, second_half;
    for (int i = 0; i < n; i++) {
        char fl;
        cin >> fl;
        if (fl == '+') {
            int x;
            cin >> x;
            if (first_half.empty() && second_half.empty()) {
                first_half.push_back(x);
            } else {
                if (first_half.size() >= second_half.size()) {
                    second_half.push_back(x);
                } else {
                    while (first_half.size() < second_half.size() && !second_half.empty()) {
                        int val = second_half.front();
                        first_half.push_back(val);
                        second_half.pop_front();
                    }
                    second_half.push_back(x);
                }
            }
        } else if (fl == '*') {
            int x;
            cin >> x;
            int size = first_half.size() + second_half.size();
            while (first_half.size() < second_half.size() && !second_half.empty()) {
                int val = second_half.front();
                first_half.push_back(val);
                second_half.pop_front();
            }
            if (size % 2 == 0) {
                first_half.push_back(x);
            } else {
                second_half.push_front(x);
            }
        } else if (fl == '-') {
            if (first_half.empty()) {
                    while (first_half.size() < second_half.size() && !second_half.empty()) {
                        int val = second_half.front();
                        first_half.push_back(val);
                        second_half.pop_front();
                    }
            }
            cout << first_half.front() << '\n';
            first_half.pop_front();
            if (!second_half.empty() && first_half.size() < second_half.size()) {
                first_half.push_back(second_half.front());
                second_half.pop_front();
            }
        }
    }

    return 0;
}

/*
7
+ 1
+ 2
+ 3
* 4
-
-
-
 */