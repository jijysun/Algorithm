#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/shared_ptr_base.h>

using namespace std;

bool visited[100001];
int asc[100001];
int n, m, r, cnt;

vector<int> graph[100001];

void dfs (int node) {
    if (visited[node]) {
        return;
    }
    visited[node] = true, cnt ++;
    asc[node] = cnt;
    for (int i = 0; i<graph[node].size(); i++) {
        dfs(graph[node][i]);
    }

}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m >> r;

    int a, b;
    for (int i = 0; i<m; i++) {
        cin >> a >> b;
        graph[a].push_back(b), graph[b].push_back(a);
    }

    for (int i = 1; i<=n; i++)
        sort(graph[i].begin(), graph[i].end());


    dfs (r);

    for (int i = 1; i<=n; i++)
        cout << asc[i] << '\n';

    return 0;
}
