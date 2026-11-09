# C++ STL 정리 — 내가 실제로 쓴 것 기준 (2026-11-09)

> 기준: 내 Algorithm 레포 `.cpp` 57개를 grep으로 센 빈도 + 지금까지 리뷰한 문제들에서 나랑 Claude가 쓴 코드.
> 레포 사용 빈도: `vector` 41개 파일 · `pair` 25 · `queue` 14 · `string` 14 · `map` 6 · `stack` 5 · `priority_queue` 4 · `deque` 2
> 함수 호출 수: `.first/.second` 190 · `.size` 96 · `.push_back` 65 · `.push/.pop/.empty` 35~39 · `.top` 32 · `sort` 11 · `find` 7 · `reverse` 6
> `set`, `unordered_map`, `unordered_set`은 레포엔 없고 리뷰 문제(불량 사용자, 뉴스 클러스터링, 보석 쇼핑)에서만 썼어.
> 아래 **[함정]** 표시는 전부 로컬 g++ 13.3에서 실제로 돌려서 확인한 결과야.

---

## 0. 모든 컨테이너 공통

| 함수 | 하는 일 | 비고 |
|---|---|---|
| `size()` | 원소 개수 | **unsigned(`size_t`)**. 아래 함정 참고 |
| `empty()` | 비었는가 | `size()==0`보다 의도가 잘 보여 |
| `clear()` | 전부 비움 | **테스트 케이스마다 전역 컨테이너 초기화할 때 필수** (stack/queue/pq엔 없음 → `q = queue<int>();`) |
| `begin()` / `end()` | 첫 원소 / **마지막 다음** 위치 iterator | `end()`는 원소가 아니야. "못 찾음" 표시로 쓰여 |
| `rbegin()` | 마지막 원소 iterator | `set`/`map`에서 최댓값 꺼낼 때 `*s.rbegin()` |

**[함정] `size()`는 unsigned야**: 빈 vector에서 `v.size() - 1` = **18446744073709551615**(실측). `for (int i = 0; i < v.size() - 1; i++)`에 빈 벡터가 들어가면 터져. → `(int)v.size() - 1`로 바꾸거나 `i + 1 < v.size()`로 써.

---

## 1. vector — 레포 41/57 파일

```cpp
vector<int> v;                              // 빈 벡터
vector<int> v(n, 0);                        // 크기 n, 0으로 채움
vector<vector<int>> g(n, vector<int>(m, -1)); // n×m 2차원 (격자, visited)
vector<vector<pair<int,int>>> adj(n + 1);   // 인접 리스트 (다익스트라)
vector<int> answer = {0, (int)gems.size() - 1}; // 리스트 초기화 (보석 쇼핑)
```

| 함수 | 하는 일 | 복잡도 | 내가 쓴 곳 |
|---|---|---|---|
| `push_back(x)` | 맨 뒤에 추가 | O(1) | 거의 모든 문제 (65회) |
| `pop_back()` | 맨 뒤 제거 | O(1) | 백트래킹 되돌리기 (보석 쇼핑 `idx.pop_back()`) |
| `back()` / `front()` | 맨 뒤 / 맨 앞 값 | O(1) | |
| `v[i]` | i번째 값 (범위 검사 없음) | O(1) | |
| `at(i)` | i번째 값 (범위 밖이면 예외) | O(1) | 디버깅용 |
| `resize(n, val)` | 크기 변경 | O(n) | |
| `assign(n, val)` | 크기 n, 전부 val로 다시 채움 | O(n) | **테스트 케이스 초기화에 딱 좋아** |
| `insert(it, x)` / `erase(it)` | 중간 삽입/삭제 | **O(n)** | 앞쪽에서 반복하면 느려 → deque/list 고려 |
| `reserve(n)` | 용량만 미리 확보 | | |

**자주 쓰는 패턴**
```cpp
// 정렬 + 중복 제거 (좌표 압축 등)
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());   // {1,1,1,2,2,3} → {1,2,3} (실측 크기 3)

// 순서 기반 LRU (캐시 문제 답안)
auto it = find(cache.begin(), cache.end(), city);
if (it != cache.end()) cache.erase(it);          // hit: 기존 위치에서 빼고
cache.push_back(city);                           // 맨 뒤(최신)로
```

---

## 2. pair (+ 구조화 바인딩) — 레포 25 파일, `.first/.second` 190회

```cpp
pair<int,int> p = {1, 2};
p.first; p.second;
make_pair(1, 2);                  // {1, 2}랑 같아. 요즘은 {}가 편함
auto [cost, cur] = pq.top();      // C++17 구조화 바인딩 — .first/.second 대신 이름 붙이기
for (auto& [nx, w] : adj[cur])    // 다익스트라 템플릿에서 쓴 방식
```

- **비교 규칙**: first 먼저, 같으면 second. 그래서 `sort`하면 first 오름차순 → second 오름차순 (실측 `{2,1},{1,5},{1,2}` → `{1,2}` 먼저)
- **[팁]** `.first/.second`가 190번이나 나와. 한 함수 안에서 3번 이상 쓰면 `auto [a, b]`로 이름 붙이는 게 읽기 편하고, **유사 이름 혼동(9회) 패턴**도 줄어

---

## 3. string — 레포 14 파일

| 함수 | 하는 일 | 주의 |
|---|---|---|
| `size()` / `length()` | 길이 | 둘이 같아 |
| `substr(pos, len)` | pos부터 **len개** | 두 번째 인자는 끝 위치가 아니라 **길이야**. `"hello".substr(1,3)` = `"ell"` |
| `find(str)` | 처음 나오는 **인덱스** | 없으면 `string::npos` (`-1` 아님, `== string::npos`로 비교) |
| `append(s)` / `+=` | 이어 붙이기 | |
| `s[i]` | 문자 하나 (`char`) | `s[i] - '0'` → 숫자, `s[i] - 'a'` → 알파벳 인덱스 |
| `stoi(s)` / `stoll(s)` | 문자열 → int / long long | `stoi("042")` = 42 |
| `to_string(x)` | 숫자 → 문자열 | |
| `reverse(s.begin(), s.end())` | 뒤집기 | |
| `tolower(c)` / `toupper(c)` | 대소문자 | 뉴스 클러스터링 |
| `isalpha(c)` / `isdigit(c)` | 알파벳/숫자 판별 | 뉴스 클러스터링(알파벳 쌍만), 수식 복원하기 |

```cpp
// 공백 분리 (CodeSignal 3번에서 막혔던 것)
istringstream iss(s); string w;
while (iss >> w) words.push_back(w);           // 연속 공백도 알아서 건너뜀 (실측 "a bb  ccc" → 3개)

// 한 줄 통째로 읽기
getline(cin, line);                            // cin >> 뒤에 쓰면 남은 '\n' 때문에 빈 줄이 읽혀 → cin.ignore() 먼저
```

---

## 4. map / unordered_map — 레포 6 파일 + 뉴스 클러스터링, 보석 쇼핑

```cpp
map<string, int> cnt;                    // 키 정렬됨 (레드-블랙 트리) — O(log n)
unordered_map<string, int> cnt;          // 정렬 안 됨 (해시) — 평균 O(1)
unordered_map<string, vector<int>> um;   // 키 → 인덱스 목록 (보석 쇼핑 네 코드)
```

| 함수 | 하는 일 | 주의 |
|---|---|---|
| `m[key]` | 값 접근. **없으면 기본값(0)으로 삽입** | **[함정] 조회만 해도 원소가 생겨** (실측: `if (m["x"]==0)` 후 size = 1) |
| `m[key]++` | 카운팅 | 이때는 자동 삽입이 오히려 편해 |
| `count(key)` | 있으면 1, 없으면 0 | **존재 여부 확인은 이걸로** |
| `find(key)` | iterator, 없으면 `end()` | 찾은 값도 같이 쓸 때 |
| `erase(key)` | 키 삭제 | 보석 쇼핑: 개수 0이면 `erase` → `size()` = 종류 수 유지 |
| `size()` | 키 개수 | |
| `for (auto& [k, v] : m)` | 순회 | `map`은 키 오름차순, `unordered_map`은 순서 보장 없음 |

```cpp
// [함정] 순회하면서 지우기 — erase가 다음 iterator를 돌려줌
for (auto it = m.begin(); it != m.end(); ) {
    if (조건) it = m.erase(it);
    else ++it;
}

// 다중집합 교집합/합집합 (뉴스 클러스터링)
for (auto& [k, a] : A) if (B.count(k)) inter += min(a, B[k]);
```

**[트레이드오프] map vs unordered_map**: 순서가 필요 없고 키가 많으면 `unordered_map`. 키 순서대로 순회하거나 `lower_bound`가 필요하면 `map`. 코테 규모(10⁵)에선 둘 다 통과하는 경우가 대부분이야. 보석 쇼핑을 둘 다로 돌려도 0.05초 안쪽이었어.

---

## 5. set / unordered_set — 불량 사용자, 보석 쇼핑

```cpp
set<int> s;                              // 정렬 + 중복 없음
set<vector<string>> result;              // 불량 사용자: 정렬한 조합을 넣어 중복 제거
unordered_set<string>(gems.begin(), gems.end()).size();  // 종류 수 한 줄 (보석 쇼핑)
```

| 함수 | 하는 일 | 복잡도 |
|---|---|---|
| `insert(x)` | 추가 (이미 있으면 무시) | O(log n) |
| `erase(x)` | 삭제 | O(log n) |
| `count(x)` | 있으면 1 | O(log n) |
| `*s.begin()` / `*s.rbegin()` | 최솟값 / 최댓값 | O(1) (실측 `{5,1,3}` → 1 / 5) |
| `lower_bound(x)` | x 이상 첫 원소 | O(log n). **`s.lower_bound(x)`로 쓸 것** (아래) |

**[함정]** `lower_bound(s.begin(), s.end(), x)`(전역 함수)는 set에서 **O(n)**이야. set/map은 반드시 멤버 함수 `s.lower_bound(x)`로 써.

---

## 6. queue — 레포 14 파일 (BFS)

| 함수 | 하는 일 |
|---|---|
| `push(x)` | 뒤에 넣기 |
| `front()` | 맨 앞 보기 (**pop은 값을 안 돌려줘**) |
| `pop()` | 맨 앞 빼기 |
| `empty()` / `size()` | |

```cpp
// BFS 3줄 체크: ① 이웃을 push하나 ② visited를 push 순간 세팅하나 ③ 경계 검사가 push 전인가
queue<pair<int,int>> q;
q.push({sx, sy}); visited[sx][sy] = 1;
while (!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;   // ③ 경계 먼저
        if (visited[nx][ny] || g[nx][ny] == 0) continue;
        visited[nx][ny] = 1;                                     // ② push 순간
        q.push({nx, ny});                                        // ①
    }
}

// 레벨 BFS (몇 번째 단계인지 셀 때)
while (!q.empty()) {
    int sz = q.size();                  // 이번 레벨 개수를 먼저 고정
    for (int i = 0; i < sz; i++) { ... }
    level++;
}
```

---

## 7. stack — 레포 5 파일

| 함수 | 하는 일 |
|---|---|
| `push(x)` / `pop()` / `top()` / `empty()` | queue와 같은데 `front` 대신 `top` |

- **[함정]** `pop()` 전에 `empty()` 확인을 안 하면 빈 스택에서 UB(정의되지 않은 동작)야. 괄호 검사 같은 문제에서 자주 터져.
- `vector`로도 똑같이 쓸 수 있어 (`push_back` / `back` / `pop_back`). 중간 원소를 봐야 하면 vector가 나아.

---

## 8. priority_queue — 레포 4 파일 (다익스트라)

```cpp
priority_queue<int> pq;                                   // 기본 = 최대 힙 (top이 가장 큼)
priority_queue<int, vector<int>, greater<int>> pq;        // 최소 힙 (top이 가장 작음)
priority_queue<pair<long long,int>,
               vector<pair<long long,int>>, greater<>> pq; // 다익스트라: {비용, 노드} 순서!
```

| 함수 | 하는 일 | 복잡도 |
|---|---|---|
| `push(x)` | 넣기 | O(log n) |
| `top()` | 가장 우선인 값 | O(1) |
| `pop()` | 가장 우선인 값 빼기 | O(log n) |

- 실측: 3, 1, 2를 넣으면 기본 top = **3**, `greater` top = **1**
- **[함정] pair 순서**: 비교는 first부터야. 다익스트라에서 `{노드, 비용}`으로 넣으면 노드 번호 순으로 꺼내져서 틀려. **`{비용, 노드}`**로 넣어.
- **[함정] 최소 힙 대신 음수 트릭**: `pq.push(-cost)`도 되지만 꺼낼 때 부호를 깜빡하기 쉬워 → `greater<>`가 안전해
- 중간 원소 수정/삭제 불가 → 다익스트라는 "낡은 항목이면 건너뛰기"(`if (cost > dist[cur]) continue;`)로 처리

---

## 9. deque — 레포 2 파일

`push_front` / `push_back` / `pop_front` / `pop_back` / `front` / `back` / `dq[i]` 전부 O(1). 양쪽에서 넣고 빼야 할 때 (0-1 BFS, 회전 큐) 써.

---

## 10. `<algorithm>` · `<numeric>` 함수

| 함수 | 하는 일 | 반환 | 내가 쓴 곳 |
|---|---|---|---|
| `sort(b, e)` | 오름차순 | — | 11회. 섬 연결하기(크루스칼), 숫자게임 |
| `sort(b, e, greater<>())` | 내림차순 | — | |
| `sort(b, e, [](auto& a, auto& b){...})` | 사용자 정의 | — | 아래 예시 |
| `stable_sort` | 같은 값의 원래 순서 유지 | — | **`sort`는 불안정** — 동률 순서가 중요하면 이거 |
| `reverse(b, e)` | 뒤집기 | — | 6회 |
| `max(a, b)` / `max({a,b,c})` | 큰 값 | **값** | 일곱 부하 |
| `max_element(b, e)` | 가장 큰 원소 위치 | **iterator** → `*`로 값, `- v.begin()`으로 인덱스 | 보석 쇼핑 |
| `find(b, e, x)` | x 위치 | iterator, 없으면 `e` | 캐시 |
| `count(b, e, x)` | x 개수 | 값 | |
| `lower_bound(b, e, x)` | **x 이상** 첫 위치 (정렬 필수) | iterator | 가사 검색 |
| `upper_bound(b, e, x)` | **x 초과** 첫 위치 | iterator | 가사 검색 |
| `unique(b, e)` | 연속 중복을 뒤로 밀기 | 새 끝 iterator | 정렬 + `erase`랑 세트 |
| `next_permutation(b, e)` | 다음 순열 (정렬 후 시작) | bool | 실측: `{1,2,3}` → 6개 |
| `accumulate(b, e, init)` | 합 | init 타입 | 아래 함정 |
| `fill(b, e, x)` | 채우기 | — | |
| `swap(a, b)` | 교환 | — | |

```cpp
// x 이상 개수 / 특정 값 개수 (정렬된 배열)
int idx = lower_bound(a.begin(), a.end(), x) - a.begin();                 // {1,3,3,5}, x=3 → 1
int cnt = upper_bound(a.begin(), a.end(), 3) - lower_bound(a.begin(), a.end(), 3); // 3 - 1 = 2개

// 람다 정렬: second 내림차순, 같으면 first 오름차순
sort(vp.begin(), vp.end(), [](auto& x, auto& y) {
    if (x.second != y.second) return x.second > y.second;
    return x.first < y.first;
});
```

**[함정] `accumulate`의 init 타입 = 결과 타입**: `accumulate(v.begin(), v.end(), 0)`은 int로 더해서 10억 3개면 **−1294967296**(실측 오버플로). `0LL`로 쓰면 3000000000.

**[함정] 값 반환 vs iterator 반환** (인수인계 문서 정리 그대로)
- 값: `max`, `min`, `count`, `string::find`(→ 인덱스)
- iterator: `find`, `max_element`, `min_element`, `lower_bound`, `upper_bound`, `set::find`, `map::find`
- "못 찾음": `end()` / `string::npos` / `count == 0`

---

## 11. 입출력 · 기타

```cpp
ios::sync_with_stdio(false); cin.tie(nullptr);   // 입력 많을 때 (+= 문제 60만 케이스)
cout << x << '\n';                               // endl은 매번 flush해서 느려
```

| 함정 | 내 사례 |
|---|---|
| **쉼표 연산자** `a = b, b = a`는 스왑이 아니야 → `swap(a, b)` | 예상 대진표 (50% 무한 루프) |
| **`using namespace std` 이름 충돌**: 전역에 `count`, `next`, `ref`, `max` 같은 이름 짓지 말 것 | 다익스트라 템플릿 |
| **정수 나눗셈 순서**: `a * K / b` ≠ `a / b * K` | |
| **int 범위**: 약 ±2.1×10⁹. 곱이나 합이 넘으면 `long long` | |
| **전역 컨테이너**: 테스트 케이스마다 `clear()` / `assign()` / `= {}` | 초기화 누락 11회 |
| **`memset`은 0 / −1만** 안전 (바이트 단위로 채워서) → 그 외 값은 `fill` | |
| **CodeSignal**: `bits/stdc++.h`, `memset`, `memcpy`, `strlen`, `assert` 불가 → 헤더 직접 include | 링커리어 코테 |

---

## 12. 헤더 (bits 못 쓸 때)

```cpp
#include <iostream>       // cin, cout
#include <vector>
#include <string>
#include <map>            // map, multimap
#include <unordered_map>
#include <set>            // set, multiset
#include <unordered_set>
#include <queue>          // queue, priority_queue
#include <stack>
#include <deque>
#include <algorithm>      // sort, reverse, max_element, lower_bound, unique, next_permutation, find, count
#include <numeric>        // accumulate, iota
#include <sstream>        // istringstream
#include <climits>        // INT_MAX, INT_MIN, LLONG_MAX
#include <cctype>         // isdigit, isalpha, tolower, toupper
#include <utility>        // pair, swap
```

---

## 참고 자료

- [cppreference — Containers library](https://en.cppreference.com/w/cpp/container) / [Algorithms library](https://en.cppreference.com/w/cpp/algorithm) (1순위 레퍼런스. 이번 세션에서 직접 열어보진 않았어 → 출처 미확인)
- [실측] 본문의 **[함정]** 값은 전부 로컬 g++ 13.3 `-std=c++17`에서 출력한 결과야
- [실측] 사용 빈도는 내 Algorithm 레포 `.cpp` 57개를 grep으로 센 수치야
