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

int n;
ifstream fin;
ofstream fout;

vector<int> next_partition(vector<int> &prefix) {
    if (n <= 2) {
        return vector<int>{2};
    }
    int size = prefix.size();
    prefix[size - 1]--;
    prefix[size - 2]++;
    if (prefix[size - 2] > prefix[size - 1]) {
        prefix[size - 2] += prefix[size - 1];
        prefix.resize(n - 1);
    } else {
        while (2 * prefix[size - 2] <= prefix[size - 1]) {
            int cur = prefix[size - 1] - prefix[size - 2];
            prefix[size - 1] = prefix[size - 2];
            prefix.push_back(cur);
        }
    }
    return prefix;
}

void print(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        if (i != v.size() - 1) {
            fout << v[i] << "+";
        } else {
            fout << v[i];
        }
    }
}

int main() {
    kek();

    fin.open("nextpartition.in");
    fout.open("nextpartition.out");
    string s;
    fin >> s;
    int pos = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '=') {
            int c = s[i] - '0';
            n = n * 10 + c;
        } else {
            pos = i;
            break;
        }
    }
    vector<int> prefix;
    int number = 0;
    for (int i = pos + 1; i < s.size(); i++) {
        if (s[i] != '+') {
            int c = s[i] - '0';
            number = number * 10 + c;
        } else {
            prefix.push_back(number);
            number = 0;
        }
    }
    prefix.push_back(number);
    if (prefix.size() == 1) {
        fout << "No solution";
        return 0;
    }
    fout << s.substr(0, pos + 1);
    print(next_partition(prefix));

    return 0;
}