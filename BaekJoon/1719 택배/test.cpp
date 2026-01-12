#include <bits/stdc++.h>
using namespace std;
// https://www.acmicpc.net/problem/1719

#define INF 1000 // 최대 경로는 1000

int n, m;

vector<vector<pair<int, int>>> logics_vec;
// int logics_arr[100][100];

vector<vector<int>> dij;
vector<vector<int>> result;

void input() {

    cin >> n >> m;

    logics_vec = vector(n+2, vector<pair<int, int>>());

    int from, to, weight;

    for (int i = 0; i < m; i++) {

        cin >> from >> to >> weight;

        logics_vec[from].push_back({to, weight});
        logics_vec[to].push_back({from, weight});
        // logics_arr[from][to] = logics_arr[to][from] = weight;
    }
}

vector<int> dijkstra(int start) {
    vector<int> dist(n+1, INF);
    dist[start] = 0;

    // 가까운 정점 기준, 거리/정점
    priority_queue<pair<int, int>> pq;
    pq.push({dist[start], start});

    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        top.first = -top.first;

        pq.pop();
        for (pair<int, int> next : logics_vec[top.second]) {
            if (dist[next.first] > top.first + next.second) {
                dist[next.first] = top.first + next.second;
                pq.push ({-dist[next.first], next.first});
            }
        }


    }
    return dist;
}

void solution() {

    /*
     * 집하장을 몇 개 마련했지만, 택배 화물이 각 집하장들 사이를 오갈 때 어떤 경로를 거쳐야 하는지 결정하지 못했다.
     * 어떤 경로를 거칠지 정해서, 이를 경로표로 정리하는 것이 여러분이 할 일이다.
     *
     * 모든 집하장 기준에 대한 타 집하장 과의 최단 경로
     * = 모든 집하장에 대한 다익스트라가 필요
     */

    for (int i = 1; i <= n; i++) {
        result.push_back(dijkstra(i));
    }
    result.push_back(dijkstra(0));

    for (int i = 1; i < result.size(); i++){
        for (int j = 1; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << '\n';
    }
}


int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    input();
    solution();
}
