# SWEA 24001, 로봇 언어 (성공)

# 문제 소개

[문제 사이트 하이퍼링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=2&problemLevel=3&contestProbId=AZVqPrHaAy_HBIOy&categoryId=AZVqPrHaAy_HBIOy&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=2)

수직선 위에 로봇이 하나 놓여 있다. 현재 로봇의 좌표는 0이다.

로봇은 아래 두 종류의 명령어만 이해할 수 있다.

- L: 왼쪽으로 한 칸 이동한다. 로봇의 좌표가 1 감소하게 된다.
- R: 오른쪽으로 한 칸 이동한다. 로봇의 좌표가 1 증가하게 된다.

로봇에게 입력할 명령어를 나타내는 문자열 S가 주어진다.

다만, 문자열 중 일부는 물음표(‘?’)로 채워져 있는데, 이 부분은 당신이 L 또는 R로 대체해야 한다.

물음표를 모두 대체한 이후, 당신은 로봇에 명령어를 순서대로 입력하면서, 로봇이 원점으로부터 얼마나 멀리 떨어졌는지를 기록할 것이다.

당신은 물음표를 적절히 대체하여 로봇과 원점 사이의 최대 거리를 최대화하고자 한다.

**[입력]**

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스는 한 개의 줄로 이루어진다.

각 줄에는 길이가 1 이상 50 이하인, L,R,?로만 구성된 문자열 S가 주어진다.

**[출력]**

각 테스트 케이스마다, 문자열 S의 물음표를 L 또는 R로 적절히 대체하여 로봇과 원점 사이의 최대 거리를 최대화했을 때, 이 최대 거리를 한 줄에 하나씩 출력한다.

```cpp
3
????
L??RR??LL
LLRR

출력
4
5
2
```

- 예제 1: “LLLL” 또는 “RRRR”
- 예제 2: “LRRRRRRLL”로 대체하면, 로봇의 좌표는 [-1, 0, 1, 2, 3, 4, 5, 4, 3]이고, 각각 원점으로부터의 거리는 [1, 0, 1, 2, 3, 4, 5, 4, 3]이므로, 원점에서부터의 최대 거리는 5이다.

---

# 풀이 과정

- `?`를 L과 R 중 개수가 더 많은 쪽으로 통일하면 될 거라고 가설을 세웠고, 같으면 아무 쪽으로나 통일했다.
- 136/151이 나왔고, `R?L`, `LR?RL` 같은 반례에서 틀리는 걸 확인했다.
- 남은 5분 동안 `?`를 전부 L로 바꾼 경우와 전부 R로 바꾼 경우를 둘 다 시뮬레이션하는 방식으로 바꿔서 성공했다.

```cpp
#include<iostream>

using namespace std;

/*
수직선 위 로봇. 0 시작.
- L: 왼쪽으로 한 칸 이동한다. 로봇의 좌표가 1 --
- R: 오른쪽으로 한 칸 이동한다. 로봇의 좌표가 1 ++

로봇에게 입력할 명령어를 나타내는 문자열 S
- 문자열 중 일부는 물음표(‘?’)로 채워져 있는데, 이 부분은 당신이 L 또는 R로 대체godi gka
- 물음표 모두 대체 이후, 로봇에 명령어를 순서대로 입력하면서, 원점으로부터 얼마나 멀리 떨어졌는지를 기록할 것
- 물음표를 적절히 대체하여 로봇과 원점 사이의 최대 거리를 '최대화'

즉 ?는 

L??RR??LL 예제에 대해
1. LRRRRRRLL -> -1 0 1 2 3 4 5 4 3 -> 최대 거리는 5
2. LLLRRLLLL -> -1 -2 -3 -2 -1 -2 -3 -4 -5 -> 최대 거리는 5

- 즉 L과 R 중 더 많은 곳에 할당한다.
- 만약 L과 R이 같으면 아무 곳이나 통일

?RLR? 이라고 가정하자
- 가설1: R이 제일 많다 -> RRLRR = -1 -2 -1 -2 -3 = 최대 거리는 3

??RL?R?L
- 가설1: 둘이 같다, 통일 -> LLRLLRLL -> -1 -2 -1 -2 -3 -2 -3 -4 = 4
- RRRLRRRL = 1 2 3 2 3 4 5 4 = 4 가설 일치

*/
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		string s;
		cin >> s;

		int l=0, r=0, q=0;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'L') l++;
			else if (s[i] == 'R') r++;
			else if (s[i] == '?') q++;
		}

		//cout << "l: " << l << " , r:"  << r << ", q: " << q << endl;

		if (l == r && r == 0) {
			// ?만 가득
			cout << q << endl;
		}
		else if (q == 0) {
			// No '?'

			int max_dis = 0, pos = 0;
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == 'L') {
					pos--;
				}
				else {
					pos++;
				}
				max_dis = max(max_dis, abs(pos));
			}
			cout << max_dis << endl;
		}
		else {
			char target;

			int max_dis = 0, pos = 0;
			string news = s;
			for (int i = 0; i < news.size(); i++) {
				if (news[i] == '?') news[i] = 'L';
				if (news[i] == 'L') {
					pos--;
				}
				else {
					pos++;
				}
				max_dis = max(max_dis, abs(pos));
			}

			pos = 0;
			news = s;
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == '?') s[i] = 'R';
				if (s[i] == 'L') {
					pos--;
				}
				else {
					pos++;
				}
				max_dis = max(max_dis, abs(pos));
			}

			cout << max_dis << endl;
		}

	}
	/*
	136/151
	-> LRRL 에 대해 1을 뱉는다.
	?LRLR? 에 대해 2.
	L인 경우, -1 -2 -1 -2 -1 -2
	R인 경우, 1, 0, 1, 0 1, 2

	R?L 에 대해 1을 뱉는다. 2 이어야 함 (동일 케이스인 RR?LL에도 2)
	LR?RL에 대해 1을 뱉는다. 2 이어야 함
	RL?RL에 대해 1을 뱉음. 2 이어야 함.
	L?R은 2로 뱉음.
	- 즉 같은 조건에서 엇갈림
	- 즉 물음표 기준 양 측의 L과 R이 얼마나 연속되는 지를 검사해야 한다.
	- 여태 까지의 합이 음수고, 
	if (l >= r) {
				target = 'L';
			} 으로 하고 있어서...

	5분 남짓 그냥 무식하게 다 해버리자.

	*/
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
```

---

# 결과 & 근거

**성공**

- 최대 거리는 어느 한 순간의 위치라서, 그 순간 이전의 `?`를 전부 같은 방향으로 두는 게 최선이다. 그래서 "전부 L"과 "전부 R" 두 경우만 보면 된다.
- 개수가 많은 쪽으로 통일하는 가설은 앞쪽 흐름을 반영하지 못해서 틀렸다.

```cpp
// 더 깔끔한 코드
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

// '?'를 전부 fill('L' 또는 'R')로 바꿔서 움직였을 때, 원점에서 가장 멀어진 거리
int simulate(const string& s, char fill) {
	int pos = 0, max_dis = 0;
	for (char c : s) {
		char cmd = (c == '?') ? fill : c;
		pos += (cmd == 'L') ? -1 : 1;
		max_dis = max(max_dis, abs(pos));
	}
	return max_dis;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		string s;
		cin >> s;

		// 최대 거리가 나오는 순간 t를 생각하면, t 이전의 '?'는 모두 같은 방향이 최선이다.
		// → "전부 L"과 "전부 R" 두 경우만 보면 항상 최적이 들어 있다.
		// ('?'만 있거나 '?'가 없는 경우도 이 두 번 안에 자연스럽게 처리됨)
		cout << max(simulate(s, 'L'), simulate(s, 'R')) << '\n';   // "#t" 없이 출력
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

```

> 
> 
> 
> ***한 줄 요약***
> 
> **시뮬레이션 + 그리디 관찰 문제.**
> 
>  `?`를 전부 L로 바꾼 경우와 전부 R로 바꾼 경우를 각각 시뮬레이션해 원점에서의 최대 거리 중 큰 값을 구한다. 최대 거리 시점 이전의 `?`는 한 방향으로 통일하는 게 최선이라는 관찰이 핵심.
> 

### 알고리즘 분류

- 시뮬레이션
- 그리디
- 브루트포스