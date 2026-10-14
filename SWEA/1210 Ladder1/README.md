# SWEA 1210,  Ladder1 (성공)

# 문제 소개

[문제 사이트 링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=3&problemLevel=4&contestProbId=AV14ABYKADACFAYh&categoryId=AV14ABYKADACFAYh&categoryType=CODE&problemTitle=&orderBy=INQUERY_COUNT&selectCodeLang=ALL&select-1=4&pageSize=10&pageIndex=1)

점심 시간에 산책을 다니는 사원들은 최근 날씨가 더워져, 사다리 게임을 통하여 누가 아이스크림을 구입할지 결정하기로 한다. 김 대리는 사다리타기에 참여하지 않는 대신 사다리를 그리기로 하였다.

![[SW문제해결+기본]+2일차+-+Ladder+1_그림1.png](SW%EB%AC%B8%EC%A0%9C%ED%95%B4%EA%B2%B0%EA%B8%B0%EB%B3%B82%EC%9D%BC%EC%B0%A8-Ladder1_%EA%B7%B8%EB%A6%BC1.png)

사다리를 다 그리고 보니 김 대리는 어느 사다리를 고르면 X표시에 도착하게 되는지 궁금해졌다. 

이를 구해보자.  <그림 1>의 예를 살펴보면, 출발점 x=0 및 x=9인 세로 방향의 두 막대 사이에 임의의 개수의 막대들이 랜덤 간격으로 추가되고(이 예에서는 2개가 추가됨) 이 막대들 사이에 가로 방향의 선들이 또한 랜덤하게 연결된다. 

X=0인 출발점에서 출발하는 사례에 대해서 화살표로 표시한 바와 같이, 아래 방향으로 진행하면서 좌우 방향으로 이동 가능한 통로가 나타나면 방향 전환을 하게 된다.

방향 전환 이후엔 다시 아래 방향으로만 이동하게 되며, 바닥에 도착하면 멈추게 된다.문제의 X표시에 도착하려면 X=4인 출발점에서 출발해야 하므로 답은 4가 된다. 해당 경로는 별도로 표시하였다.

아래 <그림 2>와 같은

![[SW문제해결+기본]+2일차+-+Ladder+1_그림2.png](SW%EB%AC%B8%EC%A0%9C%ED%95%B4%EA%B2%B0%EA%B8%B0%EB%B3%B82%EC%9D%BC%EC%B0%A8-Ladder1_%EA%B7%B8%EB%A6%BC2.png)

**100 x 100 크기의 2차원 배열로 주어진 사다리에 대해서, 지정된 도착점에 대응되는 출발점 X를 반환하는 코드를 작성하라**

(‘0’으로 채워진 평면상에 사다리는 연속된 ‘1’로 표현된다. 도착 지점은 '2'로 표현된다).

**[제약 사항]**

한 막대에서 출발한 가로선이 다른 막대를 가로질러서 연속하여 이어지는 경우는 없다.

**[입력]**

입력 파일의 첫 번째 줄에는 테스트 케이스의 번호가 주어지며, 바로 다음 줄에 테스트 케이스가 주어진다.

총 10개의 테스트 케이스가 주어진다.

**[출력]**

#부호와 함께 테스트 케이스의 번호를 출력하고, 공백 문자 후 도착하게 되는 출발점의 x좌표를 출력한다.

---

# 풀이 과정

- 전형적인 트리/그래프 순회 문제이다.
- BFS가 약해서 BFS로 풀려다가 DFS로 풀게 되었다.
    - 이유는 출발지에서 목적지로 가는 경로는 단 1개이다.
    - 그렇기에 너비 우선이 아닌, 깊이 우선으로 탐색하게 될 경우의 출발지가 곧 답이 된다.
- 또한 그래프 순회도 사다리 구조 상 무조건 올라가게 된다.
    - 그렇기에 좌 우의 가로줄 먼저 고려하고 난 다음에 위쪽을 고려하는 식으로 설정.

```cpp

vector<vector<int>> arr, visited;

// 목적지 기준 무조건 올라가되, 좌우 먼저 보니까.
int dx[3] = {0, 0, -1};
int dy[3] = {1, -1, 0};

bool flag = false;
int des_y = 0;

void dfs(int x, int y) {

    if (flag) return;

    visited[x][y] = 1;

    for (int i = 0; i < 3; i++) {
        if (flag) return;

        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= 100 || ny < 0 || ny >= 100) continue;
        if (visited[nx][ny] == 1) continue;
        if (arr[nx][ny] == 0) continue;
        if (nx == 0 && arr[nx][ny] == 1) {
            // cout << "목적지: " << nx << " " << ny << endl;
            flag = true;
            des_y = ny;
            return;
        }

        if (arr[nx][ny] == 1 && visited[nx][ny] == 0 ) {
            visited[nx][ny] = 1;
            dfs(nx, ny);
        }
    }
}

int main(int argc, char **argv) {
    int test_case;
    int T;
    for (test_case = 1; test_case <= 10; ++test_case) {
        int idx = 0, sx = 0, sy = 0;
        des_y = 0;
        flag = false;
        cin >> idx;

        arr.assign(100, vector<int>(100, 0));
        visited.assign(100, vector<int>(100, 0));
        for (int row = 0; row < 100; row++) {
            for (int col = 0; col < 100; col++) {
                cin >> arr[row][col];
                if (arr[row][col] == 2) {
                    sx = row, sy = col;
                }
            }
        }

        // cout << "start: " << sx << " " <<  sy << '\n';

        dfs(sx, sy);

        cout << "#" << test_case << " " << des_y << endl;
    }
    return 0; //정상종료시 반드시 0을 리턴해야합니다.
}

```

---

# 결과 & 근거

- 21분에 빠른 구현을 성공했다가 8/10 으로 실패.
- 이유를 알아보다가 DFS 내부 순회 For 문에 대해 flag에 대한 return 문을 추가하여 26분 통과하였다.
    
    ```java
    1 0 1 
    1 1 1 
    2 0 1
    ```
    
    - 로직 상 중간 1.1에 도착했다고 치자.
    - 손으로 타보면: `col 2` 출발 → `(1,2)`에서 가로줄 만남 → `(1,0)` → `(2,0)`. **정답 = 2**
    - 체크 없을 때 `dfs(1,0)`의 for 루프:
        
        ```cpp
        i=0 (우) → (1,1) 재귀 → ... → (1,2)에서 (0,2) 발견 → flag=true, des_y=2   ← 정답 확정
        i=1 (좌) → 범위 밖, continue
        i=2 (상) → (0,0), nx==0 && arr==1  →  des_y = 0 으로 덮어쓴다          ★ 오답
        ```
        

### 알고리즘 분석

- 시뮬레이션
- DFS / 그래프 탐색 (대안)
- 역추적