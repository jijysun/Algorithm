# 프로그래머스, 지게차와 크레인 (실패)

# 문제 소개

[문제 사이트 링크](https://school.programmers.co.kr/learn/courses/30/lessons/388353)

A 회사의 물류창고에는 알파벳 대문자로 종류를 구분하는 컨테이너가 세로로 `n` 줄, 가로로 `m`줄 총 `n` x `m`개 놓여 있습니다. 특정 종류 컨테이너의 출고 요청이 들어올 때마다 지게차로 창고에서 접근이 가능한 해당 종류의 컨테이너를 모두 꺼냅니다. 접근이 가능한 컨테이너란 4면 중 적어도 1면이 창고 외부와 연결된 컨테이너를 말합니다.

최근 이 물류 창고에서 창고 외부와 연결되지 않은 컨테이너도 꺼낼 수 있도록 크레인을 도입했습니다. 크레인을 사용하면 요청된 종류의 모든 컨테이너를 꺼냅니다.

![물류창고-1-1.drawio.png](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/0e90cfc3-ddd7-4841-9ed8-c420cb6be7a5/%E1%84%86%E1%85%AE%E1%86%AF%E1%84%85%E1%85%B2%E1%84%8E%E1%85%A1%E1%86%BC%E1%84%80%E1%85%A9-1-1.drawio.png)

위 그림처럼 세로로 4줄, 가로로 5줄이 놓인 창고를 예로 들어보겠습니다. 이때 "A", "BB", "A" 순서대로 해당 종류의 컨테이너 출고 요청이 들어왔다고 가정하겠습니다. “A”처럼 알파벳 하나로만 출고 요청이 들어올 경우 지게차를 사용해 출고 요청이 들어온 순간 접근 가능한 컨테이너를 꺼냅니다. "BB"처럼 같은 알파벳이 두 번 반복된 경우는 크레인을 사용해 요청된 종류의 모든 컨테이너를 꺼냅니다.

![물류창고-1-2.drawio.png](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/e5fac969-705a-41cf-8609-ad41e30ea694/%E1%84%86%E1%85%AE%E1%86%AF%E1%84%85%E1%85%B2%E1%84%8E%E1%85%A1%E1%86%BC%E1%84%80%E1%85%A9-1-2.drawio.png)

위 그림처럼 컨테이너가 꺼내져 3번의 출고 요청 이후 남은 컨테이너는 11개입니다. 두 번째 요청은 크레인을 활용해 모든 `B` 컨테이너를 꺼냈음을 유의해 주세요. 세 번째 요청이 들어왔을 때 2행 2열의 `A` 컨테이너만 접근이 가능하고 2행 3열의 `A` 컨테이너는 접근이 불가능했음을 유의해 주세요.

처음 물류창고에 놓인 컨테이너의 정보를 담은 1차원 문자열 배열 `storage`와 출고할 컨테이너의 종류와 출고방법을 요청 순서대로 담은 1차원 문자열 배열 `requests`가 매개변수로 주어집니다. 이때 모든 요청을 순서대로 완료한 후 남은 컨테이너의 수를 return 하도록 solution 함수를 완성해 주세요.

---

#### 제한사항

- 2 ≤ `storage`의 길이 = `n` ≤ 50
    - 2 ≤ `storage[i]`의 길이 = `m` ≤ 50
        - `storage[i][j]`는 위에서 부터 `i + 1`번째 행 `j + 1`번째 열에 놓인 컨테이너의 종류를 의미합니다.
        - `storage[i][j]`는 알파벳 대문자입니다.
- 1 ≤ `requests`의 길이 ≤ 100
    - 1 ≤ `requests[i]`의 길이 ≤ 2
    - `requests[i]`는 한 종류의 알파벳 대문자로 구성된 문자열입니다.
    - `requests[i]`의 길이가 1이면 지게차를 이용한 출고 요청을, 2이면 크레인을 이용한 출고 요청을 의미합니다.

---

#### 테스트 케이스 구성 안내

아래는 테스트 케이스 구성을 나타냅니다. 각 그룹 내의 테스트 케이스를 모두 통과하면 해당 그룹에 할당된 점수를 획득할 수 있습니다.

| 그룹 | 총점 | 추가 제한 사항 |
| --- | --- | --- |
| #1 | 10% | `requests`에 크레인을 사용한 출고 요청만 존재합니다. |
| #2 | 15% | `requests`에 지게차를 사용한 출고 요청만 존재합니다. |
| #3 | 25% | `requests`에 컨테이너의 종류가 최대 한 번씩 등장합니다. 즉, 이전에 꺼낸 컨테이너 종류를 다시 꺼내지 않습니다. |
| #4 | 50% | 제한사항 외 추가조건이 없습니다. |

---

#### 입출력 예

| storage | requests | result |
| --- | --- | --- |
| ["AZWQY", "CAABX", "BBDDA", "ACACA"] | ["A", "BB", "A"] | 11 |
| ["HAH", "HBH", "HHH", "HAH", "HBH"] | ["C", "B", "B", "B", "B", "H"] | 4 |

---

#### 입출력 예 설명

**입출력 예 #1**

문제 설명의 예시와 같습니다.

**입출력 예 #2**

![물류창고-2.drawio.png](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/95339b77-babc-4be8-96ee-60235ea50393/%E1%84%86%E1%85%AE%E1%86%AF%E1%84%85%E1%85%B2%E1%84%8E%E1%85%A1%E1%86%BC%E1%84%80%E1%85%A9-2.drawio.png)

창고의 초기 상태와 모든 요청을 수행한 뒤의 상태입니다. 남은 컨테이너의 수인 4를 return 해야 합니다.

---

# 풀이 과정

- 처음엔 단순 4방향 인접 체크로 접근했다. → 하지만 빠르게  내부 고립 빈 칸 처리를 못한다는 걸 알아챘다.
- 백준이 있던 시절, "치즈 문제"와 동일한 구조임을 인식했다.
- 그래서 경계에서 BFS로 reachable 빈 칸을 구하는 방향으로 전환을 시도했다.
- 크레인은 즉시 삭제, 지게차는 BFS 후 인접 컨테이너만 후처리하는 방식을 구상했다.
- But 35분에 포기. 크레인 후처리와 지게차 접근 가능 정의를 동시에 잡지 못했다.

``` cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

char str [51][51]={'0', };

char visited[51][51] = {'0' };

int dfs (){
    
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    
    // 바깥 쪽이 들어났는 지 알 수 있어야 해.
    // 다시 vector를 재할당?
    
    for (int i = 0; i<52; i++){
        for (int j = 0; j<52; j++){
            str[i][j] = '0';
        }

    }
    
    for (int i = 0; i<storage.size(); i++){
        for (int j = 0; j<storage[i].size(); j++){
            str[i+1][j+1] = storage[i][j];
            answer ++;
        }
    }
    
    // 무조건 트리 순회 문제이다.
    // 마지막 A 케이스에 의해 바깥쪽 순회를 계속해야 함.
    // 테두리를 감싸는 트리 문제
    
    
    for (int i = 0; i< requests.size(); i++){
        // 삭제 로직, 진짜 무식하게 해볼까?
        // 바깥+지게차가 삭제: -1
        // 크레인이 삭제 + 바깥쪽이 있으면 
        // 배열만큼 순회 + 만약 4분면 중 하나라도 비어있다면 지게차로 삭제 가능
        if (requests[i].size() == 1){
            // 1번만, 바깥에서 삭제. -> 이거 바깥쪽 순회하는 치즈 문제인데, 
            for (int j = 1; j<storage.size(); j++){
                vector<pair<int, int>> pos;
                
                for (int k = 1; k<storage[j].size(); k++){
                    if (str[j][k] == requests[i][0]){ // 일치하면서
                        if (str[j-1][k] == '0' || str[j+1][k] == '0' || str[j][k-1] == '0' || str[j][k+1] == '0'){ // 바깥쪽이면
                            pos.push_back({j, k}); 
                        }
                        
                    }
                    
                    
                }
                for (pair<int, int> a : pos){ // 작업은 후처리 이어야 함!
                    str[a.first][a.second] = '0';
                    answer --;
                }
            }
        }
        else {
            // 크레인, 그냥 상관없이 삭제
            for (int j = 1; j<storage.size(); j++){
                for (int k = 1; k<storage[j].size(); k++){
                    
                    if (str[j][k] == requests[i][0]){ // 그냥 바로 일치하면 삭제
                        answer --;
                    }
                    if (str[j-1][k] == '0' || str[j+1][k] == '0' || str[j][k-1] == '0' || str[j][k+1] == '0'){ 
                        str[j][k] = '0'; // 지게차 접근 가능을 표현
                    }
                    else{
                        str[j][k] = '1'; // 아직은 남아 있음을 표현.
                    }
                    
                }
            }
            
        }
    }
    
    
    
//     for (int i = 0; i<51; i++){
//         for (int j = 0 ; j<51; j++){
//             cout << str[i][j] << ' ';
//         }
//         cout << '\n';
//     }
    
    return answer;
}
```

---

# 결과 & 근거

- 실패 (35분 내 미완성 포기)
- 분석해보니 '외부와 연결된 빈 칸'을 단순 인접 체크로 대체한 오류 + 크레인 수행 시 그리드 갱신 누락 등에 의해 완벽한 실패였다.
- 맨 처음부터 바깥쪽 테두리를 빠르게 만들고, BFS/DFS 방식으로 순회 했다면 성공했을 것이다.

### 알고리즘 분류

- 구현, BFS, 시뮬레이션, 플러드 필 (Flood Fill)