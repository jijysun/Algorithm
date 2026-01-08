# 17299 오등큰수 (실패)

# 문제 소개

문제 사이트 링크

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞힌 사람 | 정답 비율 |
| --- | --- | --- | --- | --- | --- |
| 1 초 | 512 MB | 23286 | 11133 | 8690 | 46.932% |

## 문제

크기가 N인 수열 A = A1, A2, ..., AN이 있다. 수열의 각 원소 Ai에 대해서 오등큰수 NGF(i)를 구하려고 한다.

Ai가 수열 A에서 등장한 횟수를 F(Ai)라고 했을 때, Ai의 오등큰수는 오른쪽에 있으면서 수열 A에서 등장한 횟수가 F(Ai)보다 큰 수 중에서 가장 왼쪽에 있는 수를 의미한다. 그러한 수가 없는 경우에 오등큰수는 -1이다.

예를 들어, A = [1, 1, 2, 3, 4, 2, 1]인 경우 F(1) = 3, F(2) = 2, F(3) = 1, F(4) = 1이다. A1의 오른쪽에 있으면서 등장한 횟수가 3보다 큰 수는 없기 때문에, NGF(1) = -1이다. A3의 경우에는 A7이 오른쪽에 있으면서 F(A3=2) < F(A7=1) 이기 때문에, NGF(3) = 1이다. NGF(4) = 2, NGF(5) = 2, NGF(6) = 1 이다.

## 입력

첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다. 둘째에 수열 A의 원소 A1, A2, ..., AN (1 ≤ Ai ≤ 1,000,000)이 주어진다.

## 출력

총 N개의 수 NGF(1), NGF(2), ..., NGF(N)을 공백으로 구분해 출력한다.

## 예제 1

```
7
1 1 2 3 4 2 1
-> -1 -1 1 2 2 1 -1
```

---

# 초기 접근 방법

- 뭔가 차례대로 접근해야 한다는 생각에 DP 가 떠올랐다.
- 그리고 그렇다라는 알고리즘이 딱히 생각나지 않았다.

---

# 풀이 과정

```cpp
#include <bits/stdc++.h>

using namespace std;
// https://www.acmicpc.net/problem/17299

int n;
vector<int>arr;

int checking[1000001];

stack<int>s;

void solution();

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
        checking[x]++;
        s.push(x);
    }
}

void solution() {

        /*
         * 문제
         * - 내 기준 우측에 있는 모든 큰 수를 확인해야 한다.
         * - upper bound로 빠르게 탐색할 수 있나? -> 정렬이 필요 = x
         * - 뭔가 이분 탐색이 필요한데
         *
         * 삽입 하면서 할 수 있나?
         * 근데 지금 보면 해당 되는 오등큰수를 모두 출력 중.
         *
         */

    stack<int>s;
    s.push(checking[arr[arr.size()-1]]);
    for (int i = n-2;  i>=0; i--) {

        int checkingNum = checking[arr[i]];
        while (!s.empty() && checkingNum >= checking[s.top()]) { // 등장 횟수 크고, 가장 왼쪽
            s.pop();
        }

        if (s.empty()) {
            // print용 변수에 -1 추가
        }
        else {
            // print용 변수에 stack.top 추가
        }
        s.push(arr[i]);
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

- DP로 풀고 싶었으나, 어쩔 수 없이 2중 for문을 삽입해야 한다.
- 그럼 O(n^2) 으로 시간초과가 발생하므로, DP는 아니라는 생각에 빠른 포기를 했다.
- 또한 문제를 좀 잘못 읽었다.
    - 오등큰수가 등장 횟수가 많은 수 중 가장 왼쪽의 수가 아닌, 모든 수를 구해야 한다 생각했다…
- 정답은 스택
    - LIFO 성질을 이용하는 것이다.
    - 오등큰수가 등장하기만 하면, 반복문 순회를 멈추거나 [stack.top](http://stack.top)() 이용하여 오등큰수를 출력하면 되는 것이다.
- https://non-stop.tistory.com/89

### 알고리즘 분류

- 자료구조
- 스택