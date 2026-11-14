# SWEA 11315, 오목판정 (성공)

# 문제 소개

[문제 사이트 하이퍼링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=2&problemLevel=3&contestProbId=AXaSUPYqPYMDFASQ&categoryId=AXaSUPYqPYMDFASQ&categoryType=CODE&problemTitle=&orderBy=RECOMMEND_COUNT&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=4)

N X N 크기의 판이 있다. 판의 각 칸에는 돌이 있거나 없을 수 있다. 돌이 가로, 세로, 대각선 중 하나의 방향으로 다섯 개 이상 연속한 부분이 있는지 없는지 판정하는 프로그램을 작성하라.

**[입력]**

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 하나의 정수 N(5 ≤ N ≤ 20)이 주어진다.

다음 N개의 줄의 각 줄에는 길이 N인 문자열이 주어진다. 각 문자는 ‘o’또는 ‘.’으로, ‘o’는 돌이 있는 칸을 의미하고, ‘.’는 돌이 없는 칸을 의미한다.

**[출력]**

각 테스트 케이스 마다 돌이 다섯 개 이상 연속한 부분이 있으면 “YES”를, 아니면 “NO”를 출력한다.

```cpp
입력
4
5
....o
...o.
..o..
.o...
o....
5
...o.
ooooo
...o.
...o.
.....
5
.o.oo
oo.oo
.oo..
.o...
.o...
5
.o.o.
o.o.o
.o.o.
o.o.o
.o.o.

출력
#1 YES
#2 YES
#3 YES
#4 NO
```

---

# 풀이 과정

- 처음엔 슬라이딩 윈도우로 행, 열, 대각선을 따로 검사하려 했는데 대각선을 어떻게 확인할지에서 막혔다.
- 32분쯤 돌이 있는 칸 기준으로 8방향을 쭉 확인하면 된다는 걸 깨달았다.
- 돌 위치를 모아두고, 방향마다 4칸을 더 보며 전부 돌이면 YES로 판정했다 (45분 55초).

```cpp
#include<iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
		vector<pair<int, int>> stone;   // 돌 위치 모음
		int n;
		cin >> n;
		vector<string> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == 'o') stone.push_back({ i, j });
			}
		}

		// 우, 하, 우하, 좌하 (반대 방향은 다른 돌에서 시작하면 같은 줄을 확인하게 됨)
		int dx[4] = { 0, 1, 1, 1 };
		int dy[4] = { 1, 0, 1, -1 };

		bool answer = false;
		for (pair<int, int> s : stone) {
			int x = s.first, y = s.second;

			for (int d = 0; d < 4; d++) {
				int cnt = 0;   // 시작 돌 다음부터 같은 방향으로 이어진 돌 수
				for (int j = 1; j < 5; j++) {
					int nx = x + dx[d] * j, ny = y + dy[d] * j;
					if (nx < 0 || ny < 0 || nx >= n || ny >= n) break;   // 판 밖
					if (arr[nx][ny] == '.') break;                       // 끊김
					cnt++;
				}
				if (cnt == 4) { answer = true; break; }   // 시작 돌 + 4개 = 5개 연속
			}
			if (answer) break;   // 하나 찾으면 나머지 돌은 볼 필요 없음
		}

		cout << "#" << test_case << " " << (answer ? "YES" : "NO") << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

```

---

# 결과 & 근거

**성공 (45분 55초)**

- 행·열·대각선은 방향 벡터 몇 개로 바꿔 생각하면 돌마다 한 칸씩 전진하는 같은 코드로 처리된다.
- 모든 돌을 시작점으로 보니까 4방향(우, 하, 우하, 좌하)만 봐도 충분하고, 찾으면 바로 끝내면 된다.

> 
> 
> 
> ***한 줄 요약***
> 
> 격자 방향 탐색 문제. 
> 
> 돌마다 4방향(우, 하, 우하, 좌하)으로 4칸을 더 확인해 5개가 연속인지 판정하고, 하나라도 있으면 즉시 YES다. 행·열·대각선을 방향 벡터로 통일하는 게 핵심.
> 

### 알고리즘 분류

- 구현
- 격자 (방향 탐색)
- 브루트포스