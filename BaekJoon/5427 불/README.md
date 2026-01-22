# 5427 불 (실패)

# 문제 소개

[문제 사이트 링크](https://www.acmicpc.net/problem/5427)

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞힌 사람 | 정답 비율 |
| --- | --- | --- | --- | --- | --- |
| 1 초 | 256 MB | 55598 | 15964 | 10873 | 26.633% |

## 문제

상근이는 빈 공간과 벽으로 이루어진 건물에 갇혀있다. 건물의 일부에는 불이 났고, 상근이는 출구를 향해 뛰고 있다.

매 초마다, 불은 동서남북 방향으로 인접한 빈 공간으로 퍼져나간다. 벽에는 불이 붙지 않는다. 상근이는 동서남북 인접한 칸으로 이동할 수 있으며, 1초가 걸린다. 상근이는 벽을 통과할 수 없고, 불이 옮겨진 칸 또는 이제 불이 붙으려는 칸으로 이동할 수 없다. 상근이가 있는 칸에 불이 옮겨옴과 동시에 다른 칸으로 이동할 수 있다.

빌딩의 지도가 주어졌을 때, 얼마나 빨리 빌딩을 탈출할 수 있는지 구하는 프로그램을 작성하시오.

## 입력

첫째 줄에 테스트 케이스의 개수가 주어진다. 테스트 케이스는 최대 100개이다.

각 테스트 케이스의 첫째 줄에는 빌딩 지도의 너비와 높이 w와 h가 주어진다. (1 ≤ w,h ≤ 1000)

다음 h개 줄에는 w개의 문자, 빌딩의 지도가 주어진다.

- '.': 빈 공간
- '#': 벽
- '@': 상근이의 시작 위치
- '*': 불

각 지도에 @의 개수는 하나이다.

## 출력

각 테스트 케이스마다 빌딩을 탈출하는데 가장 빠른 시간을 출력한다. 빌딩을 탈출할 수 없는 경우에는 "IMPOSSIBLE"을 출력한다.

## 예제 입력 1

```
5
4 3
####
#*@.
####
7 6
###.###
#*#.#*#
#.....#
#.....#
#..@..#
#######
7 4
###.###
#....*#
#@....#
.######
5 5
.....
.***.
.*@*.
.***.
.....
3 3
###
#@#
###

-> 
2
5
IMPOSSIBLE
IMPOSSIBLE
IMPOSSIBLE
```

---

# 초기 접근 방법

- 지금은 최단 경로가 필요로 하다.
    - 출발지는 정해져 있으나, 목적지는 따로 구해야 한다.
    - 따로 가중치가 없으므로, BFS를 통한 배열 밖을 나가는 경로가 필요하다.
- 초기 아이디어는 먼저 상근이가 나갈 때의 걸리는 시간을 구한다.
    - 그 다음 각 불에 대한 BFS를 진행, 각 불이 출구를 막거나, 출구까지 도달하는 시간을 구한다.
    - 비교./..?

---

# 풀이 과정

```cpp
#include <bits/stdc++.h>
using namespace std;
// https://www.acmicpc.net/problem/14864

int t, w, h;

vector<string> s;
vector<vector<char>> arr;

vector<pair<int, int>> dir = { {1, 0}, {-1, 0} , {0, 1} , {0, -1}};

pair<int, int> p;
vector<pair<int, int>> fire;

void solution();
int bfs(pair<int, int>);

void input() {

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> w >> h;
        arr = vector<vector<char>>(h);

        string str;
        for (int j = 0; j < h; j++) {
            cin >> str;

            s.push_back(str);
        }

        cout << "solution call" << '\n';

        solution();
        arr.clear();
        fire.clear();

        s.clear();
    }
}

void solution() {

    /*
     * 빌딩의 지도가 주어졌을 때, 얼마나 빨리 빌딩을 탈출할 수 있는지 구하는 프로그램을 작성하시오.
     * 출발지 -> 목적지가 주어진 최단 경로 = BFS + 깊이가 존재하는.
     * 나가는 조건
     * - bfs 탐색하면서 벽이나, 불이 아니면서 배열 바깥인 경우, check = true
     * 하지만 조건이 있다.
     *
     *
     * 상근 기준 BFS 와 불들 기준 bfs 비교 -> 만약 불이 더 짧으면 Impossible?
     * 같으면 안됨 ( 이제 불이 붙으려는 칸으로 이동할 수 없다. -> 같은 경우에 대해 배제하는 것 같음 )
     *
     */

    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j<s[i].size(); j++) {
            if (s[i][j] == '@') {
                p = {i, j};
                cout << p.first << " " << p.second << '\n';
            }
            else if (s[i][j] == '*') {
                fire.push_back({i, j});
            }
            arr[j].push_back(s[i][j]);
        }

    }

    // 상근 기준 BFS()
    int person = bfs(p);

    printf("상근: %d\n", person);

    // 불 기준 BFS()
    cout << "fire: ";
    vector<int> fireList;
    for (int i = 0; i < fire.size(); i++)
    {
        int x = bfs(fire[i]);
        fireList.push_back(x);
        cout << x << " ";
    }
    cout << '\n';

}

int bfs(pair<int, int> start) {
    queue<pair<int, int>> q;
    q.push(start);

    cout << start.first << " " << start.second << '\n';

    int visited[1001][1001];

    visited[start.first][start.second] = 1;
    int exit = 0;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        cout << cur.first << " " << cur.second << '\n';

        for (pair<int, int> i : dir) {
            // not 벽, 불,
            int next_x = cur.first + i.first, next_y = cur.second + i.second;
            if (next_x < 0 || next_x >= h || next_y < 0 || next_y >= w) {
                // 밖을 나갔다면 success;
                exit =  visited[cur.first][cur.second]+1;
                break;
            }
            if (arr[next_x][next_y] == '#')
                continue;
            if (arr[next_x][next_y] == '*')
                continue;
            if (arr[next_x][next_y] == '@')
                continue;
            if (visited[next_x][next_y] != 0)
                continue;

            visited[next_x][next_y] = visited[cur.first][cur.second] + 1;
            q.push(make_pair(next_x, next_y));
        }

    }

    return exit;
}

int main() {
    // ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    input();
    // solution();

    return 0;
}

```

---

# 결과 & 근거

- 아직도 BFS를 제대로 구현 못하는 것 같다.
    - 정확히는 뼈대는 구현하는데, 인덱싱적 접근에서 헷갈려서 인덱싱 오류로 실행 실패가 된다.
- 아이디어 접근은 좋았으나, 만약 불이 많아질 경우 시간 초과가 뜬다는 풀이가 많다.
    - 판의 크기가 크기 대문에 모든 불에 대한 BFS는 시간이 오래 걸린다.
    - 원래도 생각했었지만, 더 정확한 풀이는 “불 → 상근이 → 불 → …” 방식의 단계 별 BFS 가 필요하다…
    - 뭔가 자신 있게 풀었지만 확실하게 실패했을 것이다.
- https://daekyojeong.github.io/posts/BOJ15/, https://starlightbox.tistory.com/48

### 알고리즘 분류

- 그래프 이론 - 그래프 탐색
- 너비 우선 탐색
- 격자 그래프

**유사 알고리즘**

- https://www.acmicpc.net/problem/3055, 3055 탈출