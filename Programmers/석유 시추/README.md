# 문제 소개

문제 사이트 링크

#### **문제 설명**

**[본 문제는 정확성과 효율성 테스트 각각 점수가 있는 문제입니다.]**

세로길이가 `n` 가로길이가 `m`인 격자 모양의 땅 속에서 석유가 발견되었습니다. 석유는 여러 덩어리로 나누어 묻혀있습니다. 당신이 시추관을 수직으로 **단 하나만** 뚫을 수 있을 때, 가장 많은 석유를 뽑을 수 있는 시추관의 위치를 찾으려고 합니다. 시추관은 열 하나를 관통하는 형태여야 하며, 열과 열 사이에 시추관을 뚫을 수 없습니다.

!석유시추-1.drawio.png

예를 들어 가로가 8, 세로가 5인 격자 모양의 땅 속에 위 그림처럼 석유가 발견되었다고 가정하겠습니다. 상, 하, 좌, 우로 연결된 석유는 하나의 덩어리이며, 석유 덩어리의 크기는 덩어리에 포함된 칸의 수입니다. 그림에서 석유 덩어리의 크기는 왼쪽부터 8, 7, 2입니다.

!석유시추-2.drawio.png

시추관은 위 그림처럼 설치한 위치 아래로 끝까지 뻗어나갑니다. 만약 시추관이 석유 덩어리의 일부를 지나면 해당 덩어리에 속한 모든 석유를 뽑을 수 있습니다. 시추관이 뽑을 수 있는 석유량은 시추관이 지나는 석유 덩어리들의 크기를 모두 합한 값입니다. 시추관을 설치한 위치에 따라 뽑을 수 있는 석유량은 다음과 같습니다.

| 시추관의 위치 | 획득한 덩어리 | 총 석유량 |
| --- | --- | --- |
| 1 | [8] | 8 |
| 2 | [8] | 8 |
| 3 | [8] | 8 |
| 4 | [7] | 7 |
| 5 | [7] | 7 |
| 6 | [7] | 7 |
| 7 | [7, 2] | 9 |
| 8 | [2] | 2 |

오른쪽 그림처럼 7번 열에 시추관을 설치하면 크기가 7, 2인 덩어리의 석유를 얻어 뽑을 수 있는 석유량이 9로 가장 많습니다.

석유가 묻힌 땅과 석유 덩어리를 나타내는 2차원 정수 배열 `land`가 매개변수로 주어집니다. 이때 시추관 하나를 설치해 뽑을 수 있는 가장 많은 석유량을 return 하도록 solution 함수를 완성해 주세요.

---

#### 제한사항

- 1 ≤ `land`의 길이 = 땅의 세로길이 = `n` ≤ 500
    - 1 ≤ `land[i]`의 길이 = 땅의 가로길이 = `m` ≤ 500
    - `land[i][j]`는 `i+1`행 `j+1`열 땅의 정보를 나타냅니다.
    - `land[i][j]`는 0 또는 1입니다.
    - `land[i][j]`가 0이면 빈 땅을, 1이면 석유가 있는 땅을 의미합니다.

#### 정확성 테스트 케이스 제한사항

- 1 ≤ `land`의 길이 = 땅의 세로길이 = `n` ≤ 100
    - 1 ≤ `land[i]`의 길이 = 땅의 가로길이 = `m` ≤ 100

#### 효율성 테스트 케이스 제한사항

- 주어진 조건 외 추가 제한사항 없습니다.

---

#### 입출력 예

| land | result |
| --- | --- |
| [[0, 0, 0, 1, 1, 1, 0, 0], [0, 0, 0, 0, 1, 1, 0, 0], [1, 1, 0, 0, 0, 1, 1, 0], [1, 1, 1, 0, 0, 0, 0, 0], [1, 1, 1, 0, 0, 0, 1, 1]] | 9 |
| [[1, 0, 1, 0, 1, 1], [1, 0, 1, 0, 0, 0], [1, 0, 1, 0, 0, 1], [1, 0, 0, 1, 0, 0], [1, 0, 0, 1, 0, 1], [1, 0, 0, 0, 0, 0], [1, 1, 1, 1, 1, 1]] | 16 |

---

#### 입출력 예 설명

**입출력 예 #1**

문제의 예시와 같습니다.

**입출력 예 #2**

!석유시추-3.drawio.png

시추관을 설치한 위치에 따라 뽑을 수 있는 석유는 다음과 같습니다.

| 시추관의 위치 | 획득한 덩어리 | 총 석유량 |
| --- | --- | --- |
| 1 | [12] | 12 |
| 2 | [12] | 12 |
| 3 | [3, 12] | 15 |
| 4 | [2, 12] | 14 |
| 5 | [2, 12] | 14 |
| 6 | [2, 1, 1, 12] | 16 |

6번 열에 시추관을 설치하면 크기가 2, 1, 1, 12인 덩어리의 석유를 얻어 뽑을 수 있는 석유량이 16으로 가장 많습니다. 따라서 `16`을 return 해야 합니다.

---

**제한시간 안내**

- 정확성 테스트 : 10초
- 효율성 테스트 : 언어별로 작성된 정답 코드의 실행 시간의 적정 배수

---

# 풀이 과정

- 구상은 쉬웠다. 각 열을 뚫었을 때 닿는 덩어리 크기의 합이 그 열의 점수, 그 최댓값이 답이다.
- 덩어리 크기는 BFS로 구하면 되니 "열마다 덩어리 시작점을 찾고 BFS로 합산"하는 그림을 그렸다.
- 그런데 구현에서 무너졌다. 온라인 컴파일러에서 Segmentation Fault.

```cpp
#include <iostream>
#include <map>
#include <ostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

/*
 * 세로/열 n, 가로/행 m에서 석유 찾기 -> 정확히 시추를 수직 + 1개만 뚫을 수 있음 = 최대 석유 찾기!
 * - 시추는 일부라도 석유 덩어리를 찾으면 모든 석유를 뽑을 수 있음!
 */

// land: 석유가 묻힌 땅과 석유 덩어리를 나타내는 2차원 정수 배열
// 1 ≤ land의 길이 = 땅의 세로길이 = n ≤ 500
// 1 ≤ land[i]의 길이 = 땅의 가로길이 = m ≤ 500
// land[i][j]가 0이면 빈 땅을, 1이면 석유가 있는 땅을 의미
queue<pair<int, int>> q;

vector<pair<int, int>> dir = { {1, 0} ,{-1, 0} ,{0, 1} ,{0, -1}};

int bfs (pair <int, int> p, const vector<vector<int>>& land) { // Segment Fault
    int total = 0;
    while (q.empty() == false) { // queue init
        q.pop();
    }
    map<pair<int, int>, int> visited; // visited map value

    q.push(p);

    while (!q.empty())
    {
        pair<int, int> pair1 = q.front();
        q.pop(), total++, visited[pair1]++; // 빼면서 oil 확인, 방문 처리

        // 사분면 탐색 + q 삽입
        for (pair<int, int> d : dir) {
            pair<int, int> next = make_pair(pair1.first + d.first, pair1.second + d.second);
            if (next.second < 0 || next.second >= land[0].size() || next.first  < 0 || next.first >= land.size()) {
                continue;
            }
            cout << next.first << ", " << next.second << endl;

            if (visited[next] == 0 && land[next.first][next.second] == 1) {
                // 방문한 적 없고 기름이 있으면 push
                q.push(next);
            }
        }
    }
    return total;

}

int solution(vector<vector<int>> land) {
    int answer = 0;

    // 어차피 가로
    for (int i = 0; i< land[0].size(); i++) {

        // 덩어리 판별이 중요해.
        /*
         * 뚫는다!
         * - 뚫으면서 찾는 석유는 1이겠지? 좌표 기억
         * -> 만약 그 다음도 석유이면 같은 덩어리로, 좌표 기억 X
         * -> 만약 그 다음이 맨 땅이라면 덩어리 끝. 이전 찾은 좌표 기억
         *
         * 뚫고 난 뒤,
         * - DFS/BFS를 통한 석유 찾기
         * - return oil 후 총합 하기
         */

        // 뚫기.
        int check = 0; // 이전이 석유였는가.
        pair<int, int> pos;
        vector<pair<int,int>> oil;
        for (int j = 0; j < land.size(); j++)
        {
            if (land[i][j] == 1 && check == 0) {
                // 덩어리 처음을 만난 것
                check = 1;
                pos = make_pair(i, j);
            }
            else if (land[i][j] == 1 && check == 1) {
                // 같은 덩어리, continue;
            }
            else if (land[i][j] == 0 && check == 1) {
                // 덩어리가 끊긴 것
                oil.push_back(pos);
            }
        }

        int total = 0; // 중간 총합용 변수

        for (pair<int, int> o : oil) {
            // dfs/bfs (o) -> return oil_count
            total += bfs(o, land);
        }
        cout << i+1 << "번 시추 결과: " <<  total << endl;
        if (answer < total) {
            answer = total;
        }
    }

    return answer;
}
int main ()
{
    return 0;
}
```

- 인덱싱에서 너무 헷갈려 ㅆㅂ

---

# 결과 & 근거

- 어쨌든 실패
1. 직접 원인인 인덱스 전치
    - 이 문제는 가로가 `land[i].size()`, 세로가 `land.size()`로 평소 감각과 반대다.
    - 바깥 루프 i를 가로(`land[0].size()`)로 돌리면서 접근은 `land[i][j]`로 했다.
    - 첫 인덱스는 행인데 열을 넣은 셈이라, n != m 이면 즉시 범위를 벗어난다.
    - 이후 i, j 대신 row, col을 쓰기로 했다. `land[i][j]`는 틀렸는지 안 보이지만 `land[col][row]`는 보인다.
2.  BFS의 visited 마킹 타이밍
    - `q.pop()` 직후에 방문 처리를 했다.
    - 그러면 아직 큐 안에 있어서 방문 처리가 안 된 칸을 여러 이웃이 중복으로 push한다.
    - 덩어리 크기가 과다 계수되고 큐도 불필요하게 커진다.
    - BFS의 방문 처리는 pop이 아니라 push 시점이다.
3. 설계 비효율 — visited를 bfs 안의 지역 변수로 둠
    - 같은 덩어리를 열마다 처음부터 다시 탐색했다.
    - 최악 500열 × O(500×500) = 1.25억 + map의 O(log N) + 노드 할당 오버헤드 → 통과 불가.
4. flush 누락
    - 덩어리 끝을 "석유 다음 맨 땅"으로만 감지했다. 열 최하단이 석유면 그 덩어리가 영원히 누락된다.
- 올바른 설계는 질문을 뒤집는 것이었다.
    - "이 열이 어떤 덩어리에 닿나"를 열마다 묻지 말고, "이 덩어리가 어떤 열에 걸쳐 있나"를 덩어리마다 묻는다.
    - 전체를 한 번만 flood fill 하며 덩어리에 번호와 크기를 부여하고, 열에서는 번호만 모아 중복 제거 후 합산.
    - O(n×m) = 25만. 덩어리 시작점을 찾을 필요가 없어지면서 2·3·4번이 동시에 사라진다.
- 아이디어가 쉬워서 "쉬운 문제"로 분류했는데, 난이도는 아이디어가 아니라 중복 탐색 제거와 격자 인덱싱에 있었다.

```cpp
#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> land) {
    int n = land.size(), m = land[0].size();
    vector<vector<int>> id(n, vector<int>(m, 0));   // 0 = 미방문
    vector<long long> colSum(m, 0);
    int dy[] = {1,-1,0,0}, dx[] = {0,0,1,-1};
    int cur = 0;

    for (int row = 0; row < n; row++)
    for (int col = 0; col < m; col++) {
        if (land[row][col] != 1 || id[row][col] != 0) continue;

        cur++;
        queue<pair<int,int>> q;
        q.push({row, col});
        id[row][col] = cur;                  // push 시점 방문 처리
        int cnt = 0;
        set<int> cols;                       // 이 덩어리가 걸친 열

        while (!q.empty()) {
            auto [y, x] = q.front(); q.pop();
            cnt++; cols.insert(x);
            for (int d = 0; d < 4; d++) {
                int ny = y + dy[d], nx = x + dx[d];
                if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                if (land[ny][nx] == 1 && id[ny][nx] == 0) {
                    id[ny][nx] = cur;        // push 시점 방문 처리
                    q.push({ny, nx});
                }
            }
        }
        for (int c : cols) colSum[c] += cnt;
    }
    return (int)*max_element(colSum.begin(), colSum.end());
}
```

### 알고리즘 분류

- BFS, DFS
- 플러드 필 (Flood Fill)
- 연결 성분
- 격자 탐색
- 구현