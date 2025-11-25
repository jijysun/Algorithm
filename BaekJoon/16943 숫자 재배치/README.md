# 16943 숫자 재배치

# 문제 소개

[문제 사이트 링크](https://www.acmicpc.net/problem/16943)

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞힌 사람 | 정답 비율 |
| --- | --- | --- | --- | --- | --- |
| 2 초 | 512 MB | 5942 | 2872 | 2154 | 46.006% |

## 문제

두 정수 A와 B가 있을 때, A에 포함된 숫자의 순서를 섞어서 새로운 수 C를 만들려고 한다. 즉, C는 A의 순열 중 하나가 되어야 한다.

가능한 C 중에서 B보다 작으면서, 가장 큰 값을 구해보자. C는 0으로 시작하면 안 된다.

## 입력

첫째 줄에 두 정수 A와 B가 주어진다.

## 출력

B보다 작은 C중에서 가장 큰 값을 출력한다. 그러한 C가 없는 경우에는 -1을 출력한다.

## 제한

- 1 ≤ A, B < 10^9

## 예제 1

```
1234 3456
-> 3421
```

## 예제 2

```
1000 5
-> -1
```

## 예제 3

```
789 123
-> -1
```

---

# 초기 접근 방법

- 백트래킹
- 모든 경우의 수 조합 = 브루트 포스

---

# 풀이 과정

- 변수 및 라이브러리 사용 이유
- 조건부 해석 이유

```cpp

#include <bits/stdc++.h>
using namespace std;

// https://www.acmicpc.net/problem/16943

// int a, b;

string s1, s2, answer;
vector<int> a, b;
map<int, int> checked;
bool findAnswer = false;

// 문자열 그대로 사용?

void input() {
    cin >> s1 >> s2;

    for (int i = 0; i<s1.size(); i++) {
        a.push_back(s1[i]);
    }
    for (int i = 0; i<s2.size(); i++) {
        b.push_back(s2[i]);
    }
}

// c = ...........
void permutation (int depth, string c) {
    cout << c << '\n';

    if (findAnswer) {
        return;
    }

    if (depth == s1.size()) {
        if (s2 > c) {
            answer = c;
        }
        cout << c << '\n';
        findAnswer = true;
        return;
    }

    for (int i = s1.size()-1; i>=0; i--) {
        int a = s1[i], b = s2[depth];
        if (b < a) {
            continue;
        }

        // cout << "depth, a: " << depth << ", " << s1[i] << '\n';
        if (depth == 0 && s1[i] == '0') {
            // cout << "0! continue!" << '\n';
            continue;;
        }

        if(checked[a] == 0) {
            checked[a] = 1;
            c[depth] = s1[i];
            permutation(depth +1, c);
            checked[a] = 0;
        }
    }

}

bool compare (int a, int b) {
    return a > b;
}

void solution() {
    if (s1.size() > s2.size()) {
        cout << -1 << '\n';
        return;
    }
    if (*min_element(a.begin(), a.end()) >= b.front() ) {
        cout << -1 << '\n';
        return;
    }

    sort(a.begin(), a.end(), compare);
    /*string new_s1="";
    for (int i = 0; i<a.size(); i++) {
        // cout << a[i] <<'\n';
        char c = a[i] + '0';
        new_s1.append(c);
    }*/

    sort(a.begin(), a.end(), compare);
    string new_s1(a.begin(), a.end());
    s1 = new_s1;

    cout << s1 << '\n';

    string s;
    for (int i = 0; i<s1.size(); i++) {
        s.append(".");
    }
    permutation(0, s);

    // 모든 경우의 수 검색해야 함.
    // 약간 DFS 로 내려 가면서?

    // 그 순열 조합을 어떻게 구현하더라...

}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    input();
    solution();

    /*bool answer = "1234" < "5678";
    cout << answer << '\n';*/
}

```

---

# 결과 & 근거

- 분명 저번에 했던 순열 구현하는 방법은 공부했었는데 또 헷갈려서 헤맸다.
- 배열로 할려다가 문자열 그대로 사용한다는 전제로 전환 하면서 또 헤맸다.
    - 자료형 간 옮기는 방법이나, depth 를 아직 잘 모르는 듯 하다.
    - 쉬운 문제였는데..

https://100100e.tistory.com/345

### 알고리즘 분류

- 수학
- 브루트포스 알고리즘
- 백트래