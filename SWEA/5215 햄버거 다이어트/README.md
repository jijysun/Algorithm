# SWEA 5215, 햄버거 다이어트 (실패)

# 문제 소개

[문제 사이트 링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=3&problemLevel=4&contestProbId=AWT-lPB6dHUDFAVT&categoryId=AWT-lPB6dHUDFAVT&categoryType=CODE&problemTitle=&orderBy=INQUERY_COUNT&selectCodeLang=ALL&select-1=4&pageSize=10&pageIndex=2)

평소 햄버거를 좋아하던 민기는 최근 부쩍 늘어난 살 때문에 걱정이 많다.그렇다고 햄버거를 포기할 수 없었던 민기는 햄버거의 맛은 최대한 유지하면서 정해진 칼로리를 넘지 않는 햄버거를 주문하여 먹으려고 한다.

민기가 주로 이용하는 햄버거 가게에서는 고객이 원하는 조합으로 햄버거를 만들어서 준다.하지만 재료는 미리 만들어서 준비해놓기 때문에 조합에 들어가는 재료를 잘라서 조합해주지는 않고, 재료를 선택하면 준비해놓은 재료를 그대로 사용하여 조합해준다. 

민기는 이 가게에서 자신이 먹었던 햄버거의 재료에 대한 맛을 자신의 오랜 경험을 통해 점수를 매겨놓았다.민기의 햄버거 재료에 대한 점수와 가게에서 제공하는 재료에 대한 칼로리가 주어졌을 때,민기가 좋아하는 햄버거를 먹으면서도 다이어트에 성공할 수 있도록 정해진 칼로리 이하의 조합 중에서 민기가 가장 선호하는 햄버거를 조합해주는 프로그램을 만들어보자.

(단 여러 재료를 조합하였을 햄버거의 선호도는 조합된 재료들의 맛에 대한 점수의 합으로 결정되고, 같은 재료를 여러 번 사용할 수 없으며, 햄버거의 조합의 제한은 칼로리를 제외하고는 없다.)

**[입력]**

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 재료의 수, 제한 칼로리를 나타내는 N, L(1 ≤ N ≤ 20, 1 ≤ L ≤ 104)가 공백으로 구분되어 주어진다.

다음 N개의 줄에는 재료에 대한 민기의 맛에 대한 점수와 칼로리를 나타내는 Ti, Ki(1 ≤ Ti ≤ 103, 1 ≤ Ki ≤ 103)가 공백으로 구분되어 주어진다.

**[출력]**각 줄마다 "#T" (T는 테스트 케이스 번호)를 출력한 뒤, 주어진 제한 칼로리 이하의 조합중에서 가장 맛에 대한 점수가 높은 햄버거의 점수를 출력한다.

```cpp
입력 
1        //Test Case 갯수
5 1000   //Test Case #1, N = 5, L = 1000
100 200  //Test Case #1, 첫번째 재료 정보
300 500
250 300
500 1000
400 400

출력
-> 
#1 750
```

---

# 풀이 과정

- 처음에는 동일 문제가 반복되는 것을 통해 격자 DP로 진행했다
- 이후 0-1 배낭 문제인 건 알아차렸다. 매핑은 그대로다.
    - 배낭 용량 = 제한 칼로리 / 물건 = 재료 / 무게 = 칼로리 / 가치 = 점수
    - "같은 재료를 여러 번 사용할 수 없으며" = 각 물건 1번만 = 0-1 배낭
- 그런데 상태 정의에서 막혀 43분에 스킵했다.

```cpp
#include <bits/stdc++.h>
#include<iostream>

using namespace std;

vector<int> dp;
vector<pair<int,int>> combi; // 재료의 점수, 칼로리
int max_score = 0;
int main(int argc, char** argv) {

	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int cnt, max_cal;
		cin >> cnt >> max_cal;
		combi.clear();
		dp.assign(cnt+1,0);

		for (int i = 0; i < cnt; ++i) {
			int a, b;
			cin >> a >> b;
			combi.push_back(make_pair(a,b));
		}

		for (int i = 1; i < cnt; ++i) {
			pair<int, int> cur = combi[i]; // 점수, 칼로리
			int cur_cal = cur.second;
			dp[i-1] = combi[i-1].first;

			for (int j = i; j < cnt; ++j) {
				pair<int, int> next = combi[j];

				if (cur_cal + next.second <= max_cal) {
					// dp[i] = 현 재료를 무조건 골랐을 때의 누적 최대값.
					dp[i]=max(dp[i], dp[i-1] + next.first);
					cur_cal += next.second;
					max_score = max(max_score, dp[i]);
				}
			}
		}

		cout << "#" << test_case << " " << max_score  << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
```

---

# 결과 & 근거

- 실패 (43분, 상태 정의에서 막혀 사실상 미구현)
- 0-1 배낭임은 알아차렸으나 dp[i][j] 의 두 인덱스를 둘 다 재료 번호로 잡아 막혔다.
    - 배낭의 두 번째 인덱스는 "남은 자원(칼로리)"이다.
- 점화식은 "담는다 / 안 담는다" 두 갈래의 max 이고, 항상 위 행만 참조한다.

```cpp
#include <bits/stdc++.h>
#include<iostream>

using namespace std;

vector<vector<int>> dp;
vector<int> score, cal;
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	for(test_case = 1; test_case <= T; ++test_case) {
		int cnt, c;
		cin >> cnt >> c;
		dp.assign(cnt+1, vector<int>(c+1, 0));
		score.assign(cnt+1, 0),
		cal.assign(cnt+1, 0);

		for (int i = 0; i<cnt; i++) {
			cin >> score[i] >> cal[i];
		}

		for (int i = 1; i<=cnt; i++) { // 재료 내 순회
			for (int j = 0; j<=c; j++) { // 가능 자원 내 순회
				int not_take = dp[i-1][j];
				int take = -1;
				if (j >= cal[i-1]) {
					take = dp[i-1][j-cal[i-1]] + score[i-1];
				}
				dp[i][j] = max (not_take, take);
			}
		}
		cout << "#" << test_case << " " << dp[cnt][c] << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
```

### 알고리즘 분류

- DP
- 0-1 배낭 (Knapsack)
- 비트마스크 완전탐색 (대안 해법)