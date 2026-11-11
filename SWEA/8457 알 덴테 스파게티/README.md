# SWEA 8457, 알 덴테 스파게티 (성공)

# 문제 소개

[문제 사이트 하이퍼링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=2&problemLevel=3&contestProbId=AWzal4EKksEDFAVU&categoryId=AWzal4EKksEDFAVU&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=11&problemLevel=2%2C3&&&&&&&&&)

선표는 가게에서 처음으로 스파게티 면을 샀다. 봉투에 적힌 정보에 따르면, 면을 정확히 B초 동안 삶아야 이상적인 상태의 면이 된다고 한다.

그러나 안타깝게도, 지금 선표집의 모든 시계는 고장이 났다.

그래서 가게에서 모래시계를 하나 사서 집으로 가려고 한다.

가게에는 N개의 모래시계가 있고, i번째 모래시계는 정확히 xi초를 측정할 수 있다.

모래가 다 내려오면 바로 모래시계를 뒤집는 것으로 2xi초, 3xi초, …도 측정할 수 있다.

그러나 나머지 시간은 측정할 수 없다.

선표는 모래시계로는 정확한 시간을 측정할 수 없을 것 같아서, 조금 타협하여 E초 정도의 오차를 허용하려고 한다.

그러므로, 어떤 하나의 모래시계를 구입하여 B – E초에서 B + E초 중 하나를 측정해낼 수 있으면 된다.

구입해도 되는 모래시계의 개수를 구하는 프로그램을 작성하라

**[입력]**

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 세 정수 N, B, E(1 ≤ N ≤ 100, 1 ≤ B ≤ 1440, 0 ≤ E ≤ 104) 가 공백 하나로 구분되어 주어진다.

두 번째 줄에는 N개의 정수 x1, x2, ⋯, xN (1 ≤ xi ≤ 104)가 공백 하나로 구분되어 주어진다.

**[출력]**

각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고,

각 테스트 케이스마다 구입해도 되는 모래시계의 개수를 출력한다.

**입력**

```cpp
2

2 10 2

3 4

3 10 5

16 100 10000
```

**출력**

```cpp
#1 2

#2 0
```

---

# 풀이 과정

- 모래시계를 중복해서 살 수 있는지, 하나만 살 수 있는지 지문이 불친절하다고 느꼈다.
- 모래시계가 범위를 넘으면 제외하고, 범위 안이면 바로 세고, 범위보다 작으면 범위 안에 그 시간의 배수가 있는지 확인했다.
- 처음엔 `a <= e*2` 조건 때문에 96/104가 나왔다. `4 15 1 / 1 15 8 10` 반례를 직접 만들어서 원인을 찾았고, 26분 30초에 해결했다.

```cpp
#include<iostream>
#include <vector>

using namespace std;

/*
 * 스파게이 면 삶기 -> 정확히 B초 삶기
 * but 시계 고장 -> 여러 종류의 모래시계를 통한 측정
 * - 어느 정도의 오차인 E는 허용.
 * = 그러므로, 어떤 하나의 모래시계를 구입하여 B – E초에서 B + E초 중 하나를 측정해낼 수 있으면 된다.
 * == 구입해도 되는 모래시계의 개수를 구하는 프로그램을 작성하라
 *
 *
 *
 * 2 10 2 -> 10초에서 오차 허용한 결과 8~12초 이어야 함.
 * 3, 4
 * -> 이 경우는 3으로 9초, 4로 12초를 만들 수 있으므로
 * 아 항상 지문이 참 불친절해. 모래시계 하나 중복 구매 가능? 아니면 정확히 하나만 구매 가능한 것?
 *
 * 8 기준 8%3 == 2, 8/3 == 2 이므로 min_t%a < a
 *
 * 3 10 5 -> 5초 ~ 15초
 * 16 100 10000
 * 최소가 범위 내로 들어가지 않아서 패스
 *
 */
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case) {
		int n, b, e;
		cin>>n>>b>>e;
		vector<int> sand;

		int a, answer = 0;
		int min_t = b-e, max_t = b+e;

		for (int i = 0; i < n; ++i) {
			cin >> a;
			sand.push_back(a);

			if ( a > max_t ) continue;

			if (min_t <= a && a<= max_t){
				// cout << "정확히 들어갑니다, " << a << endl;
				answer ++;
			}
			else if (a < min_t /*&& a <= e*2*/ ) {
				// cout << "만들 수 있습니다, " << a << endl;

				for (int l = min_t ; l <= max_t ; ++l) {
					if (l%a == 0) {
						answer ++;
						break;
					}
				}
				// answer++;
			}
		}

		cout << "#" << test_case << " " << answer << endl;

	}

	// 20분 구현 완 -> 96/104

	/*
	 * 오차가 0일때 확인
	 *
	 * 조건식 문제 확인
	 * 1
	 * 4 15 1
	 * 1 15 8 10 -> 3이 아닌 2를 뱉음. (a <= e*2) 조건식이 잘못됨.
	 * 26분 30초 해결.
	 */
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
```

---

# 결과 & 근거

**성공 (26분 30초)**

- 모래시계 하나로 x, 2x, 3x… 중 하나가 [B−E, B+E] 안에 있으면 된다. 그래서 범위 안에 x의 배수가 있는지만 보면 된다.
- `a <= e*2`는 배수 존재와 상관없는 조건이었다. 이걸 지우니 통과했다.
- 올림 나눗셈으로 "B−E 이상인 최소 배수"를 구하면 O(1)로도 판정할 수 있다.

```cpp
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case) {
		int n, b, e;
		cin>>n>>b>>e;

		int a, answer = 0;
		int min_t = b-e, max_t = b+e;   // 허용 범위 [B-E, B+E] (B-E는 음수일 수도 있다)

		for (int i = 0; i < n; ++i) {
			cin >> a;

			// 한 번만 재도 범위를 넘으면, 배수는 더 커지니까 절대 불가능
			if ( a > max_t ) continue;

			if (min_t <= a && a <= max_t) {
				// 1배(그대로)로 이미 범위 안
				answer ++;
			}
			else if (a < min_t) {
				// 범위 안의 수 l 중에 a의 배수가 하나라도 있으면 OK
				// (범위 길이 2E+1 ≤ 20001, 모래시계 100개 → 최대 200만 번이라 충분)
				for (int l = min_t ; l <= max_t ; ++l) {
					if (l%a == 0) {
						answer ++;
						break;
					}
				}
			}
		}

		cout << "#" << test_case << " " << answer << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
```

> 
> 
> 
> ***한 줄 요약***
> 
> **배수 판정 수학 문제.** 
> 
> 모래시계 시간 x의 배수가 [B−E, B+E] 안에 하나라도 있는지 범위를 돌며 확인하고, 그런 모래시계 수를 센다. 범위를 넘는 경우와 이미 범위 안인 경우를 먼저 거르는 게 핵심이고, 올림 나눗셈으로 O(1) 판정도 된다.
> 

### 알고리즘 분류

- 수학
- 브루트포스