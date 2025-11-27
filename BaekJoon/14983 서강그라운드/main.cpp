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