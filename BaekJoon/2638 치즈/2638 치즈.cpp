#include <algorithm>
#include <iostream>
#include <queue>
#include <string.h>
#include <vector>

using namespace std;

int n, m, hour, paper[101][101];
bool visit[101][101];

queue<pair<int, int> > cheese;
vector<pair<int, int> > dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // 위 부터 시계 방향

void outside_dfs(int x, int y) {
    for (int i = 0; i < dir.size(); i++) {
        int next_x = x + dir[i].first, next_y = y + dir[i].second;
        if (next_x < 0 || next_x >= n || (next_y < 0 || next_y >= m))
            continue; // 배열 밖을 벗어난 경우.

        if (paper[next_x][next_y] <= 0 && !visit[next_x][next_y]) {
            // 아예 외부 공간 -1 이거나, 녹아서 생긴 외부 공간 0 인 경우
            visit[next_x][next_y] = true;
            paper[next_x][next_y] = -1; // 완전히 외부 공간으로 표현
            outside_dfs(next_x, next_y);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> paper[i][j];
            if (paper[i][j] == 1) cheese.push({i, j}); // cheese.push_back({i, j});
        }
    }

    paper[0][0] = -1;

    // 치즈가 아닌, 치즈가 녹을 때 마다 빈 공간에 대해 DFS를 해주어야 한다.
    while (!cheese.empty()) {
        outside_dfs(0, 0); // 외부 공간에 대한 dfs! 0 -> -1

        queue<pair<int, int>> temp_cheese;
        vector<pair<int, int>> can_melt_cheese;

        while (!cheese.empty()) {
            int can_melt = 0, x = cheese.front().first, y = cheese.front().second;
            for (int j = 0; j < dir.size(); j++) {
                if (paper[(x + dir[j].first)][(y + dir[j].second)] == -1)  // 외부 공간이면?
                    can_melt++;
            }

            if (can_melt < 2)
                temp_cheese.push({x, y}); // 녹지 않는 벡터에 대해서만 벡터에 복사
            else
                can_melt_cheese.push_back({x, y}); // melt! 한 번에 melt 해야 함!

            cheese.pop();
        }

        for (pair<int, int> melt : can_melt_cheese)
            paper[melt.first][melt.second] = -1;

        cheese = temp_cheese, memset(visit, false, sizeof(visit)), hour++; // 치즈 복붙, visit 초기화, 녹은 시간 ++
    }

    cout << hour << '\n';

    return 0;
}