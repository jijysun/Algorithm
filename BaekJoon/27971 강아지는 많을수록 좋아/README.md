# 27971 강아지는 많을수록 좋다 (시간초과)

# 문제 소개

[문제 사이트 링크](https://www.acmicpc.net/problem/27971)

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞힌 사람 | 정답 비율 |
| --- | --- | --- | --- | --- | --- |
| 2 초 | 1024 MB | 1571 | 717 | 581 | 45.284% |

## 문제

마법소녀 마도카의 고양이에 깊은 감명을 받은 마법소녀 호무라는 자신도 마법을 이용하여 강아지 $N$마리를 집에서 키우기로 결심했다!

호무라는 한 번의 행동에서 다음 2가지 마법 중 하나를 선택하여 사용한다. 가장 처음에는 호무라의 집에 강아지가 존재하지 않는다.

- A-생성 마법: 강아지 A마리를 호무라의 집에 생성한다.
- B-생성 마법: 강아지 B마리를 호무라의 집에 생성한다.

그러나 미숙한 마법 사용은 호무라에게 추가적인 제약 사항을 주게 되었다. 만약 호무라의 방에 생성된 강아지의 수가 M개의 닫힌구간들 [L_1,R_1],[L_2,R_2], … [L_M,R_M] 중 하나 이상에 포함되게 된다면, 그 즉시 방에 생성된 모든 강아지가 사라지게 된다!

이를 명심하면서, 호무라는 위의 2가지 마법을 적절히 사용하여, 최소의 행동 횟수로 호무라의 집에 **정확히** N마리의 강아지가 있도록 만들고 싶다. 계산을 어려워하는 호무라를 위해 최소의 행동 횟수를 계산해주자!

## 입력

첫 번째 줄에 키우기를 원하는 강아지의 수 N (2\leq N\leq 100\,000)$, 제약 사항에 해당하는 닫힌구간의 개수 M (1≤M≤100), 그리고 A와 B (1≤ A,B≤ N)가 띄어쓰기로 구분되어 주어진다. 그 다음 M줄에 걸쳐서, 각 줄에 제약 사항에 해당하는 닫힌구간의 양 끝점이 주어진다. 1≤i≤M에 대하여 L_i와 R_i는 1 이상 N-1 이하의 정수이며,L_i≤R_i이다.

## 출력

첫 번째 줄에 **정확히** $N$마리의 강아지를 호무라의 집에 들일 수 있는 최소의 행동 횟수를 출력한다. 만약 불가능하다면 $-1$을 출력한다.

---

# 초기 접근 방법

이전 값 활용하는 DP or 누적합

- 입력받은 A와 B 중 큰 값을 위주로 방정식을 세운다?

근데 추가적으로 순서가 중요하다.

dp[i] 

- = i 번째 마법을 사용했을 때의 강아지의 수
- = dp[i-1] + 구간에 속하지 않으면서 최소 횟수에 다가가도록 하는 A or B의 합

그리고 만약 해당되는 A와 B를 찾았을 때의 검사를 해야 한다. 즉 각각 A와 B를 나열했을 때 구간에 속하는 지 검사해야 한다.

- N*N 2차원 배열을 만들어서 구간에 속했는지 검사?
- DP 에다가 그래프 이론까지 같이 있는 건가?

약간 그런 느낌이지 않을까

- DFS나 BFS 같은 그래프 탐색과 재귀호출이 필요하다
    - 0부터 시작해서 모든 경우의 수를 노드 처럼 방문한다
    - 방문 가능한 경우 재귀 호출, 방문 불가능한 경우 스킵 같은 식으로
- DP 같은 동적 프밍이나, 누적합이 필요하다.
    - 이게 제일 문제인데,

---

# 풀이 과정

```cpp
#include <iostream>
#include <regex>

using namespace std;

int n, m, a, b, answer, checked=false;

bool visited[100001];
int sector [100001];
vector<pair<int, int>> arr; // 어쨌든 피해야 하는 요소임.

void input() {
    cin >> n >> m >> a >> b;

    for (int i = 0; i<m; i++) {
        int a1, a2;
        cin >> a1 >> a2;

        /*for (int j = a1; j<=a2; j++) { // 이게 엄청 많아서 시간초과되는 듯?
            sector[j] = 1;
        }*/

        arr.push_back({a1, a2});
    }

    if (a>b) {
        int temp = a;
        a = b;
        b = temp;
    }
}

void dfs (int dog, int cnt) {
    // cout << "dog: " << dog <<'\n';

    if (dog == n) {
        answer = cnt;
        checked = true;
        return;
    }
    if (dog + a > n) { // 작은 수 더해서 넘어가면 지금 경로는 쓸모 없다.
        return;
    }
    if (dog + b <= n) {
        // 검사 로직
        bool search = false;
        for (int j = 0; j<arr.size(); j++) {
            if (arr[j].first <= sector[dog+b] && sector[dog+b] <= arr[j].second ) {
                search = true;
            }
        }
        if (!search) {
            visited[dog+b] = true;
            dfs(dog+b, cnt+1);
        }
    }
    if (dog + a <= n) { // not else if
        bool search = false;
        for (int j = 0; j<arr.size(); j++) {
            if (arr[j].first <= sector[dog+a] && sector[dog+a] <= arr[j].second ) {
                search = true;
            }
        }
        if (!search) {
            visited[dog+a] = true;
            dfs(dog+a, cnt+1);
        }
    }
}

void solution() {
    dfs(0, 0);
    // 일단 이전 값 활용하는 DP가 보여

    // 최소 횟수이어야 되니까 큰 수 위주로 더해가는 느낌
    // cout <<"\n\n\n-------\n"<<'\n';
    if (checked) {
        cout << answer << '\n';
    }
    else {
        cout << "-1" <<'\n';
    }

}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    input();
    solution();

    return 0;
}

```

---

# 결과 & 근거

- 접근은 좋았던 것 같다.
    - 2차원 배열이나 재귀 호출 비스무리한 탐색이 필요하기에 그래프 탐색을 떠올렸던 건 좋았던 것 같다.
- 시간 초과로 실패했다.
    - 아마 DFS에다가 A와 B 경우 까지 배로 탐색 수가 증가해서 시간 초과가 발생한 듯 하다.
- https://velog.io/@lemythe423/BOJ-27971.-%EA%B0%95%EC%95%84%EC%A7%80%EB%8A%94-%EB%A7%8E%EC%9D%84%EC%88%98%EB%A1%9D-%EC%A2%8B%EB%8B%A4-DP
    - 그래프 탐색에서는 그래도 DFS 보다는 BFS가 시간적 효율이 좋은 건 알고 있었는데 워낙 DFS에 익숙해져서..
    - 열심히 연습해야겠다.

### 알고리즘 분류

- 다이나믹 프로그래밍
- 그래프 이론
- 그래프 탐색
- 너비 우선 탐색