#include <bits/stdc++.h>
using namespace std;

// https://www.acmicpc.net/problem/2156

int graph;
int arr [10002];

void input() {

    cin >> graph;

    for (int i = 0 ; i < graph; i++) {
        cin >> arr[i];
    }

}

void solution() {

    int dp=0, cnt = 0;


    for (int i = 0 ; i<graph-1; i++) { // 첫 번째도 고려해야 할 것 같음.
        if (cnt == 2) {
            cnt = 0;
            continue;
        }

        if (/*cnt ==  &&*/ dp+arr[i] > dp-arr[i]+arr[i+1]) {
            dp+=arr[i], cnt++;
            // printf("더합니다: %d -> dp: %d\n", arr[i], dp);
        }

    }

    // 끝부분 처리
    if (cnt < 2) {
        dp += arr[graph-1];
        printf("더합니다: %d -> dp: %d\n", arr[graph-1], dp);
    }
    cout << dp << '\n';

}


int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    input(), solution();

    /*
     * 포도주 잔: 일렬, 1~n 만큼의 포도주가 들어있음.
     * 1. 마신 후 원래 위치
     * 2. 위치가 연속되는 3잔을 모두 마실 수는 없다.
     * = 가장 많은 포도주를 마셔야 한다.
     */

    /*
     * 생각나는 것: DP, 배낭, 그리디
     *
     * dp [i] = i 잔 까지의 최대 마실 수 있는 포도잔 량 -> max (i-1 까지 다 마심, )
     */


}