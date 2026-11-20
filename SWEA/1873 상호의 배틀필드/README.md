# 문제 소개

[문제 사이트 하이퍼링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=3&contestProbId=AV5LyE7KD2ADFAXc&categoryId=AV5LyE7KD2ADFAXc&categoryType=CODE&problemTitle=&orderBy=SUBMIT_COUNT&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=1)

상호는 전차로 시가전을 하는 것을 테마로 한 새로운 게임 “배틀 필드”를 개발하기로 했다.그래서 먼저 간단하게 프로토 타입 게임을 만들었다.이 프로토 타입에서 등장하는 전차는 사용자의 전차 하나뿐이며, 적이나 아군으로 만들어진 전차는 등장하지 않는다.사용자의 전차는 사용자의 입력에 따라 격자판으로 이루어진 게임 맵에서 다양한 동작을 한다.다음 표는 게임 맵의 구성 요소를 나타낸다.

| 문자 | 의미 |
| --- | --- |
| . | 평지(전차가 들어갈 수 있다.) |
| * | 벽돌로 만들어진 벽 |
| # | 강철로 만들어진 벽 |
| - | 물(전차는 들어갈 수 없다.) |
| ^ | 위쪽을 바라보는 전차(아래는 평지이다.) |
| v | 아래쪽을 바라보는 전차(아래는 평지이다.) |
| < | 왼쪽을 바라보는 전차(아래는 평지이다.) |
| > | 오른쪽을 바라보는 전차(아래는 평지이다.) |

다음 표는 사용자가 넣을 수 있는 입력의 종류를 나타낸다.

| 문자 | 동작 |
| --- | --- |
| U | Up : 전차가 바라보는 방향을 위쪽으로 바꾸고, 한 칸 위의 칸이 평지라면 위 그 칸으로 이동한다. |
| D | Down : 전차가 바라보는 방향을 아래쪽으로 바꾸고, 한 칸 아래의 칸이 평지라면 그 칸으로 이동한다. |
| L | Left : 전차가 바라보는 방향을 왼쪽으로 바꾸고, 한 칸 왼쪽의 칸이 평지라면 그 칸으로 이동한다. |
| R | Right : 전차가 바라보는 방향을 오른쪽으로 바꾸고, 한 칸 오른쪽의 칸이 평지라면 그 칸으로 이동한다. |
| S | Shoot : 전차가 현재 바라보고 있는 방향으로 포탄을 발사한다. |

전차가 이동을 하려고 할 때, 만약 게임 맵 밖이라면 전차는 당연히 이동하지 않는다.

전차가 포탄을 발사하면, 포탄은 벽돌로 만들어진 벽 또는 강철로 만들어진 벽에 충돌하거나 게임 맵 밖으로 나갈 때까지 직진한다.

만약 포탄이 벽에 부딪히면 포탄은 소멸하고, 부딪힌 벽이 벽돌로 만들어진 벽이라면 이 벽은 파괴되어 칸은 평지가 된다.

강철로 만들어진 벽에 포탄이 부딪히면 아무 일도 일어나지 않는다.

게임 맵 밖으로 포탄이 나가면 아무런 일도 일어나지 않는다.

초기 게임 맵의 상태와 사용자가 넣을 입력이 순서대로 주어질 때, 모든 입력을 처리하고 나면 게임 맵의 상태가 어떻게 되는지 구하는 프로그램을 작성하라.

**[입력]**

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 두 정수 H, W (2 ≤ H, W ≤ 20) 이 공백으로 구분되어 주어진다.

이는 게임 맵의 높이가 H, 너비가 W임을 나타낸다.

즉, 게임 맵은 H x W크기의 격자판이다.

다음 H개의 각각의 줄에는 길이가 W인 문자열이 주어진다.

각각의 문자는 위의 게임 맵 구성 요소 표에 있는 문자들만 포함하며, 전차는 단 하나만 있다.

다음 줄에는 사용자가 넣을 입력의 개수를 나타내는 정수 N(0 < N ≤ 100) 이 주어진다.

다음 줄에는 길이가 N인 문자열이 주어진다.

각각의 문자는 위의 사용자가 넣을 수 있는 입력의 종류를 나타내는 표에 있는 문자들만 포함된다.

**[출력]**

각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고 한 칸을 띄운 후, 모든 입력을 처리하고 난 후의 게임 맵을 H개의 줄에 걸쳐 출력한다.


```
입력
1
3 7
-**....
--..#**
#<.****
23
SURSSSSUSLSRSSSURRDSRDS

출력
#1 **....v
.-..#..
#......
```

---

# 풀이 과정

- 입력값이랑 배열 값 바꾸고 뭐가 복잡해서 좀 걸릴 줄 알았는데 29분 클리어
- 전차 위치를 입력 받을 때 기억해 두고, U/D/L/R은 switch로 전차 모양을 먼저 바꾼 뒤 앞 칸이 맵 안의 평지일 때만 이동했다.
- S는 전차 모양으로 방향을 정하고, 맵 밖이나 강철 벽이면 멈추고 벽돌 벽이면 평지로 바꾼 뒤 멈추게 했다.
- 예제 명령을 하나씩 손으로 따라가며 맵을 그려 확인했고, 25분에 구현을 마쳤다.

```cpp
#include<iostream>
#include <vector>

using namespace std;

/*
배틀필드 게임
.	평지(전차가 들어갈 수 있다.)
*	벽돌로 만들어진 벽
#	강철로 만들어진 벽
-	물(전차는 들어갈 수 없다.)
^	위쪽을 바라보는 전차(아래는 평지이다.)
v	아래쪽을 바라보는 전차(아래는 평지이다.)
<	왼쪽을 바라보는 전차(아래는 평지이다.)
>	오른쪽을 바라보는 전차(아래는 평지이다.)

사용자가 넣을 수 있는 입력의 종류를 나타낸다.
U	Up : 전차가 바라보는 방향을 위쪽으로 바꾸고, 한 칸 위의 칸이 평지라면 위 그 칸으로 이동한다.
D	Down : 전차가 바라보는 방향을 아래쪽으로 바꾸고, 한 칸 아래의 칸이 평지라면 그 칸으로 이동한다.
L	Left : 전차가 바라보는 방향을 왼쪽으로 바꾸고, 한 칸 왼쪽의 칸이 평지라면 그 칸으로 이동한다.
R	Right : 전차가 바라보는 방향을 오른쪽으로 바꾸고, 한 칸 오른쪽의 칸이 평지라면 그 칸으로 이동한다.
S	Shoot : 전차가 현재 바라보고 있는 방향으로 포탄을 발사한다.

- 이동을 하려고 할 때, 만약 게임 맵 밖이라면 전차는 당연히 이동 X
- 발사 시, 포탄은 [벽돌로 만들어진 벽 or 강철로 만들어진 벽에 충돌] or게임 맵 밖으로 나갈 때까지 직진
- 벽에 부딪히면 포탄은 소멸하고, 부딪힌 벽이 벽돌로 만들어진 벽이라면 이 벽은 파괴되어 칸은 평지가 됨
- 강철로 만들어진 벽에 포탄이 부딪히거나 맵 밖으로 나가면, 아무 일도 일어나지 않는다.

= 초기 게임 맵 + 사용자가 넣을 입력이 순서대로 주어질 때, 모든 입력 후 맵의 상태를 구하기!
- 마지막 개판난 맵 상태를 출력하는 것
- 전차는 단 하나
- S, shoot 에 대한 *을 .으로 만드는 것

*/
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int H, W;
		cin >> H >> W;

		vector<vector<char>> map;

		map.assign(H, vector<char>(W));

		int tx, ty;
		for (int i = 0; i < H; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < s.size(); j++) {
				map[i][j] = s[j];
				// 전차 pos 기억

				if (s[j] == '<' || s[j] == '^' || s[j] == '>' || s[j] == 'v') {
					tx = i, ty = j;
				}
			}
		}

		int input_size;
		cin >> input_size;

		string s;
		cin >> s;

		for (int i = 0; i < s.size(); i++) {
			char c = s[i];
			if (c == 'U' || c == 'D' || c == 'L' || c == 'R') { // 이동
				switch (c) {
				case 'U':
					map[tx][ty] = '^';
					if (tx-1 < 0 || ty < 0 || tx-1 >= H || ty >= W) {
						break;
					}
					if (map[tx - 1][ty] == '.') {
						// 갈 수 있음 이동.
						map[tx - 1][ty] = '^';
						map[tx][ty] = '.';
						tx--;
					}
					break;
				case 'D':
					map[tx][ty] = 'v';
					if (tx + 1 < 0 || ty < 0 || tx + 1 >= H || ty >= W) {
						break;
					}
					if (map[tx + 1][ty] == '.') {
						// 갈 수 있음 이동.
						map[tx + 1][ty] = 'v';
						map[tx][ty] = '.';
						tx++;
					}
					break;
				case 'L':
					map[tx][ty] = '<';
					if (tx < 0 || ty -1 < 0 || tx >= H || ty -1 >= W) {
						break;
					}
					if (map[tx][ty-1] == '.') {
						// 갈 수 있음 이동.
						map[tx][ty-1] = '<';
						map[tx][ty] = '.';
						ty--;
					}
					break;
				case 'R':
					map[tx][ty] = '>';
					if (tx < 0 || ty + 1 < 0 || tx >= H || ty + 1 >= W) {
						break;
					}
					if (map[tx][ty + 1] == '.') {
						// 갈 수 있음 이동.
						map[tx][ty+1] = '>';
						map[tx][ty] = '.';
						ty++;
					}
					break;
				}
			}
			else if (c == 'S') {
				int dir;

				// 상 우 하 좌
				int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

				if (map[tx][ty] == '^') {
					dir = 0;
				}
				else if (map[tx][ty] == '>') {
					dir = 1;
				}
				else if (map[tx][ty] == 'v') {
					dir = 2;
				}
				else {
					dir = 3;
				}

				int nx = tx, ny = ty;
				while (true) {
					nx += dx[dir], ny += dy[dir];
					if (nx < 0 || ny < 0 || nx >= H || ny >= W) {
						break;
					}
					else if (map[nx][ny] == '#') {
						break;
					}
					else if (map[nx][ny] == '*') {
						map[nx][ny] = '.';
						break;
					}
					// 나머지: -, . 인 경우는 그냥 지나치기.
				}

			}
		}
		cout << "#" << test_case << " ";
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cout << map[i][j];
			}
			cout << endl;
		}

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

/*
25분 구현 완
-> 이전 좌표에 대한 평지 처리 
* SURSSSSUSLSRSSSURRDSRDS
***....
*-..#**
#<.****

1. S -> #이므로 X
***....
*-..#**
#<.****

U
***....
*-..#**
#^.****
- 물이라서 X

R
***....
*-..#**
#.>****
- 평지라서 이동 가능

S
***....
*-..#**
#.>.***
- 벽 뿌심

S

S

S
*/
```

---

# 결과 & 근거

**성공 (약 29분)**

- 전차 모양 자체가 방향 정보라서, 위치만 기억하면 이동과 발사를 모두 처리할 수 있다.
- 이동 명령은 이동 여부와 상관없이 방향(모양)을 먼저 바꾸고, 앞 칸이 맵 안의 평지일 때만 이동한다. 포탄은 평지와 물은 통과하고 벽이나 맵 밖에서 멈춘다.
- 이동량, 전차 모양, 명령 문자를 같은 방향 인덱스로 묶으면 U/D/L/R 네 블록을 복붙하지 않아도 된다.

```cpp
#include<iostream>
#include <vector>
#include <string>

using namespace std;

// 방향 인덱스: 0 = 상, 1 = 우, 2 = 하, 3 = 좌
// 같은 인덱스로 이동량(dx, dy), 전차 모양(tank), 명령 문자(cmd)를 묶어 둔다
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
char tank[4] = { '^', '>', 'v', '<' };
char cmd[4] = { 'U', 'R', 'D', 'L' };

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int H, W;
		cin >> H >> W;

		vector<vector<char>> map;
		map.assign(H, vector<char>(W));

		// 전차 위치(tx, ty)와 바라보는 방향(dir)을 입력 받을 때 기억
		int tx = 0, ty = 0, dir = 0;
		for (int i = 0; i < H; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < W; j++) {
				map[i][j] = s[j];
				for (int d = 0; d < 4; d++) {
					if (s[j] == tank[d]) {
						tx = i, ty = j, dir = d;
					}
				}
			}
		}

		int input_size;
		cin >> input_size;
		string s;
		cin >> s;

		for (int i = 0; i < input_size; i++) {
			char c = s[i];

			if (c == 'S') {
				// 포탄: 바라보는 방향으로 한 칸씩 직진
				int nx = tx, ny = ty;
				while (true) {
					nx += dx[dir], ny += dy[dir];
					if (nx < 0 || ny < 0 || nx >= H || ny >= W) break;   // 맵 밖 → 아무 일 없음
					if (map[nx][ny] == '#') break;                        // 강철 벽 → 소멸만
					if (map[nx][ny] == '*') {                             // 벽돌 벽 → 평지로 만들고 소멸
						map[nx][ny] = '.';
						break;
					}
					// '.'와 '-'(물)는 그냥 통과
				}
				continue;
			}

			// U/D/L/R: 명령 문자로 방향 인덱스를 찾는다 → 4개 case를 복붙할 필요가 없다
			for (int d = 0; d < 4; d++) {
				if (c == cmd[d]) dir = d;
			}

			// 1) 방향은 무조건 바꾼다 (이동 못 해도 모양은 바뀜)
			map[tx][ty] = tank[dir];

			// 2) 앞 칸이 맵 안이고 평지일 때만 이동
			int nx = tx + dx[dir], ny = ty + dy[dir];
			if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
			if (map[nx][ny] != '.') continue;

			map[tx][ty] = '.';          // 원래 자리는 평지
			map[nx][ny] = tank[dir];    // 새 자리에 전차
			tx = nx, ty = ny;
		}

		cout << "#" << test_case << " ";
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cout << map[i][j];
			}
			cout << '\n';
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
> **시뮬레이션 문제.** 
> 
> 전차 위치와 방향을 기억하고, 이동 명령은 방향을 먼저 바꾼 뒤 앞 칸이 평지일 때만 이동하며, 포탄은 벽이나 맵 밖을 만날 때까지 직진시킨다. 방향 인덱스 하나로 이동량, 모양, 명령을 묶는 게 핵심.
> 

### 알고리즘 분류

- 구현
- 시뮬레이션