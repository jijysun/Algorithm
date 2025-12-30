#include <bits/stdc++.h>
using namespace std;

// https://www.acmicpc.net/problem/15683

int n, m, observe;

int room[9][9];

struct cctv {
    int num, x, y;
};

struct canObserve {
    int up, down, left, right;
};


vector<cctv> cctvList;

void input() {
    cin >> n >> m;
    observe = n * m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> room[i][j];
            if (room[i][j] != 0 && room[i][j] != 6) {
                cctvList.push_back({room[i][j], i, j});
            }
            if (room[i][j] != 0) {
                observe--;
            }
        }
    }
}

bool compare(cctv c1, cctv c2) {
    return c1.num > c2.num;
}

canObserve search(int x, int y) {
    canObserve s = {0,0,0,0};

    if (x != 0) {
        for (int i = x - 1; i >= 0; i--) {
            // 열
            if (room[i][y] == 6) {
                break;
            }
            if (room[i][y] == 0) {
                 s.up++;
            }
        }
    }

    if (x != n - 1) {
        for (int i = x; i < n; i++) {
            // 아래로 열
            if (room[i][y] == 6) {
                break;
            }
            if (room[i][y] == 0) {
                 s.down++;
            }
        }
    }

    if (y!=0) {
        for (int i = y - 1; i >= 0; i--) {
            // 행
            if (room[x][i] == 6) {
                break;
            }
            if (room[x][i] == 0) {
                 s.left++;
            }
        }
    }

    if (y != m-1) {
        for (int i = y; i < m; i++) {
            // 행
            if (room[x][i] == 6) {
                break;
            }
            if (room[x][i] == 0) {
                s.right++;
            }
        }
    }
    return s;
}

void observeRoom(int x, int y, int up, int down, int left, int right) {
    if (x != 0 && up) {
        for (int i = x - 1; i >= 0; i--) {
            // 열
            if (room[i][y] == 6) {
                break;
            }
            if (room[i][y] == 0) {
                room[i][y] = -1;
            }
        }
    }

    if (x != n - 1 && down) {
        for (int i = x; i < n; i++) {
            // 아래로 열
            if (room[i][y] == 6) {
                break;
            }
            if (room[i][y] == 0) {
                room[i][y] = -1;
            }
        }
    }

    if (y!=0 && left) {
        for (int i = y - 1; i >= 0; i--) {
            // 행
            if (room[x][i] == 6) {
                break;
            }
            if (room[x][i] == 0) {
                room[x][i] = -1;
            }
        }
    }

    if (y != m-1 && right) {
        for (int i = y; i < m; i++) {
            // 행
            if (room[x][i] == 6) {
                break;
            }
            if (room[x][i] == 0) {
                room[x][i] = -1;
            }
        }
    }
}



void solution() {
    // CCTV -> 감시 가능, 벽이 있는 곳 감시 불가능
    /*
     * CCTV
     * - 감시 가능, 벽 쪽 감시 불가능
     * - 회전 가능 (90도)
     *
     * 일단 5번은 어디에 있든 상관 x
     */

    sort(cctvList.begin(), cctvList.end(), compare); // 많은 탐색 기준


    // 감시 가능 -1로 표현

    for (cctv c: cctvList) {
        printf("%d -> %d.%d\n", c.num, c.x, c.y);

        if (c.num == 5) {
            for (int i = 0; i < m; i++) {
                // 행
                if (room[c.x][i] == 6) {
                    break;
                }
                if (room[c.x][i] == 0) {
                    room[c.x][i] = -1, observe--;
                }
            }
            continue;
        }
        if (c.num == 4) {
            canObserve s = search(c.x, c.y);
            int maxOb = s.down+s.left+s.left+s.right;
            max(maxOb-s.down, max (maxOb-s.left, max(maxOb-s.right, maxOb-s.up));
        }

        for () {
            // 90도 회전은 어떻게?
        }
    }


    // CCTV의 최대 개수는 8개를 넘지 않는다. -> 입력 값과 전체 데이터 개수가 적으므로 완전탐색해도 될 듯.


    // 사각 지대를 최소화 해야 한다. 사각지대의 최소 크기를 구하시오.
}


int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    input(), solution();
}
