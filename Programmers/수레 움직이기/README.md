# 프로그래머스, 수레 움직이기 (실패)

# 문제 소개

[문제 사이트 하이퍼링크](https://school.programmers.co.kr/learn/courses/30/lessons/250134)

`n` x `m` 크기 격자 모양의 퍼즐판이 주어집니다.

퍼즐판에는 빨간색 수레와 파란색 수레가 하나씩 존재합니다. 각 수레들은 자신의 시작 칸에서부터 자신의 도착 칸까지 이동해야 합니다.

모든 수레들을 각자의 도착 칸으로 이동시키면 퍼즐을 풀 수 있습니다.

당신은 각 턴마다 **반드시 모든 수레를 상하좌우로 인접한 칸 중 한 칸으로 움직여야 합니다.** 단, 수레를 움직일 때는 아래와 같은 규칙이 있습니다.

- 수레는 벽이나 격자 판 밖으로 움직일 수 없습니다.
- 수레는 자신이 방문했던 칸으로 움직일 수 없습니다.
- 자신의 도착 칸에 위치한 수레는 **움직이지 않습니다.** 계속 해당 칸에 고정해 놓아야 합니다.
- 동시에 두 수레를 같은 칸으로 움직일 수 없습니다.
- 수레끼리 자리를 바꾸며 움직일 수 없습니다.

예를 들어, 아래 그림처럼 `n` = 3, `m` = 2인 퍼즐판이 있습니다.

![rb_horse1.jpg](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/2d21a258-144f-4d03-81c1-1a857a942efa/rb_horse1.jpg)

- 속이 빨간색인 원은 빨간색 수레를 나타냅니다.
- 속이 파란색인 원은 파란색 수레를 나타냅니다.
- 테두리가 빨간색인 원은 빨간색 수레의 도착 칸을 나타냅니다.
- 테두리가 파란색인 원은 파란색 수레의 도착 칸을 나타냅니다.

위 퍼즐판은 아래와 같은 순서로 3턴만에 풀 수 있습니다.

![rb_horse2.jpg](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/e1c81aa3-238b-4f0e-b21d-697903543b72/rb_horse2.jpg)

- 빨간색 사선이 처진 칸은 빨간색 수레가 방문했던 칸을 나타냅니다. 규칙에 따라 빨간색 수레는 빨간색 사선이 처진 칸(방문했던 칸)으로는 이동할 수 없습니다.
- 파란색 사선이 처진 칸은 파란색 수레가 방문했던 칸을 나타냅니다. 규칙에 따라 파란색 수레는 파란색 사선이 처진 칸(방문했던 칸)으로는 이동할 수 없습니다.

![rb_horse3.jpg](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/2b78f38c-121a-441c-90f9-704eb0642e96/rb_horse3.jpg)

- 위처럼 동시에 수레를 같은 칸으로 움직일 수는 없습니다.

퍼즐판의 정보를 나타내는 2차원 정수 배열 `maze`가 매개변수로 주어집니다. 퍼즐을 푸는데 필요한 턴의 최솟값을 return 하도록 solution 함수를 완성해 주세요. 퍼즐을 풀 수 없는 경우 0을 return 해주세요.

---

#### 제한사항

- 1 ≤ `maze`의 길이 (= 세로 길이) ≤ 4
    - 1 ≤ `maze[i]`의 길이 (= 가로 길이) ≤ 4
    - `maze[i][j]`는 0,1,2,3,4,5 중 하나의 값을 갖습니다.

| `maze[i][j]` | 의미 |
| --- | --- |
| 0 | 빈칸 |
| 1 | 빨간 수레의 시작 칸 |
| 2 | 파란 수레의 시작 칸 |
| 3 | 빨간 수레의 도착 칸 |
| 4 | 파란 수레의 도착 칸 |
| 5 | 벽 |
- 빨간 수레의 시작 칸, 빨간 수레의 도착 칸, 파란 수레의 시작 칸, 파란 수레의 도착 칸은 퍼즐판에 1개씩 존재합니다.

---

#### 입출력 예

| maze | result |
| --- | --- |
| [[1, 4], [0, 0], [2, 3]] | 3 |
| [[1, 0, 2], [0, 0, 0], [5, 0 ,5], [4, 0, 3]] | 7 |
| [[1, 5], [2, 5], [4, 5], [3, 5]] | 0 |
| [[4, 1, 2, 3]] | 0 |

---

#### 입출력 예 설명

**입출력 예 #1**

문제 예시와 같습니다.

**입출력 예 #2**

![rb_horse4.jpg](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/54629429-3bec-4288-a7b4-6303c0929880/rb_horse4.jpg)

7턴만에 퍼즐을 풀 수 있습니다. 다른 방법으로도 퍼즐을 풀 수 있지만 7턴보다 빠르게 풀 수는 없습니다.

**입출력 예 #3**

![rb_horse5.jpg](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/c6aed2ad-dbbf-477e-bac7-fd5cd44bad00/rb_horse5.jpg)

다음 턴에 파란색 수레가 파란색 수레의 도착 칸에 위치한 후 고정되어 빨간색 수레가 빨간색 수레의 도착 칸에 도착할 수 없게 됩니다.

퍼즐을 풀 수 없으므로 0을 return 해야 합니다.

**입출력 예 #4**

![rb_horse6.jpg](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/0ff7e955-77d6-4760-9e16-75cf2313fc0d/rb_horse6.jpg)

수레는 서로 위치를 바꾸면서 움직일 수 없으므로 퍼즐을 풀 수 없습니다. 따라서 0을 return 해야 합니다.

---

# 풀이 과정

- 격자 위에서 최소 이동 횟수를 구하는 문제라 BFS로 판단했다.
- 수레가 2대이므로 `visited`도 2개(`red_visit`, `blue_visit`), 큐도 2개(`red_q`, `blue_q`) 필요하다고 생각하고 동시에 돌리려 했다.
- 이동 금지 규칙을 먼저 주석으로 정리했다 — 벽/격자 밖(격자 경계 검사), 방문했던 칸(DFS나 BFS의 visited), 같은 칸 동시 진입 금지(한 탐색 안에서 주의할 점), 자리 교환 금지.
- 각 수레의 현 위치를 계속 들고 다녀야 하고 목적지까지의 최솟값을 반환해야 하니 BFS가 맞다고 봤다.
- 중간에 `visited`를 0/1이 아니라 **1로 초기화하고 값을 비교하면서** 채워야 하는 게 아닐까 싶었다. 「각 칸마다 각 수레가 갈 수 있는 최솟값을 저장해두는 방식? BFS 백트래킹?」까지 갔지만 정리하지 못했다.
- 결국 큐 2개를 동시에 굴리는 구조가 너무 복잡해져서 41분에 포기했다.

```cpp
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

/*
빨간 + 파란 수레 -> 각자의 도착칸으로!
- 수레는 벽이나 격자 판 밖으로 움직일 수 없습니다. -> 격자!
- 수레는 자신이 방문했던 칸으로 움직일 수 없습니다. -> DFS나 BFS
- 자신의 도착 칸에 위치한 수레는 움직이지 않습니다. 계속 해당 칸에 고정해 놓아야 합니다.
- 동시에 두 수레를 같은 칸으로 움직일 수 없습니다. -> 한 DFS 내 주의점!
- 수레끼리 자리를 바꾸며 움직일 수 없습니다. -> 당연
- 반드시 모든 수레를 상하좌우로 인접한 칸 중 한 칸으로 움직여야 합니다
*/

int red_visit[4][4], blue_visit[4][4];

int d_rx, d_ry, d_bx, d_by; // 목적지.

// 시계 방향, 상 우 하 좌
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
vector<vector<int>> m;

void bfs (int srx, int sry, int sbx, int sby){
    /*
    두 수레를 동시에 dfs
    - visited가 2개 필요 -> red, blue
    - 현 위치 기억이 필요
    - 목적지 까지의 최소값 return -> BFS?

    */
    int cnt = 0;

    queue<pair<int, int>> red_q, blue_q;

    bool r_flag = false, b_flag = false;

    red_q.push ({srx, sry});
    blue_q.push ({sbx, sby});

    while (true){

        // 한 쪽이 제자리만 간 경우

        if (r_flag && b_flag) break;

        if (r_flag) {

        }
        if (b_flag){

        }
        if (red_q.empty() && blue_q.empty()){
            break;
        }

        if (rx == d_rx && ry == d_ry && bx == d_bx, by == d_by) { // 만약 모두 제자리 간 경우
            break;
        }

        if (rx != d_rx && ry != d_ry) {
            int r_nx, r_ny;
            for (int i = 0; i<4; i++){
                r_nx = rx + dx[i], r_ny = ry + dy[i];

                if (r_nx < 0 || r_nx >= 4 || r_ny < 0 || r_ny >= 4) continue;
                if (red_visit[r_nx][r_ny]) continue;
                if (m[r_nx][r_ny] == 2 || m[r_nx][r_ny] == 5 || m[r_nx][r_ny] == 4)  continue;

                if (m[r_nx][r_ny] == 3){
                    r_flag = true;
                    break;
                }

                red_q.push ({r_nx, r_ny});
                red_visit[r_nx][r_ny] = red_visit[r_nx][r_ny]
                // 배열 숫자 만큼 자리를 만들어서 각 자리 당 각 수레가 갈 수 있는 최솟 값을 마련?
                // BFS 백트래킹?
            }
        }
        if (bx != d_bx && by != d_by) {
            int b_nx, b_ny;

            for (int i = 0; i<4; i++){
                b_nx = bx + dx[i], b_ny = by + dy[i];

                if (b_nx < 0 || b_nx >= 4 || b_ny < 0 || b_ny >= 4) continue;
                if (blue_visit[b_nx][b_ny]) continue;
                if (m[b_nx][b_ny] == 1 || m[b_nx][b_ny] == 5 ||m[b_nx][b_ny] == 3)  continue;

                if (m[b_nx][b_ny] == 4){
                    b_flag = true;
                    break;
                }

                blue_q.push ({b_nx, b_ny});
                // 배열 숫자 만큼 자리를 만들어서 각 자리 당 각 수레가 갈 수 있는 최솟 값을 마련?
                // BFS 백트래킹?
            }
        }

        cnt ++;
    }
}

int solution(vector<vector<int>> maze) {
    int answer = 0;
    m = maze;
    int rx, ry, bx, by;

    for (int i = 0; i<maze.size(); i++){
        for (int j = 0; j<maze[i].size(); j++){
            if (maze[i][j] == 1) {
                rx = i, ry = j;
            }
            if (maze[i][j] == 2) {
                bx=i, by=j;
            }
            if (maze[i][j] == 3) {
                d_rx=i, d_ry=j;
            }
            if (maze[i][j] == 4) {
                d_bx=i, d_by=j;
            }
        }
    }

    bfs(rx, ry, bx, by);

    return answer;
}
```

---

# 결과 & 근거

- **실패** (41분 포기). 답이 0인 테스트케이스만 통과하고 나머지는 무한 루프.
- BFS가 아니라 **DFS 백트래킹**이 정답이었다.
    - 「자신이 방문했던 칸으로 움직일 수 없다」가 **경로마다 따로 적용**되므로, BFS의 "한 번 방문한 상태는 다시 안 본다"는 전제가 깨진다.
    - 큐를 2개로 나눌 필요 없이 **두 수레의 좌표를 한 상태 `(rx, ry, bx, by)`로 묶는다.**
- 좌표만 가지고 4차원 BFS로 짜면 **공식 예제 4개는 전부 통과하고 히든에서 1.9%가 틀린다.**
    - 최소 반례 `[[1,3,2],[0,4,5]]` → 정답 4 / 좌표만 BFS 3.

```cpp
#include <string>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;

int N, M;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
vector<vector<int>> g;
int rgx, rgy, bgx, bgy;
bool rv[4][4], bv[4][4];
int best;

bool inRange(int x, int y) { return x >= 0 && x < N && y >= 0 && y < M; }

void dfs(int rx, int ry, int bx, int by, int depth) {
    if (depth >= best) return;                        // 가지치기

    bool rDone = (rx == rgx && ry == rgy);            // 두 좌표가 모두 같아야 도착
    bool bDone = (bx == bgx && by == bgy);
    if (rDone && bDone) { best = min(best, depth); return; }

    int rOpt = rDone ? 1 : 4;                         // 도착한 수레는 "제자리" 1개
    int bOpt = bDone ? 1 : 4;

    for (int i = 0; i < rOpt; i++) {
        int nrx = rDone ? rx : rx + dx[i];
        int nry = rDone ? ry : ry + dy[i];
        if (!rDone) {
            if (!inRange(nrx, nry)) continue;
            if (g[nrx][nry] == 5) continue;           // 벽
            if (rv[nrx][nry]) continue;               // 자기가 밟았던 칸
        }
        for (int j = 0; j < bOpt; j++) {
            int nbx = bDone ? bx : bx + dx[j];
            int nby = bDone ? by : by + dy[j];
            if (!bDone) {
                if (!inRange(nbx, nby)) continue;
                if (g[nbx][nby] == 5) continue;
                if (bv[nbx][nby]) continue;
            }
            if (nrx == nbx && nry == nby) continue;                         // 같은 칸 금지
            if (nrx == bx && nry == by && nbx == rx && nby == ry) continue; // 자리 교환 금지

            if (!rDone) rv[nrx][nry] = 1;             // 마킹: for 안, 재귀 전
            if (!bDone) bv[nbx][nby] = 1;
            dfs(nrx, nry, nbx, nby, depth + 1);
            if (!rDone) rv[nrx][nry] = 0;             // 리셋: 재귀 후 (백트래킹)
            if (!bDone) bv[nbx][nby] = 0;
        }
    }
}

int solution(vector<vector<int>> maze) {
    g = maze; N = maze.size(); M = maze[0].size();
    int rx = 0, ry = 0, bx = 0, by = 0;
    memset(rv, 0, sizeof(rv)); memset(bv, 0, sizeof(bv));

    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        if (g[i][j] == 1) { rx = i; ry = j; }
        if (g[i][j] == 2) { bx = i; by = j; }
        if (g[i][j] == 3) { rgx = i; rgy = j; }
        if (g[i][j] == 4) { bgx = i; bgy = j; }
    }
    rv[rx][ry] = 1; bv[bx][by] = 1;                   // 출발칸도 방문 처리

    best = INT_MAX;
    dfs(rx, ry, bx, by, 0);
    return best == INT_MAX ? 0 : best;                // 불가능하면 0
}
```

> 
> 
> 
> ***한 줄 요약***
> 
> 수레 2대의 좌표를 **한 상태 `(rx, ry, bx, by)`로 묶어** 최소 턴 수를 찾는 문제. 
> 
> 「자신이 방문했던 칸에 못 간다」가 **경로마다 따로 적용**되므로 BFS가 아니라 **DFS 백트래킹**이며, 이중 `for`로 두 수레의 이동을 동시에 고르고 같은 칸·자리 교환을 걸러낸다. 도착한 수레는 선택지를 "제자리 1개"로 만들어 고정 규칙을 표현하고, `visited` 마킹/리셋 쌍이 `for` 루프를 감싸는 것이 핵심.
> 

### 알고리즘 분류

- DFS / 백트래킹
- 완전탐색
- 격자 탐색
- 다중 객체 상태 관리