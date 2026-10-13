# 프로그래머스, 코딩 테스트 공부 (실패)

# 문제 소개

[문제 사이트 링크](https://school.programmers.co.kr/learn/courses/30/lessons/118668)

#### **문제 설명**

**[본 문제는 정확성과 효율성 테스트 각각 점수가 있는 문제입니다.]**

당신은 코딩 테스트를 준비하기 위해 공부하려고 합니다. 코딩 테스트 문제를 풀기 위해서는 알고리즘에 대한 지식과 코드를 구현하는 능력이 필요합니다.

알고리즘에 대한 지식은 `알고력`, 코드를 구현하는 능력은 `코딩력`이라고 표현합니다. `알고력`과 `코딩력`은 0 이상의 정수로 표현됩니다.

문제를 풀기 위해서는 문제가 요구하는 일정 이상의 `알고력`과 `코딩력`이 필요합니다.

예를 들어, 당신의 현재 `알고력`이 15, `코딩력`이 10이라고 가정해보겠습니다.

- A라는 문제가 `알고력` 10, `코딩력` 10을 요구한다면 A 문제를 풀 수 있습니다.
- B라는 문제가 `알고력` 10, `코딩력` 20을 요구한다면 `코딩력`이 부족하기 때문에 B 문제를 풀 수 없습니다.

풀 수 없는 문제를 해결하기 위해서는 `알고력`과 `코딩력`을 높여야 합니다. `알고력`과 `코딩력`을 높이기 위한 다음과 같은 방법들이 있습니다.

- `알고력`을 높이기 위해 알고리즘 공부를 합니다. `알고력` 1을 높이기 위해서 1의 시간이 필요합니다.
- `코딩력`을 높이기 위해 코딩 공부를 합니다. `코딩력` 1을 높이기 위해서 1의 시간이 필요합니다.
- 현재 풀 수 있는 문제 중 하나를 풀어 `알고력`과 `코딩력`을 높입니다. 각 문제마다 문제를 풀면 올라가는 알고력과 코딩력이 정해져 있습니다.
- 문제를 하나 푸는 데는 문제가 요구하는 시간이 필요하며 같은 문제를 여러 번 푸는 것이 가능합니다.

당신은 주어진 모든 문제들을 풀 수 있는 `알고력`과 `코딩력`을 얻는 최단시간을 구하려 합니다.

초기의 `알고력`과 `코딩력`을 담은 정수 `alp`와 `cop`, 문제의 정보를 담은 2차원 정수 배열 `problems`가 매개변수로 주어졌을 때, 모든 문제들을 풀 수 있는 `알고력`과 `코딩력`을 얻는 최단시간을 return 하도록 solution 함수를 작성해주세요.

**모든 문제들을 1번 이상씩 풀 필요는 없습니다. `입출력 예 설명`을 참고해주세요.**

---

#### 제한사항

- 초기의 `알고력`을 나타내는 `alp`와 초기의 `코딩력`을 나타내는 `cop`가 입력으로 주어집니다.
    - 0 ≤ `alp`,`cop` ≤ 150
- 1 ≤ `problems`의 길이 ≤ 100
- `problems`의 원소는 [`alp_req`, `cop_req`, `alp_rwd`, `cop_rwd`, `cost`]의 형태로 이루어져 있습니다.
- `alp_req`는 문제를 푸는데 필요한 `알고력`입니다.
    - 0 ≤ `alp_req` ≤ 150
- `cop_req`는 문제를 푸는데 필요한 `코딩력`입니다.
    - 0 ≤ `cop_req` ≤ 150
- `alp_rwd`는 문제를 풀었을 때 증가하는 `알고력`입니다.
    - 0 ≤ `alp_rwd` ≤ 30
- `cop_rwd`는 문제를 풀었을 때 증가하는 `코딩력`입니다.
    - 0 ≤ `cop_rwd` ≤ 30
- `cost`는 문제를 푸는데 드는 시간입니다.
    - 1 ≤ `cost` ≤ 100

**정확성 테스트 케이스 제한사항**

- 0 ≤ `alp`,`cop` ≤ 20
- 1 ≤ `problems`의 길이 ≤ 6
    - 0 ≤ `alp_req`,`cop_req` ≤ 20
    - 0 ≤ `alp_rwd`,`cop_rwd` ≤ 5
    - 1 ≤ `cost` ≤ 10

**효율성 테스트 케이스 제한사항**

- 주어진 조건 외 추가 제한사항 없습니다.

---

#### 입출력 예

| alp | cop | problems | result |
| --- | --- | --- | --- |
| 10 | 10 | [[10,15,2,1,2],[20,20,3,3,4]] | 15 |
| 0 | 0 | [[0,0,2,1,2],[4,5,3,1,2],[4,11,4,0,2],[10,4,0,4,2]] | 13 |

#### 입출력 예 설명

**입출력 예 #1**

1. `코딩력` 5를 늘립니다. `알고력` 10, `코딩력` 15가 되며 시간이 5만큼 소요됩니다.
2. 1번 문제를 5번 풉니다. `알고력` 20, `코딩력` 20이 되며 시간이 10만큼 소요됩니다. 15의 시간을 소요하여 모든 문제를 풀 수 있는 `알고력`과 `코딩력`을 가질 수 있습니다.

**입출력 예 #2**

1. 1번 문제를 2번 풉니다. `알고력` 4, `코딩력` 2가 되며 시간이 4만큼 소요됩니다.
2. `코딩력` 3을 늘립니다. `알고력` 4, `코딩력` 5가 되며 시간이 3만큼 소요됩니다.
3. 2번 문제를 2번 풉니다. `알고력` 10, `코딩력` 7이 되며 시간이 4만큼 소요됩니다.
4. 4번 문제를 1번 풉니다. `알고력` 10, `코딩력` 11이 되며 시간이 2만큼 소요됩니다. 13의 시간을 소요하여 모든 문제를 풀 수 있는 `알고력`과 `코딩력`을 가질 수 있습니다.

**제한시간 안내**

- 정확성 테스트 : 10초
- 효율성 테스트 : 언어별로 작성된 정답 코드의 실행 시간의 적정 배수

---

# 풀이 과정

- 처음엔 "한계 안에서 최선" 구조로 보고 Greedy로 접근했다.
- 풀 수 있는 문제 중 가장 효율이 좋은 것을 고르고, 효율이 역전되는 순간에 직접 능력치를 올리는 방식을 구상했다.
- 그런데 "효율이 좋은 문제"를 정의하지 못해서 45분을 다 썼다. 포기.

```cpp
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 *
* - 제한사항 숫자 베끼기      (n≤100, k≤10 / r2≤10^6 / n,m≤500)
- 내 접근의 연산량 = ?       → 1억/초 기준 통과 여부 O/X
- 상태와 전이를 한 문장으로   "상태 = 감염된 노드 집합, 전이 = 타입 t 선택"
- 예시 1개를 손으로 돌리기   (내 로직이 정답을 뱉는지)
 */

bool cmp (vector <int> &a, vector <int> &b)
{
    if (a[0] == b[0])
    {
        if (a[1] == b[1])
        {
            return a[4] < b[4];
        }
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

// 0 ≤ alp,cop ≤ 150
// problems의 원소는 [alp_req, cop_req, alp_rwd, cop_rwd, cost
int solution(int alp, int cop, vector<vector<int>> problems) {
    // 모든 문제들을 풀 수 있는 알고력과 코딩력을 얻는 최단시간을 return

    // if alp == cop -> can solve A
    // else if alp < cop -> cant solve B
    // 현재 풀 수 있는 문제 중 하나를 풀어 알고력과 코딩력을 높입니다.
    // 각 문제마다 문제를 풀면 올라가는 알고력과 코딩력이 정해져 있습니다.
    // 문제를 하나 푸는 데는 문제가 요구하는 시간이 필요하며 같은 문제를 여러 번 푸는 것이 가능합니다.
    // 모든 문제들을 1번 이상씩 풀 필요는 없습니다
    // 모든 문제들을 풀 수 있는 알고력과 코딩력을 얻는 최단시간을 구하려 합니다.

    /*
     * 모든 문제를 무조건 풀 필요는 없다.
     * - 고르는 건 효율적으로 골라서 증가를 잘 해야 한다.
     *
     * Problems.size()는 최대 100을 넘지 않는다.
     * - 모든 문제를 풀 수 있는 최단 시간을 구하려면 알고력/코딩력 증가가 효율적이어야 한다
     * - 완전 탐색 알고리즘을 사용해보자.
     * - 대신 probelms를 alp_req, cop_req 기준 오름 차순 정렬 후 ?
     */

    sort(problems.begin(), problems.end(), cmp);
    for (int i = 0; i < problems.size(); i++)
    {
        vector<int> p = problems[i];
        cout << p[0] << " " << p[1] << " " << p[2] << " " << p[3] << " " << p[4] << endl;
    }

    int solved[101];
    int answer = 0; // 이걸 total_cost로 사용하자.

    while (true)
    {
        break;
        bool check = false; // 못푸는 경우가 생기는 경우 1
        int can_solve = 0;
        int pre_alp_rwd = 0, pre_cop_rwd = 0, pre_cost=0;

        // 존재하는 문제 중에서 가장 스킬업 효율이 뛰어난 문제를 풀기 or 하나만 스킬업

        for (int i = 0; i < problems.size(); i++) { // 풀 수 있는 문제 탐색
            vector<int> p = problems[i];
            int alp_req = p[0], cop_req = p[1], alp_rwd = p[2], cop_rwd = p[3], cost = p[4];

            if (alp >= alp_req && cop >= cop_req) { // 풀 수 있는 문제 중 가장 효율적인 거 판별
                if (alp_rwd > pre_alp_rwd && cop_rwd > pre_cop_rwd) {
                    can_solve = i;
                }
                else if (alp_rwd == pre_alp_rwd && cop_rwd == pre_cop_rwd && cost < pre_cost ) {
                    can_solve = i;
                }

            }
            else {
                check = true; // 못 푼 경우
            }
        }
        if (!check)
        {
            break;
        }

        cout << "가장 스킬업 잘 되는 문제: " << can_solve << " - " << problems[can_solve][0] << "." << problems[can_solve][1] << endl;

        if (problems[can_solve][0] - alp + problems[can_solve][1] - cop ) {

        }

        // 풀어서 스킬 업
        alp += problems[can_solve][0],
        cop += problems[can_solve][1],
        answer += problems[can_solve][4]; // cost
    }

    return answer;
}
```

---

# 결과 & 근거

- 실패 (45분 포기, 무한루프로 시간 초과)
- 접근 오류: Greedy로 가정했으나 보상이 2차원 벡터라 비교 함수 자체가 정의되지 않는다.
- 제한사항(alp, cop ≤ 150)을 상태 공간 크기로 환산하지 않아 격자 DP 신호를 놓쳤다.

```cpp
#include <bits/stdc++.h>
using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {

    // ── 1. 목표 지점 구하기 ─────────────────────────────────────
    // "모든 문제를 풀 수 있는" 상태 = 모든 요구치의 최댓값을 넘긴 상태
    int max_alp = 0, max_cop = 0;
    for (vector<int>& p : problems) {
        max_alp = max(max_alp, p[0]);   // p[0] = alp_req
        max_cop = max(max_cop, p[1]);   // p[1] = cop_req
    }

    // ── 2. 출발 지점 클램핑 ─────────────────────────────────────
    // 목표보다 이미 높은 능력치는 아무 쓸모가 없다 (더 올려도 이득 0).
    // 잘라내지 않으면 dp 배열 범위를 벗어나고 상태 수도 쓸데없이 늘어난다.
    alp = min(alp, max_alp);
    cop = min(cop, max_cop);

    // ── 3. dp 테이블 ───────────────────────────────────────────
    // dp[a][c] = 알고력 a, 코딩력 c 에 도달하는 데 드는 "최소 시간"
    const int INF = 1e9;
    vector<vector<int>> dp(max_alp + 1, vector<int>(max_cop + 1, INF));
    dp[alp][cop] = 0;   // 출발점은 0시간

    // ── 4. 상태를 오름차순으로 훑으며 전이 ───────────────────────
    // 모든 전이가 a, c 를 "감소시키지 않는다"(보상 >= 0).
    // 그래서 작은 상태부터 채우면 나중 상태가 갱신될 일이 없다 → 단방향 DP 성립.
    for (int a = alp; a <= max_alp; a++) {
        for (int c = cop; c <= max_cop; c++) {

            if (dp[a][c] == INF) continue;   // 아직 도달 못한 상태면 출발점이 될 수 없다

            // 전이 ①: 알고력만 1 올린다 (1시간). 목표를 넘지 않을 때만.
            if (a + 1 <= max_alp)
                dp[a + 1][c] = min(dp[a + 1][c], dp[a][c] + 1);

            // 전이 ②: 코딩력만 1 올린다 (1시간)
            if (c + 1 <= max_cop)
                dp[a][c + 1] = min(dp[a][c + 1], dp[a][c] + 1);

            // 전이 ③: 지금 풀 수 있는 문제를 푼다
            for (vector<int>& p : problems) {
                int alp_req = p[0], cop_req = p[1];
                int alp_rwd = p[2], cop_rwd = p[3], cost = p[4];

                if (a < alp_req || c < cop_req) continue;   // 요구치 미달이면 못 푼다

                // 보상을 받되 목표를 넘으면 목표에서 자른다 ← 클램핑. 이게 없으면 범위 초과
                int na = min(a + alp_rwd, max_alp);
                int nc = min(c + cop_rwd, max_cop);

                dp[na][nc] = min(dp[na][nc], dp[a][c] + cost);
            }
        }
    }

    // ── 5. 목표 상태의 최소 시간 ────────────────────────────────
    return dp[max_alp][max_cop];
}
```

### 알고리즘 분류

- DP (격자 DP)
- 최단경로 (전이 비용 최소화 — 능력치 감소가 없어 다익스트라 불필요)
- 그래프 탐색
- 완전탐색 + 메모이제이션