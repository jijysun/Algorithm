# SWEA 2814, 최장 경로 (성공)

# 문제 소개

[문제 사이트 하이퍼링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=2&problemLevel=3&contestProbId=AV7GOPPaAeMDFAXB&categoryId=AV7GOPPaAeMDFAXB&categoryType=CODE&problemTitle=&orderBy=RECOMMEND_COUNT&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=3)

N개의 정점과 M개의 간선으로 구성된 가중치가 없는 무방향 그래프에서의 최장 경로의 길이를 계산하자.

정점의 번호는 1번부터 N번까지 순서대로 부여되어 있다.

경로에는 같은 정점의 번호가 2번 이상 등장할 수 없으며, 경로 상의 인접한 점들 사이에는 반드시 두 정점을 연결하는 간선이 존재해야 한다.

경로의 길이는 경로 상에 등장하는 정점의 개수를 나타낸다.

**[입력]**

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 두 개의 자연수 N M(1 ≤ N ≤ 10, 0 ≤ M ≤ 20)이 주어진다.

두 번째 줄부터 M개의 줄에 걸쳐서 그래프의 간선 정보를 나타내는 두 정수 x y(1 ≤ x, y ≤ N)이 주어진다.

x와 y는 서로 다른 정수이며, 두 정점 사이에 여러 간선이 존재할 수 있다.

**[출력]**

각 테스트 케이스마다 ‘#x ’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고, 그래프에서의 최장 경로의 길이를 출력한다.

```cpp
입력
2
1 0
3 2
1 2
3 2
출력
#1 1
#2 3
```

---

# 풀이 과정

- 정점을 두 번 이상 지날 수 없는 최장 경로라서, 모든 정점에서 DFS를 시작해 들어갈 때 visited를 켜고 나올 때 끄는 백트래킹으로 풀었다.
- 깊이(지나온 정점 수)가 최댓값보다 크면 그때마다 갱신했다.
- 간선이 없으면 정점 하나만으로 길이 1이니까 바로 1을 출력했다.

```cpp
#include<iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
 
int answer = 0;
 
vector<vector<int>> arr;
vector<int>visited;
void dfs(int start, int depth) {
     
    if (depth > answer) {
        answer = depth;
    }
 
    for (int i = 0; i < arr[start].size(); i++) {
        int nx = arr[start][i];
        if (visited[nx]) continue;
         
        visited[nx] = 1;
        dfs(nx, depth+1);
        visited[nx] = 0;
    }
     
}
int main(int argc, char** argv)
{
    int test_case, T;
 
    cin >> T;
 
    for (test_case = 1; test_case <= T; ++test_case) {
 
        int n, m;
        cin >> n >> m;
 
        if (m == 0) {
            cout << "#" << test_case << " 1" << endl;
            continue;
        }
        arr.assign(n + 1, vector<int>());
         
 
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            arr[a].push_back(b), arr[b].push_back(a);
        }
 
        for (int i = 1; i < n; i++) {
            // 모든 정점 dfs 탐색.
            visited.assign(n + 1, 0);
             
            visited[i] = 1;
            dfs(i, 1);
        }
 
 
        cout << "#" << test_case << " " << answer << endl;
        answer = 0;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
```

---

# 결과 & 근거

**성공**

- N ≤ 10이라 모든 정점에서 시작해 DFS 백트래킹으로 경로를 전부 펼쳐봐도 된다. visited는 재귀 전에 켜고 재귀 후에 꺼야 한다.
- 시작점 반복을 `i < n`으로 쓰면 N = 1일 때 한 번도 안 돌아서 0이 나온다. 이걸 `m == 0` 분기가 가리고 있었다. `i <= n`으로 고치면 분기 없이 모든 경우가 처리된다.

```cpp
#include<iostream>
#include <vector>

using namespace std;

int answer = 0;
vector<vector<int>> arr;   // 인접 리스트 (무방향 → 양쪽에 추가)
vector<int> visited;       // 지금 "경로 위에" 있는 정점 = 1

// start까지 왔고, 지금까지 경로 길이(정점 수)가 depth
void dfs(int start, int depth) {
	if (depth > answer) answer = depth;   // 지나가는 길이마다 최장 갱신

	for (int i = 0; i < arr[start].size(); i++) {
		int nx = arr[start][i];
		if (visited[nx]) continue;   // 이미 경로에 있는 정점은 다시 못 감
		visited[nx] = 1;             // 마킹 (재귀 전)
		dfs(nx, depth + 1);
		visited[nx] = 0;             // 리셋 (재귀 후) → 다른 경로에서 다시 쓸 수 있게
	}
}

int main(int argc, char** argv)
{
	int test_case, T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
		int n, m;
		cin >> n >> m;

		// 전역 변수는 테스트 케이스 "시작"에서 초기화 → continue 등으로 건너뛸 일이 없다
		answer = 0;
		arr.assign(n + 1, vector<int>());

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}

		// 정점 1 ~ n 전부를 시작점으로 (i <= n)
		// → 간선이 0개여도 dfs(i, 1)에서 answer = 1이 되므로 특수 분기가 필요 없다
		for (int i = 1; i <= n; i++) {
			visited.assign(n + 1, 0);
			visited[i] = 1;
			dfs(i, 1);
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
> **그래프 DFS 백트래킹 문제.** 
> 
> 모든 정점을 시작점으로 DFS를 돌며 visited를 들어갈 때 켜고 나올 때 꺼서 같은 정점을 반복하지 않는 경로를 전부 탐색하고 최장 길이를 갱신한다. N ≤ 10이라 전수 탐색이 가능하다는 판단과 마킹·리셋 위치가 핵심.
> 

### 알고리즘 분류

- 그래프
- DFS
- 백트래킹