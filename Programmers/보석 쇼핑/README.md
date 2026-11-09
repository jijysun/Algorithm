# 프로그래머스, 보석 쇼핑 (실패)

# 문제 소개

[문제 사이트 하이퍼링크](https://school.programmers.co.kr/learn/courses/30/lessons/67258)

**[본 문제는 정확성과 효율성 테스트 각각 점수가 있는 문제입니다.]**

개발자 출신으로 세계 최고의 갑부가 된 `어피치`는 스트레스를 받을 때면 이를 풀기 위해 오프라인 매장에 쇼핑을 하러 가곤 합니다.

어피치는 쇼핑을 할 때면 매장 진열대의 특정 범위의 물건들을 모두 싹쓸이 구매하는 습관이 있습니다.

어느 날 스트레스를 풀기 위해 보석 매장에 쇼핑을 하러 간 어피치는 이전처럼 진열대의 특정 범위의 보석을 모두 구매하되 특별히 아래 목적을 달성하고 싶었습니다.

`진열된 모든 종류의 보석을 적어도 1개 이상 포함하는 가장 짧은 구간을 찾아서 구매`

예를 들어 아래 진열대는 4종류의 보석(RUBY, DIA, EMERALD, SAPPHIRE) 8개가 진열된 예시입니다.

| 진열대 번호 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 보석 이름 | DIA | RUBY | **RUBY** | **DIA** | **DIA** | **EMERALD** | **SAPPHIRE** | DIA |

진열대의 3번부터 7번까지 5개의 보석을 구매하면 모든 종류의 보석을 적어도 하나 이상씩 포함하게 됩니다.

진열대의 3, 4, 6, 7번의 보석만 구매하는 것은 중간에 특정 구간(5번)이 빠지게 되므로 어피치의 쇼핑 습관에 맞지 않습니다.

진열대 번호 순서대로 보석들의 이름이 저장된 배열 gems가 매개변수로 주어집니다. 이때 모든 보석을 하나 이상 포함하는 가장 짧은 구간을 찾아서 return 하도록 solution 함수를 완성해주세요.

가장 짧은 구간의 `시작 진열대 번호`와 `끝 진열대 번호`를 차례대로 배열에 담아서 return 하도록 하며, 만약 가장 짧은 구간이 여러 개라면 `시작 진열대 번호`가 가장 작은 구간을 return 합니다.

#### **[제한사항]**

- gems 배열의 크기는 1 이상 100,000 이하입니다.
    - gems 배열의 각 원소는 진열대에 나열된 보석을 나타냅니다.
    - gems 배열에는 1번 진열대부터 진열대 번호 순서대로 보석이름이 차례대로 저장되어 있습니다.
    - gems 배열의 각 원소는 길이가 1 이상 10 이하인 알파벳 대문자로만 구성된 문자열입니다.

---

#### **입출력 예**

| gems | result |
| --- | --- |
| `["DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"]` | [3, 7] |
| `["AA", "AB", "AC", "AA", "AC"]` | [1, 3] |
| `["XYZ", "XYZ", "XYZ"]` | [1, 1] |
| `["ZZZ", "YYY", "NNNN", "YYY", "BBB"]` | [1, 5] |

#### **입출력 예에 대한 설명**

**입출력 예 #1**

문제 예시와 같습니다.

**입출력 예 #2**

3종류의 보석(AA, AB, AC)을 모두 포함하는 가장 짧은 구간은 [1, 3], [2, 4]가 있습니다.

`시작 진열대 번호`가 더 작은 [1, 3]을 return 해주어야 합니다.

**입출력 예 #3**

1종류의 보석(XYZ)을 포함하는 가장 짧은 구간은 [1, 1], [2, 2], [3, 3]이 있습니다.

`시작 진열대 번호`가 가장 작은 [1, 1]을 return 해주어야 합니다.

**입출력 예 #4**

4종류의 보석(ZZZ, YYY, NNNN, BBB)을 모두 포함하는 구간은 [1, 5]가 유일합니다.

그러므로 [1, 5]를 return 해주어야 합니다.

※ 공지 - 2020년 7월 21일 테스트케이스가 추가되었습니다.

---

# 풀이 과정

- 슬라이딩 윈도우로 크기를 키워가며 하는 건 무조건 TLE라고 생각했다.
- gems 크기가 최대 100,000이라 순회는 N번으로 가정하는 게 나을 것 같았다.
- 키는 보석 이름(string)이고 값으로 인덱스들을 vector처럼 갖는 구조가 필요했는데, 검색해서 `unordered_map<string, vector<int>>`를 알게 됐다.
- 종류마다 인덱스를 하나씩 골라 조합하고, 가장 큰 인덱스 − 가장 작은 인덱스가 최소인 걸 답으로 하려 했다.
- 38분 만에 구현했지만 정확성 3/15, 효율성은 전부 실패했다.

```cpp
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

/*
특정 범위의 물건들을 모두 싹쓸이 구매
- 대신 진열된 모든 종류의 보석을 적어도 1개 이상 포함하는 가장 짧은 구간을 찾아서 구매
- 모든 보석을 하나 이상 포함하는 가장 짧은 구간을 찾아서 return!

가장 짧은 구간의 시작 진열대 번호와 끝 진열대 번호를 차례대로 배열에 담아서 return 하도록 하며, 
만약 가장 짧은 구간이 여러 개라면 시작 진열대 번호가 가장 작은 구간을 return 

먼저 슬라이딩 윈도우로 크기를 키워가며 하는 건 무조건 TLE.

예제를 보면 그냥 순회는 N 번으로 가정하는 게 나을 것 같아.
- gems 배열의 크기는 1 이상 100,000 이하 이므로 100,000 * N 으로 끝내는 게 깔끔.

키 값이 gems[i], string 이고, 각 값에 vector 처럼 인덱스를 가지고 있는?
이걸 어떻게 구현하지?
- unordered_map? -> 이건 검색해서 알게 됨
- 그다음 인덱싱에 대한 조합을 통해 가장 큰 값 - 가장 작은 값의 차이가 작은 거로 기억.

*/

unordered_map <string, vector<int>> um;
vector<int> idx;
map<string, int> visited_gem;
int visitied_idx[100001];
int type = 0, min_area = 100001;

vector<int> answer(2);

void combi (){
    
    if (idx.size() == type){ // 다른 보석을 전부 포함했다는 걸 어떻게 알지?
        // for (int i : idx) cout << i+1 << " ";
        int i1 = *min_element(idx.begin(), idx.end()) + 1, i2 = *max_element (idx.begin(), idx.end()) + 1;
        
        // cout << i1 << " " << i2 << endl;
        
        if (i2-i1 <= answer[1]-answer[0]){
            if (i2 <= answer[1]){
                // cout << "change! " << answer[0] << " " << answer[1] << " -> " << i1 << " " << i2 << endl;
                answer[0] = i1, answer[1] = i2;
            }
        }
        
        return;
    }
    
    
    for (const auto& pair : um) {
        
        string gem = pair.first;
        vector<int> gem_idx_list = pair.second;
        if (visited_gem[gem]) continue;
        
        visited_gem[gem] = 1;
        for (int i = 0; i<gem_idx_list.size(); i++){
            
            if (visitied_idx[gem_idx_list[i]]) continue;
            visitied_idx[gem_idx_list[i]] = 1;
        
            idx.push_back(gem_idx_list[i]);
        
            combi();
            visitied_idx[gem_idx_list[i]] = 0;
            idx.pop_back();
        }
        visited_gem[gem] = 0;
    }
    
}

map<string, int> visited2;

vector<int> solution(vector<string> gems) {
    
    answer[0] = 0, answer[1] = 100000;
    
    for (int i = 0; i<gems.size(); i++){
        um[gems[i]].push_back(i);
        
        if (visited2[gems[i]] == 0) {
            visited2[gems[i]] = 1;
            type ++;
        }
    }
    
    cout << "type: " << type << endl;
    
    combi();
    
    return answer;
}
```

---

# 결과 & 근거

**실패 (38분, 정확성 3/15 · 효율성 0)**

- 종류마다 인덱스를 고르는 경우를 전부 열거해서 지수 시간이 됐다. 종류 순서까지 중복으로 세서 8종류면 40,320배 더 걸렸다.
- 동률 처리를 if 두 개로 쪼개는 바람에, 더 짧지만 끝이 뒤에 있는 구간을 버렸다 (예: `A B B C A`).
- 오른쪽 끝을 늘리고, 모든 종류가 들어 있는 동안 왼쪽을 줄이는 투 포인터로 O(N)에 풀 수 있다.
    - 핵심은 창이 "다 포함" 상태가 되면 **왼쪽을 줄일 수 있을 만큼 줄이고**, 한 종류가 빠지는 순간 멈춰. 그다음 오른쪽을 늘려서 빠진 종류를 다시 찾는 것이다.

```cpp
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> gems) {
    // 1) 전체 보석 종류 수. set에 다 넣으면 중복이 빠지니까 크기 = 종류 수.
    int type = unordered_set<string>(gems.begin(), gems.end()).size();

    // 2) 현재 창 [l, r] 안에 각 보석이 몇 개 있는지.
    //    count가 0이 되면 erase해서 "cnt.size() = 창 안의 종류 수"가 되게 유지한다.
    unordered_map<string, int> cnt;

    // 3) 처음 답은 "전체 구간". 전체 구간은 항상 모든 종류를 포함하니까 안전한 초기값이다.
    //    (0-index로 들고 다니다가 마지막에 +1)
    vector<int> answer = {0, (int)gems.size() - 1};

    int l = 0;
    // 4) 오른쪽 끝 r을 한 칸씩 늘린다 → 창에 보석 하나 추가.
    for (int r = 0; r < gems.size(); r++) {
        cnt[gems[r]]++;

        // 5) 창이 모든 종류를 포함하는 동안 → 왼쪽 l을 줄여 본다.
        //    줄일 수 있을 때까지 줄이면, "r에서 끝나는 가장 짧은 구간"이 된다.
        while (cnt.size() == type) {
            // 5-1) 더 짧을 때만 갱신 (strict <).
            //      l은 계속 커지기만 하니까, 길이가 같으면 먼저 찾은 쪽 = 시작이 더 작은 쪽이 남는다.
            //      → "길이 같으면 시작 번호 작은 것" 조건이 자동으로 지켜진다.
            if (r - l < answer[1] - answer[0]) answer = {l, r};

            // 5-2) 맨 왼쪽 보석을 창에서 뺀다. 마지막 1개였다면 종류 자체를 지운다.
            if (--cnt[gems[l]] == 0) cnt.erase(gems[l]);
            l++;
        }
    }
    // 6) l, r 둘 다 앞으로만 움직이니까 각각 최대 N번 → 전체 O(N).
    return {answer[0] + 1, answer[1] + 1};
}
```

> 
> 
> 
> ***한 줄 요약***
> 
> **투 포인터(가변 윈도우) + 해시맵 문제.** 
> 
> 오른쪽 끝을 늘려 보석을 넣고, 모든 종류가 들어 있는 동안 왼쪽을 줄이며 최소 구간을 갱신한다. 창 안 종류 수를 `map.size()`로 유지하는 것과 strict `<` 갱신으로 동률 시 앞 구간을 남기는 게 핵심.
> 

### 알고리즘 분류

- 투 포인터
- 해시맵
- 구현