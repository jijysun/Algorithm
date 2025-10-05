# 16939 2×2×2 큐브 (실패)

# 문제 소개

[문제 사이트 링크](https://www.acmicpc.net/problem/1283)

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞힌 사람 | 정답 비율 |
| --- | --- | --- | --- | --- | --- |
| 2 초 | 512 MB | 2231 | 959 | 715 | 41.546% |

## 문제

오늘은 2×2×2 [루빅스 큐브](https://en.wikipedia.org/wiki/Rubik's_Cube)를 풀어보려고 한다. 큐브의 각 면은 양방향으로 90도 돌릴 수 있게 만들어져 있다. 큐브의 각 면에 있는 색상이 모두 같으면 큐브를 풀었다고 한다.

2×2×2 루빅스 큐브가 주어졌을 때, 정확히 한 번 돌려서 큐브를 풀 수 있는지 아닌지 구해보자.

## 입력

첫째 줄에 2×2×2 루빅스 큐브 각 면의 각 칸 색상이 주어진다. 색상은 1부터 6까지의 자연수로 나타내며, 각 자연수는 총 4번 등장한다. i번째 수가 의미하는 칸은 아래와 같다.

[](https://upload.acmicpc.net/8742b71d-e834-4901-b71b-aa4a47fc04a3/-/preview/)

## 출력

루빅스 큐브를 정확히 한 번 돌려서 풀 수 있으면 1, 없으면 0을 출력한다.

---

# 초기 접근 방법

- 따로 알고리즘이 없는 인덱스 접근이 중요한 알고리즘 문제인 듯 하다.

---

# 풀이 과정

```cpp
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
```

---

# 결과 & 근거

- 분명 쉬운 문제는 맞다…..
- 인덱스 접근 에서 너무 헤매서 결국 실패했다.
- https://100100e.tistory.com/216 → 보면 정말 하드 코딩으로 단순하게 풀었다.

### 알고리즘 분류

- 구현 (ㄹㅇ 구현)