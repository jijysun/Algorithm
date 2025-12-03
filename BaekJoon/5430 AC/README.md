# 문제 소개

[문제 사이트 링크](https://www.acmicpc.net/problem/5430)

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞힌 사람 | 정답 비율 |
| --- | --- | --- | --- | --- | --- |
| 1 초 | 256 MB | 187580 | 44805 | 31667 | 21.264% |

## 문제

선영이는 주말에 할 일이 없어서 새로운 언어 AC를 만들었다. AC는 정수 배열에 연산을 하기 위해 만든 언어이다. 이 언어에는 두 가지 함수 R(뒤집기)과 D(버리기)가 있다.

함수 R은 배열에 있는 수의 순서를 뒤집는 함수이고, D는 첫 번째 수를 버리는 함수이다. 배열이 비어있는데 D를 사용한 경우에는 에러가 발생한다.

함수는 조합해서 한 번에 사용할 수 있다. 예를 들어, "AB"는 A를 수행한 다음에 바로 이어서 B를 수행하는 함수이다. 예를 들어, "RDD"는 배열을 뒤집은 다음 처음 두 수를 버리는 함수이다.

배열의 초기값과 수행할 함수가 주어졌을 때, 최종 결과를 구하는 프로그램을 작성하시오.

## 입력

첫째 줄에 테스트 케이스의 개수 T가 주어진다. T는 최대 100이다.

각 테스트 케이스의 첫째 줄에는 수행할 함수 p가 주어진다. p의 길이는 1보다 크거나 같고, 100,000보다 작거나 같다.

다음 줄에는 배열에 들어있는 수의 개수 n이 주어진다. (0 ≤ n ≤ 100,000)

다음 줄에는 [x1,...,xn]과 같은 형태로 배열에 들어있는 정수가 주어진다. (1 ≤ xi ≤ 100)

전체 테스트 케이스에 주어지는 p의 길이의 합과 n의 합은 70만을 넘지 않는다.

## 출력

각 테스트 케이스에 대해서, 입력으로 주어진 정수 배열에 함수를 수행한 결과를 출력한다. 만약, 에러가 발생한 경우에는 error를 출력한다.

## 예제 입력 1

```
4
RDD
4
[1,2,3,4]
DD
1
[42]
RRD
6
[1,1,2,3,5,8]
D
0
[]

```

## 예제 출력 1

```
[2,1]
error
[1,2,3,5,8]
error

```

---

# 초기 접근 방법

- 이것도 그냥 문자열에서 파싱해서 쓰는 느낌?

---

# 풀이 과정

- 변수 및 라이브러리 사용 이유
- 조건부 해석 이유

```cpp

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct AC {
    string order;
    int size{};
    vector<int>list;
    string s;
};

void stringToInt (AC &ac, const string &s) {
    string sum;

    if (ac.size == 0) {
        return;
    }
    for (int i = 1; i<s.size(); i++) {
        if (isalnum(s[i])) {
            sum+=s[i];
        }
        else if (s[i] == ',' || s[i] == ']') {
            ac.list.push_back(stoi(sum));
            sum.clear();
        }
    }
}

void orderList(AC &ac) {
    int change = 0;
    for (int i = 0; i<ac.order.size(); i++) {
        if (ac.size == 0) {
            cout <<"error" <<"\n";
            return;
        }
        if (ac.order[i] == 'R') { // 한 번 만!
            change = (++change)%2;
        }
        else if (ac.order[i] == 'D' && !ac.list.empty() ) { // delete
            if (change == 1) {
                ac.list.pop_back();
            }
            else {
                ac.list.erase(ac.list.begin());
            }
            ac.size--;
        }
    }
    if (change) {
        reverse(ac.list.begin(), ac.list.begin()+ac.size);
    }
    if (ac.size) {
        cout << "[";
        for (int i = 0; i<ac.size; i++) {
            cout << ac.list[i];
            if (i != ac.size-1) {
                cout <<",";
            }
        }cout <<"]\n";
    }
}

int main() {

    int t;
    cin >> t;
    AC ac [t];

    for (int i = 0; i< t; i++) {
        string s;
        cin >>ac[i].order >> ac[i].size >> s;
        stringToInt(ac[i],s);
        orderList(ac[i]);
    }
    return 0;
}
```

---

# 결과 & 근거

- 뭔가 테스트 케이스 만들어 보는 거는 다 넣고, 성공하는데 다 실패한다… 어디서 틀렸는 지 모르겠다,…..,.,

https://ohsol.tistory.com/entry/%EB%B0%B1%EC%A4%80-5430%EB%B2%88-AC-C-%ED%92%80%EC%9D%B4

- 이분은 덱을 사용

### 알고리즘 분류

- 구현
- 자료 구조
- 문자열
- 파싱
- 덱