# SWEA 24524, 레벨업 (성공)

# 문제 소개

[문제 사이트 하이퍼링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=2&problemLevel=3&contestProbId=AZelvp3qmdDHBISV&categoryId=AZelvp3qmdDHBISV&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=2)

1차원 수직선 상에서 진행되는 게임이 있다.

게임에는 N개의 체크포인트가 있으며, 당신은 1번 체크포인트에서 시작하여 2번, 3번, …, N-1번 체크포인트를 순서대로 방문한 뒤, N번 체크포인트에 도착해야 레벨을 하나 올릴 수 있다. 

그런데, 게임사에서 특별히 이벤트를 개최하여 2번, 3번, …, N-1번 체크포인트 중 정확히 한 곳을 방문하지 않아도 된다.

이때, 당신이 레벨을 올리기 위해 이동해야 할 거리의 최솟값을 구하는 프로그램을 작성하라.i번 체크포인트의 좌표는 Xi로 표기한다. 

i번 체크포인트에서 j번 체크포인트로 가기 위해 이동해야 하는 거리는 |Xi - Xj|이다.

**[입력]**

첫 번째 줄에 테스트 케이스의 수 T가 주어진다. 각 테스트 케이스는 두 개의 줄로 이루어진다.

첫 번째 줄에는 체크포인트의 수 N (3 ≤ N ≤ 50)이 주어진다.

두 번째 줄에는 각 체크포인트의 좌표를 나타내는 N개의 정수 X1, X2, ···, XN (-100 ≤ Xi ≤ 100)이 주어진다.

모든 체크포인트의 좌표는 서로 다르다.

**[출력]**

각 테스트 케이스마다, 당신이 레벨을 올리기 위해 이동해야 할 거리의 최솟값을 한 줄에 하나씩 출력한다.

```cpp
입력
3
5
1 -1 2 -2 3
3
1 2 3
3
1 -1 3

출력
6
2
2
```

---

# 풀이 과정

- 1번과 N번을 제외한 가운데 체크포인트 중 하나를 빼면 된다고 이해했다.
- 처음엔 이웃한 두 점 사이 거리가 가장 큰 쪽을 빼는 방식으로 짰는데 28/68이 나왔다.
- 25분쯤 무식하게 하나씩 빼보는 완전 탐색으로 바꿔서 29분에 성공했다.

```cpp
#include<iostream>
#include <vector>

using namespace std;

/*
1차원 수직선 게임
- N개의 체크포인트 + 1부터 순서대로 방문 -> N번 cp에 도착해야 레벨업
- 게임사에서 특별히 이벤트를 개최하여 2번, 3번, …, N-1번 체크포인트 중 정확히 한 곳을 방문하지 않아도 된다.
- 당신이 레벨을 올리기 위해 이동해야 할 거리의 최솟값을 구하는 프로그램

i번 체크포인트의 좌표는 Xi로 표기한다.
i번 체크포인트에서 j번 체크포인트로 가기 위해 이동해야 하는 거리는 |Xi - Xj|이다.

5 (3 ≤ N ≤ 50)
1 -1 2 -2 3
- 이 중 1개를 건너띌 수 있다는 뜻
- 지문이 i-j라 했는데 여기선 j-i라 해버리네. 그럼 그렇게 해야지 뭐...
- X4를 방문하지 않으면 총 이동 거리는 |X2 - X1| + |X3 - X2| + |X5 - X3| = 2+3+1 = 6으로 최소
-1 -1 + 2 - -1 + 3 - 2 = 2 + 3 + 1 = 6

즉 1과 N 제외 중간 하나 삭제
- 길이가 3인 경우는 중간 빼먹으면 그만.
- 길이가 4 이상 부터 구현

pair<int, int> + i=1 ~ n-1 까지 해서 pair{i, i+1} 도입 + max_pair 갱신
max_pair 정보로 하나 스킵하기?

*/

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	int n;
	vector<pair<int, int>> cpv;
	for (test_case = 1; test_case <= T; ++test_case) {

		cin >> n;
		vector<int> cp;
		for (int i = 0; i < n; i++) {
			int c;
			cin >> c;
			cp.push_back(c);
		}

		if (cp.size() == 3) {
			cout << abs(cp[0] - cp[2]) << endl;
			continue;
		}
		else {
			int sum = 0;
			int min_diff = 999999;
			for (int i = 1; i < n - 1; i++) {
				sum = 0;
				int pre = 0;
				for (int j = 1; j < n; j++) {
					if (j == i) continue;
					else {
						sum += abs(cp[pre] - cp[j]);
						pre = j;
					}
				}

				if (min_diff >= sum) {
					min_diff = sum;
				}
			}
			cout << min_diff << endl;
			
		}

		//int max_diff = 0, max_idx = 0;
		//for (int i = 0; i < cp.size() - 1; i++) {
		//	cpv.push_back({ cp[i], cp[i + 1] });
		//	if (abs(cp[i] - cp[i + 1]) >= max_diff) {
		//		max_idx = i, max_diff = abs(cp[i] - cp[i + 1]);
		//	}
		//}

		//vector<int> new_cp;
		//for (int i = 0; i < cp.size(); i++) {
		//	if (i == max_idx)continue;
		//	new_cp.push_back(cp[i]);
		//}

		///*for (int i = 0; i < new_cp.size(); i++) {
		//	cout << new_cp[i] << " ";
		//} cout << endl;*/

		//int sum = 0;
		//for (int i = 0; i < new_cp.size() - 1; i++) {
		//	sum += abs(new_cp[i] - new_cp[i + 1]);
		//}
		//cout << sum << endl;

	}

	/*
	19분 구현 제출: 28/68
	25분 무식하게 구현 시작.
	29분 완전 탐색으로 구현 성공.
	*/
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
/*

1 2 3 100
= 1 1 97 -> 99이다
= 근데 2를 빼면 2 97 = 99
= 근데 3을 빼면 2 97 = 99
*/
```

---

# 결과 & 근거

**성공 (29분)**

- 점 하나를 뺐을 때 줄어드는 거리는 가장 긴 간선 하나가 아니라 양옆 세 점의 관계로 정해져서, 그리디는 틀렸다.
- N ≤ 50이라 가운데 점을 하나씩 빼고 전체 거리를 다시 계산해도 충분하다. N = 3도 같은 루프로 처리된다.

```cpp
// 더 깔끔한 코드
#include <iostream>
#include <vector>
#include <cstdlib>
#include <climits>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int n;
		cin >> n;
		vector<int> cp(n);
		for (int i = 0; i < n; i++) cin >> cp[i];

		// 1번과 N번은 반드시 방문 → 건너뛸 수 있는 건 가운데(인덱스 1 ~ n-2) 중 하나
		// N ≤ 50이라 "하나씩 빼보고 전체 거리를 다시 계산"해도 50 x 50 = 2,500번
		int min_diff = INT_MAX;
		for (int skip = 1; skip < n - 1; skip++) {
			int sum = 0, pre = 0;           // pre = 직전에 방문한 체크포인트
			for (int j = 1; j < n; j++) {
				if (j == skip) continue;    // 이번에 건너뛰는 점
				sum += abs(cp[pre] - cp[j]);
				pre = j;
			}
			min_diff = min(min_diff, sum);
		}

		cout << min_diff << '\n';   // 이 문제는 "#t" 없이 숫자만 출력
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

```

> 
> 
> 
> ***한 줄 요약***
> 
> 완전 탐색 구현 문제. 
> 
> 가운데 체크포인트를 하나씩 빼보며 나머지를 순서대로 방문하는 총 거리를 계산하고 최솟값을 구한다. N ≤ 50이라 그리디 대신 전수로 가는 판단이 핵심
> 

### 알고리즘 분류

- 브루트포스
- 구현