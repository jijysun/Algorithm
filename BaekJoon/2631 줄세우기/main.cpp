#include <bits/stdc++.h>

using namespace std;
// https://www.acmicpc.net/problem/2631

int n, arr [201], dp [201];

void input() {

    cin >> n;

    for (int i =0; i < n; i++) {
        cin >> arr[i];
    }
}

void solution() {

    // 최장 증가 수열 문제 == dp 문제이다.

    /*
     * 최장 수열 애들은 고정 시키고, 나머지는 대충 교환하면 되는 문제이다.
     * = 입력 받은 n - 고정된 애들
     */

    int max_switch = 0;

    for (int i =0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j<i; j++) {
            if (arr[i] > arr[j] && dp[j]+1 > dp[i]) {
                dp[i] = dp[j]+1;
                max_switch = max(max_switch, dp[i]);
            }
        }
    }

    cout << n - max_switch << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input(), solution();
    return 0;
}