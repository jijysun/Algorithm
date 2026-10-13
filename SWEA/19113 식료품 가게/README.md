# SWEA 19113, 식료품 가게 (실패)

# 문제 소개

[문제 사이트 링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=2&problemLevel=3&contestProbId=AYxCRFA6iiEDFASu&categoryId=AYxCRFA6iiEDFASu&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=4)

식료품 가게의 주인인 철수는 대대적인 할인행사를 계획하고 있습니다. 철수는 25% 할인된 가격으로 상점의 모든 품목을 판매하기로 했습니다. 즉, 각 품목의 판매 가격은 정상 가격의 정확히 75%입니다. 우연하게도 식료품 가게에서 판매하는 모든 물건의 정상가는 4의 배수인 정수이고, 고로 할인된 가격 역시 모두 정수입니다.

철수는 먼저 모든 판매 물품의 할인된 판매가격을 프린터로 출력했고, 또한 할인행사 종료 후 다시 쓸 모든 품목에 정상 가격표 역시 출력했습니다.

잠깐 자리를 비웠던 철수가 다시 가격표의 출력을 확인하기 위해서 프린터로 돌아와 보니, 공교롭게 프린터는 모든 물품의 할인가격과 정상가격을 한꺼번에 오름차순으로 정렬한 뒤 순서대로 출력하여 하나의 출력물 더미를 만들었습니다. 예를 들어, 정상가격이 20, 80, 100인 경우 할인가격은 15, 60, 75이며 프린터의 인쇄 출력 더미는 오름차순으로 정렬된 15, 20, 60, 75, 80, 100 가격표들로 구성됩니다.

철수는 어느 가격표가 할인 가격표인지 구분할 수 없습니다. 이 상황에서 철수는 무엇이 할인가격표인지 구분해낼 수 있을까요?

**[입력]**

첫 번째 줄에 테스트 케이스의 수 TC가 주어진다. 이후 TC개의 테스트 케이스가 새 줄로 구분되어 주어진다. 각 테스트 케이스는 다음과 같이 구성되었다.

첫 번째 줄에는 상점의 품목 수 N이 주어진다. (1 ≤ N ≤ 100)

두 번째 줄에는 프린터에서 인쇄한 2N개의 정수 Pi가 오름차순으로 주어진다. (1 ≤ Pi ≤ 10^9)

**[출력]**

각 테스트 케이스 마다 한 줄씩, 물건의 할인가격에 해당하는 N개의 정수를 오름차순으로 정렬하여 출력하라.

```cpp
2
3
15 20 60 75 80 100
4
90 90 120 120 120 150 160 200
```

```cpp

#1 15 60 75
#2 90 90 120 150
```

---

# 풀이 과정

- 할인가 d 와 정상가 p 는 d = 0.75p,
    - 즉 p = d/3*4 관계다.
- 정렬된 목록을 앞에서부터 보며, p/3*4 가 목록에 남아 있으면 p 를 할인가로 판정하고 그 정상가를 소비하는 방식으로 짰다.
    - 25분 구현,

```cpp
#include <bits/stdc++.h>
#include<iostream>

using namespace std;

map<long, long> price;
vector<long> price_vec, answer;

int main(int argc, char** argv)
{
    int test_case;
    int T = 4;
    cin >> T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    int price_num = 0;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> price_num;
        price_vec.clear(), price.clear(), answer.clear();

        for (long i = 0; i < price_num*2; ++i)
        {
            // 입력
            long p = 0;
            cin >> p;
            price[p]++;
            price_vec.push_back(p);
        }

        for (long p : price_vec) {
            // vector 내 값들은 오름차순이 기본. 그냥 할인 전 가격을 만나면 갯수 할당?
            // cout << p / 3 * 4 << " ";
            if (price[p] == 0) continue;
            if (price[p / 3 * 4] > 0) {
                answer.push_back(p);
                price[p / 3 * 4] --, price[p] --;
            }
        }
        // cout << endl;
        cout << "#" << test_case << " ";
        for (long i : answer) {
            cout << i << " ";
        }
        cout << '\n';

    }

    return 0; //정상종료시 반드시 0을 리턴해야합니다.
}

```

---

# 결과 & 근거

- 실패 (34분 포기, 100개 테스트케이스 중 0개 통과)
- 오버플로를 의심했으나 오진. 모든 중간값이 int 범위 안이다.
- 실제 원인은 할인가 자신을 소비하지 않은 것. 이미 정상가로 쓰인 값이 나중에 할인가 후보로 재검사되어 답에 끼어들고 개수까지 틀어진다.
- 반례 12 12 15 15 16 16 20 20 24 32 에서 정답 5개 대신 6개를 출력했다.

수정

- price[p] - -; 를 붙여주면 끝
- 출력 형식에 주의하자.

### 알고리즘 분류

- 그리디
- 정렬
- 해시 / 맵 카운팅
- 매칭 (쌍 짓기)
- 구현