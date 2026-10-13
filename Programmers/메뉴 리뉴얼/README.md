# 프로그래머스, 매뉴 리뉴얼 (실패)

# 문제 소개

[문제 사이트 링크](https://school.programmers.co.kr/learn/courses/30/lessons/72411)

#### **문제 설명**

레스토랑을 운영하던 `스카피`는 코로나19로 인한 불경기를 극복하고자 메뉴를 새로 구성하려고 고민하고 있습니다.

기존에는 단품으로만 제공하던 메뉴를 조합해서 코스요리 형태로 재구성해서 새로운 메뉴를 제공하기로 결정했습니다. 어떤 단품메뉴들을 조합해서 코스요리 메뉴로 구성하면 좋을 지 고민하던 "스카피"는 이전에 각 손님들이 주문할 때 가장 많이 함께 주문한 단품메뉴들을 코스요리 메뉴로 구성하기로 했습니다.

단, 코스요리 메뉴는 최소 2가지 이상의 단품메뉴로 구성하려고 합니다. 또한, 최소 2명 이상의 손님으로부터 주문된 단품메뉴 조합에 대해서만 코스요리 메뉴 후보에 포함하기로 했습니다.

예를 들어, 손님 6명이 주문한 단품메뉴들의 조합이 다음과 같다면,

(각 손님은 단품메뉴를 2개 이상 주문해야 하며, 각 단품메뉴는 A ~ Z의 알파벳 대문자로 표기합니다.)

| 손님 번호 | 주문한 단품메뉴 조합 |
| --- | --- |
| 1번 손님 | A, B, C, F, G |
| 2번 손님 | A, C |
| 3번 손님 | C, D, E |
| 4번 손님 | A, C, D, E |
| 5번 손님 | B, C, F, G |
| 6번 손님 | A, C, D, E, H |

가장 많이 함께 주문된 단품메뉴 조합에 따라 "스카피"가 만들게 될 코스요리 메뉴 구성 후보는 다음과 같습니다.

| 코스 종류 | 메뉴 구성 | 설명 |
| --- | --- | --- |
| 요리 2개 코스 | A, C | 1번, 2번, 4번, 6번 손님으로부터 총 4번 주문됐습니다. |
| 요리 3개 코스 | C, D, E | 3번, 4번, 6번 손님으로부터 총 3번 주문됐습니다. |
| 요리 4개 코스 | B, C, F, G | 1번, 5번 손님으로부터 총 2번 주문됐습니다. |
| 요리 4개 코스 | A, C, D, E | 4번, 6번 손님으로부터 총 2번 주문됐습니다. |

---

#### **[문제]**

각 손님들이 주문한 단품메뉴들이 문자열 형식으로 담긴 배열 orders, "스카피"가 `추가하고 싶어하는` 코스요리를 구성하는 단품메뉴들의 갯수가 담긴 배열 course가 매개변수로 주어질 때, "스카피"가 새로 추가하게 될 코스요리의 메뉴 구성을 문자열 형태로 배열에 담아 return 하도록 solution 함수를 완성해 주세요.

#### **[제한사항]**

- orders 배열의 크기는 2 이상 20 이하입니다.
- orders 배열의 각 원소는 크기가 2 이상 10 이하인 문자열입니다.
    - 각 문자열은 알파벳 대문자로만 이루어져 있습니다.
    - 각 문자열에는 같은 알파벳이 중복해서 들어있지 않습니다.
- course 배열의 크기는 1 이상 10 이하입니다.
    - course 배열의 각 원소는 2 이상 10 이하인 자연수가 `오름차순`으로 정렬되어 있습니다.
    - course 배열에는 같은 값이 중복해서 들어있지 않습니다.
- 정답은 각 코스요리 메뉴의 구성을 문자열 형식으로 배열에 담아 사전 순으로 `오름차순` 정렬해서 return 해주세요.
    - 배열의 각 원소에 저장된 문자열 또한 알파벳 `오름차순`으로 정렬되어야 합니다.
    - 만약 가장 많이 함께 주문된 메뉴 구성이 여러 개라면, 모두 배열에 담아 return 하면 됩니다.
    - orders와 course 매개변수는 return 하는 배열의 길이가 1 이상이 되도록 주어집니다.

---

#### **[입출력 예]**

| orders | course | result |
| --- | --- | --- |
| `["ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"]` | [2,3,4] | `["AC", "ACDE", "BCFG", "CDE"]` |
| `["ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"]` | [2,3,5] | `["ACD", "AD", "ADE", "CD", "XYZ"]` |
| `["XYZ", "XWY", "WXA"]` | [2,3,4] | `["WX", "XY"]` |

#### **입출력 예에 대한 설명**

---

**입출력 예 #1**

문제의 예시와 같습니다.

**입출력 예 #2**

AD가 세 번, CD가 세 번, ACD가 두 번, ADE가 두 번, XYZ 가 두 번 주문됐습니다.

요리 5개를 주문한 손님이 1명 있지만, 최소 2명 이상의 손님에게서 주문된 구성만 코스요리 후보에 들어가므로, 요리 5개로 구성된 코스요리는 새로 추가하지 않습니다.

**입출력 예 #3**

WX가 두 번, XY가 두 번 주문됐습니다.

3명의 손님 모두 단품메뉴를 3개씩 주문했지만, 최소 2명 이상의 손님에게서 주문된 구성만 코스요리 후보에 들어가므로, 요리 3개로 구성된 코스요리는 새로 추가하지 않습니다.

또, 단품메뉴를 4개 이상 주문한 손님은 없으므로, 요리 4개로 구성된 코스요리 또한 새로 추가하지 않습니다.

---

# 풀이 과정

- 코스 길이마다 조합을 만들고, 각 조합이 실제로 주문됐는지 확인하는 방향으로 짰다.
- O(1) 조회를 위해 graph[손님][알파벳] 2차원 벡터를 미리 만들어뒀다.
    - 모든 경우의 수를 점검하는 브루트 포스 알고리즘으로 판단.
- 문자열 조합을 만드는 아스키 연산에서 막혀 40분 포기.

```cpp
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

/*
- 제한사항 숫자 베끼기: orders 배열의 크기는 2 이상 20 이하
- 내 접근의 연산량 = ?       → 1억/초 기준 통과 여부 O/X 
- 상태와 전이를 한 문장으로   "상태 = 감염된 노드 집합, 전이 = 타입 t 선택"
- 예시 1개를 손으로 돌리기   (내 로직이 정답을 뱉는지)
*/

vector <vector<int>> graph (21, vector<int>(26));
string alpha (int start, string s, int size, vector<string> &orders){
    if (s.size() == size){
        // course 검사
        
        cout << s << '\n';
        
        
        for (int i = 0; i<orders.size(); i++){
            
        }
        
        
        // 각 주문에서 O(1)로 찾을 수 있음 좋은데
        
    }
    else {
        // 조합
        string new_s = s + to_string('A'+ start); // 아스키 변환 후 넘기기
        
        for (int i = start; i<26; i++){
            alpha (start+1, new_s, size, orders);
        }
        
    }
    return "s";
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    
    
    /*
    코스 기준 별로 최소 2명이 주문한 단품을 코스 요리 메뉴 구성으로 만들어야 한다.
    - 오름차순 정렬 return 
    
    */
    
    // A, B, C, D, E, F, G, H
    
    for (int i = 0; i<orders.size(); i++){
        for (int j = 0; j<orders[i].size(); j++){
            graph[i][j] = 1;
        }
    }
    
    
    for (int c : course){
        string s = "";        
        alpha (0, s, c, orders);
    }
    
    
    return answer;
}
```

---

# 결과 & 근거

- 실패 (40분 포기, 실행조차 되지 않는 상태)
- 아스키: to_string('A'+i) 는 "68" 을 만든다. char 캐스팅 또는 push_back 을 써야 한다.
- 조합 재귀에서 i+1 대신 start+1 을 넘겨 조합이 생성되지 않았다. pop_back 복구도 없었다.
- 탐색 공간을 26개 알파벳 전체로 잡아 약 1만 배 낭비. 손님 주문에서만 뽑으면 된다.

```cpp

// src 에서 크기 k 인 조합을 모두 만들어 cnt 에 집계한다.
//   src   : 한 손님의 주문 (오름차순으로 정렬되어 있음)
//   start : 이번 자리에 고를 수 있는 가장 왼쪽 인덱스
//   cur   : 지금까지 고른 문자들
void combi(const string& src, int start, int k, string& cur, map<string,int>& cnt) {

    if ((int)cur.size() == k) {   // k개를 다 골랐다 → 이 조합을 1회 주문된 것으로 집계
        cnt[cur]++;
        return;                   // ★ 종료 조건은 함수 진입부에. 루프 끝이 아니다
    }

    for (int i = start; i < (int)src.size(); i++) {
        cur.push_back(src[i]);    // i번째 문자를 고른다 (문자를 그대로 붙인다. to_string 아님)

        combi(src, i + 1, k, cur, cnt);
        //           ↑ ★ start+1 이 아니라 i+1.
        //             "i를 골랐으니 다음은 i보다 뒤에서" → 중복 없이 오름차순 조합이 된다.
        //             start+1 을 넘기면 i 가 무의미해져 같은 경로만 반복한다.

        cur.pop_back();           // ★ 백트래킹: 다음 i 를 시도하기 전에 원상복구
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    // 주문을 정렬해둔다. "XWY" 같은 입력이 있으므로,
    // 정렬해야 조합이 "WX" 처럼 오름차순 문자열로 만들어진다.
    for (string& o : orders) sort(o.begin(), o.end());

    for (int k : course) {        // 코스 길이별로 독립적으로 처리
        map<string,int> cnt;      // 조합 문자열 -> 몇 명이 주문했나

        for (const string& o : orders) {
            if ((int)o.size() < k) continue;   // 단품 수가 부족한 손님은 이 코스를 못 만든다
            string cur;
            combi(o, 0, k, cur, cnt);
            // ★ 26개 알파벳이 아니라 "이 손님이 주문한 것"에서만 뽑는다.
            //    답은 최소 2명이 주문한 조합이므로, 반드시 누군가의 주문 안에 들어 있다.
            //    전체 공간에서 뽑으면 약 1만 배 더 많은 조합을 만들게 된다.
        }

        int best = 0;
        for (auto& p : cnt) best = max(best, p.second);   // 이 길이에서 가장 많이 주문된 횟수

        if (best < 2) continue;   // "최소 2명 이상" 조건. 1명뿐이면 이 코스 길이는 후보가 없다

        for (auto& p : cnt) {
            if (p.second == best) answer.push_back(p.first);   // 공동 1위는 모두 포함
        }
    }

    sort(answer.begin(), answer.end());   // 최종 결과는 오름차순
    return answer;
}
```

### 알고리즘 분류

- 조합 (백트래킹)
- 해시 / 맵 집계
- 완전탐색
- 구현
- 문자열