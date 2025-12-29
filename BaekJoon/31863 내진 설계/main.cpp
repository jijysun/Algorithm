#include <bits/stdc++.h>
using namespace std;

// https://www.acmicpc.net/problem/31863

int n, m;

char arr[1001][1001];

pair<int, int>  earthQuake;

vector<pair<int, int> > dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 상하좌우


int surviveBuilding = 0;
int collapsedbuilding =0;

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j]; // 공백/개행을 무시하고 한 글자씩 읽음
            if (arr[i][j] == '@') {
                earthQuake = {i, j};
            }
            else if (arr[i][j] == '*' || arr[i][j] == '#') {
                surviveBuilding++;
            }
        }
    }
}

void solution() {
    // 지진: 상하좌우 각 2칸
    // 여진: 상하좌우 1칸

    // 내진설계 X: 바로 0 으로 초기화
    // 내진설계 O: 1번 버티면 * 으로, 이후 다시 0으로

    queue<pair<int, int>> aftershock;


    // 진원지는 단 하나.
    for (int i = 0; i < 4; i++) {
        pair<int, int> n_e = {earthQuake.first + dir[i].first, earthQuake.second + dir[i].second};
        pair<int, int> nn_e = {
            earthQuake.first + dir[i].first + dir[i].first, earthQuake.second + dir[i].second + dir[i].second
        };
        if (arr[n_e.first][n_e.second] == '|') {
            // 맨처음 방파제 만나면 이후 스킵
            // 이후도 못감
            continue;
        }
        if (n_e.first >= 0 && n_e.first < n && n_e.second >= 0 && n_e.second < m) { // 배열 안에 있고, 건물을 접촉한 경우
            if (arr[n_e.first][n_e.second] == '*') {
                // 무너진 경우 여진 큐에 추가.
                aftershock.push({n_e.first, n_e.second});
                arr[n_e.first][n_e.second] = '!';
                surviveBuilding--, collapsedbuilding++;
            }
            else if (arr[n_e.first][n_e.second] == '#') { // 내진 설계는 감소
                arr[n_e.first][n_e.second] = '*';
            }
        }
        if (nn_e.first >= 0 && nn_e.first < n && nn_e.second >= 0 && nn_e.second < m) { // 배열 안에 있고, 건물을 접촉한 경우
            if (arr[nn_e.first][nn_e.second] == '*') {
                aftershock.push({nn_e.first, nn_e.second});
                arr[nn_e.first][nn_e.second] = '!';
                surviveBuilding--, collapsedbuilding++;
            }
            else if (arr[nn_e.first][nn_e.second] == '#') {
                arr[nn_e.first][nn_e.second] = '*';
            }
        }
    }

    // 여진 발생 큐가 빌 때 까지
    while (!aftershock.empty()) {
        pair<int, int> front = aftershock.front();
        aftershock.pop();

        for (int i = 0; i < 4; i++) {
            pair<int, int> n_e = {front.first + dir[i].first, front.second + dir[i].second};
            if (n_e.first >= 0 && n_e.first < n && n_e.second >= 0 && n_e.second < m) { // 배열 안에 있고,
                if (arr[n_e.first][n_e.second] == '*') { // 건물을 접촉한 경우
                    // 무너진 경우 여진 큐에 추가.
                    aftershock.push({n_e.first, n_e.second});
                    arr[n_e.first][n_e.second] = '!';
                    surviveBuilding--, collapsedbuilding++;
                }
                else if (arr[n_e.first][n_e.second] == '#') { // 내진 설계는 감소
                    arr[n_e.first][n_e.second] = '*';
                }
            }
        }
    }
    
    // 무너진 건물 + 무너지지 않은 건물의 개수 출력.
    cout << collapsedbuilding << " " << surviveBuilding << '\n';
}


int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    input(), solution();
}
