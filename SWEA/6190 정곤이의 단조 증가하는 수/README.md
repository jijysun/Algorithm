# 문제 소개

[문제 사이트 하이퍼링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=3&contestProbId=AWcPjEuKAFgDFAU4&categoryId=AWcPjEuKAFgDFAU4&categoryType=CODE&problemTitle=&orderBy=SUBMIT_COUNT&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=2)

정곤이는 자신이 엄청난 수학자임을 증명하기 위해, 어떤 규칙 만족하는 수를 찾아보기로 했다.

그 규칙은 단조 증가하는 수인데, 각 숫자의 자릿수가 단순하게 증가하는 수를 말한다.

어떤 k자리 수 X = d1d2…dk 가 d1 ≤ d2 ≤ … ≤ dk 를 만족하면 단조 증가하는 수이다.

예를 들어 111566, 233359는 단조 증가하는 수이고, 12343, 999888은 단조 증가하는 수가 아니다.

양의 정수 N 개 A1, …, AN이 주어진다.

1 ≤ i < j ≤ N 인 두 i, j에 대해, Ai x Aj값이 단조 증가하는 수인 것들을 구하고 그 중의 최댓값을 출력하는 프로그램을 작성하라.

**[입력]**

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 하나의 정수 N(1 ≤N ≤ 1,000) 이 주어진다.

두 번째 줄에는 N개의 정수 A1, …, AN(1 ≤ Ai ≤ 30,000) 이 공백 하나로 구분되어 주어진다.

**[출력]**

각 테스트 케이스마다 단조 증가하는 수인 Ai x Aj중에서 그 최댓값을 출력한다.

만약 Ai x Aj중에서 단조 증가하는 수가 없다면 -1을 출력한다.

```
입력
1
4
2 4 7 10

출력
#1 28

```

---

# 풀이 과정

- 처음에는 입력된 숫자 각각이 단조인지 검사했다가 0/50이 나왔고, 두 수의 곱 자체가 단조여야 한다는 걸 다시 읽었다.
- 다음엔 붙어 있는 두 수(i, i+1)만 곱해서 9/50이 나왔고, i < j인 모든 쌍을 봐야 한다는 걸 알았다.
- 모든 쌍을 이중 for로 돌면서 곱을 문자열로 바꿔 자릿수를 앞에서부터 비교했고, N = 1이면 입력값을 바로 출력했다.
- 35분이 지난 시점에 42/50 + 시간 초과가 나왔다.

```cpp
#include<iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/*
단조 증가 수 (각 숫자의 자릿수가 단순하게 증가하는 수)

d1d2…dk 가 d1 ≤ d2 ≤ … ≤ dk 를 만족하면 단조 증가하는 수
- 111566, 233359는 단조 증가하는 수
- 999888은 단조 증가하는 수가 아님

= 1 ≤ i < j ≤ N 인 두 i, j에 대해, Ai x Aj값이 단조 증가하는 수인 것들을 구하고
그 중의 최댓값을 출력하는 프로그램

2 4 7 10 ->
2 4 -> 단조! max 갱신 8
4 7 -> 단조! max 갱신 28
7 10 -> 10이 단조가 아님.

풀이 (51분 시작)
- 모든 숫자를 string으로 받는다. (숫자는 최대 30,000)
- 각 숫자당 자리 검사. 하나라도 단조가 아닌 경우 continue;
-> 이거를 pair<string, int> 해서 검사 후 단조가 아닌 경우는 1로 표시,
탐색 초기에 1인 경우는 무조건 continue?

- 둘 다 단조인 경우 stoi () 해서 곱하기 + max 갱신

11분 경과 0/50...?
-  Ai x Aj값이 단조 증가하는 수인 것들을 구하고 ..
- 곱 자체가 단조인 걸 구하는 거다.

18분 경과 5/50
21분 9/50
- 완벽하게 틀렸다는 소리.
- 0이 입력으로 주어지는 건 없어, 최소 1부터 30000. 인트 범위를 넘어가는 것도 아님.
- 설마 조합인가.

35분 경과
42/50 + TLE
- 지금 최대 30,000*30,000 을 도니까 그런 것.

*/
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int n;

		//vector<pair<string, int>> num;
		vector<string> num;

		string s;

		cin >> n;
		for (int i = 0; i < n; i++) {
			// 아니면 입력 받자 마자 검사를 진행하자.
			cin >> s;

			num.push_back(s);
		}
		if (n == 1) {
			cout << "#" << test_case << " " << num[0] << endl;
			continue;
		}

		int answer = -1;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				int n = stoi(num[i]) * stoi(num[j]);

				string multi = to_string(n); // 이게 오래 걸리나?
				//cout << multi << endl;

				bool check = false;
				int pre = 1;
				for (char c : multi) {
					if (pre > c - '0') {
						// 단조 아님
						//cout << stoi(num[i]) << "*" << stoi(num[i + 1]) << " = " << multi << endl;
						//cout << n << "is not danjo" << endl;
						check = true;
						break;
					}
					else {
						pre = c - '0';
					}
				}

				if (!check) {
					//cout << stoi(num[i]) << "*" << stoi(num[i + 1]) << " = " << multi << endl;
					//cout << n << "is danjo" << endl;
					answer = max(answer, n);
				}
			}

		}

		//int answer = -1;
		//for (int i = 0; i < num.size()-1; i++) { // 지금이랑 다음거 
		//	if (num[i].second || num[i + 1].second) {
		//		continue; // 둘 중 하나라도 아니면 continue
		//	}
		//	else {
		//		// 둘 다 단조 확인
		//		int multi = stoi(num[i].first) * stoi(num[i + 1].first);
		//		//cout << num[i].first << "*" << num[i + 1].first <<  " = " << multi << endl;
		//		if (answer <= multi) answer = multi;
		//	}
		//}

		cout << "#" << test_case << " " << answer << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

/*
1
6
11 22 33 40 15 61

전부 단조가 아님-> 통과

1
2
1 29999
1*29999 = 29999
29999is danjo
#1 29999
통과

1
1
6
#1 6 통과

1
3
1 6 8
1*6 = 6
6is danjo
6*8 = 48
48is danjo
#1 48
- 단조 여러개인 경우 수도 통과
*/
```

---

# 결과 & 근거

**실패 (35분, TC 42/50 + 시간 초과)**

- N = 1이면 쌍이 없으니 답은 -1이다. n == 1 특수 분기를 지우면 이중 for가 0번 돌아서 -1이 그대로 나온다.
- 쌍은 최대 약 50만 개라 반복 횟수는 문제가 없다. 쌍마다 stoi 2번과 to_string 1번을 하는 게 무거웠다. 입력을 int로 받고 자릿수는 %10, /10으로 검사하고, 곱이 이미 찾은 답 이하면 검사를 건너뛴다.

```cpp
#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

// x의 자릿수가 왼쪽 → 오른쪽으로 감소하지 않는가?
// 오른쪽(일의 자리)부터 보면 "앞자리 <= 뒷자리"가 깨지는 순간을 %10, /10만으로 찾을 수 있다
bool isDanjo(int x) {
	int right = x % 10;   // 지금까지 본 것 중 가장 오른쪽 자리
	x /= 10;
	while (x > 0) {
		int left = x % 10;
		if (left > right) return false;   // 앞자리가 더 크면 단조 아님
		right = left;
		x /= 10;
	}
	return true;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int n;
		cin >> n;

		// 입력을 처음부터 int로 받는다 → 쌍마다 stoi 2번 + to_string 1번(약 50만 쌍)이 사라진다
		vector<int> num(n);
		for (int i = 0; i < n; i++) {
			cin >> num[i];
		}

		// N = 1이면 쌍이 없으니 -1 (특수 분기 없이 아래 이중 for가 0번 돌아서 그대로 -1)
		int answer = -1;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				int multi = num[i] * num[j];   // 최대 30,000 * 30,000 = 9억 < int 최대(약 21억)

				// 이미 찾은 답 이하면 검사할 필요가 없다 → 단조 검사를 대부분 건너뛴다
				if (multi <= answer) continue;

				if (isDanjo(multi)) {
					answer = multi;
				}
			}
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
> **완전 탐색 문제.** 
> 
> i < j인 모든 쌍의 곱을 구하고, 일의 자리부터 %10으로 앞자리 ≤ 뒷자리인지 검사해 최댓값을 갱신한다. 지문의 i < j(모든 쌍)를 정확히 읽는 것과 문자열 변환 없이 정수로 자릿수를 보는 게 핵심.
> 

### 알고리즘 분류

- 브루트포스
- 구현
- 수학