# SWEA 20728, 공평한 분배 2 (실패)

# 문제 소개

[문제 사이트 하이퍼링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AY6cg0MKeVkDFAXt&categoryId=AY6cg0MKeVkDFAXt&categoryType=CODE&problemTitle=%EA%B3%B5%ED%8F%89%ED%95%9C+%EB%B6%84%EB%B0%B0&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=&pageSize=10&pageIndex=1)

사탕이 담긴 N개의 주머니가 있다. 이 중 i (1≤i≤N) 번째 주머니에는 사탕이 ai개 들어 있다. 당신은 이 주머니 중 정확히 K개를 선택하여 어린이들에게 나누어 주려고 한다.공정성을 위해, 당신은 나눠 준 주머니 가운데 사탕의 개수가 가장 많은 것과 가장 적은 것의 사탕 개수 차이를 최소화하려고 한다.모든 유효한 방법 중 차이의 최솟값을 구하는 프로그램을 작성하라.

**입력**

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스는 두 개의 줄로 이루어진다. 첫 번째 줄에는 주머니의 개수 N (2≤N≤50)과 나눠 줄 주머니의 개수 K (2≤K≤N)이 공백 하나를 사이로 두고 주어진다.두 번째 줄에는 주머니 속 사탕의 개수를 나타내는 N개의 정수 a1,a2, ⋯ ,aN(1≤ai≤109)이 공백 하나씩을 사이로 두고 주어진다.

**출력**

각 테스트 케이스마다, 차이의 최솟값을 출력한다.

```cpp
입력
3
3 2
1 2 3
3 3
5 20 10
4 3
4 3 2 1

출력
#1 1 
#2 15
#3 2
```

---

# 풀이 과정

- 처음엔 조합으로 K개를 전부 골라봤는데 12/116에서 TLE가 났다.
- 정렬한 뒤 연속한 K개의 (최대 − 최소)만 보는 방식으로 바꿔서 58/116까지 올렸다.
- N == K면 전부 나눠줘야 하니까 따로 처리했다.
- 차이가 0인 경우는 없는데 뭔가 빠트린 것 같아서 고민하다가 31분에 포기했다.

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
/*
 * 사탕이 담긴 N개의 주머니
 * - 각 주머니 당 사탕이 다름
 * - 이 주머니 중 K개를 선택해서 나눠주기
 * - 고정성을 위해 사탕의 개수가 가장 많은 것과 가장 적은 것의 사탕 개수 차이를 최소화
 * - 모든 유효한 방법 중 차이의 최솟값을 구하는 프로그램을 작성
 *
 *
 */

int main(int argc, char** argv) {
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case) {
        int bag, give_bag;
        cin >> bag >> give_bag;
        int min_diff = INT_MAX;
        vector<int> bag_vec;
        for (int i = 0; i < bag; i++) {
            int t;
            cin >> t;
            bag_vec.push_back(t);
        }

        sort(bag_vec.begin(), bag_vec.end());
        if (bag == give_bag) {
            // 전부 나눠주어야 함
            cout << "#" << test_case << " " << bag_vec[bag - 1] - bag_vec[0] << endl;
        }
        else {

            for (int i = 0; i < bag-give_bag; i++) {
                int diff = bag_vec[i+give_bag-1]-bag_vec[i];
                if (diff <= min_diff) {
                    min_diff = diff;
                }
            }

            cout << "#" << test_case << " " << min_diff << endl;
        }
    }

    /*
     * 18분 완료 -> 12/116 + TLE
     * 20분 정렬 추가 + 조합 삭제 -> 58/116
     *
     * 0인 경우는 존재하지 않아. 뭔가 빠트린 게 있어. 31분 포기
     * - 대신 최대한 많은 사탕을 나누어주어야 한다는 조건은 없어.
     *
     */
    return 0; //정상종료시 반드시 0을 리턴해야합니다.
}

```

---

# 결과 & 근거

**실패 (31분, 58/116)**

- 정렬 + 연속 K개 창은 맞는 풀이였는데, 창의 시작점이 0 ~ N−K까지 N−K+1개인 걸 `i < N-K`로 하나 빼먹어서 마지막 창을 안 봤다.
- `N == K` 특수 분기는 같은 버그 때문에 생긴 증상을 덮은 것이었다. 범위를 `i + K - 1 < N`으로 고치면 분기가 필요 없다.

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(int argc, char** argv) {
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case) {
        int bag, give_bag;
        cin >> bag >> give_bag;
        int min_diff = INT_MAX;
        vector<int> bag_vec;
        for (int i = 0; i < bag; i++) {
            int t;
            cin >> t;
            bag_vec.push_back(t);
        }

        // 정렬하면, K개를 골랐을 때 (최대 - 최소)가 가장 작은 선택은 항상 "연속한 K개"다.
        // (중간을 건너뛰면 범위만 넓어지고 이득이 없으니까)
        sort(bag_vec.begin(), bag_vec.end());

        // 창 [i, i+K-1]의 끝이 배열 안에 있는 동안 반복 → 시작점 0 ~ N-K, 총 N-K+1개
        // (N == K면 창이 딱 1개 → 특수 분기 없이 자동 처리)
        for (int i = 0; i + give_bag - 1 < bag; i++) {
            int diff = bag_vec[i + give_bag - 1] - bag_vec[i];   // 창의 최대 - 최소
            min_diff = min(min_diff, diff);
        }

        // a_i ≤ 10^9 → 차이도 10^9 이하라 int로 충분
        cout << "#" << test_case << " " << min_diff << '\n';
    }
    return 0; //정상종료시 반드시 0을 리턴해야합니다.
}
```

> 
> 
> 
> ***한 줄 요약***
> 
> **정렬 + 고정 크기 슬라이딩 윈도우 문제.** 
> 
> 정렬하면 최적의 K개는 항상 연속 구간이라서, 길이 K 창을 N−K+1개 모두 보며 (끝 − 시작)의 최솟값을 구한다. 창 개수를 하나도 빠짐없이 세는 반복 범위가 핵심.
> 

### 알고리즘 분류

- 정렬
- 슬라이딩 윈도우