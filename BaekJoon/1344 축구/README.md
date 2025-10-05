# 1344 축구 (실패)

# 문제 소개

[문제 사이트 링크](https://www.acmicpc.net/problem/1344)

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞힌 사람 | 정답 비율 |
| --- | --- | --- | --- | --- | --- |
| 2 초 | 128 MB | 3185 | 2050 | 1561 | 66.116% |

## 문제

홍준이는 축구 경기를 보고 있다. 그러다가 홍준이는 역시 두 팀 중 적어도 한 팀이 골을 소수로 득점할 확률이 궁금해 졌다. 축구 경기는 90분동안 이루어지고, 분석을 쉽게하기 위해서 경기를 5분 간격으로 나눴다. 처음 간격은 처음 5분이고, 두 번째 간격은 그 다음 5분, 그리고 이런식으로 나눈다. 경기가 진행되는 동안 각 간격에서 A팀이 득점할 확률과 B팀이 득점할 확률이 주어진다. 그리고, 각 간격에서 두 팀은 각각 많아야 한 골을 득점할 수 있다. 경기가 끝난 후 적어도 한 팀이 골을 소수로 득점할 확률을 구하시오.

## 입력

첫째 줄에 A팀이 득점할 확률, 둘째 줄에 B팀이 득점할 확률이 퍼센트 단위로 주어진다. 퍼센트 단위로 주어지는 확률은 모두 0보다 크거나 같고 100보다 작거나 같은 정수이다.

## 출력

첫째 줄에 적어도 한 팀이 골을 소수로 득점할 확률을 출력한다. 정답과의 절대/상대 오차가 10^-6이내인 경우에 정답이다.

---

# 초기 접근 방법

- 각 소수 득점에 대해 각 확률을 구하고, 마지막 총 확률에 종합하면 된다.
- 그렇기에 계속해서 더해나가는 DP 방식이 되겠다.

---

# 풀이 과정

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
 * https://www.acmicpc.net/problem/1344
 * soccer
 */

// double a, b;

int a, b;

double d_a, d_b;

int a_dp[17], b_dp[17];

vector<int> sosu = {2, 3, 5, 7, 11, 13, 17};

void input() {
    cin >> a >> b;
}

double combi (int n, int r) {
    if (r<0 || r>n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n/2) r = n-r;

    double res = 1;
    for (int i = 1; i<=r; ++i) {
        res *= (n-i+1)/i;
    }
    return res;
}

void solution() {

    d_a = a/100.0, d_b = b/100.0;
    double probability, p_a=0, p_b=0;

    for (int i : sosu) { // 조합론 써야 하는데 그거 헷갈려서 시간 다 써먹었어요...
        double combination = combi(18, i);

        p_a += combination * pow (d_a, i) * pow (1.0-d_a, 18-i);
        p_b += combination * pow (d_b, i) * pow (1.0-d_b, 18-i);

        /*double a_per=0;
        double s1=1, s2=1, s3=0;
        for (int j = 0; j < i; j++ ) {
            s1*=(16-j);
        }
        for (int j = 1;  j<=i; j++) {
            s2*=j;
            s3++;
        }

        a_per+= s1/s2/(double)100;

        // cout << s1 << s2 << '\n';
        cout << s1/s2/(double)100*pow((double)a/100, s3) << '\n';*/
    }

    cout << p_a+p_b - p_a*p_b << '\n';

}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    input();
    solution();
}
```

---

# 결과 & 근거

- 실패,,,
    - 해답은 “각 소수에 대한 확률의 총합이다” 라는 건 정확히 파악했다.
    - 그러나 확률 구하는 거 에서 헤매다가 구현에 실패했다.
- https://88-it.tistory.com/311
- 조합과 확률에 항상 헤매는 듯 하다…
    - https://thebasics.tistory.com/334

### 알고리즘 분류

- 수학
- 다이나믹 프로그래밍
- 조합론
- 확률론