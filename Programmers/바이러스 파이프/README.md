# 문제 소개

문제 사이트 링크

#### **문제 설명**

`1`번부터 `n`번까지 번호가 붙은 `n`개의 배양체를 `n-1`개의 파이프로 이어 하나의 트리 모양을 만들었습니다. 각 파이프는 `A`,`B`,`C` 3개의 종류 중 하나로 초기에 모든 파이프는 닫혀있습니다.

배양체 중 하나가 바이러스에 감염되어 있습니다. 바이러스에 감염된 배양체는 열린 파이프를 통해 연결된 다른 인접한 배양체를 감염시킵니다.

당신은 종류가 같은 파이프를 한꺼번에 모두 열었다가 닫을 수 있습니다. 단, 한 종류의 파이프를 연 후 다시 닫기 전에 다른 종류의 파이프를 열 수 없습니다. 파이프를 열었다 닫는 행동을 최대 `k`번 반복해 최대한 많은 배양체에 바이러스를 감염시키려고 합니다.

배양체의 개수를 나타내는 정수 `n`, 감염된 배양체의 노드 번호를 나타내는 정수 `infection`, 파이프의 정보를 나타내는 2차원 정수 배열 `edges`, 최대 행동 수를 나타내는 정수 `k`가 매개변수로 주어집니다. 최대 `k`번 파이프를 열었다 닫은 후, 감염된 배양체 개수의 최댓값을 return 하도록 solution 함수를 완성해 주세요.

---

#### 제한사항

- 2 ≤ `n` ≤ 100
- 1 ≤ `infection` ≤ `n`
- `edges`의 길이 = `n-1`
    - `edges[i]`는 [`x`, `y`, `type`]의 형태로 `x`번 노드의 배양체와 `y`번 노드의 배양체 사이가 `type` 종류의 파이프로 연결되어 있음을 의미합니다.
    - 1 ≤ `x` < `y` ≤ `n`
    - 1 ≤ `type` ≤ 3
    - 1은 `A`, 2는 `B`, 3은 `C` 를 나타냅니다.
- 1 ≤ `k` ≤ 10

---

#### 테스트 케이스 구성 안내

아래는 테스트 케이스 구성을 나타냅니다. 각 그룹 내의 테스트 케이스를 모두 통과하면 해당 그룹에 할당된 점수를 획득할 수 있습니다.

| 그룹 | 총점 | 테스트 케이스 그룹 설명 |
| --- | --- | --- |
| #1 | 10% | 트리가 일렬 모양입니다. 즉, 각 배양체에 연결된 파이프는 1개 혹은 2개입니다. |
| #2 | 20% | 파이프의 type은 A 혹은 B만 주어집니다. |
| #3 | 30% | 한 배양체에 연결된 파이프의 type이 모두 다릅니다. |
| #4 | 40% | 추가 제한 사항 없음 |

---

#### 입출력 예

| n | infection | edges | k | result |
| --- | --- | --- | --- | --- |
| 10 | 1 | [[1, 2, 1], [1, 3, 1], [1, 4, 3], [1, 5, 2], [5, 6, 1], [5, 7, 1], [2, 8, 3], [2, 9, 2], [9, 10, 1]] | 2 | 6 |
| 7 | 6 | [[1, 2, 3], [1, 4, 3], [4, 5, 1], [5, 6, 1], [3, 6, 2], [3, 7, 2]] | 3 | 7 |

#### 입출력 예 설명

**입출력 예 #1**

트리가 아래 그림과 같이 구성되어 있습니다.

!pipe_1.jpg

B 타입 파이프를 열었다 닫은 후, A 타입 파이프를 열었다 닫으면 감염된 배양체가 총 6개가 됩니다.

1. B 타입 파이프 열림 : [1 - 5, 2 - 9]를 연결하는 파이프가 열립니다. 배양체 #5가 감염됩니다.

2. B 타입 파이프 닫힘

3. A 타입 파이프 열림 : [1 - 2, 1 - 3, 5 - 6, 5 - 7, 9 - 10]을 연결하는 파이프가 열립니다. 배양체 #2, #3, #6, #7이 감염됩니다.

4. A 타입 파이프 닫힘

5. 최종적으로 감염된 배양체는 #1, #2, #3, #5, #6, #7입니다.

2번의 행동으로 감염된 배양체가 6개보다 많아지는 방법은 없습니다. 따라서 6을 return 해야 합니다.

**입출력 예 #2**

트리가 아래 그림과 같이 구성되어 있습니다.

!pipe_2.jpg

ABC 혹은 ACB 혹은 BAC 순으로 파이프를 열었다 닫으면 감염된 배양체가 총 7개가 됩니다.

3번의 행동으로 감염된 배양체가 7개보다 많아지는 방법은 없습니다. 따라서 7을 return 해야 합니다.

---

# 풀이 과정

- "최대 k번의 행동으로 최대 감염" 문구에서 Greedy를 떠올렸었다.
- 그래도 트리 + 순회이고 k라는 한계가 있으니 "최대 depth가 있는 level BFS"로 접근했다.
- 구현하면서 막혔다.
    - 감염체가 여러 개일 때 각각 BFS를 새로 시작할지, 큐를 공유할지 정리가 안 됐다.
    - 34분 트라이 중에 포기.
    - 되짚어보니 구상에서 두 개를 놓쳤다.

```cpp
#include <queue>
#include <string>
#include <vector>

using namespace std;
/*
 * 1 ~ n 까지의 배양체 -> n-1개의 파이프로 이어서 트리 만듬
 * 각 파이프는 A,B,C 3개의 종류 중 하나로 초기에 모든 파이프는 닫혀있습니다.
 * 배양체 중 하나는 바이러스 감염. -> 인접 열린 파이프로 타 인접 배양체 감염시킴!
 * - 대신 종류가 같은 파이프를 '한 번에 open/close' 할 수 있음.
 * - 열고 다른 파이프를 열 수 없음. 열고 닫은 후, 다시 다른 파이프!
 * - 파이프를 열었다 닫는 행동을 '최대 k번 반복해 최대한' 많은 배양체에 바이러스를 감염시키는 게 목적!
 */

// n = 배양체 개수. 2 ≤ n ≤ 100
// infection = 감염 배양체 노드 번호, 1 ≤ infection ≤ n
// edges = 파이프 정보 -> [node1, node2, pipe_type], 1 ≤ n1 < n2 ≤ n
// -> pipe_type = 1/A, 2/B, 3/C 최대 개.
// k = 최대 행동 수. 1 ≤ k ≤ 10

// 34분 포기 -> 다른 문제 풀이
vector<int> infection_arr;
vector<vector<pair<int, int>>> tree; // 무방향 tree로 선언.
queue<pair<int, int>> q; // node, depth
int visited_arr [101] = { 0 };
int total_count;
void bfs(int infec_node, int level) {
    /*int temp[3]={0,0,0};
    vector<vector<int>> tree2(3);
    for (int i = 0; i< tree[infec_node].size(); i++) {
        int n2 = tree[infec_node][i].first;
        int pipe_type = tree[infec_node][i].second;
        tree2[pipe_type].push_back(n2);
    }*/

    // 주변 계산
    q.push({infec_node, 0});

    while (q.empty() == false)
    {
        int n1 = q.front().first;
        int n1_depth = q.front().second;
        for (int i = 0 ; i < tree[n1].size(); i++)
        {
            int next_node = tree[n1][i].first;
            int next_pipe = tree[n1][i].second;
            if (visited_arr[next_node] == 0){
                q.push({next_node, n1_depth + 1});
            }
        }
    }

}

int solution(int n, int infection, vector<vector<int>> edges, int k)
{
    int answer = 0;

    total_count = k;
    tree.resize(n);
    for (int i = 0; i < edges.size(); i++) {
        int n1 = edges[i][0], n2 = edges[i][1], pipe_type = edges[i][2]; // 복잡해서 알기 쉽게 변수 구분
        tree[n1].push_back({n2, pipe_type}), tree[n2].push_back({n1, pipe_type});
    }

    infection_arr.clear();
    infection_arr.push_back(infection);

    /*
     * 풀이과정
     * k라는 최댓값에서 최대 결과를 가져와야 한다
     * - 한계에서 최선의 결과. Greedy Algorithm이다.
     * - 하필 또 트리 = 순회에서 최댓값 결과를 가져와야 한다. (목적지가 아니여서 Bellmen-Ford나 Dijkstra는 아님)
     * - 이정도면 BFS로 접근해야 할 것 같아. K라는 한계가 정해져있어서 depth 보다 breath를 중요시해야 할 것 같아.
     * - 즉 최대 depth가 있는 BFS 느낌?
     *
     * - 지금 구현 완전히 틀렸다
     * - k 만큼, Level BFS를 실행했어야 한다. (바이러스는 매번 최대 감염 경로로만 움직인다 라고 착각)
     */

    for (int i = 0; i<k; i++)
    {
        /*
     * 로직
     * 1. 맨 처음 감염체 있겠지?
     * - 먼저 바로 그 주변, 거리 1인 애들에 대해 BFS.
     * - 많은 것에 대해 연다? 만약 여기서 적은 것 이후에 퍼져나간 애가 더욱 많이 감염시킬 수 있다면?
     * -
     *
     * k for문
     * 1. 감염체 기준 계속되는 BFS? -> 감염체 전용 vector<int> 가 필요해
     * 2.
     */
        for (int i = 0; i<infection_arr.size(); i++)
        {
            // 감염체 마다 주변 한 번 BFS
            bfs(infection_arr[i]);
        }
    }

    // k 번 열고 닫은 후의 '감염된 최대' 배양체 개수.
    return answer;
}

int main()
{
}

```

---

# 결과 & 근거

- 어쨌든 실패
1. Greedy가 성립하지 않는다. 예시 #1이 그대로 반례다.
    - A 먼저: 2,3 감염 → 3개 (당장 최대) → B로 5,9 추가 → 최종 5개
    - B 먼저: 5만 감염 → 2개 (당장 최소) → A로 2,3,6,7 추가 → 최종 6개
    - 당장의 이득이 다음 턴의 감염 범위를 좁힌다. 지역 최적 ≠ 전역 최적.
2. k는 탐색 깊이가 아니라 "선택 횟수"다.
    - 탐색 대상은 입력 트리가 아니라 A/B/C를 k번 고르는 선택 트리였다.
    - 3^10 = 59,049 × BFS O(n+E) ≈ 200 → 약 1,200만. 완전탐색이 여유롭게 들어간다.
    - k ≤ 10, 파이프 3종이라는 제한이 사실 "3^k 완전탐색 하라"는 신호였다.
3. 사실 하나 더 착각했다. 같은 종류를 "한꺼번에" 여는 거라 감염은 거리 1만 퍼지지 않는다.
    - 해당 타입 서브그래프에서 감염 집합이 속한 연결 성분 전체를 흡수한다.
    - 즉 한 행동 안에는 거리 제한이 아예 없는데, 나는 제한이 있다고 가정했다.

```cpp
#include <bits/stdc++.h>
using namespace std;

int N, K, best;
vector<vector<pair<int,int>>> g;   // node -> (next, type)

void dfs(int depth, vector<char> inf, int cnt) {
    best = max(best, cnt);
    if (depth == K) return;

    for (int t = 1; t <= 3; t++) {
        vector<char> nxt = inf;
        int ncnt = cnt;

        // 타입 t 파이프만 열었을 때: 감염 집합의 연결 성분 전체 흡수
        queue<int> q;
        for (int i = 1; i <= N; i++) if (inf[i]) q.push(i);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (auto& e : g[cur])
                if (e.second == t && !nxt[e.first]) {
                    nxt[e.first] = 1;      // push 시점에 방문 처리
                    ncnt++;
                    q.push(e.first);
                }
        }
        if (ncnt == cnt) continue;          // 가지치기: 변화 없는 선택은 무의미
        dfs(depth + 1, nxt, ncnt);
    }
}

int solution(int n, int infection, vector<vector<int>> edges, int k) {
    N = n; K = k;
    g.assign(n + 1, {});                    // n+1 — 1-indexed
    for (auto& e : edges) {
        g[e[0]].push_back({e[1], e[2]});
        g[e[1]].push_back({e[0], e[2]});
    }
    vector<char> inf(n + 1, 0);
    inf[infection] = 1;
    best = 1;
    dfs(0, inf, 1);
    return best;
}
```

### 알고리즘 분류

- 완전탐색 (브루트포스)
- DFS, 백트래킹
- BFS (연결 성분)
- 트리, 그래프 이론
- 시뮬레이션