# 문제 소개

[문제 사이트 하이퍼링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=3&contestProbId=AWXGKdbqczEDFAUo&categoryId=AWXGKdbqczEDFAUo&categoryType=CODE&problemTitle=&orderBy=SUBMIT_COUNT&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=3)

자연수 N와 R가 주어진다. 이 때의 N combination R의 값을 1234567891로 나눈 나머지를  출력하세요.

예를들면 N이 4, R이 2라면 4 combination 2는 (4 * 3) / (2 * 1) = 6이 된다.

**[입력]**

첫 줄에 테스트케이스의 개수 T가 주어진다. (1 ≤ T ≤ 20)

각 케이스의 첫 줄에 정수 N, R이 주어진다. (1 ≤ N ≤ 1000000, 0 ≤ R ≤ N)

**[출력]**

각 테스트케이스마다 한 줄에 걸쳐, 테스트케이스 수 “#(TC) “를 출력하고, N combination R을 1234567891로 나눈 나머지를 출력하시오.

```
입력
1
10 2

출력
#1 45
```

---

# 풀이 과정

- 어렵다,….
- N이 최대 100만이라 nCr이 int는 물론 long long 범위도 무조건 넘는다고 보고, 범위를 어떻게 처리할지부터 고민했다.
- n! / (r!(n-r)!)을 그대로 구하면 터지니까, nCr = nC(n-r)로 r을 줄이고 `res = res * (n - i + 1) / i`로 곱하면서 바로 나누는 방식으로 구현했다.
- 마지막에 1234567891로 나눈 나머지를 출력했지만, 35분이 지난 시점에 4/20에서 멈췄다.

!image.png

```cpp
#include<iostream>

using namespace std;
/*

조합, 자연수 N와 R -> N combination R의 값을 1234567891로 나눈 나머지 출력
-  N이 4, R이 2라면 4 combination 2는 (4 * 3) / (2 * 1) = 6
- 1 ≤ N ≤ 1000000, 0 ≤ R ≤ N

최대, 최악의 경우 999,999,000,000를 출력해야 한다
- 이걸 어떻게 할 것인지?
- INT_MAX 2,147,483,647 무조건 INT_MAX를 넘는다.
- 먼저 나누기? 계산식은 대충 

n! / r!(n-r!) % 1234567891 을 출력하라는 것.

35분 경과 4/20

*/

long long combination(int n, int r) {
	if (r < 0 || r > n) return 0;
	if (r > n - r) r = n - r; // nCr == nC(n-r) 활용

	long long res = 1;
	for (int i = 1; i <= r; ++i) {
		res = res * (n - i + 1) / i;
	}
	return res;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		long long n, r;

		cin >> n >> r;
		// r이 0일 수도 있음.
		//cout << LLONG_MAX << endl; // 9,223,372,036,854,775,807

		// 조합 공식

		cout << "#" << test_case <<" " << combination(n, r) % 1234567891 << endl;

	}

	/
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

```

---

# 결과 & 근거

**실패 (35분, TC 4/20)**

- 곱하면서 나누는 방식은 나누기 전 중간값이 long long을 넘는 순간(N = 62, R = 28부터) 틀린다. 그렇다고 중간에 나머지를 취하면 나눗셈이 깨진다. 나머지 연산은 +, -, ×에서만 성립하고 ÷에서는 성립하지 않는다.
- 1234567891은 소수라서 페르마 소정리로 x로 나누기를 x^(MOD-2) 곱하기로 바꿀 수 있다. n!, r!, (n-r)!을 나머지로 미리 구해 두고, 분모의 역원은 분할 정복 거듭제곱으로 O(log MOD)에 구한다.
- 팩토리얼은 최대 N까지 한 번만 구한다. MOD 미만인 두 수의 곱은 약 1.5×10^18이라 long long에 들어간다.

```cpp
#include<iostream>
#include <vector>

using namespace std;

const long long MOD = 1234567891;   // 소수 → 페르마 소정리로 나눗셈을 곱셈으로 바꿀 수 있다

// a^e % MOD 를 O(log e)로 (분할 정복 거듭제곱)
long long power(long long a, long long e) {
	long long res = 1;
	a %= MOD;
	while (e > 0) {
		if (e & 1) res = res * a % MOD;   // 지금 비트가 1이면 곱해 둔다
		a = a * a % MOD;                  // a, a^2, a^4, a^8 ...
		e >>= 1;
	}
	return res;
}

// nCr = n! / (r! * (n-r)!)
// 나머지 연산에서는 나눗셈이 안 되므로 → x로 나누기 = x^(MOD-2) 곱하기 (페르마 소정리)
long long combination(int n, int r, const vector<long long>& fact) {
	if (r < 0 || r > n) return 0;
	long long bottom = fact[r] * fact[n - r] % MOD;
	return fact[n] * power(bottom, MOD - 2) % MOD;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 팩토리얼은 테스트 케이스마다 다시 구할 필요 없이 최대 N까지 한 번만
	// 곱하기 전 두 수가 모두 MOD 미만(약 12억) → 곱은 약 1.5 * 10^18 < long long 최대(약 9.2 * 10^18)
	const int MAX_N = 1000000;
	vector<long long> fact(MAX_N + 1);
	fact[0] = 1;
	for (int i = 1; i <= MAX_N; i++) {
		fact[i] = fact[i - 1] * i % MOD;
	}

	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		long long n, r;
		cin >> n >> r;   // r = 0이면 fact[0] = 1이라 자연스럽게 1이 나온다
		cout << "#" << test_case << " " << combination(n, r, fact) << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
```

> 
> 
> 
> ***한 줄 요약***
> 
> **모듈러 조합 문제.** 
> 
> n!, r!, (n-r)!을 나머지로 미리 구하고, 분모는 페르마 소정리(x^(MOD-2))로 역원을 만들어 곱한다. 나머지 연산에서 나눗셈은 역원 곱셈으로 바꿔야 한다는 게 핵심.
> 

### 알고리즘 분류

- 수학
- 조합론
- 모듈러 곱셈 역원
- 분할 정복을 이용한 거듭제곱