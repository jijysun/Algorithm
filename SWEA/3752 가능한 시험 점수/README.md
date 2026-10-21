# SWEA 3752, 가능한 시험 점수 (실패)

# 문제 소개

[문제 사이트 하이퍼링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWHPkqBqAEsDFAUn)

영준이는 학생들의 시험을 위해 N개의 문제를 만들었다.

각 문제의 배점은 문제마다 다를 수 있고, 틀리면 0점 맞으면 배점만큼의 점수를 받게 된다.

학생들이 받을 수 있는 점수로 가능한 경우의 수는 몇 가지가 있을까?

예를 들어, 첫 번쨰 Testcase의 경우, 총 문제의 개수는 3개이며 각각의 배점은 2, 3, 5점이다

가능한 시험 점수의 경우의 수를 살펴보면 0, 2, 3, 5, 7, 8, 10의 7가지가 있다.

두 번째 Testcase의 경우, 총 문제의 개수는 10개이며 각각의 배점은 모두 1점이다.

가능한 시험점수의 경우의 수를 살펴보면 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10으로 모두 11가지이다.

**[입력]**

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 자연수 N(1 ≤ N ≤ 100)이 주어진다.

두 번째 줄에는 각 문제의 배점을 의미하는 N개의 자연수가 공백으로 구분되어 주어진다. 배점은 1이상 100이하의 자연수이다.

**[출력]**

각 테스트 케이스마다 학생들이 받을 수 있는 점수의 경우의 수를 출력한다.

```cpp

2
3
2 3 5
10
1 1 1 1 1 1 1 1 1 1
....
#1 7
#2 11
```

---

# 풀이 과정

- 간단한 조합 문제라 생각했다.
- 예시 문제만 통과하고, 바로 TLE.

```cpp

/*
 * 시험에 N개 문제
 * - 배점이 다름.
 * - 학생들이 받을 수 있는 점수로 가능한 경우의 수는 몇 가지?
 *
 * 1. 문제의 개수는 3개이며 각각의 배점은 2, 3, 5
 * - 0, 2, 3, 5, 7, 8, 10의 7가지
 *
 * 2. 10개이며 각각의 배점은 모두 1
 * - 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
 *
 * 완벽한 조합 문제?
 */

int n;

vector<int> score, visited;
int total;
vector<int> total_visited;

int cnt;

vector<int>combi;
void combination (int start) {
	if (combi.size() == score.size()) {
		return;
	}

	for (int i = start; i < score.size(); ++i) {

		if (visited[i] != 0) continue;
		if (total_visited[total+score[i]] == 0) {
			cnt ++;
		}

		visited[i] = 1;
		total_visited[total+score[i]] = 1;
		total += score[i];
		combi.push_back(score[i]);

		/*for (int c : combi) {
			cout << c << " ";
		} cout << endl;
		cout << "total: " << total << endl;*/

		combination(start+1);

		combi.pop_back();
		visited[i] = 0;
		total-=score[i];

	}

}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case) {
		cin >> n;

		cnt = 1;
		score.clear();
		visited.assign(101, 0);
		total_visited.assign(5052, 0);

		for (int i = 0; i < n; ++i) {
			int a;
			cin >>  a;
			score.push_back(a);
		}

		combination(0);
		cout << "#" << test_case << " " << cnt << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
```

---

# 결과 & 근거

- 조합으로 풀려고 어떻게든 노력하다 실패
- 정확히는 DP 흐름이다
    - 각 점수를 더해서 역순으로 내려온다.
    - 만약 그 점수가 가능한 경우에 대해서는 “가능”을 표시한다
- 전부 확인이 끝난 경우, 1을 count 해서 끝낸다.

```cpp
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int T; cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int n; cin >> n;
        vector<int> score(n);
        for (auto& x : score) cin >> x;

        /* 세는 대상은 "조합" 이 아니라 "점수" 다.
           조합은 2^100 가지지만, 점수는 0 ~ (합) 사이의 정수뿐이므로 최대 10,001 가지.
           그래서 "각 점수가 도달 가능한가" 를 bool 배열로 관리한다.               */
        int maxSum = accumulate(score.begin(), score.end(), 0);   // 최대 10,000
        vector<char> can(maxSum + 1, 0);                          // ★ 지역 변수, 매번 새로
        can[0] = 1;                                               // 0점은 항상 가능 (전부 틀림)

        int cur = 0;                                              // 지금까지 본 문제들의 배점 합
        for (int x : score) {
            cur += x;
            for (int j = cur; j >= x; j--)                        // ★ 역순 (이유는 아래)
                if (can[j - x]) can[j] = 1;                       // j-x 가 가능하면 j 도 가능
        }

        cout << "#" << tc << " " << count(can.begin(), can.end(), 1) << "\n";
    }
    return 0;
}
```

> N개 문제의 배점으로 만들 수 있는 **서로 다른 점수의 개수**를 구하는 문제. 조합은 `2^100`가지지만 점수는 최대 **10,001가지**뿐이므로, 조합을 열거하는 대신 **"각 점수가 도달 가능한가"를 `bool` 배열로 관리하는 0-1 배낭 DP**로 푼다. 각 문제를 최대 한 번만 쓰도록 **1차원 배열을 역순으로 갱신**하는 것이 핵심이며, `bitset`의 `b |= b << x`로 3줄로 줄일 수 있다.
> 

### 알고리즘 분류

- DP