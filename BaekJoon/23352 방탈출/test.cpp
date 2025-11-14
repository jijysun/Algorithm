#include <bits/stdc++.h>
using namespace std;

int n, m;
int room[51][51];

int room_sum, a_d; // start, end, depth

vector<int> dx = {0, 0, 1};
vector<int> dy = {-1, 1, 0};

void input() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> room[i][j];
        }
    }
}


void bfs(int start, int end, bool visited[51][51]) {
    // queue

    queue<pair<int, int> > q;
    q.push({start, end});
    visited[start][end] = true;

    while (!q.empty()) {
        pair<int, int> pos = q.front();
        q.pop();

        cout << "pos: " << pos.first << "," << pos.second << '\n';

        for (int i = 0; i < 3; i++) {
            pair<int, int> next = {pos.first + dx[i], pos.second + dy[i]};

            if (next.first < 0 || next.first >= n || next.second < 0 || next.second >= m ) {
                continue;
            }

            if (room[next.first][next.second] && !visited[next.first][next.second]) {
                q.push({next.first, next.second});
                visited[next.first][next.second] = true;
            }
            else if (next.first == n-1) {
                // depth 측정할 수 있어야 함!
                int depth = abs(start - next.first) + abs(end - next.second);

                if (a_d < depth) {
                    printf("end! start (%d,%d): %d, end(%d,%d): %d, depth: %d\n", start, end, room[start][end], next.first, next.second,  room[next.first][next.second], depth);
                    room_sum = room[start][end] + room[next.first][next.second];
                }
                else if (a_d == depth && room_sum < room[start][end] + room[next.first][next.second]) {
                    printf("end! start (%d,%d): %d, end(%d,%d): %d, depth: %d\n", start, end, room[start][end], next.first, next.second,  room[next.first][next.second], depth);
                    room_sum = room[start][end] + room[next.first][next.second];
                }
            }
        }
    }
}


void solution() {
    // 가장 긴 경로
    // 탈출 하려면 위 -> 아래인가?


    /*
     * 문제의 핵심: 가장 긴 경로를 찾는 BFS 구현하기.
     */

    room_sum= 0, a_d = 0;

    for (int i = 0; i < m; i++) {
        if (room[0][i]) {
            cout << "---- start -> " << 0 << "," << i << "---\n";
            bool visited[51][51] = {false};
            bfs(0, i, visited);
            cout << "--- end ---- \n";
        }
    }
    cout << room_sum <<'\n';
}


int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    input();
    solution();
}
