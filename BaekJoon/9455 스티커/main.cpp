#include <bits/stdc++.h>

using namespace std;

int n, m;

int sticker [2][100001];
int side_max [100001]; // 한 행만 봐도 되니까

void solution();


void input() {

    // 한 스티커를 쓰면 상하좌우 스티커는 못씀
    // 이런 상황에서 뗄 수 있는 스티커의 최대값,


    cin >> n ;

    for (int i = 0; i < n; i++) {
        cin >> m;
        for (int j = 0; j<2; j++) {
            for (int k = 0; k<m; k++) {
                cin >> sticker[j][k];
            }
        }
        solution();
    }


}

void solution() {



    // dp 이면서 저번에 풀었던 비슷한 문제.
    // 각 끝을 미리 정해서 큰 값 정하고, 비교?



    // m 이 홀수 짝수에 따라 달라지나?
    /*
     * 홀수: 한 줄을 무조건 버려야 함. -> 어떻게? ->  각 홀수 자리 vs 짝수 자리
     * 짝수: 모든 경우의 수
     */

    // 건너뛸 수 있는 조건. ->



    int pre_max = max (sticker[0][0], sticker[1][0]); // 첫 번쨰 행을 버리냐
    int max_index = 0, max_sum = pre_max;


    for (int i = 1; i<m-1 ; i++) {
        // 현재보다 양 옆 큰 값을 고르는 게 더 낫다면?
        int cur_max = max (sticker[0][i], sticker[1][i]);
        int next_max = max (sticker[0][i+1], sticker[1][i+1]);

        if (pre_max + next_max > cur_max) {
            max_index = i;
            max_sum = pre_max + next_max;
        }

        pre_max = cur_max;
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input(), solution();
    return 0;
}
