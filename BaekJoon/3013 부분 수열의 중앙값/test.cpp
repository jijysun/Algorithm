#include <bits/stdc++.h>
using namespace std;

/*
 * https://www.acmicpc.net/problem/3013
 * Median value of partial sequence
 */

int N, B, idx=0; // B = �߾Ӱ�

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
    // ���� �������� ���ؼ� ���� ����?
    // idea: ������ / ���� = ���� seq[idx1] �϶� ++?
    // �ٵ� �������� ��� ���� ������ -> ���� �����̴� �ణ �׷� �������� pair <start, end> = �� �̷� ������ ������ ������ �ʿ�
    for (int i = 0; i<N; i++) {
        for (int j = 0; j <N; j++) {
            // sum

        }
    }
}

void solution() {

    // �ش� B�� �������� �����̵� ������
    int i = 1;
    while (2*i+1 <= N) {

        int size = 2*i;
        for (int j = 0; j<=size; j++) {
            int start = idx - (size-j), end = idx+j;
            if (start < 0 || end >N-1) { // �迭 ����� ��ŵ
                continue;
            }

            // �̷��� ������ �����ϸ� �ð� ���� Ǯ �� �ֳ�?
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