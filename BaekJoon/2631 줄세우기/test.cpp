#include <bits/stdc++.h>
using namespace std;

/*
 * https://www.acmicpc.net/problem/2631
 * line-up
 */

int n; // 2~200

vector<int> kids(201);
int dp[201];

vector<int> answer;

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> kids[i];
    }
}


void solution() {
    /*
     * 스왚을 최소로 하는 알고리즘 (그리디? DP? 브루트포스?)
     * 어쨌든 이전 값을 계속해서 재활용하는 점이 DP?
     *
     * dp [i][j] = i 값을 j 로 옮겼을 때 ?
     * dp[i] = 1번 옮겼을 때의 최소 값? =
     *
     */

    // 근데 스왚 하고 자리 이동은 어떻게? 자료구조를 사용해야 하나?


    // 뭔가 설명하기는 어려운데 그런 느낌
    // 전체적으로 증가하는 수열? 에서
    // 중간에 넣을 수 있는 값이 존재하는 경우 끼워넣기
    // 없는 경우 중간 수열 안에서 불순물 제거하는 느낌으로,.
    /*while (true) {
        for (int i = 0; i < n; i++) {
            // 배열을 순회하면서 제일 길게 증가하는 수열을 어떻게 찾을 것인가? 범위 설정은 어떻게 할 것인가?
            // 이걸 찾는 게 핵심 요건 = 결국 DP 이네
            // 아니 그러면 그냥 한 번만 순회하면 되는 거 아냐?
        }
        break;
    }*/


    for (int j = 0; j<n; j++) {
        int pre = kids[j]; // pre 가 아닌, min 느낌이어야 해.
        dp[j] = 1;
        for (int i = j+1; i < n; i++) {

            if (pre < kids[i]) {
                // 이전 보다는 큰데, 바로 직전 값 보다 큰 경우
                if (kids[i] < kids[i - 1]) {
                    pre = kids[i];
                    dp[i]=dp[i-1];
                }
                else {
                    dp[i] = dp[i - 1] + 1;
                }
            }
            else {
                dp[i]=dp[i-1];
            }
            cout << "dp [" << i << "]: " << dp[i] << '\n';
        }
        cout << n - dp[n-1] << "\n\n\n";
    }
}


int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    input();
    solution();
}
