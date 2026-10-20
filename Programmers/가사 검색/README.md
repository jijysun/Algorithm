# 프로그래머스, 가사 검색 (실패)

# 문제 소개

[문제 사이트 하이퍼링크](https://school.programmers.co.kr/learn/courses/30/lessons/60060)

**[본 문제는 정확성과 효율성 테스트 각각 점수가 있는 문제입니다.]**

친구들로부터 천재 프로그래머로 불리는 **"프로도"**는 음악을 하는 친구로부터 자신이 좋아하는 노래 가사에 사용된 단어들 중에 특정 키워드가 몇 개 포함되어 있는지 궁금하니 프로그램으로 개발해 달라는 제안을 받았습니다.

그 제안 사항 중, 키워드는 와일드카드 문자중 하나인 '?'가 포함된 패턴 형태의 문자열을 뜻합니다. 와일드카드 문자인 '?'는 글자 하나를 의미하며, 어떤 문자에도 매치된다고 가정합니다. 예를 들어 `"fro??"`는 `"frodo"`, `"front"`, `"frost"` 등에 매치되지만 `"frame"`, `"frozen"`에는 매치되지 않습니다.

가사에 사용된 모든 단어들이 담긴 배열 `words`와 찾고자 하는 키워드가 담긴 배열 `queries`가 주어질 때, 각 키워드 별로 매치된 단어가 몇 개인지 **순서대로** 배열에 담아 반환하도록 `solution` 함수를 완성해 주세요.

### **가사 단어 제한사항**

- `words`의 길이(가사 단어의 개수)는 2 이상 100,000 이하입니다.
- 각 가사 단어의 길이는 1 이상 10,000 이하로 빈 문자열인 경우는 없습니다.
- 전체 가사 단어 길이의 합은 2 이상 1,000,000 이하입니다.
- 가사에 동일 단어가 여러 번 나올 경우 중복을 제거하고 `words`에는 하나로만 제공됩니다.
- 각 가사 단어는 오직 알파벳 소문자로만 구성되어 있으며, 특수문자나 숫자는 포함하지 않는 것으로 가정합니다.

### **검색 키워드 제한사항**

- `queries`의 길이(검색 키워드 개수)는 2 이상 100,000 이하입니다.
- 각 검색 키워드의 길이는 1 이상 10,000 이하로 빈 문자열인 경우는 없습니다.
- 전체 검색 키워드 길이의 합은 2 이상 1,000,000 이하입니다.
- 검색 키워드는 중복될 수도 있습니다.
- 각 검색 키워드는 오직 알파벳 소문자와 와일드카드 문자인 `'?'` 로만 구성되어 있으며, 특수문자나 숫자는 포함하지 않는 것으로 가정합니다.
- 검색 키워드는 와일드카드 문자인 `'?'`가 하나 이상 포함돼 있으며, `'?'`는 각 검색 키워드의 접두사 아니면 접미사 중 하나로만 주어집니다.
    - 예를 들어 `"??odo"`, `"fro??"`, `"?????"`는 가능한 키워드입니다.
    - 반면에 `"frodo"`(`'?'`가 없음), `"fr?do"`(`'?'`가 중간에 있음), `"?ro??"`(`'?'`가 양쪽에 있음)는 불가능한 키워드입니다.

### **입출력 예**

| words | queries | result |
| --- | --- | --- |
| `["frodo", "front", "frost", "frozen", "frame", "kakao"]` | `["fro??", "????o", "fr???", "fro???", "pro?"]` | `[3, 2, 4, 1, 0]` |

### **입출력 예에 대한 설명**

- `"fro??"`는 `"frodo"`, `"front"`, `"frost"`에 매치되므로 3입니다.
- `"????o"`는 `"frodo"`, `"kakao"`에 매치되므로 2입니다.
- `"fr???"`는 `"frodo"`, `"front"`, `"frost"`, `"frame"`에 매치되므로 4입니다.
- `"fro???"`는 `"frozen"`에 매치되므로 1입니다.
- `"pro?"`는 매치되는 가사 단어가 없으므로 0 입니다.

---

# 풀이 과정

- 사실 제대로 된 접근 조차 하지 못했다
- 일일이 대조해보는 로직으로 가려다가 멘붕으로 실패

```cpp
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    
    sort (queries.begin(), queries.end());
    
    for (string q : queries){
        int cnt = 0;
        for (string w : words){
            cout << q << " - " << w << endl;
            
            if (w.size() != q.size()) continue;
            
            int alpha = 0, alpha_cnt=0;
            
            for (int i = 0; i<w.size(); i++){
                if (w[i] == '?')continue;
                
                alpha++;
                if (q[i] == w[i]) alpha_cnt ++;
            }
            if (alpha_cnt == alpha){
                // cout << q << " - " << w << endl;
                cnt ++;
            }
            
        }
        answer.push_back(cnt);
    }
        
    return answer;
}
```

---

# 결과 & 근거

- 길이가 다르면 절대 매치되지 않는다 → **길이를 전처리 단계의 그룹 키로 쓴다.**
    - 쿼리 안에서 `w.size() != q.size()` 를 확인하는 건 같은 사실을 비싸게 쓰는 것
- "fro??" 처럼 **고정된 부분이 앞에 모여 있으면**, 사전순 정렬에서 매치되는 단어들이
**연속 구간**을 이룬다. 그러면 구간의 양 끝만 이분탐색으로 찾고 개수는 뺄셈이다.
    - 구간의 최소 = '?' 를 'a' 로 치환
    - 구간의 최대 = '?' 를 'z' 로 치환
- "??odo" 는 앞이 열려 있어 연속 구간이 아니다. **단어와 쿼리를 모두 뒤집으면** 접두사 쿼리가 되므로, **뒤집은 단어 배열을 하나 더 정렬해둔다.**
- 전부 '?' 인 쿼리("?????")는 접미사 분기로 보내면 자동으로 처리된다.

```cpp
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
    const int MAXLEN = 10001;                   // 문자열 길이 <= 10,000

    /* 1단계 — 길이별로 분리. 정방향과 역방향 두 벌을 만든다.
       역방향이 필요한 이유: "??odo" 같은 접미사 쿼리를 뒤집어 접두사 쿼리로 바꾸기 위해 */
    vector<vector<string>> fwd(MAXLEN), rev(MAXLEN);
    for (auto& w : words) {
        int L = w.size();
        fwd[L].push_back(w);
        string r = w; reverse(r.begin(), r.end());
        rev[L].push_back(r);
    }

    /* 2단계 — 각 길이 그룹을 사전순 정렬.
       정렬해두면 "같은 접두사를 가진 단어들" 이 연속 구간이 된다 */
    for (int L = 0; L < MAXLEN; L++) if (!fwd[L].empty()) {
        sort(fwd[L].begin(), fwd[L].end());
        sort(rev[L].begin(), rev[L].end());
    }

    /* 3단계 — '?' 를 최소/최대 문자로 치환해 구간을 만들고, 양 끝을 이분탐색 */
    auto countRange = [&](vector<string>& arr, string pat) -> int {
        string lo = pat, hi = pat;
        for (auto& c : lo) if (c == '?') c = 'a';      // 구간의 최소
        for (auto& c : hi) if (c == '?') c = 'z';      // 구간의 최대
        auto a = lower_bound(arr.begin(), arr.end(), lo);
        auto b = upper_bound(arr.begin(), arr.end(), hi);
        return (int)(b - a);                           // 뺄셈으로 개수
    };

    vector<int> answer;                                // ★ queries 를 정렬하지 않는다
    for (auto& q : queries) {                          //   순서를 그대로 유지
        int L = q.size();
        if (L >= MAXLEN || fwd[L].empty()) { answer.push_back(0); continue; }

        if (q[0] != '?') answer.push_back(countRange(fwd[L], q));   // 접두사형 "fro??"
        else {                                                      // 접미사형 "??odo"
            string r = q; reverse(r.begin(), r.end());              //   또는 전체 "?????"
            answer.push_back(countRange(rev[L], r));
        }
    }
    return answer;
}
```

> 와일드카드 `?`가 **접두사 또는 접미사에만** 오는 패턴 매칭 개수 문제. 길이가 같아야만 매치되므로 단어를 **길이별로 그룹핑해 사전순 정렬**하고, `?`를 `'a'`/`'z'`로 치환해 만든 구간의 양 끝을 이분탐색으로 찾아 개수를 뺄셈으로 구한다. 접미사 쿼리는 단어와 쿼리를 모두 뒤집으면 접두사 쿼리가 되므로 **뒤집은 배열을 하나 더 준비하는 것**이 핵심.
> 

### 알고리즘 분류

- 이분탐색
- 정렬
- 문자열
- (대안) 트라이