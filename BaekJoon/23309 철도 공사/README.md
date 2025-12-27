# 23309 철도 공사 (실패)

# 문제 소개

[문제 사이트 링크](https://www.acmicpc.net/problem/23309)

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞힌 사람 | 정답 비율 |
| --- | --- | --- | --- | --- | --- |
| 2 초 (추가 시간 없음) | 512 MB (추가 메모리 없음) | 5069 | 1080 | 731 | 23.377% |

## 문제

[](https://upload.acmicpc.net/19a8adca-5e60-48c7-91f2-b3a285366a5d/-/preview/)

연세대학교가 위치한 신촌역이 속한 2호선은 그림과 같이 N개의 역이 원형으로 연결되어 있다. 각 역은 고유 번호가 할당돼 있으며 역들의 고유 번호는 서로 다르다. 그리고 특정 역의 다음 역은 시계 방향으로 인접한 역을 의미하고, 이전 역은 반시계 방향으로 인접한 역을 의미한다.

2호선은 지하철 노선들 중 유일한 흑자 노선이다. 때문에 2호선 공사 자금이 넉넉하기에 M번의 공사를 거치려고 한다. 각 공사는 다음 4가지 중 하나를 시행한다.

- 고유 번호 i를 가진 역의 다음 역의 고유 번호를 출력하고, 그 사이에 고유 번호 j인 역을 설립한다.
- 고유 번호 i를 가진 역의 이전 역의 고유 번호를 출력하고, 그 사이에 고유 번호 j인 역을 설립한다.
- 고유 번호 i를 가진 역의 다음 역을 폐쇄하고 그 역의 고유 번호를 출력한다.
- 고유 번호 i를 가진 역의 이전 역을 폐쇄하고 그 역의 고유 번호를 출력한다.

이 때, 이미 설립한 역은 다시 설립하지 않으며 폐쇄한 역은 다시 설립될 수 있다. 그리고 폐쇄 작업은 현재 설립된 역이 2개 이상일 때만 들어온다.

2호선을 공사하는 프로그램을 만들어보자.

## 입력

첫 번째 줄에 공사를 시작하기 이전에 있는 역의 개수를 나타내는 양의 정수 N과 공사 횟수를 나타내는 양의 정수 M이 주어진다. (1 ≤ N ≤ 500,000, 1 ≤ M ≤ 1,500,000)

두 번째 줄에는 공사를 시작하기 이전에 있는 역의 고유 번호를 시계 방향 순서대로 주어진다. 같은 고유 번호를 가진 역은 주어지지 않는다.

이후 M개의 줄에 걸쳐서 공사에 대한 정보를 다음과 같이 주어진다.

- `BN` i j : 고유 번호 i를 가진 역의 다음 역의 고유 번호를 출력하고, 그 사이에 고유 번호 j인 역을 설립한다.
- `BP` i j : 고유 번호 i를 가진 역의 이전 역의 고유 번호를 출력하고, 그 사이에 고유 번호 j인 역을 설립한다.
- `CN` i : 고유 번호 i를 가진 역의 다음 역을 폐쇄하고 그 역의 고유 번호를 출력한다.
- `CP` i : 고유 번호 i를 가진 역의 이전 역을 폐쇄하고 그 역의 고유 번호를 출력한다.

입력으로 들어오는 모든 역의 고유 번호는 1 이상 1\,000\,000 이하의 양의 정수다. 폐쇄 작업은 현재 설립된 역이 2개 이상일 때만 들어오며, 이미 설립된 역은 또 설립될 수 없지만 폐쇄된 역은 다시 설립될 수 있다.

## 출력

각 공사에 대한 출력 값을 M개의 줄에 걸쳐서 출력한다.

## 예제 입력 & 출력

```
4 4
2 7 3 5
BN 5 11
BP 3 6
CP 2
CN 7

```

```
2
7
11
6
```

---

# 초기 접근 방법

- 모든 역이 연결되어 있다. 혹시 모를 그래프를 생각하긴 했다.
- 그래프 적으로 접근하나, 모든 역이 순환되어 연결된다는 느낌에 포기.
- 근데 양방향으로 접근 가능한 연결 리스트로써 구현이 가능하단 생각에 이 방식으로 접근했다.

---

# 풀이 과정

- 구조체 구현과 배열을 통해 pre, cur, next로 각 역을 표현하였다.

```cpp

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, m, i, j;

struct station {
    int pre, cur, next;
};

vector<station> arr(0);

map<int, int> hashStation;

void input() {
    cin >> n >> m;
    string s;

    for (int i1 = 0; i1 < n; i1++) {
        station temp;

        cin >> temp.cur;
        hashStation[temp.cur] = i1;

        arr.push_back(temp);
    }

    // connect
    for (int i = 1; i < n - 1; i++) {
        arr[i].pre = arr[i - 1].cur, arr[i].next = arr[i + 1].cur;
    }
    arr[0].pre = arr[n - 1].cur, arr[0].next = arr[1].cur;
    arr[n - 1].pre = arr[n - 2].cur, arr[n - 1].next = arr[0].cur;

    /*
     * BN, BP: 리스트 사이에 끼워넣는다.
     * CP, CN: 리스트 이전, 다음 값을 삭제한다.
     *
     * 그 즉슨, 일반 알고리즘으로 구현하면 데이터 이동에 대한 시간 초과가 발생한다.
     * 양방향 연결 리스트 느낌으로 구현해야 한다.
     * struct 배열?
     */

    for (int i1 = 0; i1 < m; i1++) {
        cin >> s;

        // 고유 번호 어떻게 이렇게 빨리 찾지?
        // map을 도입해야 하나?
        // map[i] = arr의 인덱스?   j는 상관 없어.

        if (s == "BN") {
            // i에 대한 다음 역 고유 번호 출력 + 다음 역 설립
            cin >> i >> j;
            int cur_index = hashStation[i];

            cout << arr[cur_index].next << '\n';

            station temp;
            temp.cur = j, temp.pre = arr[cur_index].cur, temp.next = arr[cur_index].next;
            arr.push_back(temp);

            int nextStation = hashStation[arr[cur_index].next];
            arr[nextStation].pre = j;

            arr[cur_index].next = j;

            hashStation[j] = arr.size() - 1;
        } else if (s == "BP") {
            cin >> i >> j;
            int cur_index = hashStation[i];

            cout << arr[cur_index].pre << '\n';

            station temp;
            temp.cur = j, temp.pre = arr[cur_index].pre, temp.next = arr[cur_index].cur;
            arr.push_back(temp);

            // 현재 역의 이전 역 갱신
            int preStation = hashStation[arr[cur_index].pre];
            arr[preStation].next = j;
            arr[cur_index].pre = j;

            hashStation[j] = arr.size() - 1;
        } else if (s == "CP") {
            cin >> i;
            int cur_index = hashStation[i];
            // 이전 역 폐쇄

            station temp = arr[hashStation[arr[cur_index].pre]];

            cout << temp.cur << '\n';

            int pre_index = hashStation[temp.cur];
            int pre_pre_index = hashStation[arr[pre_index].pre];

            arr[pre_pre_index].next = arr[cur_index].cur;
            arr[cur_index].pre = arr[pre_pre_index].cur;
        } else if (s == "CN") {
            cin >> i;
            int cur_index = hashStation[i];
            // 다음 역 폐쇄

            station closeStation = arr[hashStation[arr[cur_index].next]];

            cout << closeStation.cur << '\n';

            int next_index = hashStation[arr[cur_index].next];
            int next_next_index = hashStation[arr[next_index].next];

            arr[next_next_index].pre = closeStation.pre;
            arr[cur_index].next = closeStation.next;
        }

        /*for (int j = 0; j<arr.size(); j++) {
            printf("%d <- %d -> %d\t", arr[j].pre, arr[j].cur, arr[j].next);
        }
        printf("\n");*/
    }
}

void solution() {
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    input(), solution();
    return 0;
}

```

---

# 결과 & 근거

- 일단 주어진 예제에 대해서는 통과했으나, 시간 초과로 실패하였다.
    - 2초이기도 했기도 했다.
    - 지금의 코드를 분석하면 N, M의 입력에 약 O(2백만) 을 사용하고, 이후 각 역에 대한 접근은 O(1) 정도 시간을 소모한다.
    - 어디서 시간 초과가 되었는지는 잘 모르겠따….
- Gemini 의 답변
    - map이 항상 무적인 건 아니다.
    - **`std::map`의 오버헤드**
    - 현재 `hashStation`으로 `std::map<int, int>`을 사용하고 계십니다.
    - `std::map`은 **Red-Black Tree** 구조로, 삽입과 탐색에 $O(\log N)$이 걸립니다.
    - 이 문제의 $N$과 $M$은 각각 최대 **1,000,000**과 **2,000,000**입니다. 수백만 번의 $O(\log N)$ 연산은 생각보다 매우 무겁습니다.
    - **해결책:** 역 번호의 범위가 1부터 1,000,000까지이므로, `map` 대신 **크기가 1,000,001인 일반 배열**을 사용하여 $O(1)$로 인덱스에 접근해야 합니다.
- 즉 이또한 배열로 접근해야 한다.

### 알고리즘 분류

- 구현
- 자료 구조
- 연결 리스트