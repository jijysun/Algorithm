# 문제 소개

[문제 사이트 하이퍼링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=3&contestProbId=AZGSf4TaM08DFAXd&categoryId=AZGSf4TaM08DFAXd&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=3)

피보나치 수열은 f1 = 1, f2 = 1, fi = fi-1 + fi-2 (i >= 3)으로 정의되는 수열이다. 예로 f3 = 2, f4 = 3, f5 = 5, f6 = 8, f7 = 13, … 이다.

1, 2, …, N을 두 개의 집합 A, B로 분할해서, ∑a∈Aƒ­a = ∑­b∈Bƒb를 만족시키는 게 가능한지 확인하고, 가능하다면 분할 방법을 출력하는 프로그램을 작성하라.

**입력**

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스는 하나의 줄로 이루어지며, 정수 N (1<=N<=100) 가 주어진다.

**출력**

각 테스트 케이스마다,

- 만약 피보나치 수들의 합이 같도록 분할하는 것이 불가능하다면, “impossible”을 출력한다.
- 분할이 가능하다면, 길이가 N인 문자열을 출력한다. 이 중 i번째 글자는 i∈A이면 ‘A’, i∈B이면 ‘B’여야 한다.

| 입력 예제 | 출력 예제 |
| --- | --- |
| 3
1
2
3 | impossible
BA
BBA |

---

# 풀이 과정

- 지문이 이해가 안 돼서 11분쯤부터 N = 1~12까지 피보나치 수를 직접 나열하며 나눠봤다.
- 3의 배수 길이면 `BBA`를 반복하면 되고, 2를 뺀 값이 3의 배수면 `BA`로 시작한 뒤 `BBA`를 반복하면 된다는 걸 25분쯤 깨달았다.
- 나머지 경우는 불가능으로 처리해 정확히 30분에 풀었다.

```cpp
#include<iostream>

using namespace std;

/*
피보나치 수 분배

피보나치 수열 (1, 2, ..N)을 2개 집합으로 분할 
- 조건 만족 시키는 지 확인 + 가능하다면 분할 방법을 출력하는 프로그램 작성
- 만약 피보나치 수들의 합이 같도록 분할하는 것이 불가능하다면, “impossible”을 출력한다.

-  분할이 가능하다면, 길이가 N인 문자열을 출력한다. 
이 중 i번째 글자는 i∈A이면 ‘A’, i∈B이면 ‘B’여야 한다.
- 분할이 가능하단 게 1~N 중 다 안써도 된다는 말인가? 그러기엔 길이가 n인 문자열 출력이므로 다 써야 함.
- 11분 경과, 지문 이해 불가능..

1

1
- im

2 = BA?
- A: 1
- B: 1

3 = BBA
- B: 1, 1
- A: 2

5 불가능.,
- A: 
- B: 

8 1, 1, 2, 3, 5, 8
- BBABBA 가능
- 3의 배수

13, 1, 1, 2, 3, 5, 8, 13
- BBABBAx = 안되지 않나?
- BABBAXX 안됨

21, 1, 1, 2, 3, 5, 8, 13, 21
- BBABBA
- BABBABBA 가능.
-> 자리가 2개 제외 3의 배수라면 BA 스타팅으로 가능!

34, 1, 1, 2, 3, 5, 8, 13, 21, 34
- BBABBABBA 가능
- 3의 배수

55, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55 = 10
- BABBABBA.. 불가능
- BBABBABBA 불가능

89, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 = 11
- BABBABBABBA 가능
- BBA는 불가능

144, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144 = 12
- BBA BBA BBA BBA 가능
- BA 스타팅은 불가능
= 즉 애초부터 3의 배수면 BBA로 출력, 안되는데 -2 후 3의 배수면 BA 스타팅으로 출력.

25분 너무 늦게 깨달았다
-> 정확히 30분 클리어

*/
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	int n;
	for (test_case = 1; test_case <= T; ++test_case) {
		
		cin >> n;

		int dp[101] = { 1, 1, };
		for (int i = 2; i < n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}

		string s = "";
		if (n % 3 == 0) {
			for (int i = 0; i < n / 3; i++) {
				s += "BBA";
			}
			cout << s << endl;
		}
		else if ((n - 2)%3 == 0) {
			s += "BA";

			for (int i = 0; i < (n - 2) / 3; i++) {
				s += "BBA";
			}
			cout << s << endl;
		}
		else {
			cout << "impossible" << endl;
		}

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
```

---

# 결과 & 근거

**성공 (30분)**

- `f(i) + f(i+1) = f(i+2)`라서 세 개씩 묶으면 `BBA`로 합이 맞고, N % 3 == 2면 `f1 = f2`를 이용해 `BA`로 시작하면 된다.
- 피보나치 홀짝은 (홀, 홀, 짝) 반복이라 N % 3 == 1이면 전체 합이 홀수여서 나눌 수 없다.
- 계산만 하고 쓰지 않던 dp 배열은 int 오버플로를 일으켜서 지웠다.

```cpp
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int n;
		cin >> n;

		// 핵심 성질: f(i) + f(i+1) = f(i+2)
		// → 세 개씩 묶으면 "앞 두 개(B, B) 합 = 세 번째(A)" 가 된다.
		string s = "";
		if (n % 3 == 0) {
			// 1~N을 (1,2,3), (4,5,6), ... 으로 묶음 → 매 묶음 BBA
			for (int i = 0; i < n / 3; i++) s += "BBA";
			cout << s << '\n';
		}
		else if (n % 3 == 2) {
			// f1 = f2 = 1 → 앞 두 개를 BA로 맞추고, 3번부터 다시 세 개씩 BBA
			s += "BA";
			for (int i = 0; i < (n - 2) / 3; i++) s += "BBA";
			cout << s << '\n';
		}
		else {
			// n % 3 == 1: 피보나치 홀짝은 (홀, 홀, 짝) 반복 → 홀수가 홀수 개 → 전체 합이 홀수
			// 홀수는 두 집합으로 똑같이 나눌 수 없다
			cout << "impossible" << '\n';
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
```

> 
> 
> 
> ***한 줄 요약***
> 
> **수학 관찰(구성) 문제.** 
> 
> f(i) + f(i+1) = f(i+2)를 이용해 세 개씩 BBA로 묶고, N % 3 == 2면 BA로 시작하며, N % 3 == 1은 전체 합이 홀수라 불가능하다. 손으로 나열해 3개 묶음 규칙과 홀짝 조건을 찾는 게 핵심
> 

### 알고리즘 분류

- 수학
- 해 구성 (constructive)