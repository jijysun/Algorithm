#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <string.h>
#include <vector>

using namespace std;

int n, m; // ���簢�� ũ��
char board[11][11];

pair<int, int> red, blue, hole;
// bool red_visit [11][11]; // �湮�� bool �� �ϴ°� �ƴ϶� �ű� ������ ��� ���� �� String ����
string red_visit[11][11]; // �湮�� bool �� �ϴ°� �ƴ϶� �ű� ������ ��� ���� �� String ����

queue<pair<int, int> > red_q;

vector<int> direct; // �̵� Ƚ���� �̰ŷ�, �ȿ� �ִ� �� movement �ε����� ����

// �ð� �ݴ� ����, �� �� �� ��
vector<pair<int, int> > movement = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

bool cant_find = false;


// visit ������ ��� ǥ��..?

void bfs() {
    while (true) {
        red.first = red_q.front().first, red.second = red_q.front().second;
        red_q.pop();
        printf("�� ��ġ: %d,%d\n", red.first, red.second);

        for (int i = 0; i < 4; i++) {
            // 4���� BFS
            pair<int, int> pos = {red.first, red.second};

            // ���̳� �ٸ� ������ ������ �� ����.
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
