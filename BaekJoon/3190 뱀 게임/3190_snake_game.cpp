#include <iostream>
#include <queue>
#include <regex>
#include <vector>
using namespace std;

// https://www.acmicpc.net/problem/3190

int boardSize, appleCount, headDir = 1, tailDir = 1, totalTime = 1;
int board[101][101];
pair<int, int> tail = { 1, 1 }, head = { 1, 1 };
queue<pair<pair<int, int>, int>> tailOnlyDir;

vector<pair<int, int>> snakeDir = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

string dir[100001];

// 빈 칸 = 0,  뱀 = 1,  사과 = 2
// snakeDir,    right, down = 1,    left, up = -1

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL), cout.tie(NULL);

    cin >> boardSize;
    cin >> appleCount;
    for (int i = 0; i < appleCount; i++) {
        int x, y;
        cin >> x >> y;
        board[x][y] = 2;
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        string b;

        cin >> a >> b;
        dir[a] = b;
    }

    while (true) {
        head.first += snakeDir[headDir].first, head.second += snakeDir[headDir].second;

        bool check1 = head.first <= boardSize && head.first > 0 && head.second <= boardSize && head.second > 0 ? true : false
        bool check2 = board[head.first][head.second] != 1 ? true : false;

        if (check1 && check2) { 
            if (board[head.first][head.second] != 2) {
                int pos1 = tailOnlyDir.front().first.first, pos2 = tailOnlyDir.front().first.second, changedTailDir = tailOnlyDir.front().second;

                if (tail.first == pos1 && tail.second == pos2) {
                    tailDir = changedTailDir;
                    tailOnlyDir.pop();
                }

                board[tail.first][tail.second] = 0;
                tail.first += snakeDir[tailDir].first, tail.second += snakeDir[tailDir].second;
                board[tail.first][tail.second] = 1;
            }

            board[head.first][head.second] = 1;

            if (!dir[totalTime].empty()) { 
                if (dir[totalTime] == "L") { 
                    headDir = (headDir + 3) % 4;
                }
                else { 
                    headDir = (headDir + 1) % 4;
                }
                tailOnlyDir.push({ {head.first, head.second}, headDir }); 
            }
        }
        else {
            break;
        }
        totalTime++;
    }
    printf("%d\n", totalTime);
    return 0;
}
