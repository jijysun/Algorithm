#include <bits/stdc++.h>
using namespace std;

int n, m, arr[101][101], result=0, pre_melt_cnt=0;

queue<pair<int, int> > melt_cheese;

vector<pair<int, int> > dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // 위 부터 시계 방향

bool visited[101][101] = {false};

void input() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
}

void outside_dfs(int x, int y) {
    // 0.0 기준 DFs
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int n_x = x + dir[i].first, n_y = y + dir[i].second;

        if (n_x >= 0 && n_x < n && n_y >= 0 && n_y < m) { // 배열을 벗어나지 않으면서
            if (arr[n_x][n_y] == 1 && !visited[n_x][n_y]) {
                visited[n_x][n_y] = true;
                melt_cheese.push({n_x, n_y});
                pre_melt_cnt++;
            }
            else {
                if (!visited[n_x][n_y]) {
                    visited[n_x][n_y] = true;
                    outside_dfs(n_x, n_y);
                }
            }
        }
    }
}

void solution() {
    while (true) {

        outside_dfs(0, 0);

        if (melt_cheese.size() == 0) {
            break;
        }

        // visit 초기화

        for (int i = 0; i<101; i++) {
            for (int j = 0; j<101; j++) {
                visited[i][j] = false;
            }
        }

        result++, pre_melt_cnt = melt_cheese.size();

        while (melt_cheese.size() !=0) {
            arr[melt_cheese.front().first][melt_cheese.front().second] = -1;
            melt_cheese.pop();
        }

    }

    cout << result  << '\n' << pre_melt_cnt<< endl;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    input();

    solution();
}