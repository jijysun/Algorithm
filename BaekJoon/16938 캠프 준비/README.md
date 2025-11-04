# 16938 캠프 준비 (성공?)

# 문제 소개

[문제 사이트 링크](https://www.acmicpc.net/problem/16938)

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞힌 사람 | 정답 비율 |
| --- | --- | --- | --- | --- | --- |
| 2 초 | 512 MB | 5642 | 3911 | 3003 | 69.289% |

## 문제

알고리즘 캠프를 열려면 많은 준비가 필요하다. 그 중 가장 중요한 것은 문제이다. 오늘은 백준이를 도와 알고리즘 캠프에 사용할 문제를 고르려고 한다.

백준이는 문제를 N개 가지고 있고, 모든 문제의 난이도를 정수로 수치화했다. i번째 문제의 난이도는 Ai이다.

캠프에 사용할 문제는 두 문제 이상이어야 한다. 문제가 너무 어려우면 학생들이 멘붕에 빠지고, 문제가 너무 쉬우면 학생들이 실망에 빠지게 된다. 따라서, 문제 난이도의 합은 L보다 크거나 같고, R보다 작거나 같아야 한다. 또, 다양한 문제를 경험해보기 위해 가장 어려운 문제와 가장 쉬운 문제의 난이도 차이는 X보다 크거나 같아야 한다.

캠프에 사용할 문제를 고르는 방법의 수를 구해보자.

## 입력

첫째 줄에 N, L, R, X가 주어진다.

둘째 줄에는 문제의 난이도 A1, A2, ..., AN이 주어진다.

## 출력

캠프에 사용할 문제를 고르는 방법의 수를 출력한다.

## 제한

- 1 ≤ N ≤ 15
- 1 ≤ L ≤ R ≤ 10⁹
- 1 ≤ X ≤ 10⁶
- 1 ≤ A ≤ 10⁶

- 예제들
    
    ## 예제 입력 1
    
    ```
    3 5 6 1
    1 2 3
    
    ```
    
    ## 예제 출력 1
    
    ```
    2
    
    ```
    
    2번, 3번 문제를 고르는 방법, 모든 문제를 고르는 방법이 가능하다.
    
    ## 예제 입력 2
    
    ```
    4 40 50 10
    10 20 30 25
    
    ```
    
    ## 예제 출력 2
    
    ```
    2
    
    ```
    
    난이도가 10, 30인 문제를 고르거나, 20, 30인 문제를 고르면 된다.
    
    ## 예제 입력 3
    
    ```
    5 25 35 10
    10 10 20 10 20
    
    ```
    
    ## 예제 출력 3
    
    ```
    6
    ```
    

---

# 초기 접근 방법

- 모든 경우의 수를 고려해야 한다!!!!!!!!
    - 브루트포스 알고리즘으로 검색

그리고 조합의 수가 필요하다

- 백트래킹으로 조합의 수를 검색한다,
- 애초에 N이 15라 시간적으로도 충분하다.

---

# 풀이 과정

- 변수 및 라이브러리 사용 이유
- 조건부 해석 이유

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
 * https://www.acmicpc.net/problem/16938
 * prepare camping
 */

int n, L, R, x, cnt = 0;

vector<int> problem;

void input () {
    cin >> n >> L >> R >> x;

    problem = vector<int>(n);

    for (int i = 0; i <n; i++) { // 난이도 입력
        cin >> problem[i];
    }
    // L <= 문제 난이도 합 <= R
    // max (난이도) - min (난이도) >= x

}
void combination(vector<int> arr, bool visited [], int start, int n, int r) {
    if (r == 0) {
        vector<int> new_arr;

        for (int i = 0; i<n; i++) {
            if (visited[i]) {
                // cout << arr[i] << ' ';
                new_arr.push_back(arr[i]);
            }
        }
        // cout << endl;

        int min_ele = * min_element(new_arr.begin(),new_arr.end());
        int max_ele = * max_element(new_arr.begin(),new_arr.end());

        int diff = max_ele- min_ele, difficulty=0;

        for (int j : new_arr) {
            difficulty+=j;
        }

        // cout <<"diff: " << diff << ", difficulty: " << difficulty << '\n';
        // cout << "L: " << L << ", R: " << R << '\n';

        if ((L <= difficulty && difficulty <= R) && diff >= x ) {
            // cout << "cnt ++ \n";
            cnt ++;
        }

        return;
    }

    for (int i = start; i < n; i++) {
        visited[i] = true;
        combination(arr, visited, i + 1, n, r - 1);
        visited[i] = false;
    }
}

void solution() {

    // 캠프에 사용할 문제를 고르는 방법의 수를 출력한다.

    // 경우의 수 == 브루트포스

    /*
     * 1. N만큼 입력된 문제 난이도 정렬
     * 2. O(N^2) 만큼 순회 + 누적하면서 경우의 수 ++?
     */

    for (int i = 2; i <=n; i++) {
        bool visited[16] = {false};
        // cout << n  << " 개 중에서 "  << i  <<  " 개 뽑기" << '\n';
        combination(problem, visited,0, n, i);
    }

    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    input();
    solution();
}

```

---

# 결과 & 근거

- 좀 헤맸는데 성공했다.
    - 소신발언 하자면 조합 알고리즘만 알면 되는 어엄청 쉬운 문제이다
    - 고해성사 하면 조합 알고리즘은 참고하였다….
- https://studywithus.tistory.com/114

### 알고리즘 분류

- 브루트포스 알고리즘
- 비트마스킹
- 백트래킹