#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <fstream>

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

int n, k;
vector<string> gray;
ifstream fin;
ofstream fout;

void gen() {
    if (gray[0].size() == n) {
        return;
    }
    int pos = gray.size();
    for (int i = 1; i < k; i++) {
        if (i % 2 != 0) {
            for (int j = pos - 1; j >= 0; j--) {
                gray.push_back(gray[j] + to_string(i));
            }
        } else {
            for (int j = 0; j < pos; j++) {
                gray.push_back(gray[j] + to_string(i));
            }
        }
    }
    for (int i = 0; i < pos; i++) {
        gray[i] += '0';
    }
    gen();
}

int main() {
    kek();

    fin.open("telemetry.in");
    fout.open("telemetry.out");
    fin >> n >> k;
    for (int i = 0; i < k; i++) {
        gray.push_back(to_string(i));
    }
    gen();
    for (auto x : gray) {
        fout << x << '\n';
    }

    return 0;
}
