# 1541 잃어버린 괄호 (성공?)

# 문제 소개

[문제 사이트 링크](https://www.acmicpc.net/problem/1541)

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞힌 사람 | 정답 비율 |
| --- | --- | --- | --- | --- | --- |
| 2 초 | 128 MB | 110548 | 62197 | 48293 | 55.533% |

## 문제

세준이는 양수와 +, -, 그리고 괄호를 가지고 식을 만들었다. 그리고 나서 세준이는 괄호를 모두 지웠다.

그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만들려고 한다.

괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.

## 입력

첫째 줄에 식이 주어진다. 식은 ‘0’~‘9’, ‘+’, 그리고 ‘-’만으로 이루어져 있고, 가장 처음과 마지막 문자는 숫자이다. 그리고 연속해서 두 개 이상의 연산자가 나타나지 않고, 5자리보다 많이 연속되는 숫자는 없다. 수는 0으로 시작할 수 있다. 입력으로 주어지는 식의 길이는 50보다 작거나 같다.

## 출력

첫째 줄에 정답을 출력한다.

---

# 초기 접근 방법

- 그리디로 하되 문자열이 조금 짜증 나긴 했지만 기호에 초점을 두었다,

---

# 풀이 과정

- 변수 및 라이브러리 사용 이유
- 조건부 해석 이유

```cpp

#include <bits/stdc++.h>
using namespace std;

/*
 * https://www.acmicpc.net/problem/1541
 * Lost parentheses
 */

string s, num;
int answer = 0;
bool isMinus = false;

void input () {
    cin >> s;
}

void solution() {
    for (int i = 0; i <= s.size(); i++) {
        if (s[i] == '-' || s[i] == '+' || i==s.size()) {
            if (isMinus) {
                answer -= stoi(num);
                num = "";
            }
            else {
                answer += stoi(num);
                num = "";
            }
        }
        else {
            num += s[i];
        }

        if (s[i] == '-') {
            isMinus = true;
        }
    }

    cout << answer;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    input();
    solution();
}

```

---

# 결과 & 근거

- 문자열 파싱이 좀 귀찮았?지만 리팩토링을 하고 나니 성공했던 분들의 로직과 동일하였다.
- 인덱스 적인 생각을 잘하자…

### 알고리즘 분류

- 수학
- 그리디 알고리즘
- 문자열
- 파싱