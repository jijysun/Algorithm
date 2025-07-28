#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int n, a_cnt = 0, b_cnt = 0, min_b_count = INT_MAX;
string s;

int main() {
    cin >> s;

    int n = s.length();

    for (char c : s) {
        if (c == 'a')
            a_cnt++;
    }

    s += s;

    for (int i = 0; i < n; i++) {
        int j =i + a_cnt-1;

        for (int k = i; k <= j; k++) {
            if (s[k] == 'b') {
                b_cnt++;
            }
        }
        min_b_count = min(b_cnt, min_b_count);
        b_cnt = 0;
    }

    cout << min_b_count << '\n';
}