# 문제 소개

문제 사이트 링크

당신의 친구는 두 정수 A,B 를 마음 속으로 생각한 후, A+B 와 A-B 의 값을 불러주었다.

친구가 마음속으로 생각한 두 정수 A,B는 무엇일까?

**[입력]**

첫 번째 줄에 테스트 케이스의 수 TC가 주어진다.

이후 TC개의 테스트 케이스가 새 줄로 구분되어 주어진다.

각 테스트 케이스는 다음과 같이 구성되었다.

- 첫 번째 줄에 두 정수 X,Y 가 주어진다. (-100 ≤ X,Y ≤ 100).
- A + B = X, A - B = Y 이다. 항상 답이 되는 정수 A,B 가 존재함이 보장된다.

**[출력]**

- 각 테스트 케이스 마다 한 줄씩, 문제의 정답을 출력하라.

**입력/출력**

```java
2
2 0
2 -2

->
1 1
0 2

7 2

a+b  = 7
a-b = 2
a = 
```

---

# 풀이 과정

- 정말 자연스럽게도 식이 나열되어 있었다.
- 그래서 연립방정식을 활용하였다
    - 두 식을 더하는 것을 활용하면 A를 구할 수 있고,
    - 두 식을 순서대로 빼면 B를 구할 수 있다.

```cpp
// #include <bits/stdc++.h>

#include <iostream>
#include <vector>
using namespace std;
// https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=1&problemLevel=2&problemLevel=3&problemLevel=4&contestProbId=AZ3XsaWKSB3HBIPV&categoryId=AZ3XsaWKSB3HBIPV&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=4&pageSize=10&pageIndex=1

vector<pair<int, int>> arr;
int tc;

void input() {
    cin >> tc ;

    for (int i = 0; i < tc; i++) {
        int x, y;
        cin >> x >> y;
        arr.push_back({x, y});
    }
}

void solution() {

    for (int i = 0; i < tc; i++) {
        int a = (arr[i].first+arr[i].second)/2;
        int b = (arr[i].first-arr[i].second)/2;

        cout << a << " " << b <<'\n';

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input(), solution();
    return 0;
}
```

---

# 결과 & 근거

- 고민 5분 코드 5분 총 10분 컷을 냈던 것 같다.
    - 사실 알고리즘 문제의 제목에서도 답이 나와있었다.
- 매우매우 쉬운 문제.

### 알고리즘 분류

- 방정식
- 구현