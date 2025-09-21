#include <algorithm>
#include <iostream>
#include <valarray>
#include <vector>

/**
 * 17951, I felt my rating in the flurry of test papers
 * https://www.acmicpc.net/problem/17951
 */

using namespace std;

int N, K, START= 2000000, END;
vector<int> arr;

void input () {
    cin >> N >> K;

    arr = vector<int>(N);

    for (int i = 0; i<N; i++) {
        cin >> arr[i];
        if (START > arr[i]) START = arr[i];
        END += arr[i];
    }
}

void solution(int start, int end) {
    int mid, sum, groupCnt;
    while (start <= end) {
        mid = (start+end)/2, sum=0, groupCnt = 0;

        for (int i = 0; i<N; i++) {
            sum += arr[i];

            if (mid <= sum) { // 그룹을 만들 수 있는 조건 충족!
                sum = 0, groupCnt++;
            }
        }

        printf("start: %d, mid = %d, end: %d  (groupCnt: %d)\n", start, mid, end, groupCnt);

        if (K <= groupCnt) start = mid+1;
        else end = mid-1;
    }

    cout << end << '\n';
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    input ();

    solution(START, END);

    return 0;
}