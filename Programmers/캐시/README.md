# 프로그래머스, 캐시 (실패)

# 문제 소개

[문제 사이트 하이퍼링크](https://school.programmers.co.kr/learn/courses/30/lessons/17680)

지도개발팀에서 근무하는 제이지는 지도에서 도시 이름을 검색하면 해당 도시와 관련된 맛집 게시물들을 데이터베이스에서 읽어 보여주는 서비스를 개발하고 있다.

이 프로그램의 테스팅 업무를 담당하고 있는 어피치는 서비스를 오픈하기 전 각 로직에 대한 성능 측정을 수행하였는데, 제이지가 작성한 부분 중 데이터베이스에서 게시물을 가져오는 부분의 실행시간이 너무 오래 걸린다는 것을 알게 되었다.

어피치는 제이지에게 해당 로직을 개선하라고 닦달하기 시작하였고, 제이지는 DB 캐시를 적용하여 성능 개선을 시도하고 있지만 캐시 크기를 얼마로 해야 효율적인지 몰라 난감한 상황이다.

어피치에게 시달리는 제이지를 도와, DB 캐시를 적용할 때 캐시 크기에 따른 실행시간 측정 프로그램을 작성하시오.

### **입력 형식**

- 캐시 크기(`cacheSize`)와 도시이름 배열(`cities`)을 입력받는다.
- `cacheSize`는 정수이며, 범위는 0 ≦ `cacheSize` ≦ 30 이다.
- `cities`는 도시 이름으로 이뤄진 문자열 배열로, 최대 도시 수는 100,000개이다.
- 각 도시 이름은 공백, 숫자, 특수문자 등이 없는 영문자로 구성되며, 대소문자 구분을 하지 않는다. 도시 이름은 최대 20자로 이루어져 있다.

### **출력 형식**

- 입력된 도시이름 배열을 순서대로 처리할 때, "총 실행시간"을 출력한다.

### **조건**

- 캐시 교체 알고리즘은 `LRU`(Least Recently Used)를 사용한다.
- `cache hit`일 경우 실행시간은 `1`이다.
- `cache miss`일 경우 실행시간은 `5`이다.

### **입출력 예제**

| 캐시크기(cacheSize) | 도시이름(cities) | 실행시간 |
| --- | --- | --- |
| 3 | ["Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"] | 50 |
| 3 | ["Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"] | 21 |
| 2 | ["Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"] | 60 |
| 5 | ["Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"] | 52 |
| 2 | ["Jeju", "Pangyo", "NewYork", "newyork"] | 16 |
| 0 | ["Jeju", "Pangyo", "Seoul", "NewYork", "LA"] | 25 |

[해설 보러가기](http://tech.kakao.com/2017/09/27/kakao-blind-recruitment-round-1/)

---

# 풀이 과정

- `cacheSize`가 주어진 LRU 캐시를 구현하는 문제. hit이면 1, miss면 5를 더하면 된다.
- 자료구조를 고민했다. `queue`와 `vector<string>`을 같이 쓸까 생각했다가, **`vector<pair<string, int>>`에 (도시, 마지막 사용 시각)을 저장**하는 방식으로 정했다.
    - 시각 기준으로 오름차순 정렬하면 `cache[0]`이 가장 오래된 항목이 되니 그걸 버리면 된다고 봤다.
- `cacheSize == 0`이면 전부 miss이므로 `cities.size() * 5`로 바로 반환.
- 19분에 구현 완료했는데 segfault가 났다. 빈 캐시 상태 처리 때문이었다.
- 29분에 14/20 통과. TLE는 아니었다.
- 예외 케이스를 찾다가 **"캐시가 꽉 차지 않은 상태에서 hit인 경우에도 새로 넣게 된다"** 는 문제를 발견했다.
    - 35분에 0번째 도시는 무조건 넣고 1부터 순회하는 식으로 고쳐서 **75/100**.
- 38분 포기. 남은 예외 케이스를 못 찾았다.

```cpp
// 제출한 코드 (75/100)
vector<pair<string, int>> cache;

for (int i = 1; i < cities.size(); i++){
    string cur_city = cities[i];
    bool hit_flag = false;

    for (auto&[cache_city, num] : cache){
        if (cur_city == cache_city){
            hit++;
            num++, hit_flag = true;        // 시각을 1 증가시킨다
            break;
        }
    }

    if (!hit_flag){
        if (cache.size() < cacheSize){ miss++; cache.push_back({cities[i], i}); }
        else { miss++; cache[0].first = cur_city; cache[0].second = i; }
    }
    sort(cache.begin(), cache.end(), compare);   // 매 반복 정렬
}
return miss * 5 + hit;
```

---

# 결과 & 근거

- **실패** (38분 포기, 75/100).
    - 공식 예제 6개는 전부 통과했으나 히든에서 5개가 틀렸다.
    - 랜덤 200,000 케이스 교차검증 결과 **5.0% 오답**.
- 원인은 **hit 시 `num++`** 이다. `num`은 "마지막 사용 시각"인데 1만 증가시키면 다른 항목과 값이 겹치고, `std::sort`는 불안정 정렬이라 동점일 때 순서가 보장되지 않아 **잘못된 항목을 버린다.**
    - `num = i`로 현재 시각을 덮어쓰면 오답률이 0%가 된다.
    - 최소 반례는 `cacheSize=2, [a,b,a,c,a]` → **정답 17 / 내 코드 21**.
- 더 나은 구조는 **시간값을 아예 저장하지 않는 것**이다.
    - `vector<string>`의 순서를 최신성으로 쓰면(앞=LRU, 뒤=MRU) hit은 "꺼내서 맨 뒤로", miss는 "맨 앞 버리고 맨 뒤에 추가" 두 줄로 끝나고 `sort`가 사라진다.
    - 최대 입력에서 **296ms → 17ms (17배)**.

```cpp
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    if (cacheSize == 0) return (int)cities.size() * 5;   // 캐시가 없으면 전부 miss

    /* cache 의 "순서" 가 곧 최신성이다.
       앞쪽 = 오래 전에 쓴 것 (LRU),  뒤쪽 = 최근에 쓴 것 (MRU)
       -> 시간값을 따로 들고 다닐 필요가 없고 sort 도 필요 없다          */
    vector<string> cache;
    int total = 0;

    for (string city : cities) {
        for (auto& c : city) c = tolower(c);             // 대소문자 구분 없음

        auto it = find(cache.begin(), cache.end(), city);

        if (it != cache.end()) {        // ---- cache hit ----
            cache.erase(it);            // 있던 자리에서 꺼내고
            cache.push_back(city);      // 맨 뒤로 (가장 최근 사용)
            total += 1;
        }
        else {                          // ---- cache miss ----
            if ((int)cache.size() == cacheSize)
                cache.erase(cache.begin());   // 꽉 찼으면 맨 앞(가장 오래된 것)을 버린다
            cache.push_back(city);
            total += 5;
        }
    }
    return total;
}
```

> 
> 
> 
> ***한 줄 요약***
> 
> **LRU 캐시의 hit/miss 실행시간 합을 구하는 문제.** 
> 
> 시간값을 따로 저장하는 대신 vector의 순서 자체를 최신성으로 쓰면(앞=LRU, 뒤=MRU) hit은 "꺼내서 맨 뒤로", miss는 "맨 앞을 버리고 맨 뒤에 추가" 두 줄로 끝난다. hit 시 시간값을 ++로 1만 올리면 다른 항목과 값이 겹쳐 잘못된 항목을 버리게 되므로(5.0% 오답), 최신 시각으로 덮어쓰거나 애초에 순서로 표현해야 한다.
> 

### 알고리즘 분류

- 구현 / 시뮬레이션
- LRU 캐시
- 자료구조 (vector 순서 활용)
- 문자열 처리