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