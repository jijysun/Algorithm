# SWEA 25469, 페인트칠 (성공)

# 문제 소개

[문제 사이트 하이퍼링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=2&problemLevel=3&contestProbId=AZlP2QbavInHBIO0&categoryId=AZlP2QbavInHBIO0&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=1)

H x W 크기의 격자판이 있다. 처음에 모든 격자는 흰색으로 칠해져 있다. 당신은 아래와 연산을 0회 이상 사용하여 일부 격자를 검은색으로 칠하였다.    -  격자판의 행 하나 또는 열 하나를 고른다.    -  고른 행 또는 열에 있는 모든 칸을 검은색으로 칠한다. 이미 검은색인 칸을 한 번 더 검은색으로 칠하면 여전히 검은색을 유지한다.현재 격자판의 상태가 주어질 때, 이러한 상태를 만들기 위해 최소 몇 번의 연산을 사용해야 하는지 구하는 프로그램을 작성하라.

**[입력]**

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.각 테스트 케이스는 아래와 같은 구성으로 이루어진다.    -  첫 번째 줄에는 격자판의 행 수 H와 열 수 W(1 ≤ H, W ≤ 50)이 주어진다.    -  다음 H개의 줄에는 격자판의 색을 나타내는 W개의 문자가 주어진다. i번째 줄의 j번째 문자는, 격자판의 i행 j열이 검은색이면 “#”, 흰색이면 “.”이다. 문제에서 제시한 연산만을 사용하여 만들 수 있는 상태만 주어진다.

**[출력]**

각 테스트 케이스마다, 주어진 격자판 상태를 만들기 위해 필요한 최소 연산 횟수를 한 줄에 하나씩 출력한다.

```cpp
입력
2
3 3
.#.
###
.#.
5 3
###
.#.
.#.
.#.
###

출력
2
3
```

---

# 풀이 과정

- 처음엔 가로·세로로 한 번씩 훑으며 연속으로 칠해져 있는지만 보면 될 거라 생각했다.
- 가운데 한 칸만 흰 5×5 같은 반례를 떠올리고, 행/열 길이와 `#` 개수가 같으면 그 줄을 칠한 것이라는 방식으로 바꿨다.
- 전부 검은색이면 가로와 세로 횟수가 겹치니까 둘 중 작은 값을 반환했다.
- 20분에 런타임 에러가 났는데 `cin >> s`를 빼먹어서였고, 고쳐서 27분에 성공했다.

```cpp
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
		int x, y;            // x = 행 수 H, y = 열 수 W
		cin >> x >> y;

		vector<string> arr(x);
		int black = 0;
		for (int i = 0; i < x; i++) {
			cin >> arr[i];
			for (int j = 0; j < y; j++) if (arr[i][j] == '#') black++;
		}

		if (black == x * y) {
			// 전부 검은색: 꽉 찬 줄을 세면 H+W가 되지만,
			// 실제로는 행만 H번 또는 열만 W번 칠하면 되므로 둘 중 작은 값
			cout << min(x, y) << '\n';
		}
		else {
			// 흰칸이 하나라도 있으면, "꽉 찬 행"은 반드시 행으로 칠한 것이고
			// "꽉 찬 열"은 반드시 열로 칠한 것이다 → 꽉 찬 줄 수 = 최소 연산 수
			int paint_x = 0, paint_y = 0;

			for (int i = 0; i < x; i++) {
				int paint_cnt = 0;
				for (int j = 0; j < y; j++) if (arr[i][j] == '#') paint_cnt++;
				if (paint_cnt == y) paint_x++;   // i행이 꽉 참
			}

			for (int j = 0; j < y; j++) {
				int paint_cnt = 0;
				for (int i = 0; i < x; i++) if (arr[i][j] == '#') paint_cnt++;
				if (paint_cnt == x) paint_y++;   // j열이 꽉 참
			}

			cout << paint_x + paint_y << '\n';   // 이 문제는 "#t" 없이 숫자만 출력
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

```

---

# 결과 & 근거

**성공 (27분)**

- 흰칸이 하나라도 있으면, 꽉 찬 행은 반드시 행으로 칠한 것이고 꽉 찬 열은 반드시 열로 칠한 것이다. 그래서 꽉 찬 줄 수가 최소 연산 수다.
- 전부 검은색이면 행만 H번 또는 열만 W번 칠하면 되므로 min(H, W)다. 이유가 분명한 특수 분기다.

```cpp
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
		int x, y;            // x = 행 수 H, y = 열 수 W
		cin >> x >> y;

		vector<string> arr(x);
		int black = 0;
		for (int i = 0; i < x; i++) {
			cin >> arr[i];
			for (int j = 0; j < y; j++) if (arr[i][j] == '#') black++;
		}

		if (black == x * y) {
			// 전부 검은색: 꽉 찬 줄을 세면 H+W가 되지만,
			// 실제로는 행만 H번 또는 열만 W번 칠하면 되므로 둘 중 작은 값
			cout << min(x, y) << '\n';
		}
		else {
			// 흰칸이 하나라도 있으면, "꽉 찬 행"은 반드시 행으로 칠한 것이고
			// "꽉 찬 열"은 반드시 열로 칠한 것이다 → 꽉 찬 줄 수 = 최소 연산 수
			int paint_x = 0, paint_y = 0;

			for (int i = 0; i < x; i++) {
				int paint_cnt = 0;
				for (int j = 0; j < y; j++) if (arr[i][j] == '#') paint_cnt++;
				if (paint_cnt == y) paint_x++;   // i행이 꽉 참
			}

			for (int j = 0; j < y; j++) {
				int paint_cnt = 0;
				for (int i = 0; i < x; i++) if (arr[i][j] == '#') paint_cnt++;
				if (paint_cnt == x) paint_y++;   // j열이 꽉 참
			}

			cout << paint_x + paint_y << '\n';   // 이 문제는 "#t" 없이 숫자만 출력
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
> **격자 관찰 문제.** 
> 
> 흰칸이 있으면 꽉 찬 행과 열은 반드시 그 줄로 칠한 것이므로 꽉 찬 줄 수가 답이고, 전부 검은색이면 min(H, W)다. "꽉 찬 줄 = 칠한 줄"이라는 관찰과 전부 검은 경우의 예외 처리가 핵심.
> 

### 알고리즘 분류

- 구현
- 격자
- 수학 (관찰)