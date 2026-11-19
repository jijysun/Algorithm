# 문제 소개

[문제 사이트 하이퍼링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=3&contestProbId=AZPOBiaqNo8DFAWB&categoryId=AZPOBiaqNo8DFAWB&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=2)

문자열 S에 다음과 같은 연산을 몇 번 적용할 것이다.

각각의 연산은 정수 X로 표현되며, X에 따라 문자열 S가 아래와 같이 변한다.

· X > 0이면, S의 첫 번째 글자를 떼네어 마지막 글자 뒤에 붙이는 작업을 정확히 X회 반복한다.

· X < 0이면, S의 마지막 글자를 떼네어 첫 번째 글자 앞에 붙이는 작업을 정확히 -X회 반복한다.

· X = 0이면, 아무 일도 일어나지 않는다.

모든 연산이 종료된 후 문자열 S를 출력하는 프로그램을 작성하라.

**[입력]**

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스는 세 개의 줄로 이루어진다. 첫 번째 줄에는 문자열 S가 주어진다. S는 알파벳 소문자로만 구성되며, 길이가 1 이상 1,000 이하이다. 두 번째 줄에는 연산의 횟수 K가 주어진다. K는 1 이상 100 이하의 정수이다. 세 번째 줄에는 K개의 정수가 공백 하나씩을 사이로 두고 주어지며, 각각의 정수는 순서대로 문자열에 적용하는 연산을 나타낸다. 세 번째 줄에 주어지는 정수는 -109 이상 109 이하이다.

**[출력]**

각 테스트 케이스마다, 주어진 연산을 모두 순서대로 적용한 뒤의 문자열 S를 출력한다.

| 입력 예제 | 출력 예제 |
| --- | --- |
| 2
abcde
1
3
samsung
5
3 2 -6 4 2
 | deabc
ngsamsu |

---

# 풀이 과정

- 앞뒤로 글자를 옮기는 걸 보고 바로 deque를 떠올렸는데, 하나씩 옮기니 TLE가 났다.
- 그래서 나머지 연산으로 횟수를 줄인 뒤 문자열을 잘라 붙이는 방식으로 바꿨다.
- 그 뒤로 런타임 에러가 났고, 연산 횟수가 문자열 길이보다 큰 경우가 있다는 걸 늦게 알아차려 남은 9분에 포기했다.

```cpp
#include<iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*
22979. 문자열 옮기기 44분 시작

문자열 S (1 이상 1,000 이하, all 소문자)에 다음과 같은 연산 (X는 정수)
· X > 0이면, S의 첫 번째 글자를 떼네어 마지막 글자 뒤에 붙이는 작업을 정확히 X회 반복한다.
· X < 0이면, S의 마지막 글자를 떼네어 첫 번째 글자 앞에 붙이는 작업을 정확히 -X회 반복한다.
· X = 0이면, 아무 일도 일어나지 않는다.

아 이거 deque다 딱 보자마자 느낌 오노
-> 20분 TLE로 인해 그냥 문자열 접근으로 변경

= 모든 연산이 종료된 후 문자열 S를 출력하는 프로그램을 작성
*/
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	string s;
	int k, x;
	//  K는 1 이상 100 이하의 정수, 
	// X는 공백 하나씩을 사이로 두고,
	for (test_case = 1; test_case <= T; ++test_case)
	{
		deque<char> dq;
		
		cin >> s;
		cin >> k;

		for (int i = 0; i < s.size(); i++) {
			dq.push_back(s[i]);
		}

		vector<int> op;
		for (int i = 0; i < k; i++) {
			cin >> x;
			op.push_back(x);
		}

		for (int i : op) {
			if (i > 0) {

				i = i % 7;

				if (i == 0) continue;

				// 0 ~ i까지 순서대로 뒤로, 첫 글자를 맨 뒤로.
				string t = s.substr(0, i);

				string t2 = s.substr(i, s.size() - 1);
				s = t2 + t;

			}
			else if (i < 0) {

				i = i % 7;
				if (i == 0) continue;

				string t = "";
				for (int j = 0; j < abs(i); j++) {
					t += s[s.size()-1-j];
				}
				reverse(t.begin(), t.end());

				string t2 = s.substr(0, s.size() - abs(i));
				s = t + t2;

			}
		}
		cout << s << endl;

	}

	/*
	* 8분경과: 0/29 + TLE
	* 9분 남았음 = 0/29 +  런타임 에러 = 포기. 
	* 설명 좀 처음부터 제대로 읽을 걸... 문자열보다 연산 횟수가 넘어가 버리는 게 존재.
	*/

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
```

---

# 결과 & 근거

**실패 (TLE → 런타임 에러)**

- 나머지로 횟수를 줄이는 방향은 맞았는데, 나누는 값을 예제 "samsung"의 길이 7로 고정해버려서 다른 길이에서 `substr` 범위를 넘어 런타임 에러가 났다.
- 음수 X는 C++ 나머지가 음수라 배열 밖을 읽었다. `((x % n) + n) % n`으로 양수/음수를 모두 "왼쪽으로 r칸"으로 바꾸면 한 번에 해결된다.

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		string s;
		int k, x;
		cin >> s >> k;

		vector<int> op;
		for (int i = 0; i < k; i++) {
			cin >> x;            // |X| ≤ 10^9 → int 범위 안
			op.push_back(x);
		}

		int n = s.size();        // [수정] % 7(예제 "samsung" 길이) → % 문자열 길이
		for (int i : op) {
			// 길이 n만큼 돌리면 제자리 → n으로 나눈 나머지만 의미 있음
			// X > 0 : 앞 글자를 뒤로 X번  = 왼쪽으로 X칸
			// X < 0 : 뒷 글자를 앞으로 -X번 = 오른쪽으로 -X칸 = 왼쪽으로 (n - (-X % n))칸
			// C++의 %는 음수에 음수 나머지를 주므로, + n 후 다시 % n 하면 두 경우가 "왼쪽 r칸" 하나로 합쳐진다
			int r = ((i % n) + n) % n;    // 0 ~ n-1
			if (r == 0) continue;         // 제자리

			// 왼쪽으로 r칸 = 앞 r글자를 떼어 뒤에 붙이기 (r < n 이라 substr 범위를 절대 안 넘는다)
			s = s.substr(r) + s.substr(0, r);
		}

		cout << s << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
```

> 
> 
> 
> ***한 줄 요약***
> 
> 문자열 회전 + 나머지 연산 문제. 
> 
> 각 연산을 ((X % n) + n) % n으로 "왼쪽 r칸 회전"으로 바꾸고, substr로 앞 r글자를 뒤에 붙인다. 문자열 길이로 나머지를 구하는 것과 음수 나머지 처리가 핵심.
> 

### 알고리즘 분류

- 문자열
- 수학 (나머지 연산)
- 구현