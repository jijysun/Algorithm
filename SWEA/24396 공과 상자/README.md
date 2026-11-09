# SWEA 24396, 공과 상자 (실패)

# 문제 소개

[문제 사이트 하이퍼링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=2&problemLevel=3&contestProbId=AZZ_XjxKgVLHBINj&categoryId=AZZ_XjxKgVLHBINj&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=2)

B개의 검은 공, W개의 흰 공, B개의 검은 상자, W개의 흰 상자가 있다.당신은 모든 공을 상자에 담아서, 모든 상자가 정확히 한 개의 공을 담고 있도록 하고자 한다.

모든 공을 상자에 넣으면, 아래와 같이 각 상자마다 점수를 계산한다.검은 상자에 검은 공이 들어 있으면 X점, 흰 상자에 흰 공이 들어 있으면 Y점, 검은 상자에 흰 공이 들어 있거나 흰 상자에 검은 공이 들어 있으면 Z점이다.

당신은 모든 상자의 점수의 합이 최대화되도록 공을 넣고자 한다. 이 때 얻을 수 있는 최대 점수를 구하는 프로그램을 작성하라.

**[입력]**

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.각 테스트 케이스는 한 개의 줄로 이루어진다.각 줄에는 다섯 개의 정수 B, W, X, Y, Z (1 ≤ B, W ≤ 100, -1000 ≤ X, Y, Z ≤ 1000)가 공백 하나씩을 사이로 두고 주어진다.

**[출력]**

각 테스트 케이스마다, 가능한 최대 점수 합을 출력한다.

**입력**

| 3
2 2 1 1 0
9 9 -11 -11 11
15 19 -2 4 -3 |  |
| --- | --- |

**출력**

```cpp
4
198
46
```

---

# 풀이 과정

- 점수 합을 최대화하는 문제라서 DP 느낌이 났는데, DP가 어려워서 조합으로 풀고 싶었다. 근데 조합은 100 팩토리얼 제곱 정도로 커질 것 같았다.
- 더 많은 공을 점수가 더 큰 상자 쪽에 넣어야 한다고 생각했다.
- B가 제자리에 들어간 for, W가 제자리에 들어간 for로 나눠 풀려 했는데, 제자리가 아닌 공을 다른 색 상자에 어떻게 처리할지 헷갈려서 31분에 포기했다.

```cpp
#include<iostream>
#include <bits/stdc++.h>

using namespace std;

/*
 * B 개의 검은 공과 검은 상자, W 개의 흰 공과 흰 상자.
 *
 * 모든 공을 상자에 넣으면, 아래와 같이 각 상자마다 점수를 계산한다.
 * 1. 검은 상자에 검은 공이 들어 있으면 X점,
 * 2. 흰 상자에 흰 공이 들어 있으면 Y점,
 * 3. 검은 상자에 흰 공이 들어 있거나 흰 상자에 검은 공이 들어 있으면 Z점이다.
 *
 *
 * 모든 상자의 점수의 합이 최대화되도록 공을 넣고자 한다!!!!!
 * - DP 느낌이 물씬 난다.
 * - 사실 DP가 어려워서 조합으로 풀고 싶으나, 조합의 경우 거진 100 팩토리얼의 제곱 정도.
 *
 * (흰/검 공) * (흰/검 상자)
 */

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int b, w, x, y, z;

		cin>>b>>w>>x>>y>>z;

		// 더 많은 공을, 더 점수가 많은 상자 쪽에 넣어야 한다.

		if (x == 0 && y == 0 && z == 0) {
			cout << 0 << endl;
			continue;
		}

		// 방정식인 거잖아?
		// x, y, z에 대해

		// 올바르게 들어간 경우
		int max_total = 0;

		
		// 
		// 
		/*
		 * 31분 포기	
		 * 수식에서 멘탈 나가서 집중 실패
		 * - 정확히는 B가 정상적으로 들어간 for 문, W가 정상적으로 들어간 for문으로 풀려고 했음
		 * - 그리고 각 상자에 정상적으로 들어간 경우에 대해서 다른 색깔의 상자를 어떻게 해야 할 지 헷갈려 하다가 포기
		 * - 차라리 이중 for문이 나았을 텐데
		 * 
		 */
		for (int i = 0; i<b; i++) {
			int btotal = i * x + (b-i) * z;
			int wtotal = (w-b+i) * y + (w-i) * z;

			int cur_total = btotal + wtotal;

			if (max_total < cur_total) {
				swap(max_total,cur_total);
			}
		}

		for (int i = 0; i<w; i++) {
			int wtotal = i * y + (w-i) * z;
			int btotal = (b-i) * z;

			int cur_total = btotal + wtotal;

			if (max_total < cur_total) {
				swap(max_total,cur_total);
			}
		}

		cout << max_total << endl;

	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
```

---

# 결과 & 근거

**실패 (31분 포기)**

- "검은 상자 속 검은 공 개수 i" 하나만 정하면 나머지 세 칸이 자동으로 정해진다. 그래서 for 하나면 충분하고, 두 번째 for는 필요 없다.
- 흰 상자 쪽 오배치 수는 `w-i`가 아니라 `b-i`이고, `i = b`까지 포함해야 한다.
- 점수가 음수일 수 있으니 최댓값을 0이 아니라 `INT_MIN`으로 초기화해야 한다.

```cpp
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int b, w, x, y, z;
		cin>>b>>w>>x>>y>>z;

		// 점수가 전부 음수일 수도 있으니(-1000 ≤ X,Y,Z), 0이 아니라 아주 작은 값으로 시작한다.
		int max_total = INT_MIN;

		// i = "검은 상자에 들어간 검은 공" 개수. 이 값 하나만 정하면 나머지 네 칸이 전부 정해진다.
		//  - 검은 상자 b개 중 i개는 검은 공(X점), 나머지 b-i개는 흰 공(Z점)
		//  - 검은 상자에 못 들어간 검은 공 b-i개는 흰 상자로 간다(Z점)
		//  - 흰 상자 w개 중 b-i개는 검은 공이 차지했으니, 남은 w-(b-i)개에 흰 공(Y점)
		// 흰 공이 w개뿐이라 b-i ≤ w 여야 한다 → i는 max(0, b-w)부터 시작.
		// i = b(전부 제자리)도 포함해야 하니 i <= b.
		for (int i = max(0, b - w); i <= b; i++) {
			int btotal = i * x + (b - i) * z;            // 검은 상자 b개의 점수
			int wtotal = (w - b + i) * y + (b - i) * z;  // 흰 상자 w개의 점수 (오배치는 b-i개!)

			int cur_total = btotal + wtotal;
			max_total = max(max_total, cur_total);
		}

		cout << max_total << '\n';
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
```

> 
> 
> 
> ***한 줄 요약***
> 
> **변수 하나를 전부 대입해보는 구현 문제.** 
> 
> 검은 상자에 들어간 검은 공 수 i를 0~B로 정하면 나머지 세 칸이 자동으로 정해지고, 그 점수의 최댓값을 구한다. 경우의 수를 "공 순서"가 아니라 "개수 하나"로 줄이는 게 핵심.
> 

### 알고리즘 분류

- 구현
- 브루트포스
- 수학