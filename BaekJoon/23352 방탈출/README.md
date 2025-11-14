# 23352 방탈출 (실패)

# 문제 소개

[문제 사이트 링크](https://www.acmicpc.net/problem/23352)

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞힌 사람 | 정답 비율 |
| --- | --- | --- | --- | --- | --- |
| 1 초 | 512 MB | 1794 | 848 | 686 | 48.584% |

## 문제

여러 방들로 둘러싸인 구역을 탈출해야 한다. 알맞은 비밀번호를 입력하면 탈출할 수 있다.

구역의 지도는 N * M 크기의 격자판으로 나타낼 수 있으며 각 칸은 방을 의미하고 각 칸에는 0부터 9까지의 숫자가 적혀있는데 이는 해당하는 방에 적힌 숫자를 의미한다.

상하좌우 4가지 방향으로만 움직일 수 있으며, 0이 적힌 방은 들어갈 수 없다.

비밀번호의 힌트는 다음과 같다.

1. 임의의 방에서 다른 방으로 이동할 때는 항상 두 방 사이의 최단 경로로 이동한다.
2. 1번을 만족하는 경로 중 가장 긴 경로의 시작 방과 끝 방에 적힌 숫자의 합

만약 위 2가지 조건을 만족하는 경로가 여러 개라면, 시작 방과 끝 방에 적힌 숫자의 합이 가장 큰 값이 비밀번호가 된다.

시작 방과 끝 방은 동일한 위치일 수도 있다.

<예시> 5 * 5 형태의 지도가 주어질 때, 위의 2가지 조건을 만족하는 경로는 다음과 같다.

[](https://upload.acmicpc.net/9b335e35-1fb0-494d-b517-a0480eb097a9/-/preview/)

이 때 비밀번호가 무엇인지를 구해라.

만약 비밀번호를 만들 수 없는 경우 0을 출력한다.

## 입력

첫줄에 지도의 세로 크기 N ( 1≤ N ≤ 50), 가로 크기 M (1≤ M ≤ 50)이 공백을 두고 주어진다.

둘째 줄부터 N줄에 걸쳐 각 방들의 정보 A(0 ≤ A ≤9)가 공백을 두고 주어진다.

## 출력

올바른 비밀번호를 출력한다.

---

# 초기 접근 방법

- 최단 경로는 BFS다! 라는 것을 최근에 접근했었던 적이 있어 바로 BFS
- 방 탈출 조건이 도대체 어떻게 되먹은 거…?
    - 위에서 아래? 이렇게만 가면 되나?

---

# 풀이 과정

```cpp
#include <bits/stdc++.h>
using namespace std;

int n, m;
int room[51][51];

int room_sum, a_d; // start, end, depth

vector<int> dx = {0, 0, 1};
vector<int> dy = {-1, 1, 0};

void input() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> room[i][j];
        }
    }
}

void bfs(int start, int end, bool visited[51][51]) {
    // queue

    queue<pair<int, int> > q;
    q.push({start, end});
    visited[start][end] = true;

    while (!q.empty()) {
        pair<int, int> pos = q.front();
        q.pop();

        cout << "pos: " << pos.first << "," << pos.second << '\n';

        for (int i = 0; i < 3; i++) {
            pair<int, int> next = {pos.first + dx[i], pos.second + dy[i]};

            if (next.first < 0 || next.first >= n || next.second < 0 || next.second >= m ) {
                continue;
            }

            if (room[next.first][next.second] && !visited[next.first][next.second]) {
                q.push({next.first, next.second});
                visited[next.first][next.second] = true;
            }
            else if (next.first == n-1) {
                // depth 측정할 수 있어야 함!
                int depth = abs(start - next.first) + abs(end - next.second);

                if (a_d < depth) {
                    printf("end! start (%d,%d): %d, end(%d,%d): %d, depth: %d\n", start, end, room[start][end], next.first, next.second,  room[next.first][next.second], depth);
                    room_sum = room[start][end] + room[next.first][next.second];
                }
                else if (a_d == depth && room_sum < room[start][end] + room[next.first][next.second]) {
                    printf("end! start (%d,%d): %d, end(%d,%d): %d, depth: %d\n", start, end, room[start][end], next.first, next.second,  room[next.first][next.second], depth);
                    room_sum = room[start][end] + room[next.first][next.second];
                }
            }
        }
    }
}

void solution() {
    // 가장 긴 경로
    // 탈출 하려면 위 -> 아래인가?

    /*
     * 문제의 핵심: 가장 긴 경로를 찾는 BFS 구현하기.
     */

    room_sum= 0, a_d = 0;

    for (int i = 0; i < m; i++) {
        if (room[0][i]) {
            cout << "---- start -> " << 0 << "," << i << "---\n";
            bool visited[51][51] = {false};
            bfs(0, i, visited);
            cout << "--- end ---- \n";
        }
    }
    cout << room_sum <<'\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    input();
    solution();
}

```

---

# 결과 & 근거

- 뭔가 코드적으로는 다 적었지만 실패했다.
- 문제가 불친절한 건지, 내가 이해를 못한 건지, 비밀번호를 구하는 조건에 대해 너무 고민하느라 낭비했던 것 같다.
    - 더 정확히는 모든 테두리 방에서 시작해서 방 끝 으로 나가되,
    - 최장 경로의 시작 방 + 끝 방을 구하면 되는 것이었다.

https://hello-backend.tistory.com/134

### 알고리즘 분류

- 그래프 이론
- 브루트포스 알고리즘
- 그래프 탐색, 너비 우선 탐색