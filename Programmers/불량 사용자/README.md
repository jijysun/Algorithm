# 프로그래머스, 불량 사용자 (실패)

# 문제 소개

[문제 사이트 하이퍼링크](https://school.programmers.co.kr/learn/courses/30/lessons/64064)

개발팀 내에서 이벤트 개발을 담당하고 있는 "무지"는 최근 진행된 카카오이모티콘 이벤트에 비정상적인 방법으로 당첨을 시도한 응모자들을 발견하였습니다. 이런 응모자들을 따로 모아 `불량 사용자`라는 이름으로 목록을 만들어서 당첨 처리 시 제외하도록 이벤트 당첨자 담당자인 "프로도" 에게 전달하려고 합니다. 이 때 개인정보 보호을 위해 사용자 아이디 중 일부 문자를 '*' 문자로 가려서 전달했습니다. 가리고자 하는 문자 하나에 '*' 문자 하나를 사용하였고 아이디 당 최소 하나 이상의 '*' 문자를 사용하였습니다.

"무지"와 "프로도"는 불량 사용자 목록에 매핑된 응모자 아이디를 `제재 아이디` 라고 부르기로 하였습니다.

예를 들어, 이벤트에 응모한 전체 사용자 아이디 목록이 다음과 같다면

응모자 아이디 

- frodo
- fradi
- crodo
- abc123
- frodoc

---

다음과 같이 불량 사용자 아이디 목록이 전달된 경우,

불량 사용자

- fr*d*
- abc1**

---

불량 사용자에 매핑되어 당첨에서 제외되어야 야 할 제재 아이디 목록은 다음과 같이 두 가지 경우가 있을 수 있습니다.

1. 제재 아이디: frodo,  abc123
2. 제재 아이디: fradi, abc123

---

이벤트 응모자 아이디 목록이 담긴 배열 user_id와 불량 사용자 아이디 목록이 담긴 배열 banned_id가 매개변수로 주어질 때, 당첨에서 제외되어야 할 제재 아이디 목록은 몇가지 경우의 수가 가능한 지 return 하도록 solution 함수를 완성해주세요.

#### **[제한사항]**

- user_id 배열의 크기는 1 이상 8 이하입니다.
- user_id 배열 각 원소들의 값은 길이가 1 이상 8 이하인 문자열입니다.
    - 응모한 사용자 아이디들은 서로 중복되지 않습니다.
    - 응모한 사용자 아이디는 알파벳 소문자와 숫자로만으로 구성되어 있습니다.
- banned_id 배열의 크기는 1 이상 user_id 배열의 크기 이하입니다.
- banned_id 배열 각 원소들의 값은 길이가 1 이상 8 이하인 문자열입니다.
    - 불량 사용자 아이디는 알파벳 소문자와 숫자, 가리기 위한 문자 '*' 로만 이루어져 있습니다.
    - 불량 사용자 아이디는 '*' 문자를 하나 이상 포함하고 있습니다.
    - 불량 사용자 아이디 하나는 응모자 아이디 중 하나에 해당하고 같은 응모자 아이디가 중복해서 제재 아이디 목록에 들어가는 경우는 없습니다.
- 제재 아이디 목록들을 구했을 때 아이디들이 나열된 순서와 관계없이 아이디 목록의 내용이 동일하다면 같은 것으로 처리하여 하나로 세면 됩니다.

---

#### **[입출력 예]**

| user_id | banned_id | result |
| --- | --- | --- |
| `["frodo", "fradi", "crodo", "abc123", "frodoc"]` | `["fr*d*", "abc1**"]` | 2 |
| `["frodo", "fradi", "crodo", "abc123", "frodoc"]` | `["*rodo", "*rodo", "******"]` | 2 |
| `["frodo", "fradi", "crodo", "abc123", "frodoc"]` | `["fr*d*", "*rodo", "******", "******"]` | 3 |

#### **입출력 예에 대한 설명**

#### **입출력 예 #1**

문제 설명과 같습니다.

#### **입출력 예 #2**

다음과 같이 두 가지 경우가 있습니다.

1. 제재 아이디: frodo, crodo, abc123
2. 제재 아이디: frodo, crodo, frodoc

#### **입출력 예 #3**

다음과 같이 세 가지 경우가 있습니다.

1. 제재 아이디: frodo, crodo, abc123, frodoc
2. 제재 아이디: fradi, crodo, abc123, frodoc
3. 제재 아이디: fradi, frodo, abc123, frodoc

---

# 풀이 과정

- 응모자 아이디 중 불량 사용자가 확인되는 경우의 수를 구하는 문제.
- 조합 문제로 봤다. 각 불량 아이디에 해당되는 유저를 고르고, 그 후보 개수를 곱하면 될 것 같았다.
- 만약 입력 크기가 매우 컸다면 알파벳별로 인덱싱을 두고 불량 아이디를 관리하는 방식이 좋겠다고 생각했다. 그래서 매칭된 유저를 **첫 글자 기준으로 묶어 개수를 곱하는** 방식으로 짰다.
- 22분 — 배열 범위를 넘겨 `segmentation fault` / `illegal instruction`이 났다. 배열을 벡터로 바꿔 고쳤다.
- 24분 — 모든 후보가 1개일 때 곱이 1이 되어 기존 분기가 틀렸다. 수정.
- 29분 — **숫자로 시작하는 아이디 처리를 아예 빼먹은 걸 발견.** 문자 처리 코드를 복붙해서 숫자 분기를 추가했다.
- 40분 — 고쳤는데도 여전히 틀렸다. 숫자인 경우만 문제인 것 같다고 판단.
- 45분 포기. **제시된 예제 3개는 전부 통과했는데 제출하면 실패했다.**

```cpp
#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
응모자 아이디 중 불량 사용자이 확인 되는 경우의 수 구하기.
*/

/*
user_id 관련 제한
- 1<= user_id.size() <= 8
- 중복 X
- 소문자로만.

banned_id 제한
- 1 <= banned_id.size() <= user_id.size()
-  '*' 문자를 하나 이상 포함

조합 문제이다, 해당되는 걸 골랐을 때 각각의 배열에서 고르고, 조합하는 것
- 만약 문제의 각 사이즈가 매우 컸다면, 알파벳 별 인덱싱을 갖으면서 불량 아이디를 갖는 거로
*/

vector<int> banned_num(10, 0);
vector<int> banned_alpha(26, 0);

vector<int>user_id_visited;

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    user_id_visited.assign(user_id.size(), 0);

    
    for (int s = 0; s<user_id.size(); s++){
        string u = user_id[s];
    
        
        for (string b : banned_id){
            if (b.size () != u.size()) continue;
            
            bool c1 = false;
            
            for (int i = 0; i<b.size(); i++){
                if (b[i] == '*') continue;
                if (b[i] != u[i]){
                    c1 = true;
                    break;
                }
            }
            
            if (c1) {
                continue;
            }
            
            // 숫자, 영어 체크.
            
            if (u[0] >= 'a'){
                cout << "영어입니다" << endl;
                if (user_id_visited[s]) continue;
                user_id_visited[s] = 1;
            
                int idx = u[0]-'a';
            
                banned_alpha[idx] ++;
                cout << idx << "++ -> " << banned_alpha[idx] << "\n\n";
            }
            else {
                cout << "숫자입니다" << endl;
                
                if (user_id_visited[s]) continue;
                user_id_visited[s] = 1;
                
                int idx = u[0]-'0';
                banned_num[idx] ++;
                cout << idx << "++ -> " << banned_num[idx] << "\n\n";
            }
            
    
            
        }
    }
    
    // for (int i = 0; i<26; i++){
        // cout << (char) ('a'+i) << ": " << banned_alpha[i] << endl;
    // }
    
    
    vector<int> num;
    
    for (int n : banned_num){
        if (n!=0){
            num.push_back(n);
        }
        
    }
    for (int n : banned_alpha){
        if (n!=0){
            num.push_back(n);
        }
    }
    
    if (num.empty()){
        return 0;
    }
    else{
        int a = 1;
        for (int n : num){
            a*=n;
        }
        return a;
    }
    
    
    
//     int a = 1, zero_check=0;
//     for (int n : banned_alpha){
//         if ( n!= 0){
//             a*=n;
//         }
//     }
    
//     if (a == 1) {
//         return 1;
//     }
//     else {
//         return a;
//     }
    
    
    /*
    22분 결과
    - 테스트 8 〉	실패 (signal: segmentation fault (core dumped))
    - 테스트 9 〉	실패 (signal: illegal instruction (core dumped))
    
    24분
    - 배열 -> 벡터로 전환하여 segment/ill 고침
    - 모두가 1 일때는 기존 코드가 틀림
    
    29분 숫자인 경우를 까먺는 대참사
    
    40분 고쳤는데, 숫자인 경우에만 틀리는 거 같아
    */
    
    
    
    // return answer;
}
```

---

# 결과 & 근거

- **실패** (45분 포기). 공식 예제 3개는 통과했으나 제출 시 실패.
- **원인은 숫자 처리가 아니라 접근 자체였다.**
    - 랜덤 200,000 케이스에서 **53.5%가 오답**이고, 반례는 숫자 없이 알파벳만으로도 만들어진다.
    - 최소 반례 `user_id = ["aa","ab"]`, `banned_id = ["**","**"]` → **정답 1 / 내 로직 2**.
- 후보 개수를 곱하는 모델은 **각 선택이 독립일 때만** 성립한다.
    - 이 문제는 ① 같은 유저를 두 불량 아이디에 쓸 수 없고(선택이 간섭한다)
    - ② 순서 무관·내용 같으면 하나로 세므로(집합 중복 제거), 곱셈으로는 둘 다 표현할 수 없다.
- 정답은 **DFS 완전 매칭 + 비트마스크 집합**이다.
    - `user_id`가 최대 8개라 최악 `8! = 40,320` 연산으로 완전탐색이 가능하다.
    - 제한을 먼저 확인했다면 곱셈 모델을 시도할 이유가 없었다.

```cpp
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
using namespace std;

/* 불량 아이디 b 가 유저 아이디 u 와 맞는가
   - '*' 는 한 글자를 가리므로 길이가 같아야 한다
   - '*' 가 아닌 자리는 글자가 정확히 같아야 한다       */
bool match(const string& u, const string& b) {
    if (u.size() != b.size()) return false;
    for (size_t i = 0; i < b.size(); i++)
        if (b[i] != '*' && b[i] != u[i]) return false;
    return true;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int n = user_id.size(), m = banned_id.size();

    set<vector<string>> results;      // 서로 다른 "제재 아이디 목록" 들
    vector<string> picked;            // 지금까지 고른 아이디들
    vector<int> used(n, 0);           // 이 유저를 이미 썼나

    /* idx 번째 불량 아이디에 유저를 배정한다 */
    function<void(int)> dfs = [&](int idx) {
        if (idx == m) {                            // 불량 아이디를 전부 배정했다
            vector<string> key = picked;
            sort(key.begin(), key.end());          // ★ 순서 무관 -> 정렬해서 넣는다
            results.insert(key);                   //   (이게 없으면 4.8% 오답)
            return;
        }
        for (int i = 0; i < n; i++) {
            if (used[i]) continue;                             // ★ 이미 쓴 유저는 못 쓴다
                                                               //   여기서 바로 가지를 끊는다
            if (!match(user_id[i], banned_id[idx])) continue;

            used[i] = 1;  picked.push_back(user_id[i]);        // 배정
            dfs(idx + 1);                                      // 다음 불량 아이디로
            picked.pop_back();  used[i] = 0;                   // 되돌리기 (백트래킹)
        }
    };

    dfs(0);
    return results.size();
}
```

> 
> 
> 
> ***한 줄 요약***
> 
> **와일드카드 *가 섞인 불량 아이디마다 서로 다른 응모자 아이디를 배정하는 완전 매칭 문제.**
> 
> 유저가 최대 8명이므로 DFS로 배정을 전수 탐색하되, 배정 순간 used[i]로 중복을 걸러 8^8을 8!로 줄이고, 완성된 목록은 정렬해서 set에 넣어 "순서 무관 중복 제거" 를 처리한다. 정렬을 빼면 순서만 다른 목록이 따로 세어져 4.8%가 틀린다.
> 

### 알고리즘 분류

- DFS / 백트래킹
- 완전탐색
- 비트마스크
- 집합 중복 제거
- 문자열 패턴 매칭