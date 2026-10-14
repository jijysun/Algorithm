# 프로그래머스, 거리두기 확인하기 (실패)

# 문제 소개

[문제 사이트 링크](https://school.programmers.co.kr/learn/courses/30/lessons/81302)

개발자를 희망하는 죠르디가 카카오에 면접을 보러 왔습니다.

코로나 바이러스 감염 예방을 위해 응시자들은 거리를 둬서 대기를 해야하는데 개발 직군 면접인 만큼

아래와 같은 규칙으로 대기실에 거리를 두고 앉도록 안내하고 있습니다.

> 대기실은 5개이며, 각 대기실은 5x5 크기입니다.거리두기를 위하여 응시자들 끼리는 맨해튼 거리[1](https://school.programmers.co.kr/learn/courses/30/lessons/81302#fn1)가 2 이하로 앉지 말아 주세요.단 응시자가 앉아있는 자리 사이가 파티션으로 막혀 있을 경우에는 허용합니다.
> 

예를 들어,

![](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/8c056cac-ec8f-435c-a49a-8125df055c5e/PXP.png)

- 위 그림처럼 자리 사이에 파티션이 존재한다면 맨해튼 거리가 2여도 거리두기를 **지킨 것입니다.**

![](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/d611f66e-f9c4-4433-91ce-02887657fe7f/PX_XP.png)

- 위 그림처럼 파티션을 사이에 두고 앉은 경우도 거리두기를 **지킨 것입니다.**

![](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/ed707158-0511-457b-9e1a-7dbf34a776a5/PX_OP.png)

- 위 그림처럼 자리 사이가 맨해튼 거리 2이고 사이에 빈 테이블이 있는 경우는 거리두기를 **지키지 않은 것입니다.**

![](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/4c548421-1c32-4947-af9e-a45c61501bc4/P.png)

- 응시자가 앉아있는 자리(`P`)를 의미합니다.

![](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/ce799a38-668a-4038-b32f-c515b8701262/O.png)

- 빈 테이블(`O`)을 의미합니다.

![](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/91e8f98b-baeb-4f81-8cb6-5bafebebdcc7/X.png)

- 파티션(`X`)을 의미합니다.

5개의 대기실을 본 죠르디는 각 대기실에서 응시자들이 거리두기를 잘 기키고 있는지 알고 싶어졌습니다. 자리에 앉아있는 응시자들의 정보와 대기실 구조를 대기실별로 담은 2차원 문자열 배열 `places`가 매개변수로 주어집니다. 각 대기실별로 거리두기를 지키고 있으면 1을, 한 명이라도 지키지 않고 있으면 0을 배열에 담아 return 하도록 solution 함수를 완성해 주세요.

---

#### 제한사항

- `places`의 행 길이(대기실 개수) = 5
    - `places`의 각 행은 하나의 대기실 구조를 나타냅니다.
- `places`의 열 길이(대기실 세로 길이) = 5
- `places`의 원소는 `P`,`O`,`X`로 이루어진 문자열입니다.
    - `places` 원소의 길이(대기실 가로 길이) = 5
    - `P`는 응시자가 앉아있는 자리를 의미합니다.
    - `O`는 빈 테이블을 의미합니다.
    - `X`는 파티션을 의미합니다.
- 입력으로 주어지는 5개 대기실의 크기는 모두 5x5 입니다.
- return 값 형식
    - 1차원 정수 배열에 5개의 원소를 담아서 return 합니다.
    - `places`에 담겨 있는 5개 대기실의 순서대로, 거리두기 준수 여부를 차례대로 배열에 담습니다.
    - 각 대기실 별로 모든 응시자가 거리두기를 지키고 있으면 1을, 한 명이라도 지키지 않고 있으면 0을 담습니다.

---

#### 입출력 예

| places | result |
| --- | --- |
| `[["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"], ["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"], ["PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"], ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"], ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"]]` | [1, 0, 1, 1, 1] |

---

#### 입출력 예 설명

**입출력 예 #1**

첫 번째 대기실

|  |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- |
| No. | 0 | 1 | 2 | 3 | 4 |
| 0 | P | O | O | O | P |
| 1 | O | X | X | O | X |
| 2 | O | P | X | P | X |
| 3 | O | O | X | O | X |
| 4 | P | O | X | X | P |
- 모든 응시자가 거리두기를 지키고 있습니다.

두 번째 대기실

|  |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- |
| No. | 0 | 1 | 2 | 3 | 4 |
| 0 | **P** | O | O | **P** | X |
| 1 | O | X | **P** | X | P |
| 2 | **P** | X | X | X | O |
| 3 | O | X | X | X | O |
| 4 | O | O | O | **P** | **P** |
- (0, 0) 자리의 응시자와 (2, 0) 자리의 응시자가 거리두기를 지키고 있지 않습니다.
- (1, 2) 자리의 응시자와 (0, 3) 자리의 응시자가 거리두기를 지키고 있지 않습니다.
- (4, 3) 자리의 응시자와 (4, 4) 자리의 응시자가 거리두기를 지키고 있지 않습니다.

세 번째 대기실

|  |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- |
| No. | 0 | 1 | 2 | 3 | 4 |
| 0 | P | X | O | P | X |
| 1 | O | X | O | X | P |
| 2 | O | X | P | O | X |
| 3 | O | X | X | O | P |
| 4 | P | X | P | O | X |
- 모든 응시자가 거리두기를 지키고 있습니다.

네 번째 대기실

|  |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- |
| No. | 0 | 1 | 2 | 3 | 4 |
| 0 | O | O | O | X | X |
| 1 | X | O | O | O | X |
| 2 | O | O | O | X | X |
| 3 | O | X | O | O | X |
| 4 | O | O | O | O | O |
- 대기실에 응시자가 없으므로 거리두기를 지키고 있습니다.

다섯 번째 대기실

|  |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- |
| No. | 0 | 1 | 2 | 3 | 4 |
| 0 | P | X | P | X | P |
| 1 | X | P | X | P | X |
| 2 | P | X | P | X | P |
| 3 | X | P | X | P | X |
| 4 | P | X | P | X | P |
- 모든 응시자가 거리두기를 지키고 있습니다.

두 번째 대기실을 제외한 모든 대기실에서 거리두기가 지켜지고 있으므로, 배열 [1, 0, 1, 1, 1]을 return 합니다.

---

#### 제한시간 안내

- 정확성 테스트 : 10초

※ 공지 - 2022년 4월 25일 테스트케이스가 추가되었습니다.

---

1. 두 테이블 T1, T2가 행렬 (r1, c1), (r2, c2)에 각각 위치하고 있다면, T1, T2 사이의 맨해튼 거리는 |r1 - r2| + |c1 - c2| 입니다.

---

# 풀이 과정

- P 좌표마다 DFS 백트래킹을 돌리고, P 를 만날 때마다 맨해튼 거리 ≤ 2 인지 검사했다.
    - 파티션으로 막혀 있으면 괜찮다는 조건을 depth 로 처리했다.
- 공식 예시 5개는 모두 통과했으나 28.8점. 44분 디버깅 끝에 포기.

```cpp
vector<vector<char>> arr;
vector<vector<int>> visited;
vector<pair<int, int>>pos;

// 시계방향, 북 동 남 서 순으로
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int start_x, start_y;

bool flag = true;

bool dfs (int x, int y, int depth) {

    /*
     * 순회 로직
     * - P 기준 스타트
     * - 주변에 O 이면 갈 수 있다는 것 ->
     * - - 만약 P를 만난 경우 맨해튼 거리 판단
     * - 주변이 X 이면 갈 수 없다는 것 -> return;
     * -
     */
    if (!flag) {
        return flag;
    }
    visited[x][y] = 1;

    for (int i = 0; i<4; i++) {

        if (!flag) {
            return flag;
        }

        int nx = x + dx[i], ny = y + dy[i];

        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
        if (arr[nx][ny] == 'X') continue;
        if (visited[nx][ny] != 0) continue;

        if (arr[nx][ny] == 'P' && abs(nx-start_x) + abs(ny-start_y) <=2) {
            // 사람 만났으며, 맨해튼 거리 2 미만이면 플래그 false로 하고 강제 return
            if (depth > 2) {
                // cout << start_x << " " << start_y << "가 " << nx << " "  << ny << "를 만났으나 맨해튼 거리 2 이하 이지만, depth 가  " << depth <<" 입니다.\n";
            }
            else {
                // cout << start_x << " " << start_y << "가 " << nx << " "  << ny << "를 만났으나 맨해튼 거리 2 이하 입니다.\n";
                flag = false;
                return flag;
            }
        }
        /*if (arr[nx][ny] == 'P') {
            cout << start_x << " " << start_y << "가 " << nx << " "  << ny << "를 만났으나 맨해튼 거리 2 초과 입니다.\n";
        }*/

        // 즉 여기는 O 이며, 배열 이내이며 visited 하지도 않은 것.
        visited[nx][ny] = 1;
        dfs(nx, ny, depth+1);
    }
    visited[x][y] = 0; // 모든 경우 검사.

    return true;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    /*
     * 5개의 대기실 전부 순회하면 OK
     * - 전체 순회해도 1억을 넘길 수 없음
     * - 최악의 경우, 5번째 대기실의 경우 (대각선으로 배치 + P가 최대로 채워지는 조건)
     *
     * 먼저 떠오른 Idea: 각 응시자 별 트리 순회 (DFS)
     * - place[i] 마다 vecotr 초기화
     * - P를 만날때 마다 좌표 저장.
     * - P마다 DFS. -> return false가 뜨는 순간 바로 return;
     * - - 네 번째 대기실 처럼 P가 없는 경우도 OK
     */
    for (int i = 0; i<places.size(); i++) {
        arr.assign(5, vector<char>(5));
        pos.clear();
        for (int j = 0; j<places[i].size(); j++) {
            for (int k = 0; k<5; k++) {
                arr[j][k] = places[i][j][k];

                // P 좌표
                if (arr[j][k] == 'P') {
                    pos.push_back(pair<int, int>(j, k));
                }
            }
        }

        // dfs

        for (pair<int, int> p : pos) {
            visited.assign(5, vector<int>(5, 0)), **flag = true;**

            start_x = p.first, start_y = p.second;
            dfs(start_x, start_y, 0);

            // cout << "\n--------\n";
        }
        // cout << "\n---------------------\n";

        if (!flag) {
            answer.push_back(0);
        }
        else { // 만약 P 자체가 없는 경우 여기로 이동해서 ㅇㅋ
            answer.push_back(1);
        }
        /*for (int j = 0; j<places[i].size(); j++) {
            for (int k = 0; k<5; k++) {
                cout << arr[j][k] << " ";
            }
            cout << endl;
        }
        for (pair<int, int> p : pos) {
            cout << p.first << " " << p.second << endl;
        }
        cout <<"\n----\n" << endl;*/

    }
    // 29분 2,1 - 2,3 이 맨해튼 2로 오류 -> 원래는 돌아가서 지켜진 것 -> depth 추가
    // 33에 디버깅으로 입력 예시 확인 완료 (코드 개더럽네)
    // 39분: 28.8 / 100.0 손 예제 입력 시작 45분 까지
    /*
     * 예외 . 아 문제 쉬운데
     * - 무조건 파티션으로만 거리두기해야함. 빈 테이블로는 안됨
     * xp
     * px 가 되는 것. 이거는 처리하고 있는 거 같은데?
     * - 백트래킹을 제대로 하고 있는 건가? 잘 모르겠음
     * 44분 디버깅 종료 및 포기.
     */

    return answer;
}
```

---

# 결과 & 근거

- 실패 (44분 포기, 28.8점). 랜덤 200,000 케이스 측정 시 22.0% 오답.
- 원인은 flag 를 P 루프 안에서 true 로 리셋한 것 하나다. 이것만 고치면 오답률 0%.
- 더 근본적으로는 BFS 가 맞는 도구였다
    - DFS 의 depth 는 "이 탐색 경로에서의 길이"일 뿐 최단거리가 아니다.
    - BFS 의 거리는 최단거리를 보장한다.

```cpp
#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = { 0, 1, 0,-1};

// 한 대기실이 거리두기를 지키는지
bool isOk(vector<string>& g) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (g[i][j] != 'P') continue;       // 응시자에서만 출발

            // dist[x][y] = (i,j) 에서 (x,y) 까지의 최단 거리. -1 = 미방문
            // ★ BFS 라서 이 값이 최단거리임이 보장된다. DFS 의 depth 는 보장되지 않는다
            vector<vector<int>> dist(5, vector<int>(5, -1));
            queue<pair<int,int>> q;
            q.push({i, j});
            dist[i][j] = 0;

            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                if (dist[x][y] == 2) continue;   // 거리 2 에서 멈춘다. 그 이상은 볼 필요 없다

                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k], ny = y + dy[k];

                    if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
                    if (g[nx][ny] == 'X') continue;       // 파티션은 통과 못 한다
                    if (dist[nx][ny] != -1) continue;     // 이미 방문 (push 시점 처리)

                    dist[nx][ny] = dist[x][y] + 1;

                    if (g[nx][ny] == 'P') return false;
                    // ★ 거리 1 또는 2 에서 다른 응시자를 만났다 = 위반
                    //   맨해튼 거리를 따로 계산할 필요가 없다.
                    //   BFS 거리 자체가 "파티션을 피해 실제로 갈 수 있는 거리"이므로
                    //   이 한 줄이 "맨해튼 ≤ 2" 와 "파티션으로 막히지 않음" 을 동시에 만족한다

                    q.push({nx, ny});
                }
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (auto& g : places) answer.push_back(isOk(g) ? 1 : 0);
    return answer;
}
```

### 알고리즘 분류

- BFS (깊이 제한 탐색)
- 격자 탐색
- 구현
- 시뮬레이션