# 프로그래머스, 방문 길이 (성공)

# 문제 소개

[문제 사이트 링크](https://school.programmers.co.kr/learn/courses/30/lessons/49994)

게임 캐릭터를 4가지 명령어를 통해 움직이려 합니다. 명령어는 다음과 같습니다.

- U: 위쪽으로 한 칸 가기
- D: 아래쪽으로 한 칸 가기
- R: 오른쪽으로 한 칸 가기
- L: 왼쪽으로 한 칸 가기

캐릭터는 좌표평면의 (0, 0) 위치에서 시작합니다. 좌표평면의 경계는 왼쪽 위(-5, 5), 왼쪽 아래(-5, -5), 오른쪽 위(5, 5), 오른쪽 아래(5, -5)로 이루어져 있습니다.

![방문길이1_qpp9l3.png](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/ace0e7bc-9092-4b95-9bfb-3a55a2aa780e/%E1%84%87%E1%85%A1%E1%86%BC%E1%84%86%E1%85%AE%E1%86%AB%E1%84%80%E1%85%B5%E1%86%AF%E1%84%8B%E1%85%B51_qpp9l3.png)

예를 들어, "ULURRDLLU"로 명령했다면

![방문길이2_lezmdo.png](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/668c7458-e184-472d-9d32-f5d2acca759a/%E1%84%87%E1%85%A1%E1%86%BC%E1%84%86%E1%85%AE%E1%86%AB%E1%84%80%E1%85%B5%E1%86%AF%E1%84%8B%E1%85%B52_lezmdo.png)

- 1번 명령어부터 7번 명령어까지 다음과 같이 움직입니다.

![방문길이3_sootjd.png](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/08558e36-d667-4160-bfec-b754c78a7d85/%E1%84%87%E1%85%A1%E1%86%BC%E1%84%86%E1%85%AE%E1%86%AB%E1%84%80%E1%85%B5%E1%86%AF%E1%84%8B%E1%85%B53_sootjd.png)

- 8번 명령어부터 9번 명령어까지 다음과 같이 움직입니다.

![방문길이4_hlpiej.png](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/a52af28e-5835-438b-9f40-5467ebf9bf03/%E1%84%87%E1%85%A1%E1%86%BC%E1%84%86%E1%85%AE%E1%86%AB%E1%84%80%E1%85%B5%E1%86%AF%E1%84%8B%E1%85%B54_hlpiej.png)

이때, 우리는 게임 캐릭터가 지나간 길 중 **캐릭터가 처음 걸어본 길의 길이**를 구하려고 합니다. 예를 들어 위의 예시에서 게임 캐릭터가 움직인 길이는 9이지만, 캐릭터가 처음 걸어본 길의 길이는 7이 됩니다. (8, 9번 명령어에서 움직인 길은 2, 3번 명령어에서 이미 거쳐 간 길입니다)

단, 좌표평면의 경계를 넘어가는 명령어는 무시합니다.

예를 들어, "LULLLLLLU"로 명령했다면

![방문길이5_nitjwj.png](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/f631f005-f8de-4392-a76c-a9ef64b6de08/%E1%84%87%E1%85%A1%E1%86%BC%E1%84%86%E1%85%AE%E1%86%AB%E1%84%80%E1%85%B5%E1%86%AF%E1%84%8B%E1%85%B55_nitjwj.png)

- 1번 명령어부터 6번 명령어대로 움직인 후, 7, 8번 명령어는 무시합니다. 다시 9번 명령어대로 움직입니다.

![방문길이6_nzhumd.png](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/35e62f0a-43c6-4142-bec6-6d28fbc57216/%E1%84%87%E1%85%A1%E1%86%BC%E1%84%86%E1%85%AE%E1%86%AB%E1%84%80%E1%85%B5%E1%86%AF%E1%84%8B%E1%85%B56_nzhumd.png)

이때 캐릭터가 처음 걸어본 길의 길이는 7이 됩니다.

명령어가 매개변수 dirs로 주어질 때, 게임 캐릭터가 처음 걸어본 길의 길이를 구하여 return 하는 solution 함수를 완성해 주세요.

#### 제한사항

- dirs는 string형으로 주어지며, 'U', 'D', 'R', 'L' 이외에 문자는 주어지지 않습니다.
- dirs의 길이는 500 이하의 자연수입니다.

#### 입출력 예

| dirs | answer |
| --- | --- |
| "ULURRDLLU" | 7 |
| "LULLLLLLU" | 7 |

#### 입출력 예 설명

입출력 예 #1

문제의 예시와 같습니다.

입출력 예 #2

문제의 예시와 같습니다.

---

# 풀이 과정

- 처음에 좌표(칸)에 visited 를 걸었더니 예제 답이 9가 나왔다. 정답은 7.
    - **세는 대상이 칸이 아니라 "길"(간선)** 이라는 걸 여기서 알았다.
- 길은 두 칸으로 표현되는데, **길에는 방향이 없다.** A->B 와 B->A 가 같은 길이다.
    - 그래서 처음엔 `pair<pair<int,int>, pair<int,int>>` 로 양쪽 표현을 다 등록했다.
    - 동작은 했지만 가독성이 나쁘고 느렸다.

```cpp
#include <string>
#include <bits/stdc++.h>
using namespace std;
/*
1. 제한
- 좌표 평면: 최대 10*10 (음수포함)
- dirs의 길이는 500 이하의 자연수 + UDRL로 주어진다.

5. 문제 
- 지나간 길 중 캐릭터가 처음 걸어본 길의 길이를 구하기. (예시 기준 9, But 실제 7)
- 좌표평면의 경계를 넘어가는 명령어는 무시 = Continue;
*/
map<pair<int, int>, int> visited;
map<pair<pair<int, int>, pair<int, int>>, int> visited2;
int solution(string dirs) {
    int answer = 0;
    
    
    int x = 0, y = 0;
    int pre_x = 0, pre_y=0;
    for (char d : dirs){
        
        // cout << x << " " << y << ", answer: " << answer << '\n';
        
        if (d == 'U'){
            y+=1;
            if (x < -5 || x > 5 || y < -5 || y > 5){
                y-=1;
                continue;
            }
        }
        else if (d == 'R'){
            x+=1;
            if (x < -5 || x > 5 || y < -5 || y > 5){
                x-=1;
                continue;
            }
        }
        else if (d == 'D'){
            
            y-=1;
            if (x < -5 || x > 5 || y < -5 || y > 5){
                y+=1;
                continue;
            }
        }
        else if (d == 'L'){
            x-=1;
            if (x < -5 || x > 5 || y < -5 || y > 5){
                x+=1;
                continue;
            }
        }
        
        // 배열 탈출 검사
        
        // visited 처리
        pair<int, int> pos = {x, y}, pre_pos = {pre_x, pre_y};
        pair<pair<int, int>, pair<int, int>> path1 = {pos, pre_pos};
        pair<pair<int, int>, pair<int, int>> path2 = {pre_pos, pos};
        
        // if (!visited[pos]){
        //     visited[pos] ++;
        //     answer++;
        // }
        if (!visited2[path1] && !visited2[path2]){
            visited2[path1]++;
            visited2[path2]++;
            answer ++;
        }
        pre_x = x, pre_y = y;
        
        
        
    }
    // 14분 좌표에 대한 visited이 아닌, 길에 대한 visited
    // visit 처리를 어떻게 하지? map <pair<pair<int, int>>, int> 이중 pair는 개에바인데.
    // 어쨌든 길 = 두 좌표로 표현 가능. -> 21분 수정 완료.
    
    // 
    
    return answer;
}
```

---

# 결과 & 근거

- 21분 성공
- 사실 이중 Pair를 쓰지 않았어도 되었다.
    - **정규화** : 좌표를 `(y+5)*11 + (x+5)` 로 정수 하나로 접고, `min*121 + max` 로 순서를 없앤다 -> `set<int>` 하나로 끝. 양쪽 등록 불필요.
    - **방향으로 저장** : 길을 `(출발 칸, 방향)` 으로 보면 같은 길의 다른 이름은 `(도착 칸, 반대 방향)` 하나로 고정된다

```cpp
#include <string>
#include <cstring>
using namespace std;

/*
1. 제한
- 좌표 평면 : x, y 각각 -5 ~ 5 (11 x 11 칸)
- dirs 길이 <= 500, 문자는 U D R L
2. 연산량 = 500 x O(1) = 500. 통과 O
3. 상태와 전이 : 현재 칸 + 이동 방향 -> 그 "길"을 처음 걷는가
4. 예제 손검증 : O
5. 조건 중 내가 자유롭게 정할 수 있는 것 : 좌표를 0..10 으로 평행이동해도 무관
*/

int solution(string dirs) {
    /* 핵심 관찰
       세는 대상은 "칸"이 아니라 "길"(= 두 칸을 잇는 간선)이다.
       그런데 길에는 방향이 없다. A->B 와 B->A 는 같은 길이다.
       그래서 길을 (좌표, 좌표) 쌍으로 표현하면 (A,B) 와 (B,A) 두 표현이 생겨
       둘 다 등록해야 하는 번거로움이 생긴다.

       대신 길을 "(출발 칸, 방향)" 으로 표현하면, 같은 길의 다른 이름은
       "(도착 칸, 반대 방향)" 하나로 고정된다. 그 둘만 함께 막으면 끝이다.
       -> 중첩 pair 도, map 도, 정규화도 필요 없다. bool 3차원 배열 하나.                */

    const string DC = "UDRL";
    int dx[4] = {0,  0, 1, -1};
    int dy[4] = {1, -1, 0,  0};
    int opp[4] = {1, 0, 3, 2};        // U<->D, R<->L : 같은 길의 반대 방향 인덱스

    bool vis[11][11][4];              // [x+5][y+5][방향]. 좌표를 0..10 으로 평행이동
    memset(vis, 0, sizeof(vis));      // ★ 전역이 아니라 지역 + 명시적 초기화

    int answer = 0;
    int x = 0, y = 0;

    for (char d : dirs) {
        int k = DC.find(d);                       // 'U'->0, 'D'->1, 'R'->2, 'L'->3
        int nx = x + dx[k], ny = y + dy[k];       // ★ 먼저 계산만 한다

        if (nx < -5 || nx > 5 || ny < -5 || ny > 5) continue;   // 경계 검사 한 곳에서만
                                                               //   -> 롤백(-=1)이 불필요해진다

        if (!vis[x+5][y+5][k]) {                  // 이 길을 처음 걷는다
            vis[x+5][y+5][k]           = true;    //   정방향 등록
            vis[nx+5][ny+5][opp[k]]    = true;    //   역방향도 같은 길이므로 함께 등록
            answer++;                             //   길 하나 추가
        }

        x = nx, y = ny;                           // ★ 경계를 통과한 뒤에만 반영
    }

    return answer;
}
```

### 알고리즘 분류

- 구현 / 시뮬레이션
- 해시 / 집합 (간선 중복 제거)
- 좌표 인코딩