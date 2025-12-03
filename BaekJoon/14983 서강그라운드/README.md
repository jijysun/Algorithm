# 14983 서강그라운드 (성공)

# 문제 소개

[문제 사이트 링크](https://www.acmicpc.net/problem/14938)

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞힌 사람 | 정답 비율 |
| --- | --- | --- | --- | --- | --- |
| 1 초 | 128 MB | 22894 | 11877 | 9601 | 50.396% |

## 문제

예은이는 요즘 가장 인기가 있는 게임 서강그라운드를 즐기고 있다. 서강그라운드는 여러 지역중 하나의 지역에 낙하산을 타고 낙하하여, 그 지역에 떨어져 있는 아이템들을 이용해 서바이벌을 하는 게임이다. 서강그라운드에서 1등을 하면 보상으로 치킨을 주는데, 예은이는 단 한번도 치킨을 먹을 수가 없었다. 자신이 치킨을 못 먹는 이유는 실력 때문이 아니라 아이템 운이 없어서라고 생각한 예은이는 낙하산에서 떨어질 때 각 지역에 아이템 들이 몇 개 있는지 알려주는 프로그램을 개발을 하였지만 어디로 낙하해야 자신의 수색 범위 내에서 가장 많은 아이템을 얻을 수 있는지 알 수 없었다.

각 지역은 일정한 길이 l (1 ≤ l ≤ 15)의 길로 다른 지역과 연결되어 있고 이 길은 양방향 통행이 가능하다. 예은이는 낙하한 지역을 중심으로 거리가 수색 범위 m (1 ≤ m ≤ 15) 이내의 모든 지역의 아이템을 습득 가능하다고 할 때, 예은이가 얻을 수 있는 아이템의 최대 개수를 알려주자.

[](https://upload.acmicpc.net/ef3a5124-833a-42ef-a092-fd658bc8e662/-/preview/)

주어진 필드가 위의 그림과 같고, 예은이의 수색범위가 4라고 하자. ( 원 밖의 숫자는 지역 번호, 안의 숫자는 아이템 수, 선 위의 숫자는 거리를 의미한다) 예은이가 2번 지역에 떨어지게 되면 1번,2번(자기 지역), 3번, 5번 지역에 도달할 수 있다. (4번 지역의 경우 가는 거리가 3 + 5 = 8 > 4(수색범위) 이므로 4번 지역의 아이템을 얻을 수 없다.) 이렇게 되면 예은이는 23개의 아이템을 얻을 수 있고, 이는 위의 필드에서 예은이가 얻을 수 있는 아이템의 최대 개수이다.

## 입력

첫째 줄에는 지역의 개수 n (1 ≤ n ≤ 100)과 예은이의 수색범위 m (1 ≤ m ≤ 15), 길의 개수 r (1 ≤ r ≤ 100)이 주어진다.

둘째 줄에는 n개의 숫자가 차례대로 각 구역에 있는 아이템의 수 t (1 ≤ t ≤ 30)를 알려준다.

세 번째 줄부터 r+2번째 줄 까지 길 양 끝에 존재하는 지역의 번호 a, b, 그리고 길의 길이 l (1 ≤ l ≤ 15)가 주어진다.

지역의 번호는 1이상 n이하의 정수이다. 두 지역의 번호가 같은 경우는 없다.

## 출력

예은이가 얻을 수 있는 최대 아이템 개수를 출력한다.

## 예제

```
5 5 4
5 7 8 2 3
1 4 5
5 2 4
3 2 3
1 2 3

-> 23
```

---

# 초기 접근 방법

- 그래프 문제이다.
    - 근데 간선에 가중치 존재
    - 무방향 그래프? 이거 완전 다익스트라 아니야?

---

# 풀이 과정

- 사실 다익스트라 알고리즘을 한 번 쯤 공부해봤다면 쉬운 알고리즘이었다.

```cpp
#include <bits/stdc++.h>
using namespace std;

// https://www.acmicpc.net/problem/14938

int n, m, r;
vector<int> item;
vector<vector<pair<int, int>>> graph; // 거리, 목적지

using namespace std;

void input() {
    cin >> n >> m >> r;

    graph  = vector<vector<pair<int, int>>> (n+1);
    item = vector<int>(n+1);

    for (int i = 1; i<=n; i++) {
        cin >> item [i];
    }

    int a, b, l;
    for (int i = 0; i<r; i++) {
        cin >> a >> b >> l;
        graph[a].push_back({l, b});
        graph[b].push_back({l, a});
    }
}

int dijkstra (int start) {
    vector<int> dist (n+1, 99 );
    priority_queue<pair<int, int>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int cur_node = pq.top().second, cur_dist = pq.top().first;
        pq.pop();

        for (int i = 0; i<graph[cur_node].size(); i++) {
            int next_node = graph[cur_node][i].second;
            int next_dist = graph[cur_node][i].first + cur_dist;

            if (next_dist > m) { // 갈 수 없으면 continue
                // cout << "cant go to " << next_node << '\n';
                continue;
            }
            if (next_dist < dist[next_node]) {
                dist[next_node] = next_dist;
                pq.push({next_dist, next_node});
            }

        }
    }

    int sum = 0;
    for (int i = 1; i<dist.size(); i++) {
        if (dist[i] <= m) {
            sum+=item[i];
        }
    }
    // printf("%d 최대 아이템: %d\n", start, sum);
    return sum;
}

void solution() {
    // 무방향 그래프
    // 간선에 가중치 존재
    // 최대 경로 -> BFS..? 다익스트라...?
    // 예은이가 얻을 수 있는 최대 아이템 개수. -> 모든 정점에 대한 다익스트라?

    int max_sum = -1;
    for (int i = 0; i<n; i++) {
        // cout << "====" << i+1 << "====\n";
        int sum = dijkstra(i+1);

        if (max_sum < sum) {
            max_sum = sum;
        }
        // cout << "\n--------\n";
    }
    cout << max_sum << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    input();
    solution();
    return 0;
}
```

---

# 결과 & 근거

- 33분 만에 성공
    - 바로 직전에 여러 그래프 이론 관련 알고리즘을 공부했던 게 운이 좋았다.
    - 또한 심화나 변형이 아닌  다익스트라 알고리즘의 전형적인 개념을 물어보는 알고리즘 이었다.
    - 다익스트라로도 가능하기에 플로이드 워셜 로 풀이가 가능은 하다.
- https://velog.io/@717lumos/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%8B%A4%EC%9D%B5%EC%8A%A4%ED%8A%B8%EB%9D%BCDijkstra-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98

### 알고리즘 분류

- 그래프 이론
- 최단 경로
- 다익스트라
- 플로이드-워셜