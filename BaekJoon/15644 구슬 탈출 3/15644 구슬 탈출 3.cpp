#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <string.h>
#include <vector>

using namespace std;

int n, m; // 직사각형 크기
char board[11][11];

pair<int, int> red, blue, hole;
// bool red_visit [11][11]; // 방문을 bool 로 하는게 아니라 거기 까지는 어떻게 가는 지 String 으로
string red_visit[11][11]; // 방문을 bool 로 하는게 아니라 거기 까지는 어떻게 가는 지 String 으로

queue<pair<int, int> > red_q;

vector<int> direct; // 이동 횟수는 이거로, 안에 있는 건 movement 인덱스와 같게

// 시계 반대 방향, 좌 상 우 하
vector<pair<int, int> > movement = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

bool cant_find = false;


// visit 변수는 어떻게 표현..?

void bfs() {
    while (true) {
        red.first = red_q.front().first, red.second = red_q.front().second;
        red_q.pop();
        printf("현 위치: %d,%d\n", red.first, red.second);

        for (int i = 0; i < 4; i++) {
            // 4분할 BFS
            pair<int, int> pos = {red.first, red.second};

            // 벽이나 다른 구멍을 만나기 전 까지.
            printf("try %d...", i);

            while (true) {
                char next = board[pos.first + movement[i].first][pos.second + movement[i].second];

                if (next == 'O') {
                    red_visit[hole.first][hole.second] = red_visit[red.first][red.second] + to_string(i);
                    printf("return!\n");
                    return;
                }
                if (next == '#' || next == 'B') {
                    if (red_visit[pos.first][pos.second].empty()) {
                        red_visit[pos.first][pos.second] += red_visit[red.first][red.second] + to_string(i);
                        red_q.push({pos.first, pos.second});

                        printf("break!\n");
                        printf("%d,%d visited!\n", pos.first, pos.second);

                        // direct.push_back(i);
                    }
                    break;
                }
                pos.first += movement[i].first, pos.second += movement[i].second;
            }

            if (red_visit[red.first][red.second].size()>=10) {
                cout << "cant find hole!" << '\n';
                cant_find = true;
                return;
            }
        }
        printf("\n----\n");
    }
}

void print_board() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << red_visit[i][j];
        }
        cout << endl;
    }
}

int main() {
    cin >> n >> m;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;

        for (int j = 0; j < s.size(); j++) {
            board[i][j] = s[j];
            if (board[i][j] == 'R') {
                // red = {i, j};
                red_q.push({i, j});
                red_visit[i][j] = ' ';
            } else if (board[i][j] == 'B') {
                blue = {i, j};
            } else if (board[i][j] == 'O') {
                hole = {i, j};
            }
        }
    }

    bfs();

    if (cant_find) {
        cout << -1 << '\n';
        return 0;
    }

    printf("-----------\n");

    // cout <<red_visit[hole.first][hole.second] << '\n';

    cout << red_visit[hole.first][hole.second].size()-1 << '\n';
    for (int i = 1; i < red_visit[hole.first][hole.second].length(); i++) {
        switch (red_visit[hole.first][hole.second][i]) {
            case '0':
                cout << 'L';
                break;
            case '1':
                cout << 'U';
                break;
            case '2':
                cout << 'R';
                break;
            case '3':
                cout << 'D';
                break;
        }
    }

    return 0;
}
