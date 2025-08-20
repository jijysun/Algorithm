#include <algorithm>
#include <iostream>
#include <queue>
#include <string.h>
#include <vector>

using namespace std;

int n, m, hour, paper[101][101];
bool visit[101][101];

queue<pair<int, int> > cheese;
vector<pair<int, int> > dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // �� ���� �ð� ����

void outside_dfs(int x, int y) {
    for (int i = 0; i < dir.size(); i++) {
        int next_x = x + dir[i].first, next_y = y + dir[i].second;
        if (next_x < 0 || next_x >= n || (next_y < 0 || next_y >= m))
            continue; // �迭 ���� ��� ���.

        if (paper[next_x][next_y] <= 0 && !visit[next_x][next_y]) {
            // �ƿ� �ܺ� ���� -1 �̰ų�, ��Ƽ� ���� �ܺ� ���� 0 �� ���
            visit[next_x][next_y] = true;
            paper[next_x][next_y] = -1; // ������ �ܺ� �������� ǥ��
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

    // ġ� �ƴ�, ġ� ���� �� ���� �� ������ ���� DFS�� ���־�� �Ѵ�.
    while (!cheese.empty()) {
        outside_dfs(0, 0); // �ܺ� ������ ���� dfs! 0 -> -1

        queue<pair<int, int>> temp_cheese;
        vector<pair<int, int>> can_melt_cheese;

        while (!cheese.empty()) {
            int can_melt = 0, x = cheese.front().first, y = cheese.front().second;
            for (int j = 0; j < dir.size(); j++) {
                if (paper[(x + dir[j].first)][(y + dir[j].second)] == -1)  // �ܺ� �����̸�?
                    can_melt++;
            }

            if (can_melt < 2)
                temp_cheese.push({x, y}); // ���� �ʴ� ���Ϳ� ���ؼ��� ���Ϳ� ����
            else
                can_melt_cheese.push_back({x, y}); // melt! �� ���� melt �ؾ� ��!

            cheese.pop();
        }

        for (pair<int, int> melt : can_melt_cheese)
            paper[melt.first][melt.second] = -1;

        cheese = temp_cheese, memset(visit, false, sizeof(visit)), hour++; // ġ�� ����, visit �ʱ�ȭ, ���� �ð� ++
    }

    cout << hour << '\n';

    return 0;
}