# SWEA 5105, 미로의 거리 (성공)

# 문제 소개

[문제 사이트 하이퍼링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=2&problemLevel=3&contestProbId=AWTVoHTab5gDFAVT&categoryId=AWTVoHTab5gDFAVT&categoryType=CODE&problemTitle=&orderBy=INQUERY_COUNT&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=10)

이때 최소 몇 개의 칸을 지나면 출발지에서 도착지에 다다를 수 있는지 알아내는 프로그램을 작성하시오.

NxN 크기의 미로에서 출발지 목적지가 주어진다.

경로가 있는 경우 출발에서 도착까지 가는데 지나야 하는 최소한의 칸 수를, 경로가 없는 경우 0을 출력한다.

다음은 5x5 미로의 예이다. 1은 벽, 0은 통로를 나타내며 미로 밖으로 벗어나서는 안된다.

13101
10101
10101
10101
10021

마지막 줄의 2에서 출발해서 0인 통로를 따라 이동하면 맨 윗줄의 3에 5개의 칸을 지나 도착할 수 있다.

**[입력]**

첫 줄에 테스트 케이스 개수 T가 주어진다.  1<=T<=50

다음 줄부터 테스트 케이스의 별로 미로의 크기 N과 N개의 줄에 걸쳐 미로의 통로와 벽에 대한 정보가 주어진다. 5<=N<=100

0은 통로, 1은 벽, 2는 출발, 3은 도착이다.

**[출력]**

각 줄마다 "#T" (T는 테스트 케이스 번호)를 출력한 뒤, 답을 출력한다.

```cpp
3
5
13101
10101
10101
10101
10021
5
10031
10111
10101
10101
12001
5
00013
01110
21000
01111
00000

출력
#1 5
#2 5
#3 0
```

---

# 풀이 과정

- BFS로 방문하는 칸마다 현재 거리 + 1을 기록하면 된다고 생각했다.
- 입력용 배열과 BFS 거리용 배열을 따로 두었다.
- 16분 30초에 구현했지만 경로가 없는 경우에 오류가 났다. `push_back(j)`를 `push_back(s[j]-'0')`로, `bfs[nx][ny] == 1`을 `arr[nx][ny] == 1`로 고쳐서 34분에 예제를 통과했다 (파이썬 전용이라 가채점).

```cpp
#include<iostream>
#include <bits/stdc++.h>

using namespace std;

/*
 * N*N해서 출발지, 목적지가 주어짐.
 * - 최소 몇 개의 칸을 지나면 출발지에서 도착지에 다다를 수 있는지 알아내는 프로그램을 작성!
 * - 1은 벽, 0은 통로, 2는 출발지, 3은 도착.
 *
 * 문제는 쉬움 BFS + 그 방문 지역 마다 현 값에 + 1 하는
 * - 지금 예시로는 경로가 하나밖에 없지만 무조건 다 열려있는 경우도 존재
 * - bfs용 arr 변수, 0~3을 참조하는 입력용 vector 변수가 필요하다.
 *
 * 대충 4로 예시를 들면
 * 1111
 * 1113
 * 1211
 * 1111
 *
 * 0000
 * 0003
 * 0200
 * 0000
 *
 * 0000
 * 0103
 * 1210
 * 0100
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
		int n;
		cin >> n;
		// 최대 N은 100 이므로 최악의 경우 어찌저찌
		vector<vector<int>> arr(n), bfs(n, vector<int>(n, 99999));

		pair<int, int> start, dest;

		for(int i = 0; i < n; ++i) {
			string s;
			cin >> s;

			for (int j = 0; j<s.size(); j++) {
				if (s[j] == '2') {
					start.first = i;
					start.second = j;
				}
				else if (s[j] == '3') {
					dest.first = i;
					dest.second = j;
				}
				arr[i].push_back(s[j]-'0');
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cout << arr[i][j] << " ";
			}
			cout << endl;
		} cout << endl;

		// BFS.
		int dx[4] = {0, 1, 0, -1}, dy[4] ={1, 0, -1, 0};

		bfs[start.first][start.second] = 0;
		bfs[dest.first][dest.second] = 99999;

		queue<pair<int, int>> q;
		q.push(start);
		while (!q.empty()) {
			pair<int, int> p = q.front();
			q.pop();

			for (int i = 0; i < 4; ++i) {
				int nx = p.first + dx[i], ny = p.second + dy[i];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue; // 배열 밖인 경우 skip
				if (arr[nx][ny] == 1) continue;

				if (bfs[nx][ny] > bfs[p.first][p.second]+1 ) { // 갈 수 있는데 값이 존재하며, 그 값보다 작은 경로 값이면 갱신
					bfs[nx][ny] = bfs[p.first][p.second]+1;
					q.push(make_pair(nx, ny));
				}
			}

		}

		if (bfs[dest.first][dest.second] == 99999) {
			// 경로 자체가 없는 것.

			/*for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					cout << bfs[i][j] << " ";
				}
				cout << endl;
			} cout << endl;*/
			cout << "#" << test_case << " 0" << endl;
		}
		else {
			/*for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					cout << bfs[i][j] << " ";
				}
				cout << endl;
			} cout << endl;*/
			cout << "#" << test_case << " " << bfs[dest.first][dest.second]-1 << endl;
		}
	}

	/*
	 * 16분 30초 구현완, 지금 경로가 없는 경우에 한해 오류 발생.
	 * 25분 arr[i].push_back(j); 로 실수 -> arr[i].push_back(s[j]-'0');
	 * 34분  if (bfs[nx][ny] == 1) continue; 라고 착각 -> if (arr[nx][ny] == 1) continue;
	 */

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
```

---

# 결과 & 근거

**가채점 예제 통과 (34분). BFS 판정은 정확, 디버그 출력 제거 필요**

- 가중치 없는 격자 최단 거리라서 BFS가 맞고, "지나는 칸 수"는 도착 거리 − 1이다.
- 입력 미로를 그대로 출력하는 디버그 루프가 남아 있어서, 그대로 제출하면 오답이다.
- 배열 이름을 `maze`, `dist`처럼 역할대로 지으면 `arr`↔`bfs` 혼동을 막을 수 있다.

> 
> 
> 
> ***한 줄 요약***
> 
> 격자 BFS 최단 거리 문제. 
> 
> 출발 칸부터 BFS로 각 칸의 거리를 기록하고, 도착 거리 − 1을 "지나는 칸 수"로 출력하며 못 가면 0이다. 입력 배열과 거리 배열을 역할대로 구분하는 것과, 출발·도착을 빼는 −1이 핵심.
> 

### 알고리즘 분류

- BFS
- 그래프 탐색 (격자)