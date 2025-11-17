# 5107 마니또 (실패)

# 문제 소개

[문제 사이트 링크](https://www.acmicpc.net/problem/5107)

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞힌 사람 | 정답 비율 |
| --- | --- | --- | --- | --- | --- |
| 1 초 | 128 MB | 1491 | 822 | 667 | 56.863% |

## 문제

N명의 사람들이 있다. 이들은 각자 다른 한 명의 이름이 적힌 쪽지를 받아서, 그 사람에게 몰래 선행을 베푼다. 이때 자기 자신의 이름을 받을 수는 없으며, 선행을 받은 사람은 누가 자신을 도와줬는지도 알 수 없다.

그런데 이런 마니또 활동을 하던 중 할 짓이 지지리도 없던 세종이는 여기서 "마니또 체인"이라는 개념을 발견했다! 세종이가 동우에게 선행을 베풀고, 동우가 재혁이에게 선행을 베풀고, 재혁이가 호용이에게 선행을 베풀고... 이렇게 하다 보면 언젠가 누군가는 처음 선행을 베푼 세종이에게 선행을 베풀게 되리라는 것이다. 이렇게 선행을 베푸는 연결 고리가 반드시 생긴다! 이 고리는 그냥 2명일 수도 있고, 아예 N명 모두가 포함될 수도 있다.

우리가 할 일은 N명의 사람들 사이에서 이러한 연결 고리가 몇 개나 발생하는지를 알아내는 것이다. 문제는 여러 개로 이루어져 있다.

## 입력

각 테스트 케이스의 첫 번째 줄에는 사람의 명수 N이 주어진다(3 <= N <=20). 만약 N = 0이면 입력의 끝을 의미하며 더 이상의 입력은 없다.

각 테스트 케이스의 두 번째 줄부터 N개의 줄에 거쳐 두 사람의 이름이 주어진다. 각 줄에 누가 누구에게 선행을 베푸는지가 주어진다. 첫 번째 이름과 두 번째 이름은 각각 해당 케이스 전체에 걸쳐 중복되지 않으며, 한 줄에 같은 이름이 두 번 등장하지 않는다. 이름의 길이는 10자를 넘지 않는다.

## 출력

각 테스트 케이스마다, 한 줄에 해당 케이스의 번호(1부터 시작)와 연결 고리의 개수를 공백을 두고 출력한다.

## 예제 입력

```
5
Andrew Sally
Chen Andrew
Ahmed Tess
Sally Chen
Tess Ahmed
0

```

## 예제 출력 1

```
1 2
```

---

# 초기 접근 방법

- 입력이 문자열로 주어지므로, Map 을 사용해야겠다는 생각이 들었다.
    - Map <string, string>
- 크게 알고리즘이 생각나지 않기도 했고, 입력 수가 적어서 되게 간단하게 생각해보았다.
    - 입력 받을 때 해당 쌍을 Vector 변수와 Map 변수에 저장한다.
    - 그리고 vector 변수에서 하나씩 꺼내서 map의 키와 값에 계속 순회해서 맞혀본다.
        - 만약 조회했는데 null 인 경우는 고리가 이어지지 않은 경우다.
        - 만약 조회했는데 처음이 나온다면 고리가 생성된 것이다.
    - 이후 해당 값들을 map에서 지워 중복을 막는다.

---

# 풀이 과정

```cpp

#include <bits/stdc++.h>
using namespace std;

int n;
map<string, string> manito;
vector<pair<string, string>> manitoList;

void input() {
    cin >> n;
    manitoList = vector<pair<string, string>>(n);

    string a, b;
    for (int i = 0; i<n; i++) {
        cin >> manitoList[i].first >> manitoList[i].second;
        manito[manitoList[i].first] = manitoList[i].second;
    }
    int ab;
    cin >> ab;
}

void solution() {
    int cnt= 0;

    for (int i = 0; i<n; i++) {

        string fst  = manitoList[i].first;

        // cout << "fst: " << fst << '\n';
        string s = manitoList[i].second;
        vector<string> cmpList;
        cmpList.push_back(fst);
        while(true) {
            s = manito[s];
            // cout << "비교: " << s << '\n';
            if (s.empty()) {
                break;
            }
            if (fst.compare(s) == 0) {
                // cout << "같습니다: " << fst << ", " << s << '\n'; // 이러면 map 비우는 거 처리를 어떻게?

                cout << ++cnt << " ";

                for (string s2 : cmpList) { // null 처리로 스킵하게
                    manito[s2] = "";
                }

                // cnt ++;
                break;
            }
            cmpList.push_back(s);
        }
    }
    cout <<'\n';
    // cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    input();
    solution();
}

```

---

# 결과 & 근거

- 결과는 야무지게 틀렸다.
    - map 보다는 HashMap을  통한 접근이 더 올바르다 생각된다. → https://sookr5416.tistory.com/298, https://yujinkimkim.tistory.com/70
    - 이후 연결 관계를 통해 그래프를 구성해서, 그래프 탐색을 실시하면 된다. → https://devteo77.tistory.com/64
- 그리고 문제의 출력이 나만 이해하기 어려웠나…? 설명이 어려웠던 것 같다.

### 알고리즘 분류

- 자료 구조
- 그래프 이론, 그래프 탐색
- 집합과 맵, 해시를 사용한 집합과 맵
- 순열 사이클 분할