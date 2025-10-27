# 19638 센티와 마법의 뿅망치 (실패)

# 문제 소개

[문제 사이트 링크](https://www.acmicpc.net/problem/19638)

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞힌 사람 | 정답 비율 |
| --- | --- | --- | --- | --- | --- |
| 1 초 | 1024 MB | 6548 | 2290 | 1784 | 34.341% |

## 문제

센티는 마법 도구들을 지니고 여행을 떠나는 것이 취미인 악당이다.

거인의 나라에 도착한 센티는 자신보다 키가 크거나 같은 거인들이 있다는 사실이 마음에 들지 않았다.

센티가 꺼내 들은 마법 도구는 바로 마법의 뿅망치로, 이 뿅망치에 맞은 사람의 키가 ⌊뿅망치에 맞은 사람의 키 / 2⌋로 변하는 마법 도구이다. 단, 키가 1인 경우 더 줄어들 수가 없어 뿅망치의 영향을 받지 않는다.

하지만 마법의 뿅망치는 횟수 제한이 있다. 그래서 센티는 마법의 뿅망치를 효율적으로 사용하기 위한 전략을 수립했다. 바로 매번 가장 키가 큰 거인 가운데 하나를 때리는 것이다.

과연 센티가 수립한 전략에 맞게 마법의 뿅망치를 이용한다면 거인의 나라의 모든 거인이 센티보다 키가 작도록 할 수 있을까?

## 입력

첫 번째 줄에는 센티를 제외한 거인의 나라의 인구수 *N* (1 ≤ *N* ≤ 10^5)과 센티의 키를 나타내는 정수 H*centi* (1 ≤ H*centi* ≤ 2 × 10^9), 마법의 뿅망치의 횟수 제한 *T* (1 ≤ *T* ≤ 10^5)가 빈칸을 사이에 두고 주어진다.

두 번째 줄부터 *N*개의 줄에 각 거인의 키를 나타내는 정수 *H* (1 ≤ *H* ≤ 2 × 10^9)가 주어진다.

## 출력

마법의 뿅망치를 센티의 전략대로 이용하여 거인의 나라의 모든 거인이 센티보다 키가 작도록 할 수 있는 경우, 첫 번째 줄에 `YES`를 출력하고, 두 번째 줄에 마법의 뿅망치를 최소로 사용한 횟수를 출력한다.

마법의 뿅망치를 센티의 전략대로 남은 횟수 전부 이용하고도 거인의 나라에서 센티보다 키가 크거나 같은 거인이 있는 경우, 첫 번째 줄에 `NO`를 출력하고, 두 번째 줄에 마법의 뿅망치 사용 이후 거인의 나라에서 키가 가장 큰 거인의 키를 출력한다.

---

# 초기 접근 방법

- 뭔가 항상 쉬울 때 마다 불안하긴 한데, 리스트를 사용하여 매번 정렬해서 최대값만 고려하는 방식으로 작성해봤다.
- 그러다가 뭔가 우선순위 큐가 더 효율적이라 생각되어 변경하였다.

---

# 풀이 과정

- 변수 및 라이브러리 사용 이유
- 조건부 해석 이유

```cpp
#include <iostream>
#include <queue>
#include <functional>    // greater, less
using namespace std;

int n; // 1 ~ 100000
int height;  // 1~ 2 * 1,000,000,000
int hammer_cnt; // 1 ~ 100000

priority_queue<int> pq;

void input() {
    cin >> n >> height >> hammer_cnt;

    for (int i = 0; i<n; i++) { // 애초에 센티보다 작은 키들은 버릴까..
        int giant_height;
        cin >> giant_height;
        if (height <= giant_height) { // 그래도 모든 경우가 다 크다는 전제 하에
            pq.push(giant_height);
        }
    }
}

void solution() {
    int init = hammer_cnt;
    while (hammer_cnt > 0) {

        if (pq.top() < height) {
            cout << "YES\n" << init-hammer_cnt << '\n';
            return;
        }

        int top = pq.top();
        pq.pop();
        if (top/2 >= height) {
            pq.push(top/2);
        }

        if (pq.empty()) {
            int var = top/2 == 0 ? 1 : top/2;
            cout << "NO\n" << var << '\n';
            return;
        }

        // 출력용
        /*priority_queue<int> new_pq = pq;
        while (new_pq.size() != 0) {
            cout << new_pq.top() << " ";
            new_pq.pop();
        }
        cout << '\n';*/

        hammer_cnt -- ;
    }

    if (pq.top() < height || pq.empty()) { // 만약 모두 작아져서 출력 가능한 경우
        cout << "YES\n" << init - hammer_cnt << '\n';
    }
    else { // top 이 더 크거나, 큐가 비어있지 않은 경우
        cout << "NO\n" << pq.top() << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    input();
    solution();
    // cout << i;
    return 0;
}

```

---

# 결과 & 근거

- 결과는 실패… 쉬운 문제인데 틀린 게 좀 아쉽다.
- 뭔가 다른 반례가 있을 것이라 생각되어 이래저래 풀어봤지만 실패했다..
- 로직을 너무 복잡하게 생각했던 것 같다
    - 최고로 큰 거인이 나보다 작거나, 1이라는 거에 초점을 두고 풀면 쉬울 듯 하다.

### 알고리즘 분류

- 구현
- 자료 구조
- 우선순위 큐