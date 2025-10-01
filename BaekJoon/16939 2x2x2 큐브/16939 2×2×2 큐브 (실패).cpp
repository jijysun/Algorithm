#include <bits/stdc++.h>
using namespace std;

/*
 * https://www.acmicpc.net/problem/16939
 * 2*2*2 cube
 */

int n = 24;

int cube[24];
vector<vector<int>> dir = {{0, 3, 5, 7, 9, 11}, {2, 4, 6, 8, 10, 12} , {13, 14, 5, 6, 17, 18, 21, 22},
{15, 16, 7, 8, 19, 20, 23, 24}};
vector<vector<int>> check_dir = {{0, 1, 2, 3},{4, 5, 6, 7},{8, 9, 10, 11},{12, 13, 14, 15},{16, 17, 18, 19}, {20, 21, 22, 23}};


void input() {
    for (int  i = 0; i<n; i++) {
        cin >> cube[i];
    }
}

bool checkout(int a[24]) {
    int i = 0;
    for (int j = 0; j< check_dir.size(); j++) {
        for (int k = 0; k<check_dir[j].size(); k++) {
            if (a[check_dir[j][k]] != a[check_dir[j][(k+1)%dir[i].size()]]) {
                return false;
            }
        }

    }
    return true;
}

void solution() {
    // 정확히 한 번 면을 돌리는 알고리즘 -> 경우의 수는 4가지 * 위 아래 = 8번

    for (int i = 0; i<dir.size(); i++) {
        int new_cube[24], new_cube_rev[24];
        copy(begin(cube), end(cube), begin(new_cube));
        copy(begin(cube), end(cube), begin(new_cube_rev));

        for (int j = 0; j<dir[i].size(); j++) {
            printf("%d -> %d\n", new_cube[dir[i][j]], new_cube[dir[i][(j+1)%dir[i].size()]]);

            new_cube[dir[i][j]-1] =  new_cube[dir[i][(j+2)%dir[i].size()]-1] ;
        }
        printf("\n\n");
        for (int j = dir[i].size()-1; j>=0; j--) {
            printf("%d -> %d\n", new_cube_rev[dir[i][j]],  new_cube_rev[dir[i][(j-1)%dir[i].size()]]);
            new_cube_rev[dir[i][j]-1] = new_cube_rev[dir[i][(j-2)%dir[i].size()]-1];
        }

        // 검사
        if (checkout(new_cube) == true || checkout(new_cube_rev) == true) {
            cout << 1 << '\n';
            return;
        }

        for (int k = 0; k<24; k++) {
            if (k%4==0) {
                printf("\n");
            }
            printf("%d", new_cube[k]);
        }
        printf("\n\n");
        for (int k = 0; k<24; k++) {
            if (k%4==0) {
                printf("\n");
            }
            printf("%d", new_cube_rev[k]);
        }

        printf("\n\n--------\n\n");
    }
    cout << 0 << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    input();
    solution();
}