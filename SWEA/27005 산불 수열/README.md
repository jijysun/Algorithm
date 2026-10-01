# 문제 소개

문제 사이트 링크

다음과 같은 양 정수 수열 A 를 “산불 수열” 이라고 정의한다.

- A[0] = 1, A[1] = 1 이다.
- i ≥ 2에 대해서, A[i]는 모든 양의 정수에 대해 { A[i-2k], A[i-k], A[i] } 가 등차수열을 이루지 않는 최소의 수 A[i]  이다.
- 즉, A[i] - A[i-k] ≠ A[i-k] - A[i-2k] 를 만족해야 한다.

산불 수열의 n번 항을 계산해 보자.

**[입력]**

첫 번째 줄에 테스트 케이스의 수 TC가 주어진다. 이후 TC개의 테스트 케이스가 새 줄로 구분되어 주어진다. 각 테스트 케이스는 다음과 같이 구성되었다.

- 첫 번째 줄에 정수 n이 주어진다. (0 ≤ n ≤ 1000)

**[출력]**

각 테스트 케이스 마다 한 줄씩, 문제의 정답을 출력하라.

**입력/출력 예씨**

```java
5
0
1
5
8
100

1
1
2
4
4
```

---

# 풀이 과정

- 변수 및 라이브러리 사용 이유
- 조건부 해석 이유

```cpp

#include <bits/stdc++.h>

using namespace std;
// https://www.acmicpc.net/problem/2564

int x, y, store, answer;
vector<int> deg;

int tc;

void input() {
    cin >> tc ;

    for (int i = 0; i < tc; i++) {
        int x;
        cin >> x ;
        deg.push_back(x);
    }
}

void solution() {

    // a[5]는 k<=2에 대해
    // a[5-2k], a[5-k], a[5] 가 등차 수열을 이루지 않아야 한다
    // a[5] - a[5-k] != a[5-k] -a[5-2k]

    // 수열의 규칙을 알아야 하는데, 너무 설명이...

    /*
     * 0
     * 1
     *
     *
     *
     * 2
     *
     *
     * 4
     * ...
     *
     */

    for (int i = 0; i < tc; i++) {

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input(), solution();
    return 0;
}
```

---

# 결과 & 근거

- 실패했다
- 전형적인 DP 문제인 것 같은데, 점화식 이해에서 막혔다..
  - 식 풀이를 하려고 직접 필기를 하는 게 빨랐을 듯 싶다.

### 알고리즘 분류

-