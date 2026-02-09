# 1389 케빈 베이컨의 6단계 법칙 (성공)

# 문제 소개

[문제 사이트 링크](https://www.acmicpc.net/problem/1389)

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞힌 사람 | 정답 비율 |
| --- | --- | --- | --- | --- | --- |
| 2 초 | 128 MB | 58087 | 30290 | 23907 | 54.398% |

## 문제

케빈 베이컨의 6단계 법칙에 의하면 지구에 있는 모든 사람들은 최대 6단계 이내에서 서로 아는 사람으로 연결될 수 있다. 케빈 베이컨 게임은 임의의 두 사람이 최소 몇 단계 만에 이어질 수 있는지 계산하는 게임이다.

예를 들면, 전혀 상관없을 것 같은 인하대학교의 이강호와 서강대학교의 민세희는 몇 단계만에 이어질 수 있을까?

천민호는 이강호와 같은 학교에 다니는 사이이다. 천민호와 최백준은 Baekjoon Online Judge를 통해 알게 되었다. 최백준과 김선영은 같이 Startlink를 창업했다. 김선영과 김도현은 같은 학교 동아리 소속이다. 김도현과 민세희는 같은 학교에 다니는 사이로 서로 알고 있다. 즉, 이강호-천민호-최백준-김선영-김도현-민세희 와 같이 5단계만 거치면 된다.

케빈 베이컨은 미국 헐리우드 영화배우들 끼리 케빈 베이컨 게임을 했을때 나오는 단계의 총 합이 가장 적은 사람이라고 한다.

오늘은 Baekjoon Online Judge의 유저 중에서 케빈 베이컨의 수가 가장 작은 사람을 찾으려고 한다. 케빈 베이컨 수는 모든 사람과 케빈 베이컨 게임을 했을 때, 나오는 단계의 합이다.

예를 들어, BOJ의 유저가 5명이고, 1과 3, 1과 4, 2와 3, 3과 4, 4와 5가 친구인 경우를 생각해보자.

1은 2까지 3을 통해 2단계 만에, 3까지 1단계, 4까지 1단계, 5까지 4를 통해서 2단계 만에 알 수 있다. 따라서, 케빈 베이컨의 수는 2+1+1+2 = 6이다.

2는 1까지 3을 통해서 2단계 만에, 3까지 1단계 만에, 4까지 3을 통해서 2단계 만에, 5까지 3과 4를 통해서 3단계 만에 알 수 있다. 따라서, 케빈 베이컨의 수는 2+1+2+3 = 8이다.

3은 1까지 1단계, 2까지 1단계, 4까지 1단계, 5까지 4를 통해 2단계 만에 알 수 있다. 따라서, 케빈 베이컨의 수는 1+1+1+2 = 5이다.

4는 1까지 1단계, 2까지 3을 통해 2단계, 3까지 1단계, 5까지 1단계 만에 알 수 있다. 4의 케빈 베이컨의 수는 1+2+1+1 = 5가 된다.

마지막으로 5는 1까지 4를 통해 2단계, 2까지 4와 3을 통해 3단계, 3까지 4를 통해 2단계, 4까지 1단계 만에 알 수 있다. 5의 케빈 베이컨의 수는 2+3+2+1 = 8이다.

5명의 유저 중에서 케빈 베이컨의 수가 가장 작은 사람은 3과 4이다.

BOJ 유저의 수와 친구 관계가 입력으로 주어졌을 때, 케빈 베이컨의 수가 가장 작은 사람을 구하는 프로그램을 작성하시오.

## 입력

첫째 줄에 유저의 수 N (2 ≤ N ≤ 100)과 친구 관계의 수 M (1 ≤ M ≤ 5,000)이 주어진다. 둘째 줄부터 M개의 줄에는 친구 관계가 주어진다. 친구 관계는 A와 B로 이루어져 있으며, A와 B가 친구라는 뜻이다. A와 B가 친구이면, B와 A도 친구이며, A와 B가 같은 경우는 없다. 친구 관계는 중복되어 들어올 수도 있으며, 친구가 한 명도 없는 사람은 없다. 또, 모든 사람은 친구 관계로 연결되어져 있다. 사람의 번호는 1부터 N까지이며, 두 사람이 같은 번호를 갖는 경우는 없다.

## 출력

첫째 줄에 BOJ의 유저 중에서 케빈 베이컨의 수가 가장 작은 사람을 출력한다. 그런 사람이 여러 명일 경우에는 번호가 가장 작은 사람을 출력한다.

## 예제 입력 1

```
5 5
1 3
1 4
4 5
4 3
3 2
```

## 예제 출력 1

```
3
```

---

# 초기 접근 방법

- 완벽한 그래프 탐색 문제이다.
- 그래프 탐색 문제는 어쨌든 여러가지가 있으니 모든 가능성을 열어두고 접근하고자 한다.

---

# 풀이 과정

- 일단 어딘가에 시작 - 종점 이런 탐색 문제가 아니다.
- 또한 모든 사람들 간의 케빈 베이컨 값을 구해야 하므로, DFS BFS 가 맞는 풀이 라고 생각했다.

```cpp

#include <bits/stdc++.h>
using namespace std;
// https://www.acmicpc.net/problem/1389

int n, m;

vector<vector<int>> graph;
bool visited [101];
int kevin [101];
int start_pos, answer = 999999999, answer_pos;

void input() {
    cin >> n >> m;
    graph.resize(n+1);

    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
}

/*void dfs (int start, int depth) {
    visited[start] = true;
    for (int i = 0; i < graph[start].size(); i++)
    {
        if (!visited[graph[start][i]])
        {
            cout << graph[start][i] << "까지의 거리: " << depth+1 << endl;
            visited[graph[start][i]] = true;
            kevin[start_pos] += depth+1;
            dfs (graph[start][i], depth + 1);
        }
    }
}*/

void bfs (int start) {
    queue<pair<int, int>> q;
    q.push(make_pair(start, 0));
    visited[start] = true;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        for (int i = 0; i < graph[p.first].size(); i++)
        {
            if (!visited[graph[p.first][i]])
            {
                // cout << graph[p.first][i] << "까지의 거리: " << p.second+1 << endl;
                q.push({graph[p.first][i], p.second+1 });
                visited[graph[p.first][i]] = true;
                kevin[start_pos] += p.second+1;
            }
        }

    }
}

void solution() {
    // 각 번호 마다 bfs
    // bfs -> 방문 가능한 경우 전체 방문 갯수 --

    // bfs + 레벨을 알고 있는.

    // dfs +

    for (int i = 1; i <= n; i++)
    {
        // cout << i << " -> ";
        start_pos = i;
        bfs(i);
        // cout  << kevin[i] << "\n";
        if (answer > kevin[i])
        {
            answer = kevin[i];
            answer_pos = i;
        }

        fill(visited, visited+n+1, false);

        // 자신을 제외한 거에 추가
    }
    cout << answer_pos << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    input();
    solution();

    return 0;
}

```

---

# 결과 & 근거

- 항상 그래프 탐색은 DFS로 풀려고 하는 습관이 있었는데, 해당 문제는 그러면 안되는 문제였다.
    - DFS로 탐색할 경우, 최악의 케빈 베이컨 값을 맞이하게 된다.
    - 1-4 , 1-5, 4-5 인 경우 1의 기준 4 5 모두 1단계로 갈 수 있어서 케빈 베이컨 값은 2가 되어야 한다.
    - 하지만 DFS의 경우 4 → 5 → 되돌아감 → 5 (Visited!) 로 케빈 베이컨은 3이 되버린다.
- 결과는 BFS 풀이로 성공했다.
    - Pair<int, int> (노드, 레벨) 로 정점과 깊이를 표현했다.
    - 27분 컷.

```cpp
#include <bits/stdc++.h>
using namespace std;
// https://www.acmicpc.net/problem/1389

int n, m;
vector<vector<int>> graph;
bool visited [101], kevin [101];
int start_pos, answer = 999999999, answer_pos;

void input() {
    cin >> n >> m;
    graph.resize(n+1);

    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y), graph[y].push_back(x);
    }
}

void bfs (int start) {
    queue<pair<int, int>> q;
    q.push(make_pair(start, 0));
    visited[start] = true;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        for (int i = 0; i < graph[p.first].size(); i++) {
            if (!visited[graph[p.first][i]]) {
                q.push({graph[p.first][i], p.second+1 });
                visited[graph[p.first][i]] = true;
                kevin[start_pos] += p.second+1;
            }
        }
    }
}

void solution() {
    for (int i = 1; i <= n; i++) {
        start_pos = i;
        bfs(i);
        if (answer > kevin[i]) {
            answer = kevin[i], answer_pos = i;
        }

        fill(visited, visited+n+1, false);
    }
    cout << answer_pos << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    input();
    solution();
    return 0;
}
```

### 알고리즘 분류

- 그래프 이론
- 그래프 탐색
- 너비 우선 탐색
- 최단 경로
- 플로이드-워셜
    - 모든 쌍에 대한 최단 거리를 구하는 알고리즘으로 O(N^3) 이나, 주어진 데이터로는 충분하다.