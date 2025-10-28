# 3013 부분 수열의 중앙값 (실패)

# 문제 소개

[문제 사이트 링크](https://www.acmicpc.net/problem/3013)

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞힌 사람 | 정답 비율 |
| --- | --- | --- | --- | --- | --- |
| 1 초 | 128 MB | 983 | 398 | 325 | 45.904% |

## 문제

1부터 N까지 자연수 N개로 이루어진 수열 A가 있다. 각 자연수는 수열에서 한 번씩만 등장한다.

A의 부분 수열은 A의 앞과 뒤에서 숫자를 제거해서 만들 수 있다.

길이가 홀수이면서 중앙값이 B인 A의 부분 수열의 개수를 구하는 프로그램을 작성하시오. 중앙값이란 크기 순으로 수열을 정렬했을 때, 가운데에 있는 숫자이다. 예를 들어, {5, 1, 3}의 중앙값은 3이다.

## 입력

첫째 줄에 N과 B가 주어진다. (1 ≤ N ≤ 100,000, 1 ≤ B ≤ N)

둘째 줄에는 수열 A의 원소가 공백으로 구분되어서 주어진다.

## 출력

첫째 줄에 중앙값이 B인 A의 부분 수열의 개수를 출력한다.

---

# 초기 접근 방법

- 뭔가 수열의 길이을 넓혀가면서 중앙값을 구한다 생각되어 슬라이딩 윈도우 개념으로 접근하였다.
    - 무조건 중앙값이 주어지는 B 이어야 하므로 윈도우에 B가 포함되어야 한다.
    - B를 기준으로 양옆 길이을 넓혀가며 수열을 만든다.
    - 이후 만든 수열에 대해 검사 → 작은 값, 큰 값 각 개수가 동일인지 확인한다.

---

# 풀이 과정

```cpp
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

```

---

# 결과 & 근거

- 뭔가 알고리즘 적으로는? 맞긴 했지만 시간 초과하였다.
    - 아마 데이터가 커지면서 일일이 접근 + 검사한다는 점에서 엄청난 시간 분석도를 뱉을 것이다.
- 어차피 수열이므로 다른 아이디어를 빨리 접근했으나, 실패했다…
    - 각 구간에 대해 누적합을 구하고, O(1) 시간에 접근
    - 해당 누적 합 / 윈도우 한 몫이 B이어야 한다.
    - 이런 로직을 짰으나, 누적합을 구하는 알고리즘을 구현하다 끝났다.

https://measurezero.tistory.com/289

- 처음 접근한 아이디어가 꽤 좋았는데, 나쁜 시간분석도 로직으로 작성했던 것 같다.

### 알고리즘 분류

- 누적합