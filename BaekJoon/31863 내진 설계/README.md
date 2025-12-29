# 31863 내진 설계 (성공)

# 문제 소개

[문제 사이트 링크](https://www.acmicpc.net/problem/31863)

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞힌 사람 | 정답 비율 |
| --- | --- | --- | --- | --- | --- |
| 1 초 | 512 MB | 594 | 358 | 289 | 64.080% |

## 문제

오늘 새벽, 갑자기 규모 5.0 지진이 발생했다. 지진이 발생한 진원지는 N * M 격자 모양의 지역 중 한 곳이다. 진원지에서 발생한 지진을 본진, 건물이 무너졌을 때 발생하는 약한 지진을 여진이라고 하자. 본진은 진원지를 기준으로 상하좌우 각 방향으로 2칸까지 뻗어나가며, 여진은 상하좌우로 1칸까지 뻗어나간다. 본진과 여진은 건물에 영향을 준다. 내진 설계가 되어 있지 않은 건물은 지진이 도달한 즉시 무너지지만, 내진 설계가 되어 있는 건물은 지진이 2번 도달하면 무너진다. 본진과 여진이 뻗어나가는 도중 지진 방파제를 만나거나 격자 모양의 지역 밖으로 나가면 더 이상 뻗어나가지 않는다. 예제1에 대한 지진의 이동은 아래와 같다.

![image.png](image.png)

빠른 재해 복구를 위해 지진의 피해를 확인하고자 한다. 지진으로 인해 무너진 건물의 개수와 무너지지 않은 건물의 개수를 구해보자.

## 입력

첫째 줄에 정수 N과 M이 공백으로 구분되어 주어진다.

둘째 줄부터 N개의 줄에 걸쳐 길이 M의 문자열이 주어진다. 문자열을 이루는 문자는 아래 5종류이며, 진원지는 1개만 주어진다.

- `@`: 진원지
- `.`: 일반 도로
- `*`: 내진 설계가 되어있지 않은 건물
- `#`: 내진 설계가 되어있는 건물
- `|`: 방파제

## 출력

무너진 건물의 개수와 무너지지 않은 건물의 개수를 공백으로 구분하여 한 줄에 출력한다.

## 예제 입력 1

```
5 6
*.*...
..||..
..@*|*
.*.*..
..*##.
-> 4 5
```

## 예제 입력 2

```
7 9
...#...#.
.*.*..*..
...*..#..
...**.*..
.*..*.@..
.#...**..
..#.#..*.
-> 10 8

```

---

# 초기 접근 방법

- 뭔가 “나야 그래프” 라는 느낌으로 엄청 대놓고 표현하고 있긴 하다.
- 여기서 그래프 탐색을 하긴 해야 하나, DFS나 BFS 까지 갈 필요가 있나 싶어 지진, 여진 그대로 2칸씩 1칸씩 비교했다.

---

# 풀이 과정

- 맨 처음에 진원지가 여러 개 주어진다 생각해서 잘 못 풀었다가 급하게 수정했다.
- 입력에서 건물을 더하고, 큐를 이용하여
    - 건물이 무너질 때 마다 push
    - 건물이 여진을 일으켜서 없어질 때 마다 pop 하는 식으로 했다.
- 진동이 내진 설계된 건물을 만났을 때 *, 내진 설계가 안된 건물로 바꾸어 다음 진동을 만날 때 무너지도록 하였다,

```cpp
#include <bits/stdc++.h>
using namespace std;

// https://www.acmicpc.net/problem/31863

int n, m;

char arr[1001][1001];

pair<int, int>  earthQuake;

vector<pair<int, int> > dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 상하좌우

int surviveBuilding = 0;
int collapsedbuilding =0;

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j]; // 공백/개행을 무시하고 한 글자씩 읽음
            if (arr[i][j] == '@') {
                earthQuake = {i, j};
            }
            else if (arr[i][j] == '*' || arr[i][j] == '#') {
                surviveBuilding++;
            }
        }
    }
}

void solution() {
    // 지진: 상하좌우 각 2칸
    // 여진: 상하좌우 1칸

    // 내진설계 X: 바로 0 으로 초기화
    // 내진설계 O: 1번 버티면 * 으로, 이후 다시 0으로

    queue<pair<int, int>> aftershock;

    // 진원지는 단 하나.
    for (int i = 0; i < 4; i++) {
        pair<int, int> n_e = {earthQuake.first + dir[i].first, earthQuake.second + dir[i].second};
        pair<int, int> nn_e = {
            earthQuake.first + dir[i].first + dir[i].first, earthQuake.second + dir[i].second + dir[i].second
        };
        if (arr[n_e.first][n_e.second] == '|') {
            // 맨처음 방파제 만나면 이후 스킵
            // 이후도 못감
            continue;
        }
        if (n_e.first >= 0 && n_e.first < n && n_e.second >= 0 && n_e.second < m) { // 배열 안에 있고, 건물을 접촉한 경우
            if (arr[n_e.first][n_e.second] == '*') {
                // 무너진 경우 여진 큐에 추가.
                aftershock.push({n_e.first, n_e.second});
                arr[n_e.first][n_e.second] = '!';
                surviveBuilding--, collapsedbuilding++;
            }
            else if (arr[n_e.first][n_e.second] == '#') { // 내진 설계는 감소
                arr[n_e.first][n_e.second] = '*';
            }
        }
        if (nn_e.first >= 0 && nn_e.first < n && nn_e.second >= 0 && nn_e.second < m) { // 배열 안에 있고, 건물을 접촉한 경우
            if (arr[nn_e.first][nn_e.second] == '*') {
                aftershock.push({nn_e.first, nn_e.second});
                arr[nn_e.first][nn_e.second] = '!';
                surviveBuilding--, collapsedbuilding++;
            }
            else if (arr[nn_e.first][nn_e.second] == '#') {
                arr[nn_e.first][nn_e.second] = '*';
            }
        }
    }

    // 여진 발생 큐가 빌 때 까지
    while (!aftershock.empty()) {
        pair<int, int> front = aftershock.front();
        aftershock.pop();

        for (int i = 0; i < 4; i++) {
            pair<int, int> n_e = {front.first + dir[i].first, front.second + dir[i].second};
            if (n_e.first >= 0 && n_e.first < n && n_e.second >= 0 && n_e.second < m) { // 배열 안에 있고,
                if (arr[n_e.first][n_e.second] == '*') { // 건물을 접촉한 경우
                    // 무너진 경우 여진 큐에 추가.
                    aftershock.push({n_e.first, n_e.second});
                    arr[n_e.first][n_e.second] = '!';
                    surviveBuilding--, collapsedbuilding++;
                }
                else if (arr[n_e.first][n_e.second] == '#') { // 내진 설계는 감소
                    arr[n_e.first][n_e.second] = '*';
                }
            }
        }
    }
    
    // 무너진 건물 + 무너지지 않은 건물의 개수 출력.
    cout << collapsedbuilding << " " << surviveBuilding << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    input(), solution();
}

```

---

# 결과 & 근거

- 맨날 틀리다가 갑자기 너무 쉽게 풀어서 당황했다.
- 아마 진원지 1개로 정확하게 보고 풀었다면 20분 컷을 낼 수 있었을 것이다.
- https://viin.tistory.com/216 → 더 좋은 해석과 깔끔한 설명

### 알고리즘 분류

- 구현
- 그래프 이론
- 그래프 탐색
- 시뮬레이션