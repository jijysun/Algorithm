# 프로그래머스, 수식 복원하기

# 문제 소개

[문제 사이트 하이퍼링크](https://school.programmers.co.kr/learn/courses/30/lessons/340210)

당신은 덧셈 혹은 뺄셈 수식이 여러 개 적힌 고대 문명의 유물을 찾았습니다. 이 수식들을 관찰하던 당신은 이 문명이 사용하던 진법 체계가 10진법이 아니라는 것을 알아냈습니다. (2 ~ 9진법 중 하나입니다.)

수식들 중 몇 개의 수식은 결괏값이 지워져 있으며, 당신은 이 문명이 사용하던 진법에 맞도록 지워진 결괏값을 채워 넣으려 합니다.

다음은 그 예시입니다.

<**수식**>

```
14 + 3 = 17
13 - 6 = X
51 - 5 = 44
```

- `X`로 표시된 부분이 지워진 결괏값입니다.

`51 - 5 = 44`에서 이 문명이 사용하던 진법이 8진법임을 알 수 있습니다. 따라서 `13 - 6 = X`의 지워진 결괏값을 채워 넣으면 `13 - 6 = 5`가 됩니다.

다음은 또 다른 예시입니다.

<**수식**>

```
1 + 1 = 2
1 + 3 = 4
1 + 5 = X
1 + 2 = X
```

주어진 수식들에서 이 문명에서 사용한 진법이 6 ~ 9진법 중 하나임을 알 수 있습니다.

`1 + 5 = X`의 결괏값은 6진법일 때 10, 7 ~ 9진법일 때 6이 됩니다. 이와 같이 결괏값이 불확실한 수식은 `?`를 사용해 `1 + 5 = ?`와 같이 결괏값을 채워 넣습니다.

`1 + 2 = X`의 결괏값은 6 ~ 9진법에서 모두 3으로 같습니다. 따라서 `1 + 2 = X`의 지워진 결괏값을 채워 넣으면 `1 + 2 = 3`이 됩니다.

덧셈 혹은 뺄셈 수식들이 담긴 1차원 문자열 배열 `expressions`가 매개변수로 주어집니다. 이때 결괏값이 지워진 수식들의 결괏값을 채워 넣어 순서대로 문자열 배열에 담아 return 하도록 solution 함수를 완성해 주세요.

---

#### 제한사항

- 2 ≤ `expressions`의 길이 ≤ 100
    - `expressions`의 원소는 `"A + B = C"` 혹은 `"A - B = C"` 형태의 문자열입니다. A, B, C와 연산 기호들은 공백 하나로 구분되어 있습니다.
    - A, B는 음이 아닌 두 자릿수 이하의 정수입니다.
    - C는 알파벳 `X` 혹은 음이 아닌 세 자릿수 이하의 정수입니다. C가 알파벳 `X`인 수식은 결괏값이 지워진 수식을 의미하며, 이러한 수식은 한 번 이상 등장합니다.
    - 결괏값이 음수가 되거나 서로 모순되는 수식은 주어지지 않습니다.

---

#### 입출력 예

| expressions | result |
| --- | --- |
| ["14 + 3 = 17", "13 - 6 = X", "51 - 5 = 44"] | ["13 - 6 = 5"] |
| ["1 + 1 = 2", "1 + 3 = 4", "1 + 5 = X", "1 + 2 = X"] | ["1 + 5 = ?", "1 + 2 = 3"] |
| ["10 - 2 = X", "30 + 31 = 101", "3 + 3 = X", "33 + 33 = X"] | ["10 - 2 = 4", "3 + 3 = 10", "33 + 33 = 110"] |
| ["2 - 1 = 1", "2 + 2 = X", "7 + 4 = X", "5 - 5 = X"] | ["2 + 2 = 4", "7 + 4 = ?", "5 - 5 = 0"] |
| ["2 - 1 = 1", "2 + 2 = X", "7 + 4 = X", "8 + 4 = X"] | ["2 + 2 = 4", "7 + 4 = 12", "8 + 4 = 13"] |

---

#### 입출력 예 설명

**입출력 예 #1**

문제 예시와 같습니다.

**입출력 예 #2**

문제 예시와 같습니다.

**입출력 예 #3**

`30 + 31 = 101`에서 이 문명이 사용하던 진법이 6진법임을 알 수 있습니다. 따라서 `10 - 2 = X`, `3 + 3 = X`, `33 + 33 = X`의 지워진 결괏값을 채워 넣으면 `10 - 2 = 4`, `3 + 3 = 10`, `33 + 33 = 110`이 됩니다.

따라서 `["10 - 2 = 4", "3 + 3 = 10", "33 + 33 = 110"]`을 return 해야 합니다.

**입출력 예 #4**

수식에 등장하는 숫자들을 통해 이 문명이 사용하던 진법이 8진법 혹은 9진법임을 알 수 있습니다. `2 + 2 = X`와 `5 - 5 = X`의 지워진 결괏값을 채워 넣으면 8진법, 9진법에 관계없이 `2 + 2 = 4`, `5 - 5 = 0`이 됩니다. `7 + 4 = X`의 결괏값은 불확실하므로 지워진 결괏값을 채워 넣으면 `7 + 4 = ?`가 됩니다.

따라서 `["2 + 2 = 4", "7 + 4 = ?", "5 - 5 = 0"]`을 return 해야 합니다.

**입출력 예 #5**

네 번째 예시와 같지만 `5 - 5 = X`가 `8 + 4 = X`로 바뀌었습니다. 이 문명이 사용하던 진법이 9진법임을 알 수 있으므로 `7 + 4 = X`와 `8 + 4 = X`의 지워진 결괏값을 채워 넣으면 `7 + 4 = 12`, `8 + 4 = 13`이 됩니다.

따라서 `["2 + 2 = 4", "7 + 4 = 12", "8 + 4 = 13"]`을 return 해야 합니다

---

# 풀이 과정

- 경우의 수가 너무 많아서 헷갈렸다.
- 진법을 확인해야 하는데 최소 진법과 최대 진법이 존재한다고 보고, 문자열을 변환한 뒤 자릿수별로 진법을 계산해서 최소/최대 진법을 구해 보려고 했다.
- 두 자리 덧셈에서 올림이 넘어가는 케이스도 헷갈렸다.
- 한 자리 숫자 수식이 곧 최소 진법을 알려준다는 점은 포기하고 나서야 알게 됐다.
    - 아마 이게 제일 큰 접근법이었던 것 같다.
    
    **실패 (39분에 포기)**
    
    - 진법은 2~9진법 8개뿐이라 후보를 전부 대입하는 문제인데, 수식에서 최소/최대 진법을 추론하려는 방향으로 갔다
    - `stoi`는 10진수로만 읽는데 수식을 해당 진법으로 읽는 부분이 없었고, `answer`에도 값을 넣지 않아 항상 빈 배열을 반환했다
    - 모든 숫자의 자릿수가 `진법 > 자릿수`를 요구하는데, X 식의 피연산자까지 포함하지 않으면 랜덤 3만 케이스에서 26.1%가 오답이다

```cpp
vector<vector<string>> arr;
vector<vector<string>> problem; // return 할 배열

vector<string> solution(vector<string> expressions) {
    vector<string> answer;
    
    int min_radix = 2;
    int max_radix = 10; // 일단 0~9가 최대이므로.
    
    for (string s : expressions){
        stringstream ss (s);
        string token;
        vector<string> v;
        bool flag = false;
        while (ss >> token) {
            if (token == "=") continue;
            if (token == "X") flag = true;
            v.push_back(token);
        }
        if (flag) problem.push_back(v);
        else arr.push_back(v);
    }
    
    for (int i = 0; i<arr.size(); i++){
        int a = stoi(arr[i][0]), b = stoi(arr[i][2]), c = stoi(arr[i][3]), sum = 0;
        string expr = arr[i][1];
        if (expr == "+") sum = a+b;
        else sum = a-b;
        
        if (sum == c) {
            int num = sum%10;
            min_radix = max(min_radix, num+1);
        }
        else {
            if (sum%10 != c%10){
                max_radix = min(max_radix, max_radix-(sum%10-c%10));
            }
            int num10 = (a/10) + (b/10);
            if (sum/10 != c/10){
                max_radix = min(max_radix, max_radix-(c/10 - sum/10));
            }
        }
    }
    return answer;
}
```

---

# 결과 & 근거

**실패 (39분에 포기)**

- 진법은 2~9진법 8개뿐이라 후보를 전부 대입하는 문제인데, 수식에서 최소/최대 진법을 추론하려는 방향으로 갔다
- `stoi`는 10진수로만 읽는데 수식을 해당 진법으로 읽는 부분이 없었고, `answer`에도 값을 넣지 않아 항상 빈 배열을 반환했다
- 모든 숫자의 자릿수가 `진법 > 자릿수`를 요구하는데, X 식의 피연산자까지 포함하지 않으면 랜덤 3만 케이스에서 26.1%가 오답이다

```cpp
#include <string>
#include <vector>
#include <set>
#include <sstream>
using namespace std;

// base 진법 문자열 -> 10진 정수 (올림/내림 걱정 없이 10진수로 계산하기 위한 변환)
int toDec(const string& s, int base) {
    int v = 0;
    for (char ch : s) v = v * base + (ch - '0');
    return v;
}
// 10진 정수 -> base 진법 문자열 (결과를 다시 그 진법으로 되돌린다)
string toBase(int v, int base) {
    if (v < 0) return "NEG";
    if (v == 0) return "0";
    string r;
    while (v > 0) { r += char('0' + v % base); v /= base; }
    return string(r.rbegin(), r.rend());
}
struct Ex { string a, op, b, c; };

vector<string> solution(vector<string> expressions) {
    vector<Ex> known, asked;        // 결과가 있는 식 / X 인 식
    int maxDigit = 0;               // 모든 숫자에 나온 가장 큰 자릿수
    for (auto& s : expressions) {
        stringstream ss(s);
        Ex e; string eq;
        ss >> e.a >> e.op >> e.b >> eq >> e.c;
        for (char ch : e.a) maxDigit = max(maxDigit, ch - '0');
        for (char ch : e.b) maxDigit = max(maxDigit, ch - '0');   // ★ X 식의 피연산자도 포함
        if (e.c == "X") asked.push_back(e);
        else {
            for (char ch : e.c) maxDigit = max(maxDigit, ch - '0');
            known.push_back(e);
        }
    }

    // 1단계: 가능한 진법을 걸러낸다.  진법 > maxDigit 이어야 하고, 결과 있는 식이 전부 성립해야 한다
    vector<int> cand;
    for (int base = max(2, maxDigit + 1); base <= 9; base++) {
        bool ok = true;
        for (auto& e : known) {
            int x = toDec(e.a, base), y = toDec(e.b, base), z = toDec(e.c, base);
            if ((e.op == "+" ? x + y : x - y) != z) { ok = false; break; }
        }
        if (ok) cand.push_back(base);
    }

    // 2단계: 남은 후보 진법 전부로 X 식을 계산해 본다
    vector<string> answer;
    for (auto& e : asked) {
        set<string> res;            // 서로 다른 결과 문자열 (set 이라 같은 값은 하나로 합쳐진다)
        for (int base : cand) {
            int x = toDec(e.a, base), y = toDec(e.b, base);
            res.insert(toBase(e.op == "+" ? x + y : x - y, base));
        }
        // 결과가 한 종류면 확정, 둘 이상이면 진법에 따라 달라지므로 ?
        answer.push_back(e.a + " " + e.op + " " + e.b + " = " + (res.size() == 1 ? *res.begin() : "?"));
    }
    return answer;
}
```

> 
> 
> 
> ***한 줄 요약***
> 
> **쓰인 숫자에 대한 진법 추론 구현 알고리즘.**
> 
> 진법 후보가 2~9진법 8개뿐인데 수식에서 진법을 추론하려다 40분을 썼다. 후보 진법을 전부 대입해 모든 등식을 만족하는 것만 남기고, 숫자는 10진수로 바꿔 계산한 뒤 다시 그 진법으로 되돌리면 올림 고민 없이 끝난다. 작은 범위가 주어지면 추론하기 전에 "전부 대입 가능한가"를 먼저 센다.
> 

### 알고리즘 분류

- 완전탐색 (후보 진법 전수 대입)
- 구현
- 문자열 파싱
- 진법 변환
- 수학