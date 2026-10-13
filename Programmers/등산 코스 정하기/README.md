# 프로그래머스, 등산 코스 정하기 (실패)

# 문제 소개

[문제 사이트 링크](https://school.programmers.co.kr/learn/courses/30/lessons/118669)

XX산은 `n`개의 지점으로 이루어져 있습니다. 각 지점은 1부터 `n`까지 번호가 붙어있으며, 출입구, 쉼터, 혹은 산봉우리입니다. 각 지점은 양방향 통행이 가능한 등산로로 연결되어 있으며, 서로 다른 지점을 이동할 때 이 등산로를 이용해야 합니다. 이때, 등산로별로 이동하는데 일정 시간이 소요됩니다.

등산코스는 방문할 지점 번호들을 순서대로 나열하여 표현할 수 있습니다.

예를 들어 `1-2-3-2-1` 으로 표현하는 등산코스는 1번지점에서 출발하여 2번, 3번, 2번, 1번 지점을 순서대로 방문한다는 뜻입니다.

등산코스를 따라 이동하는 중 쉼터 혹은 산봉우리를 방문할 때마다 휴식을 취할 수 있으며, 휴식 없이 이동해야 하는 시간 중 가장 긴 시간을 해당 등산코스의 `intensity`라고 부르기로 합니다.

당신은 XX산의 출입구 중 한 곳에서 출발하여 산봉우리 중 한 곳만 방문한 뒤 다시 **원래의** 출입구로 돌아오는 등산코스를 정하려고 합니다. 다시 말해, 등산코스에서 출입구는 **처음과 끝에 한 번씩**, 산봉우리는 **한 번만** 포함되어야 합니다.

당신은 이러한 규칙을 지키면서 `intensity`가 최소가 되도록 등산코스를 정하려고 합니다.

다음은 XX산의 지점과 등산로를 그림으로 표현한 예시입니다.

![desc1-1.PNG](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/d1764091-629a-414b-9f77-e2ff1b38c6e0/desc1-1.PNG)

- 위 그림에서 원에 적힌 숫자는 지점의 번호를 나타내며, 1, 3번 지점에 출입구, 5번 지점에 산봉우리가 있습니다. 각 선분은 등산로를 나타내며, 각 선분에 적힌 수는 이동 시간을 나타냅니다. 예를 들어 1번 지점에서 2번 지점으로 이동할 때는 3시간이 소요됩니다.

위의 예시에서 `1-2-5-4-3` 과 같은 등산코스는 처음 출발한 원래의 출입구로 돌아오지 않기 때문에 잘못된 등산코스입니다. 또한 `1-2-5-6-4-3-2-1` 과 같은 등산코스는 코스의 처음과 끝 외에 3번 출입구를 방문하기 때문에 잘못된 등산코스입니다.

등산코스를 `3-2-5-4-3` 과 같이 정했을 때의 이동경로를 그림으로 나타내면 아래와 같습니다.

![desc1-2.PNG](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/ae2b6ccd-290b-4074-aebe-028c13dc4cbe/desc1-2.PNG)

이때, 휴식 없이 이동해야 하는 시간 중 가장 긴 시간은 5시간입니다. 따라서 이 등산코스의 `intensity`는 5입니다.

등산코스를 `1-2-4-5-6-4-2-1` 과 같이 정했을 때의 이동경로를 그림으로 나타내면 아래와 같습니다.

![desc1-3.PNG](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/165bcca3-ee06-46b4-95f8-7c3cedd2cb42/desc1-3.PNG)

이때, 휴식 없이 이동해야 하는 시간 중 가장 긴 시간은 3시간입니다. 따라서 이 등산코스의 `intensity`는 3이며, 이 보다 `intensity`가 낮은 등산코스는 없습니다.

XX산의 지점 수 `n`, 각 등산로의 정보를 담은 2차원 정수 배열 `paths`, 출입구들의 번호가 담긴 정수 배열 `gates`, 산봉우리들의 번호가 담긴 정수 배열 `summits`가 매개변수로 주어집니다. 이때, `intensity`가 최소가 되는 등산코스에 포함된 산봉우리 번호와 `intensity`의 최솟값을 차례대로 정수 배열에 담아 return 하도록 solution 함수를 완성해주세요. `intensity`가 최소가 되는 등산코스가 여러 개라면 그중 산봉우리의 번호가 가장 낮은 등산코스를 선택합니다.

---

#### 제한사항

- 2 ≤ `n` ≤ 50,000
- `n` - 1 ≤ `paths`의 길이 ≤ 200,000
- `paths`의 원소는 `[i, j, w]` 형태입니다.
    - `i`번 지점과 `j`번 지점을 연결하는 등산로가 있다는 뜻입니다.
    - `w`는 두 지점 사이를 이동하는 데 걸리는 시간입니다.
    - 1 ≤ `i` < `j` ≤ `n`
    - 1 ≤ `w` ≤ 10,000,000
    - 서로 다른 두 지점을 직접 연결하는 등산로는 최대 1개입니다.
- 1 ≤ `gates`의 길이 ≤ `n`
    - 1 ≤ `gates`의 원소 ≤ `n`
    - `gates`의 원소는 해당 지점이 출입구임을 나타냅니다.
- 1 ≤ `summits`의 길이 ≤ `n`
    - 1 ≤ `summits`의 원소 ≤ `n`
    - `summits`의 원소는 해당 지점이 산봉우리임을 나타냅니다.
- 출입구이면서 동시에 산봉우리인 지점은 없습니다.
- `gates`와 `summits`에 등장하지 않은 지점은 모두 쉼터입니다.
- 임의의 두 지점 사이에 이동 가능한 경로가 항상 존재합니다.
- return 하는 배열은 `[산봉우리의 번호, intensity의 최솟값]` 순서여야 합니다.

---

#### 입출력 예

| n | paths | gates | summits | result |
| --- | --- | --- | --- | --- |
| 6 | [[1, 2, 3], [2, 3, 5], [2, 4, 2], [2, 5, 4], [3, 4, 4], [4, 5, 3], [4, 6, 1], [5, 6, 1]] | [1, 3] | [5] | [5, 3] |
| 7 | [[1, 4, 4], [1, 6, 1], [1, 7, 3], [2, 5, 2], [3, 7, 4], [5, 6, 6]] | [1] | [2, 3, 4] | [3, 4] |
| 7 | [[1, 2, 5], [1, 4, 1], [2, 3, 1], [2, 6, 7], [4, 5, 1], [5, 6, 1], [6, 7, 1]] | [3, 7] | [1, 5] | [5, 1] |
| 5 | [[1, 3, 10], [1, 4, 20], [2, 3, 4], [2, 4, 6], [3, 5, 20], [4, 5, 6]] | [1, 2] | [5] | [5, 6] |

---

#### 입출력 예 설명

**입출력 예 #1**

문제 예시와 같습니다. 등산코스의 `intensity`가 최소가 되는 산봉우리 번호는 5, `intensity`의 최솟값은 3이므로 `[5, 3]`을 return 해야 합니다.

**입출력 예 #2**

XX산의 지점과 등산로를 그림으로 표현하면 아래와 같습니다.

![ex2.PNG](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/b978b0f5-7e8b-4dbe-aeb0-a6c21a3431e4/ex2.PNG)

가능한 `intensity`의 최솟값은 4이며, `intensity`가 4가 되는 등산코스는 `1-4-1` 과 `1-7-3-7-1` 이 있습니다. `intensity`가 최소가 되는 등산코스가 여러 개이므로 둘 중 산봉우리의 번호가 낮은 `1-7-3-7-1` 을 선택합니다. 따라서 `[3, 4]`를 return 해야 합니다.

**입출력 예 #3**

XX산의 지점과 등산로를 그림으로 표현하면 아래와 같습니다.

![ex3.PNG](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/53399b93-368c-42bd-ad68-1230f59479c8/ex3.PNG)

가능한 `intensity`의 최솟값은 1이며, 그때의 등산코스는 `7-6-5-6-7` 입니다. 따라서 `[5, 1]`를 return 해야 합니다.

- `7-6-5-4-1-4-5-6-7` 과 같은 등산코스는 산봉우리를 여러 번 방문하기 때문에 잘못된 등산코스입니다.

**입출력 예 #4**

XX산의 지점과 등산로를 그림으로 표현하면 아래와 같습니다.

![ex4.PNG](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/0abfa9ed-7b1a-4619-a23d-1becf94d1bc3/ex4.PNG)

가능한 `intensity`의 최솟값은 6, 그때의 등산코스는 `2-4-5-4-2` 입니다. 따라서 `[5, 6]`을 return 해야 합니다.

---

# 풀이 과정

- 각 gate 에서 DFS 백트래킹으로 모든 경로를 열거했다.
- 그리고 나서  (출발→봉우리) + (봉우리→출발)을 대조해 최소 intensity 를 구하려 했다.
    - 40분 포기. 백트래킹 경로부터 잘못됐다.

```cpp

vector <int> visited;
vector<int> dest, gate;
vector <vector<pair<int, int>>> graph; // [다음 노드, 다음 노드와의 가중치.]

int start; // DFS 호출할 때 마다 초기화

struct Result
{
    int start;
    int end;
    int intensity;
};
vector <Result> dfs_result;

vector<int> visit_node;

void dfs (int node, int intensity){ // 대신 모든 경우의 수 확인 = 백트래킹 조건이 있어야 함
    visit_node.push_back(node);

    for (int i = 0; i<graph[node].size(); i++){

        int next_num = graph[node][i].first, next_inten = graph[node][i].second;

        if(visited[next_num]){
            continue;
        }
        for (int g : gate){
            if (next_num == g){
                continue;
            }
        }

        for (int d : dest){
            if (next_num == d){
                // 이 경우의 수의 최소 Intensity 저장.
                if (intensity < next_inten){
                    intensity = next_inten;
                }
                // 출발지, 목적지, intensity 값 저장해야 해.
                dfs_result.push_back({start, next_num, intensity});

                cout << "visit_node: ";
                for (int l : visit_node){
                    cout << l << " ";
                }
                cout <<'\n';

                cout << start << " " << next_num << " " << intensity << endl;
                return;
            }
        }

        if (intensity < next_inten){
            intensity = next_inten;
        }
        visited[next_num] = 1;
        dfs (next_num, intensity);
        visited[next_num] = 0;
    }
    visit_node.pop_back();

}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    dest = summits;
    gate = gates;
    graph.assign(n+1,vector<pair<int, int>>());
    visited.assign (n+1, 0);

    for (int i = 0; i<paths.size(); i++){ // 인접리스트 초기화
        int start = paths[i][0], end = paths[i][1], val = paths[i][2];
        graph[start].push_back({end, val}), graph[end].push_back ({start, val});
    }

    for (int s : gates){
        // dfs 호출 후 최솟값 매번 저장
        start = s;
        dfs (s, 0); // 각 출입구 기준 DFS   

        visited.clear();
        visit_node.clear();
    }

    cout << "\n----------------------------\n" << '\n';

    dest = gates;
    for (int s : summits){
        start = s;
        dfs (s, 0);
    }

    // return 하는 배열은 [산봉우리의 번호, intensity의 최솟값] 순서
    return answer;
}
```

---

# 결과 & 근거

- 사실 접근 부터 잘못되었다
    - 복잡도상 불가능한 접근이었다
    - 왕복을 구할 필요가 없었다.  intensity 는 "경로에서 지나는 최대 간선"이다.
        - 갔던 길로 되돌아오면 새 간선이 추가되지 않으므로 최대값이 바뀌지 않는다.
        - 즉 왕복 intensity = 편도 intensity. 대조 로직 자체가 불필요
- 다익스트라를 배제한 근거가 틀렸다
    - "중간에 많이 거쳐도 되니 최단 경로가 아니다"라고 판단했다.
    - 다익스트라는 "거리 정의"를 바꿔 쓸 수 있는 틀이다.
    - 정답은 다익스트라 O(E log V) ≈ 310만, 실측 75ms.

```cpp
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {

    // ── 1. 인접 리스트: {다음 노드, 가중치}
    vector<vector<pair<int,int>>> adj(n + 1);
    for (auto& p : paths) {
        adj[p[0]].push_back({p[1], p[2]});
        adj[p[1]].push_back({p[0], p[2]});      // 양방향 통행
    }

    // ── 2. 출입구/산봉우리를 O(1) 조회 배열로. ★ gates 길이가 최대 n 이라
    //       매번 for 로 선형 탐색하면 복잡도에 O(n) 이 곱해진다
    vector<bool> is_gate(n + 1, false), is_summit(n + 1, false);
    for (int g : gates)   is_gate[g] = true;
    for (int s : summits) is_summit[s] = true;

    // ── 3. dist[v] = 어떤 출입구에서 v 까지 가는 경로 중
    //                 "경로상 최대 간선 값"이 가장 작은 것 = v 까지의 최소 intensity
    const int INF = 1e9;
    vector<int> dist(n + 1, INF);

    // {intensity, 노드}. pair 는 first 기준 정렬이라 비용이 앞에 와야 한다.
    // greater 를 줘야 최솟값이 top 에 온다
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    // ── 4. 다중 시작점: 모든 출입구를 intensity 0 으로 함께 넣는다.
    //       출입구마다 따로 돌리지 않는다 (그러면 O(gates × E log V) 가 된다)
    for (int g : gates) {
        dist[g] = 0;
        pq.push({0, g});
    }

    while (!pq.empty()) {
        auto [cur_int, cur] = pq.top();
        pq.pop();

        if (cur_int > dist[cur]) continue;   // ★ 낡은 항목. visited 배열 대신 이 한 줄
        if (is_summit[cur])      continue;   // 산봉우리는 종점 — 지나갈 수 없으므로 확장 안 함

        for (auto& [nx, w] : adj[cur]) {
            if (is_gate[nx]) continue;       // 다른 출입구로는 들어가지 않는다

            int next_int = max(cur_int, w);  // ★★ 합(+)이 아니라 최대(max).
                                             //    intensity 는 "경로에서 가장 긴 구간"이므로
                                             //    누적이 아니라 최대값 갱신이다

            if (next_int >= dist[nx]) continue;   // 개선되지 않으면 버린다
            dist[nx] = next_int;
            pq.push({next_int, nx});
        }
    }

    // ── 5. 산봉우리 중 intensity 최소. 동일하면 번호가 작은 것
    //       → 오름차순 정렬 후 "<" 로 비교하면 먼저 만난(작은 번호) 쪽이 남는다
    sort(summits.begin(), summits.end());
    vector<int> answer = {0, INF};
    for (int s : summits) {
        if (dist[s] < answer[1]) answer = {s, dist[s]};
    }
    return answer;
}
```

### 알고리즘 분류

- 다익스트라 (변형: 최소 병목 경로 / minimax path)
- 다중 시작점 최단 경로
- 우선순위 큐
- 그래프 이론