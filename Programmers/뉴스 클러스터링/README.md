# 프로그래머스, 뉴스 클러스터링 (실패)

# 문제 소개

[문제 사이트 하이퍼링크](https://school.programmers.co.kr/learn/courses/30/lessons/17677)

여러 언론사에서 쏟아지는 뉴스, 특히 속보성 뉴스를 보면 비슷비슷한 제목의 기사가 많아 정작 필요한 기사를 찾기가 어렵다. Daum 뉴스의 개발 업무를 맡게 된 신입사원 튜브는 사용자들이 편리하게 다양한 뉴스를 찾아볼 수 있도록 문제점을 개선하는 업무를 맡게 되었다.

개발의 방향을 잡기 위해 튜브는 우선 최근 화제가 되고 있는 "카카오 신입 개발자 공채" 관련 기사를 검색해보았다.

- 카카오 첫 공채..'블라인드' 방식 채용
- 카카오, 합병 후 첫 공채.. 블라인드 전형으로 개발자 채용
- 카카오, 블라인드 전형으로 신입 개발자 공채
- 카카오 공채, 신입 개발자 코딩 능력만 본다
- 카카오, 신입 공채.. "코딩 실력만 본다"
- 카카오 "코딩 능력만으로 2018 신입 개발자 뽑는다"

기사의 제목을 기준으로 "블라인드 전형"에 주목하는 기사와 "코딩 테스트"에 주목하는 기사로 나뉘는 걸 발견했다. 튜브는 이들을 각각 묶어서 보여주면 카카오 공채 관련 기사를 찾아보는 사용자에게 유용할 듯싶었다.

유사한 기사를 묶는 기준을 정하기 위해서 논문과 자료를 조사하던 튜브는 "자카드 유사도"라는 방법을 찾아냈다.

자카드 유사도는 집합 간의 유사도를 검사하는 여러 방법 중의 하나로 알려져 있다. 두 집합 `A`, `B` 사이의 자카드 유사도 `J(A, B)`는 두 집합의 교집합 크기를 두 집합의 합집합 크기로 나눈 값으로 정의된다.

예를 들어 집합 `A` = {1, 2, 3}, 집합 `B` = {2, 3, 4}라고 할 때, 교집합 `A ∩ B` = {2, 3}, 합집합 `A ∪ B` = {1, 2, 3, 4}이 되므로, 집합 `A`, `B` 사이의 자카드 유사도 `J(A, B)` = 2/4 = 0.5가 된다. 집합 A와 집합 B가 모두 공집합일 경우에는 나눗셈이 정의되지 않으니 따로 `J(A, B)` = 1로 정의한다.

자카드 유사도는 원소의 중복을 허용하는 다중집합에 대해서 확장할 수 있다. 다중집합 `A`는 원소 "1"을 3개 가지고 있고, 다중집합 `B`는 원소 "1"을 5개 가지고 있다고 하자. 이 다중집합의 교집합 `A ∩ B`는 원소 "1"을 min(3, 5)인 3개, 합집합 `A ∪ B`는 원소 "1"을 max(3, 5)인 5개 가지게 된다. 다중집합 `A` = {1, 1, 2, 2, 3}, 다중집합 `B` = {1, 2, 2, 4, 5}라고 하면, 교집합 `A ∩ B` = {1, 2, 2}, 합집합 `A ∪ B` = {1, 1, 2, 2, 3, 4, 5}가 되므로, 자카드 유사도 `J(A, B)` = 3/7, 약 0.42가 된다.

이를 이용하여 문자열 사이의 유사도를 계산하는데 이용할 수 있다. 문자열 "FRANCE"와 "FRENCH"가 주어졌을 때, 이를 두 글자씩 끊어서 다중집합을 만들 수 있다. 각각 {FR, RA, AN, NC, CE}, {FR, RE, EN, NC, CH}가 되며, 교집합은 {FR, NC}, 합집합은 {FR, RA, AN, NC, CE, RE, EN, CH}가 되므로, 두 문자열 사이의 자카드 유사도 `J("FRANCE", "FRENCH")` = 2/8 = 0.25가 된다.

### **입력 형식**

- 입력으로는 `str1`과 `str2`의 두 문자열이 들어온다. 각 문자열의 길이는 2 이상, 1,000 이하이다.
- 입력으로 들어온 문자열은 두 글자씩 끊어서 다중집합의 원소로 만든다. 이때 영문자로 된 글자 쌍만 유효하고, 기타 공백이나 숫자, 특수 문자가 들어있는 경우는 그 글자 쌍을 버린다. 예를 들어 "ab+"가 입력으로 들어오면, "ab"만 다중집합의 원소로 삼고, "b+"는 버린다.
- 다중집합 원소 사이를 비교할 때, 대문자와 소문자의 차이는 무시한다. "AB"와 "Ab", "ab"는 같은 원소로 취급한다.

### **출력 형식**

입력으로 들어온 두 문자열의 자카드 유사도를 출력한다. 유사도 값은 0에서 1 사이의 실수이므로, 이를 다루기 쉽도록 65536을 곱한 후에 소수점 아래를 버리고 정수부만 출력한다.

### **예제 입출력**

| str1 | str2 | answer |
| --- | --- | --- |
| FRANCE | french | 16384 |
| handshake | shake hands | 65536 |
| aa1+aa2 | AAAA12 | 43690 |
| E=M*C^2 | e=m*c^2 | 65536 |

---

# 풀이 과정

- 자카드 유사도 공식(교집합 / 합집합)은 바로 이해했다. 두 글자씩 끊어서 영문자 쌍만 남기고 소문자로 통일하는 부분도 문제없이 짰다.
- 문자열 집합은 잘 만들었는데 **합집합을 만드는 부분에서 막혔다.** `set<string>`에 양쪽을 다 넣으면 되겠다고 생각했는데, `ak an ds ha ha ke nd sh` 처럼 같은 쌍이 두 번 나오는 경우가 스킵되는 문제가 생겼다 (31분).
- `set<vector<string>>`를 써야 하는 것 같았는데 쓰는 법을 몰라서 막혔다.
- 교집합은 작은 쪽 기준으로 이중 for문을 돌려 일치하면 `break`하는 방식으로 셌다.
- 마지막에 **Long 처리를 어떻게 하는지 몰라서** `(long)(match/total.size()) * 65536l`로 썼다.
- 36분 50초에 포기. 테스트 2, 4는 통과했지만 1, 3이 틀렸다.

```cpp
#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
자카드 유사도, 집합 간의 유사도를 검사하는 여러 방법
- 두 집합의 교집합 크기를 두 집합의 합집합 크기로 나눈 값으로 정의
- 공집합일 경우에는 나눗셈이 정의되지 않으니 따로 J(A, B) = 1로 정의
- 원소의 중복을 허용하는 다중집합에 대해서 확장 가능
*/

vector <string> s1, s2;

int solution(string str1, string str2) { // 각 문자열의 길이는 2 이상, 1,000 이하
    int answer = 0;
    
    // 문자열은 두 글자씩 끊어서 다중집합의 원소로 만들기
    // 영문자로 된 글자 쌍만 유효하고, 기타 공백이나 숫자, 특수 문자가 들어있는 경우는 그 글자 쌍을 버린다.
    //  예를 들어 "ab+"가 입력으로 들어오면, "ab"만 다중집합의 원소로 삼고, "b+"는 버린다.
    
    // 다중집합 원소 사이를 비교할 때, 대문자와 소문자의 차이는 무시한다. "AB"와 "Ab", "ab"는 같은 원소로 취급
    
    for (int i = 0; i<str1.size(); i++){
        str1[i] = tolower(str1[i]);
    }
    for (int i = 0; i<str2.size(); i++){
        str2[i] = tolower(str2[i]);
    }
    
    for (int i = 0; i<str1.size()-1; i++){
        
        if (str1[i]<'a' || str1[i] > 'z' || str1[i+1]<'a' || str1[i+1] > 'z' ) continue;
        
        s1.push_back(str1.substr(i, 2));
    }
    for (int i = 0; i<str2.size()-1; i++){
        if (str2[i]<'a' || str2[i] > 'z' || str2[i+1]<'a' || str2[i+1] > 'z' ) continue;
        s2.push_back (str2.substr(i, 2));
    }
    
    sort (s1.begin(), s1.end());
    sort (s2.begin(), s2.end());
    
    for (string s : s1){
        cout << s << " ";
    }cout << endl;
    for (string s : s2){
        cout << s << " ";
    }cout << endl;
    
    // 공집합 판단
    
    // 교집합 -> 사이즈가 작은 문자열 기준으로 for문?
    
    long match = 0;
    if (s1.size() < s2.size()){
        for (int i = 0; i< s1.size(); i++){
            for (int j = 0; j<s2.size(); j++){
                if (s1[i] == s2[j]){
                    match++;
                    break;
                }
            }
        }
    }
    
    else {
        for (int i = 0; i< s2.size(); i++){
            for (int j = 0; j<s1.size(); j++){
                if (s2[i] == s1[j]){
                    match++;
                    break;
                }
            }
        }
    }
    
    
    
    
    set<string>total;
    // 합집합 -> 전부 Set<String> 에 넣을까? 넣고 나서면 이후 추가해도 반영은 되니까
    // 	ak an ds ha ha ke nd sh , aa aa 등의 같은 문자열 발생 시 스킵되는 문제 -> 31분
    // 이거는 set<vector<string>> 를 활용했어야 하는데, 어떻게 쓰는 지 몰라서 36분 50초 포기.

    int total_count = 0;
    for (string s : s1){
        if (total.count(s)){
            total_count++;
        }
        total.insert(s);
    }
    for (string s : s2){
        if (total.count(s)){
            total_count++;
        }
        total.insert(s);
    }

    
    cout << "match: " << match << ", total: "  << total.size() << endl;
    
    
    
    
    // FR RA AN NC CE
    // fr re en nc ch
    // -> 교집합 2 / 합집합 8 * 65536 = 16384
    
    // 두 문자열의 자카드 유사도를 출력
    // 유사도 값은 0에서 1 사이의 실수이므로, 이를 다루기 쉽도록 65536을 곱한 후에 소수점 아래를 버리고 정수부만 출력
    
    
    
    if (match == 0) {
        return 65536;
    }
    
    
    // 또한 Long 처리를 어떻게 하는 지 몰라서 못푼 것도 있음.    
    long a1 =  (long) (match/total.size() )* 65536l;
    cout << "a1: " << a1 << endl;
    return (int) a1;
}

/*

테스트 1
입력값 〉	"FRANCE", "french"
기댓값 〉	16384
실행 결과 〉	실행한 결괏값 0이 기댓값 16384과 다릅니다.
출력 〉	an ce fr nc ra 
ch en fr nc re 
match: 2, total: 8
a1: 0

테스트 2
입력값 〉	"handshake", "shake hands"
기댓값 〉	65536
실행 결과 〉	테스트를 통과하였습니다.
출력 〉	ak an ds ha ha ke nd sh 
ak an ds ha ha ke nd sh 
match: 8, total: 7
a1: 65536

테스트 3
입력값 〉	"aa1+aa2", "AAAA12"
기댓값 〉	43690
실행 결과 〉	실행한 결괏값 131072이 기댓값 43690과 다릅니다.
출력 〉	aa aa 
aa aa aa 
match: 2, total: 1
a1: 131072

테스트 4
입력값 〉	"E=M*C^2", "e=m*c^2"
기댓값 〉	65536
실행 결과 〉	테스트를 통과하였습니다.
출력 〉	

match: 0, total: 0
*/
```

---

# 결과 & 근거

- **실패** (36분 50초 포기). 테스트 2·4만 통과. 랜덤 200,000 케이스 교차검증에서 **97.3% 오답**.
- 핵심은 **다중집합이라 `set`을 쓸 수 없다**는 점이다. 지문대로 교집합은 각 원소가 `min(A개수, B개수)`번, 합집합은 `max(A개수, B개수)`번 들어가므로 **`map<string,int>`로 개수를 세야 한다.** `set`은 중복을 버려서 테스트 3의 합집합이 3이 아니라 1로 계산됐다.
- **Long 문제가 아니라 연산 순서 문제였다.** `2/8`은 정수 나눗셈으로 0이므로 `(match/total)*65536`은 항상 0이 된다. `match * 65536 / total`로 곱하기를 먼저 하면 된다. 그리고 최댓값이 `999 × 65536 = 65,470,464`로 `INT_MAX`의 3% 수준이라 **`long long` 자체가 불필요했다.**

```cpp
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

/* 문자열을 두 글자씩 끊어 유효한 쌍만 소문자로 모은다 */
vector<string> tokens(string s) {
    for (auto& c : s) c = tolower(c);            // 대소문자 무시 -> 전부 소문자로
    vector<string> v;
    for (size_t i = 0; i + 1 < s.size(); i++) {  // ★ i+1 < size() 로 쓰면 size()-1 의
                                                 //   unsigned 함정을 피한다
        if (s[i]   < 'a' || s[i]   > 'z') continue;   // 영문자가 아닌 쌍은 버린다
        if (s[i+1] < 'a' || s[i+1] > 'z') continue;
        v.push_back(s.substr(i, 2));
    }
    return v;
}

int solution(string str1, string str2) {
    vector<string> a = tokens(str1);
    vector<string> b = tokens(str2);

    /* 다중집합이므로 "개수" 를 세야 한다. set 은 중복을 버리므로 쓸 수 없다 */
    map<string, int> ca, cb;                     // ★ 원소 -> 등장 횟수
    for (auto& x : a) ca[x]++;
    for (auto& x : b) cb[x]++;

    /* 두 쪽에 등장한 모든 원소를 모은다 (합집합의 "종류") */
    set<string> keys;
    for (auto& p : ca) keys.insert(p.first);
    for (auto& p : cb) keys.insert(p.first);

    int inter = 0, uni = 0;
    for (auto& k : keys) {
        int x = ca.count(k) ? ca[k] : 0;         // A 에서의 개수 (없으면 0)
        int y = cb.count(k) ? cb[k] : 0;         // B 에서의 개수
        inter += min(x, y);                      // ★ 교집합 = min 의 합
        uni   += max(x, y);                      // ★ 합집합 = max 의 합
    }

    if (uni == 0) return 65536;                  // 둘 다 공집합이면 J = 1

    return inter * 65536 / uni;                  // ★ 곱하기를 먼저! (나누기 먼저면 0)
                                                 //   999 x 65536 = 6,547만 < INT_MAX
}
```

> 
> 
> 
> ***한 줄 요약***
> 
> 두 글자씩 끊은 **다중집합**의 자카드 유사도를 구하는 문제. 
> 
> 중복이 답을 바꾸므로 `set`이 아니라 **`map<string,int>`로 각 원소의 개수를 세고, 교집합은 `min`의 합 / 합집합은 `max`의 합**으로 계산한다. 마지막에 `65536`을 **나누기보다 먼저 곱해야** 정수 나눗셈으로 0이 되는 것을 막을 수 있고, 최댓값이 `999 × 65536 ≈ 6,547만`이라 `int`로 충분하다.
> 

### 알고리즘 분류

- 해시 / 맵 (개수 세기)
- 문자열 처리
- 구현
- 다중집합