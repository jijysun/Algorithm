# 문제 소개

문제 사이트 링크

#### **문제 설명**

x축과 y축으로 이루어진 2차원 직교 좌표계에 중심이 원점인 서로 다른 크기의 원이 두 개 주어집니다. 반지름을 나타내는 두 정수 `r1`, `r2`가 매개변수로 주어질 때, 두 원 사이의 공간에 x좌표와 y좌표가 모두 정수인 점의 개수를 return하도록 solution 함수를 완성해주세요.

※ 각 원 위의 점도 포함하여 셉니다.

---

#### 제한 사항

- 1 ≤ `r1` < `r2` ≤ 1,000,000

---

#### 입출력 예

| r1 | r2 | result |
| --- | --- | --- |
| 2 | 3 | 20 |

---

#### 입출력 예 설명

!입출력 예 설명.png

그림과 같이 정수 쌍으로 이루어진 점은 총 20개 입니다.

---

# 풀이 과정

- 단순 구현으로 봤다. 사분면별로 좌표를 전부 훑으며 두 원 사이인지 판정하고 세려 했다.
- 결과적으로 두 군데가 근본적으로 틀렸다.

```cpp
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;

    // 서로 다른 원이 주어져요. 반지름인 r1, r2이 나타낼 때,
    // 두 원 사이의 공간에 x좌표와 y좌표가 모두 정수인 점의 개수를 return하도록 solution 함수를 완성해주세요.

    // 원 사이에 있는 '정수인' 좌표

    /*
     *
     * 1. 원 테두리에 있는 좌표들 = x 또는 y가 0인 좌표 + 아닌 좌표들도 있나?
     * 2. 원들 사이에 잇는 좌표들
     *
     */
    answer += 8;

    // 사분면 기준으로 생각해볼까
    // 1사분면 기준 바깥 원의 끝점 보다는 안에, 안 원의 끝점 보다는 바깥에.

    // 1사분면, x 축 증가, y축 증가
    for (int i = 1; i<r2; i++) { // x축
        for (int j = 1; j<r2; j++){ // ycnr
            int x = i, y = j;

            if (x < r1 && y < r1)
            {
                continue;
            }
            if (x >= r2 && y >= r2)
            {
                continue;
            }
            cout << x << " " << y << endl;
            answer ++;
        }
    }

    // 2사분면, x 축 감소, y축 증가
    for (int i = 1; i<=r2; i++) {
        for (int j = 1; j<=r2; j++){
            int x = -i, y = j;

            if (x > -r1 && y < r1) {
                continue;
            }
            if (x <= -r2 && y >= r2)
            {
                continue;
            }
            cout << x << " " << y << endl;
            answer ++;
        }
    }

    return answer;
}
```

---

# 결과 & 근거

1. 원 방정식을 쓰지 않았다
    - 내 판정은 `x < r1 && y < r1`, `x >= r2 && y >= r2` 였다.
    - x와 y를 각각 반지름과 비교한 것 = 축에 정렬된 정사각형 판정이고, 원과 무관하다.
    - 원 판정은 `x*x + y*y` 인데 내 코드에는 이 식이 한 번도 등장하지 않는다.
    - 처음엔 "정수 비교가 헷갈려서"라고 생각했지만, 조건을 수식으로 적어보는 단계를 건너뛴 것이었다.
2. 복잡도를 확인하지 않았다
    - `r2 ≤ 1,000,000` 인데 이중 루프 → 10^12 연산, 1억/초 기준 약 3시간.
    - 제한사항 한 줄만 환산했으면 구현 전에 접근을 버렸다.
    - 사분면 대칭성도 쓰지 않고 사분면을 하나씩 따로 세려 했다.

```cpp
#include <bits/stdc++.h>
using namespace std;

// v의 정수 제곱근 = floor(√v) 를 오차 없이 구한다.
// sqrt는 double 기반이라 10^12 규모에서 √16 이 3.9999... 로 나올 수 있고,
// 그러면 floor가 3을 뱉어 답이 틀어진다. 그래서 ±1 보정이 필수다.
long long isqrt(long long v) {
    long long r = (long long)sqrtl((long double)v);  // 일단 근사값을 얻는다
    while (r > 0 && r * r > v) r--;                  // 너무 크면 깎는다
    while ((r + 1) * (r + 1) <= v) r++;              // 너무 작으면 올린다
    return r;                                        // r² ≤ v < (r+1)² 보장
}

long long solution(int r1, int r2) {
    long long answer = 0;
    long long R1 = r1, R2 = r2;   // ★ r2² = 10^12. int로 두면 즉시 오버플로

    // 1사분면만 센다: x ≥ 1 (x축 제외), y ≥ 0 (y=0 포함).
    // 이 기준이면 90°씩 4번 돌린 점들이 항상 서로 달라서 ×4 에 중복이 없다.
    for (long long x = 1; x <= R2; x++) {

        // 위쪽 경계: 큰 원 안쪽이어야 한다  x² + y² ≤ R2²  →  y ≤ √(R2² − x²)
        long long ymax = isqrt(R2 * R2 - x * x);

        // 아래쪽 경계: 작은 원 바깥(또는 위)이어야 한다  x² + y² ≥ R1²  →  y ≥ √(R1² − x²)
        long long ymin;
        if (x >= R1) {
            ymin = 0;                        // x만으로 이미 작은 원을 벗어났다 → y 제약 없음
        } else {
            long long v = R1 * R1 - x * x;   // y² 가 최소 이 값은 되어야 한다
            ymin = isqrt(v);                 // 우선 floor
            if (ymin * ymin < v) ymin++;     // 모자라면 1 올린다 (= ceil)
        }

        answer += ymax - ymin + 1;   // 세지 않고 뺄셈으로 구한다 ← 내부 루프가 사라진 자리
    }

    return answer * 4;   // 4사분면 대칭
}
```

### 알고리즘 분류

- 수학, 기하 (원의 방정식)
- 구현
- 대칭성 활용
- 정수 제곱근 / 부동소수점 오차 처리