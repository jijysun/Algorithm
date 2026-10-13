# 프로그래머스, 미로 탈출 명령어 (실패)

# 문제 소개

[문제 사이트 링크](https://school.programmers.co.kr/learn/courses/30/lessons/150365)

`n` x `m` 격자 미로가 주어집니다. 당신은 미로의 (x, y)에서 출발해 (r, c)로 이동해서 탈출해야 합니다.

단, 미로를 탈출하는 조건이 세 가지 있습니다.

1. 격자의 바깥으로는 나갈 수 없습니다.
2. (x, y)에서 (r, c)까지 이동하는 거리가 총 `k`여야 합니다. **이때, (x, y)와 (r, c)격자를 포함해, 같은 격자를 두 번 이상 방문해도 됩니다.**
3. 미로에서 탈출한 경로를 문자열로 나타냈을 때, 문자열이 사전 순으로 가장 빠른 경로로 탈출해야 합니다.

이동 경로는 다음과 같이 문자열로 바꿀 수 있습니다.

- l: 왼쪽으로 한 칸 이동
- r: 오른쪽으로 한 칸 이동
- u: 위쪽으로 한 칸 이동
- d: 아래쪽으로 한 칸 이동

예를 들어, 왼쪽으로 한 칸, 위로 한 칸, 왼쪽으로 한 칸 움직였다면, 문자열 `"lul"`로 나타낼 수 있습니다.

미로에서는 인접한 상, 하, 좌, 우 격자로 한 칸씩 이동할 수 있습니다.

예를 들어 다음과 같이 3 x 4 격자가 있다고 가정해 보겠습니다.

```
....
..S.
E...
```

미로의 좌측 상단은 (1, 1)이고 우측 하단은 (3, 4)입니다. `.`은 빈 공간, `S`는 출발 지점, `E`는 탈출 지점입니다.

탈출까지 이동해야 하는 거리 `k`가 5라면 다음과 같은 경로로 탈출할 수 있습니다.

1. lldud
2. ulldd
3. rdlll
4. dllrl
5. dllud
6. ...

이때 dllrl보다 사전 순으로 빠른 경로로 탈출할 수는 없습니다.

격자의 크기를 뜻하는 정수 `n`, `m`, 출발 위치를 뜻하는 정수 `x`, `y`, 탈출 지점을 뜻하는 정수 `r`, `c`, 탈출까지 이동해야 하는 거리를 뜻하는 정수 `k`가 매개변수로 주어집니다. 이때, 미로를 탈출하기 위한 경로를 return 하도록 solution 함수를 완성해주세요. **단, 위 조건대로 미로를 탈출할 수 없는 경우 `"impossible"`을 return 해야 합니다.**

---

#### 제한사항

- 2 ≤ `n` (= 미로의 세로 길이) ≤ 50
- 2 ≤ `m` (= 미로의 가로 길이) ≤ 50
- 1 ≤ `x` ≤ `n`
- 1 ≤ `y` ≤ `m`
- 1 ≤ `r` ≤ `n`
- 1 ≤ `c` ≤ `m`
- (`x`, `y`) ≠ (`r`, `c`)
- 1 ≤ `k` ≤ 2,500

---

#### 입출력 예

| n | m | x | y | r | c | k | result |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 3 | 4 | 2 | 3 | 3 | 1 | 5 | `"dllrl"` |
| 2 | 2 | 1 | 1 | 2 | 2 | 2 | `"dr"` |
| 3 | 3 | 1 | 2 | 3 | 3 | 4 | `"impossible"` |

---

#### 입출력 예 설명

**입출력 예 #1**

문제 예시와 동일합니다.

**입출력 예 #2**

미로의 크기는 2 x 2입니다. 출발 지점은 (1, 1)이고, 탈출 지점은 (2, 2)입니다.

빈 공간은 `.`, 출발 지점을 `S`, 탈출 지점을 `E`로 나타내면 다음과 같습니다.

```
S.
.E
```

미로의 좌측 상단은 (1, 1)이고 우측 하단은 (2, 2)입니다.

탈출까지 이동해야 하는 거리 `k`가 2이므로 다음과 같은 경로로 탈출할 수 있습니다.

1. rd
2. dr

`"dr"`이 사전 순으로 가장 빠른 경로입니다. 따라서 `"dr"`을 return 해야 합니다.

**입출력 예 #3**

미로의 크기는 3 x 3입니다. 출발 지점은 (1, 2)이고, 탈출 지점은 (3, 3)입니다.

빈 공간은 `.`, 출발 지점을 `S`, 탈출 지점을 `E`로 나타내면 다음과 같습니다.

```
.S.
...
..E
```

미로의 좌측 상단은 (1, 1)이고 우측 하단은 (3, 3)입니다.

탈출까지 이동해야 하는 거리 `k`가 4입니다. 이때, 이동 거리가 4이면서, `S`에서 `E`까지 이동할 수 있는 경로는 존재하지 않습니다.

따라서 `"impossible"`을 return 해야 합니다.

---

# 풀이 과정

- S에서 E를 찾았을 때 K와의 차이가 홀수면 impossible, 짝수면 그만큼 왔다갔다로 채우면 된다는 것까지는 잡았다.
- 그래서 여분 이동을 (ud, du, lr, rl) 조합으로 생성해서 끼워넣으려 했다.
    - 38분 포기.

```cpp
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

/*
- 제한사항 숫자 베끼기 
2 ≤ n (= 미로의 세로 길이) ≤ 50, 2 ≤ m (= 미로의 가로 길이) ≤ 50
1 ≤ x ≤ n, 1 ≤ y ≤ m
1 ≤ r ≤ n, 1 ≤ c ≤ m
(x, y) ≠ (r, c)
1 ≤ k ≤ 2,500

- 내 접근의 연산량 = 예상으로 DFS 시간 복잡도
- 상태와 전이를 한 문장으로   "상태 = 현 노드 값, 전이 = 다음 이동할 노드의 목적지 여부"
- 예시 1개를 손으로 돌리기: 시간 부족으로 실패
*/

// 38분 포기
// 구현이 항상 어려운 것 같아. S에서 E를 찾았을 때 원래 값이어야 할 K와 차이값의 경우에 따라 달라지는 걸 알고 있어
// 만약 1로 차이가 나면 Impossible, 짝수로 차이나면 차이 나는 만큼 (lr, rl, ud, du)를 조합으로 생성되는 만큼 answer를 찾는 것
// 사실 더 효율적으로 하려면 맨처음 부터 알파벳 순인 d -> l -> r -> u 순으로 돌았어야 했다.
// 그럼 d 부터 경우의 수를 넣고 리턴하니까 시간 복잡도는 더 줄었을 거야. DFS 순회의 시간 복잡도와 일치하게 되므로

vector <string> answer;

int row, col;
int K, R, C;
int visited[51][51];
int visited2[4];

struct Pos {
    int x;
    int y;
    char dir;
};
bool return_check = false;

vector<pair <int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector <string> dir2 = {"ud", "du", "lr", "rl"};
vector<Pos> poses;

void perm(int depth, int k, string s) {
    if (depth == k) { 
        
        answer.push_back(s);
        return; 
    }
    
    for (int i = 0; i < 4; i++) {      // ★ 0부터. start 없음
        if (visited2[i]) continue;
        
        visited2[i] = true;
        
        perm(depth + 2, k, s + dir2[i]);
        // cur.pop_back();
        visited2[i] = false;            // ★ visited 도 복구
    }
}

void dfs (int x, int y, int depth, string way){
    
    visited[x][y] = 1;
    
    if (return_check) {
        return;
    }
    cout << way << '\n';
    
    for (Pos p : poses){ // 사분면 탐색
        int nx = x+p.x, ny = y + p.y;
        if (nx < 0 || nx >= row || ny < 0 || ny >= col) {
            continue;
        }
        
        if (visited[nx][ny] != 1 && nx == R && ny == C){
            
            if (depth+1 < K){ // 적은 경우 K로 맞춰야 함를 맞춰야 함
                
                int diff  = K - depth -1;
                
                if (diff % 2 == 1){
                    // k로 맞출 수가 없음
                    return_check = true;
                    return;
                }
                
                else {
                    perm (0, diff, "");
                        
                    
                              // 이 경우의 수 추가가 좀 빡센데?
                    // down이면 ud 추가
                // up 이면 du 추가
                // left 이면 rl 추가
                // right이면 lr 추가
                }          
            }
            else if (depth+1 == K){
                answer.push_back (way + p.dir);
                visited[x][y] = 0;
            }
            
        }
    }
    
}

// 출발 위치를 뜻하는 정수 x, y, 탈출 지점을 뜻하는 정수 r, c, 탈출까지 이동해야 하는 거리를 뜻하는 정수 k
string solution(int n, int m, int x, int y, int r, int c, int k) {
    K=k, row = n, col = m, R = r, C = c;
    
    poses.push_back({0, -1, 'l'});
    poses.push_back({0, 1, 'r'});
    poses.push_back({-1,0, 'u'});
    poses.push_back({1, 0, 'd'});
    
    // 단순한 BFS/DFS로는 불가능. 왜냐하면 왔다갔다 로직이 존재.
    // 왔다갔다를 그냥 붙이기만 하면 되는 거 아냐? 횟수는 2이니까, k-2, k-4 ....와 일치하는 경우로?
    // 일치하기만 하면 경우의 수를 answer에 그냥 push_back 하면 되는 거 아닌가?
    
    dfs (x, y, 0, "");
    
    sort (answer.begin(), answer.end());
    // 단, 위 조건대로 미로를 탈출할 수 없는 경우 "impossible"을 return 
    // return answer[0];
    if (return_check){
        return "impossible";
    }
    return answer[0];
}
```

---

# 결과 & 근거

- 사실 홀짝 판단은 맞았지만, 그 다음 방향이 반대였다.
    - 여분을 "생성해서 끼워넣기" → 어디에 어떤 순서로 끼울지가 전부 경우의 수가 된다.
    사전순 최소가 보장되지 않으며, perm 의 visited 제약 때문에 최대 8칸까지만 가능했다.
- 가지치기 두 줄이 문제의 전부였다.
    - 남은 이동횟수와 목적지 까지의 최단 거리를 비교한다
    - 만약 도달 불가능하거나, 여분이 홀수 인 경우 왔다갔다로 횟수 채우기 불가능으로 “Impossible”
- 나중가서 사전순으로 탐색하면 “맨 처음 성공한 경로”가 정답인 사전순 최소이다.
    - 이 경우 answer 수집과 sort() 호출 자체가 불필요해진다.

```cpp
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int n, m, R, C, K;
string answer;

// ★ 사전순으로 배치한다. d < l < r < u
//   이 순서로 탐색하면 "처음 성공한 경로"가 곧 사전순 최소다.
//   그래서 답을 모아서 sort 할 필요가 없다.
int dx[4] = { 1,  0, 0, -1};
int dy[4] = { 0, -1, 1,  0};
char dc[4] = {'d','l','r','u'};

// x, y   : 현재 위치 (1-indexed)
// depth  : 지금까지 이동한 횟수
// path   : 지금까지의 명령어 (참조로 공유하고 push/pop 으로 백트래킹)
// 반환값 : 이 가지에서 답을 찾았는가
bool dfs(int x, int y, int depth, string& path) {

    int remain = K - depth;                    // 앞으로 써야 하는 이동 횟수
    int dist   = abs(x - R) + abs(y - C);      // 목적지까지의 최단(맨해튼) 거리

    // ── 가지치기 ① 남은 횟수로 도달조차 못 하면 버린다
    if (dist > remain) return false;

    // ── 가지치기 ② 여분(remain - dist)이 홀수면 버린다.
    //    왔다갔다 한 번은 이동 2회를 소모하고 제자리로 돌아온다.
    //    따라서 남는 횟수는 반드시 짝수여야 정확히 k 로 맞출 수 있다.
    //    이 두 줄이 4^2500 을 2,580회 호출로 줄인다. (실측)
    if ((remain - dist) % 2 != 0) return false;

    // 여기 도달했다면 ①②를 통과했으므로 remain==0 일 때 dist==0 이 보장된다
    if (depth == K) {
        answer = path;
        return true;        // ★ 사전순으로 돌았으므로 이게 최소다. 더 찾을 필요 없다
    }

    for (int i = 0; i < 4; i++) {              // d → l → r → u 순
        int nx = x + dx[i], ny = y + dy[i];

        if (nx < 1 || nx > n || ny < 1 || ny > m) continue;   // 1-indexed 경계
        // ★ visited 체크는 하지 않는다. 같은 칸을 다시 밟아야 k 를 맞출 수 있다.

        path.push_back(dc[i]);
        if (dfs(nx, ny, depth + 1, path)) return true;   // 성공을 위로 즉시 전파
        path.pop_back();                                 // 실패하면 복구 (백트래킹)
    }
    return false;
}

string solution(int nn, int mm, int x, int y, int r, int c, int k) {
    n = nn; m = mm; R = r; C = c; K = k;
    answer = "impossible";                    // 못 찾으면 이 값이 그대로 남는다

    string path;
    path.reserve(k);                          // k=2500 이므로 미리 확보 (재할당 방지)
    dfs(x, y, 0, path);

    return answer;
}
```

*사전순 DFS 백트래킹. 모든 경우를 모아 정렬하는 게 아니라 **d→l→r→u 순으로 돌아 첫 성공을 즉시 return**, 그리고 맨해튼 거리 + 홀짝으로 가지치기하는 게 핵심.*

### 알고리즘 분류

- DFS / 백트래킹
- 가지치기 (거리 + 홀짝 패리티)
- 그리디 (사전순 탐색 순서 고정)
- 구현