#include <bits/stdc++.h>
using namespace std;
// https://www.acmicpc.net/problem/14864

int t, w, h;

vector<string> s;
vector<vector<char>> arr;

vector<pair<int, int>> dir = { {1, 0}, {-1, 0} , {0, 1} , {0, -1}};


pair<int, int> p;
vector<pair<int, int>> fire;

void solution();
int bfs(pair<int, int>);

void input() {

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> w >> h;
        arr = vector<vector<char>>(h);

        string str;
        for (int j = 0; j < h; j++) {
            cin >> str;

            s.push_back(str);
        }

        cout << "solution call" << '\n';

        solution();
        arr.clear();
        fire.clear();

        s.clear();
    }
}


void solution() {

    /*
     * 빌딩의 지도가 주어졌을 때, 얼마나 빨리 빌딩을 탈출할 수 있는지 구하는 프로그램을 작성하시오.
     * 출발지 -> 목적지가 주어진 최단 경로 = BFS + 깊이가 존재하는.
     * 나가는 조건
     * - bfs 탐색하면서 벽이나, 불이 아니면서 배열 바깥인 경우, check = true
     * 하지만 조건이 있다.
     *
     *
     * 상근 기준 BFS 와 불들 기준 bfs 비교 -> 만약 불이 더 짧으면 Impossible?
     * 같으면 안됨 ( 이제 불이 붙으려는 칸으로 이동할 수 없다. -> 같은 경우에 대해 배제하는 것 같음 )
     *
     */

    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j<s[i].size(); j++) {
            if (s[i][j] == '@') {
                p = {i, j};
                cout << p.first << " " << p.second << '\n';
            }
            else if (s[i][j] == '*') {
                fire.push_back({i, j});
            }
            arr[j].push_back(s[i][j]);
        }

    }


    // 상근 기준 BFS()
    int person = bfs(p);

    printf("상근: %d\n", person);


    // 불 기준 BFS()
    cout << "fire: ";
    vector<int> fireList;
    for (int i = 0; i < fire.size(); i++)
    {
        int x = bfs(fire[i]);
        fireList.push_back(x);
        cout << x << " ";
    }
    cout << '\n';

}

int bfs(pair<int, int> start) {
    queue<pair<int, int>> q;
    q.push(start);

    cout << start.first << " " << start.second << '\n';

    int visited[1001][1001];

    visited[start.first][start.second] = 1;
    int exit = 0;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        cout << cur.first << " " << cur.second << '\n';

        for (pair<int, int> i : dir) {
            // not 벽, 불,
            int next_x = cur.first + i.first, next_y = cur.second + i.second;
            if (next_x < 0 || next_x >= h || next_y < 0 || next_y >= w) {
                // 밖을 나갔다면 success;
                exit =  visited[cur.first][cur.second]+1;
                break;
            }
            if (arr[next_x][next_y] == '#')
                continue;
            if (arr[next_x][next_y] == '*')
                continue;
            if (arr[next_x][next_y] == '@')
                continue;
            if (visited[next_x][next_y] != 0)
                continue;

            visited[next_x][next_y] = visited[cur.first][cur.second] + 1;
            q.push(make_pair(next_x, next_y));
        }

    }

    return exit;
}



int main() {
    // ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    input();
    // solution();

    return 0;
}