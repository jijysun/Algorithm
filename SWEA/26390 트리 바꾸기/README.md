# 문제 소개

문제 사이트 링크

N개의 정점과 N-1개의 간선을 가진 연결 그래프 (트리) 가 있다. 당신은 이 그래프를 하나의 체인으로 바꾸려고 한다. 여기서 체인이라 함은, 모든 정점이 최대 2개의 서로 다른 간선과 연결되어 있는 트리를 뜻한다.

당신은 이를 위해 다음 작업을 몇 번 반복할 수 있다. 먼저, 이미 연결된 정점 X, Y 를 골라 X와 Y 사이의 간선을 끊는다. 다음으로, X에 연결되어 있지 않은 정점 Z를 골라 X와 Z를 연결한다.

필요한 작업 횟수의 최솟값을 구하여라.

**[입력]**

- 첫 번째 줄에 테스트 케이스의 수 TC가 주어진다.
- 이후 TC개의 테스트 케이스가 새 줄로 구분되어 주어진다.
- 각 테스트 케이스는 다음과 같이 구성되었다.
  - 첫 번째 줄에 정수 N이 주어진다. (1 ≤ N ≤ 300000)
  - 이후 N-1개의 줄에 간선이 잇는 두 정점의 번호 ui, vi 가 주어진다. (1 ≤ ui, vi ≤ N).
  - 주어지는 입력이 트리임이 보장된다.

**[출력]**

각 테스트 케이스 마다 한 줄씩, 문제의 정답을 출력하라.

```java
2
4
1 4
4 3
3 2
4
1 2
2 3
2 4

-> 
0
1
```

---

# 풀이 과정

- 연결 그래프, 무방향 그래프 이므로 간선 입력 시 모든 노드에 추가해주었다.
- 또한 다른 작업 없이 만약 최대 2 이상인 경우에 대해서는 그냥 제거 작업이 필요하다고만 cnt ++를 해주었다.

```cpp
// #include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std;
// https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=1&problemLevel=2&problemLevel=3&problemLevel=4&contestProbId=AZyNVrgKAVXHBIRj&categoryId=AZyNVrgKAVXHBIRj&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=4&pageSize=10&pageIndex=1

int tc;

vector<vector<int>> graph(300001, vector<int>(0));
void input() {

    cin >> tc;

    for (int i = 0; i < tc; i++) {
        graph.clear();
        int n ;
        cin >> n;

        graph.resize(n+1);
        // cout << graph.size() << endl;

        for (int j = 0; j < n-1; j++) {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y),  graph[y].push_back(x);

            // 그냥 그 노드의 연결 수가 최대 2를 넘으면 cnt ++?
        }

        int cnt =0;
        for (int j = 1; j<= n; j++) {
            if (graph[j].size() >2) {
                cnt ++;
            }
        }

        cout << cnt << '\n';
    }

}

void solution() {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input(), solution();
    return 0;
}

```

---

# 결과 & 근거

- 몇 개의 테스트 케이스만 성공했다. (2/17 성공)
- 아마 필요한 최소 작업 횟수가 필요한 관계여서 지금의 코드로는 틀렸다라고 생각된다.
  - 

### 알고리즘 분류

-