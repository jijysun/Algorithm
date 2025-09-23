#include <bits/stdc++.h>
using namespace std;

int N, M, K, ans, dist[251][251];

void input () {
    cin >> N >> M;
    // dist 배열 초기화
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dist[i][j] = i == j ? 0 : 50000;
        }
    }

    // 간선 입력
    for (int i = 1; i <= M; i++) {
        int u, v, b;
        cin >> u >> v >> b;
        // 이 간선을 지나는 경로가 최단거리일 경우 양방향으로 바꿀 필요가 없다
        dist[u][v] = 0;
        // 양방향이면 dist[v][u]도 0
        dist[v][u] = b ? 0 : 1;
    }
}

void solution () {
    // 플로이드 워셜
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    cin >> K;
    while (K--) {
        int s, e;
        cin >> s >> e;
        cout << dist[s][e] << '\n';
    }
}


int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    input ();

    solution();

}