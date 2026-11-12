# SWEA 4839, 이진탐색 (성공)

# 문제 소개

[문제 사이트 하이퍼링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=2&problemLevel=3&contestProbId=AWTLcyA6qAMDFAVT&categoryId=AWTLcyA6qAMDFAVT&categoryType=CODE&problemTitle=&orderBy=INQUERY_COUNT&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=7)

코딩반 학생들에게 이진 탐색을 설명하던 선생님은 이진탐색을 연습할 수 있는 게임을 시켜 보기로 했다.짝을 이룬 A, B 두 사람에게 교과서에서 각자 찾을 쪽 번호를 알려주면, 이진 탐색만으로 지정된 페이지를 먼저 펼치는 사람이 이기는 게임이다.예를 들어 책이 총 400쪽이면, 검색 구간의 왼쪽 l=1, 오른쪽 r=400이 되고, 중간 페이지 c= int((l+r)/2)로 계산한다.찾는 쪽 번호가 c와 같아지면 탐색을 끝낸다.A는 300, B는 50 쪽을 찾아야 하는 경우, 다음처럼 중간 페이지를 기준으로 왼쪽 또는 오른 쪽 영역의 중간 페이지를 다시 찾아가면 된다.

|  | A | B |
| --- | --- | --- |
| 첫 번째 탐색 | l=1, r=400, c=200 | l=1, r=400, c=200 |
| 두 번째 탐색 | l=200, r=400, c=300 | l=1, r=200, c=100 |
| 세 번째 탐색 |  | l=1, r=100, c=50 |

책의 전체 쪽수와 두 사람이 찾을 쪽 번호가 주어졌을 때, 이진 탐색 게임에서 이긴 사람이 누구인지 알아내 출력하시오. 비긴 경우는 0을 출력한다.

**[입력]**

첫 줄에 테스트 케이스 개수 T가 주어진다.  1<=T<=50

테스트 케이스 별로 책의 전체 쪽 수 P, A, B가 찾을 쪽 번호 Pa, Pb가 차례로 주어진다. 1<= P, Pa, Pb <=1000

**[출력]**

각 줄마다 "#T" (T는 테스트 케이스 번호)를 출력한 뒤, A, B, 0 중 하나를 출력한다.

```cpp
입력

3
400 300 350
1000 299 578
1000 222 888

출력 
#1 A
#2 0
#3 A
```

---

# 풀이 과정

- 이진탐색이 헷갈렸는데 지문에 중간 페이지 공식 c = int((l+r)/2)가 주어져서 그대로 활용했다.
- A, B 각자 탐색 구간을 따로 두고 한 바퀴씩 동시에 진행하면서, 둘 다 찾으면 0, 한 명만 찾으면 그 사람이 이긴다고 판단했다.
- 파이썬 전용 문제라 C++로 풀고 가채점했다 (12분).

```cpp
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case) {
        int book, a_page, b_page;
        cin >> book >> a_page >> b_page;

        // A와 B가 각자 따로 탐색 구간 [l, r]을 가진다. 처음엔 둘 다 [1, 전체 쪽수]
        int a_l = 1, b_l = 1, a_r = book, b_r = book;

        // 한 바퀴 = 두 사람이 동시에 한 번씩 펼치는 것
        while (true) {
            int a_half = (a_l + a_r) / 2;   // 지문 공식 c = int((l+r)/2)
            int b_half = (b_l + b_r) / 2;

            // 같은 바퀴에 둘 다 찾으면 무승부 → 이 검사를 반드시 먼저
            if (a_half == a_page && b_half == b_page) {
                cout << "#" << test_case << " 0" << '\n';
                break;
            }
            if (a_half == a_page) {
                cout << "#" << test_case << " A" << '\n';
                break;
            }
            if (b_half == b_page) {
                cout << "#" << test_case << " B" << '\n';
                break;
            }

            // 지문 예시대로 l = c / r = c (c+1, c-1이 아님!)
            if (a_half < a_page) a_l = a_half;
            else a_r = a_half;

            if (b_half < b_page) b_l = b_half;
            else b_r = b_half;
        }
    }
    return 0; //정상종료시 반드시 0을 리턴해야합니다.
}

```

---

# 결과 & 근거

**가채점 통과 (12분). 판정은 정확하고, 출력 형식만 수정 필요**

- 지문 예시대로 `l = c`, `r = c`로 구간을 줄여야 한다 (`c±1`이 아님). 그래서 지문 공식을 그대로 쓴 게 정답이었다.
- 답마다 `"\n\n" << endl`로 빈 줄이 2개씩 더 출력돼서, 줄바꿈 하나로 고쳐야 한다.

> 
> 
> 
> ***한 줄 요약***
> 
> **이진탐색 시뮬레이션 문제.** 
> 
> 두 사람의 탐색 구간을 따로 두고 지문 공식 c=(l+r)/2로 동시에 좁혀 가며 먼저 찾는 사람을 가린다. 일반 이진탐색(c±1)이 아니라 지문대로 l=c, r=c로 줄이는 게 핵심.
> 

### 알고리즘 분류

- 이진탐색
- 시뮬레이션