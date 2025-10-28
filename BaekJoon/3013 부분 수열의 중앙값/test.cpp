#include <bits/stdc++.h>
using namespace std;

/*
 * https://www.acmicpc.net/problem/3013
 * Median value of partial sequence
 */

int N, B, idx=0; // B = 중앙값

int seq [100001];
vector<int> new_seq2;

int sol=1;

void input() {

    cin >> N >> B;

    for (int i = 0; i<N; i++) {
        cin >> seq[i];
        if (seq[i] == B) idx = i;
    }
}

void sol2 () {
    // 뭔가 누적합을 구해서 빠른 접근?
    // idea: 누적합 / 길이 = 몫이 seq[idx1] 일때 ++?
    // 근데 누적합을 어떻게 빨리 구하지 -> 차피 수열이니 약간 그런 느낌으로 pair <start, end> = 합 이런 식으로 개빠른 접근이 필요
    for (int i = 0; i<N; i++) {
        for (int j = 0; j <N; j++) {
            // sum

        }
    }
}

void solution() {

    // 해당 B를 기준으로 슬라이딩 윈도우
    int i = 1;
    while (2*i+1 <= N) {

        int size = 2*i;
        for (int j = 0; j<=size; j++) {
            int start = idx - (size-j), end = idx+j;
            if (start < 0 || end >N-1) { // 배열 벗어나면 스킵
                continue;
            }

            // 이렇게 일일이 접근하면 시간 내로 풀 수 있나?
            int left = 0, right = 0;
            for (int k = start; k<=end; k++) {
                if (seq[idx] < seq[k]) {
                    right++;
                }
                else if (seq[idx] > seq[k]) {
                    left ++;
                }
            }

            if (left == right) {
                /*for (int k = start; k<=end; k++) {
                    cout << seq[k] << " " ;
                }
                cout << '\n';*/
                sol++;
            }
        }
        i++;
    }
    cout << sol << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    input();
    solution();
}