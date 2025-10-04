#include <bits/stdc++.h>
using namespace std;

/*
 * https://www.acmicpc.net/problem/11722
 * Longest decreasing partial sequence
 */

// double a, b;

int n;
vector<int> arr;
pair<int, int> dp [1001];

void input() {
    cin >> n;
    arr = vector<int> (n);
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }
}

void solution() {
    if (n == 1) {
        cout << 1 << '\n';
        return;
    }

    int max_sqe_size=0;
    dp[n-1] = {arr[n-1], 1};

    for (int i = n-2; i>=0; i--) {
        int pos=i, sqe_size = 1;

        for (int j=i; j<n; j++) {
            if (arr[pos] -1 == 0) { // 더이상 감소 불가능.
                break;
            }
            if (arr[pos] > arr[j]) {
                if (j+1<n && arr[j] <= arr[j+1]  && arr[j+1] < arr[pos] ) {
                    continue;
                }
                pos = j; sqe_size++;
            }
        }

        // int max_ele = * max_element(arr.begin()+i, arr.end());
        dp[i] = {arr[i], sqe_size};

        int pre = 0;
        for (int j = i; j<n; j++) {
            if (arr[i] > dp[j].first, sqe_size < dp[j].second) {
                pre = dp[j].second;
            }
        }

        max_sqe_size = max(max(sqe_size, pre+1), max_sqe_size);
        // cout << sqe_size << '\n';
    }

    cout << /*"\n------\n" <<*/ max_sqe_size << '\n';

}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    input();
    solution();
}