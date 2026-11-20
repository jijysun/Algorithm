# 문제 소개

[문제 사이트 하이퍼링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=3&contestProbId=AWUS2OVaIpgDFAVT&categoryId=AWUS2OVaIpgDFAVT&categoryType=CODE&problemTitle=&orderBy=SUBMIT_COUNT&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=5)

수업에서 같은 조에 참여하고 싶은 사람끼리 두 사람의 출석 번호를 종이에 적어 제출하였다.

한 조의 인원에 제한을 두지 않았기 때문에, 한 사람이 여러 장의 종이를 제출하거나 여러 사람이 한 사람을 지목한 경우 모두 같은 조가 된다.

예를 들어 1번-2번, 1번-3번이 같은 조가 되고 싶다고 하면, 1-2-3번이 같은 조가 된다. 번호를 적지도 않고 다른 사람에게 지목되지도 않은 사람은 단독으로 조를 구성하게 된다.

1번부터 N번까지의 출석번호가 있고, M 장의 신청서가 제출되었을 때 전체 몇 개의 조가 만들어지는지 출력하는 프로그램을 만드시오.

**[입력]**

첫 줄에 테스트 케이스의 개수가 주어지고, 다음 줄부터 테스트 케이스 별로 첫 줄에 N과 M, 다음 줄에 M 쌍의 번호가 주어진다. 2<=N<=100, 1<=M<=100

**[출력]**

각 줄마다 "#T" (T는 테스트 케이스 번호)를 출력한 뒤, 답을 출력한다.

```cpp
입력
3
5 2
1 2 3 4
5 3
1 2 2 3 4 5
7 4
2 3 4 5 4 6 7 4	 

출력
#1 3
#2 2
#3 3
```

---

# 풀이 과정

- 예제를 손으로 묶어 보며, 같은 번호가 나오면 같은 조로 합쳐진다는 걸 확인했다.
- 조를 `vector<set<int>>`로 두고, 신청서마다 a나 b가 들어 있는 조를 완전 탐색으로 찾아 나머지 번호를 넣고, 없으면 새 조를 만들었다.
- 마지막에 조 개수 + (전체 인원 - 조에 속한 인원)으로 혼자인 사람까지 셌고, 15분 만에 예제와 직접 만든 케이스를 통과했다.

```cpp
#include<iostream>
#include <vector>
#include <set>

using namespace std;
/*

같은 조에 참여하고 싶은 사람끼리 두 사람의 출석 번호를 종이에 적어 제출
- 한 조의 인원에 제한을 두지 않았기 않았음
- 한 사람이 여러 장의 종이를 제출하거나 여러 사람이 한 사람을 지목한 경우 모두 같은 조가 된다

5 2
1 2 3 4
1 2는 조,
3 4 는 조
5는 없음

5 3
1 2 2 3 4 5

1, 2, 3 는 조
4, 5는 조

7 4
2 3 4 5 4 6 7 4
2 3 조
4 5 6 7조 
1 조 

풀이, 
vector<vector<int>> 조
1. 비어 있으면 바로 추가 ,2. 3

2. 조가 있으면 완전 탐색.

15분 만에 풀이완료
- 타 케이스 검증 완료

*/
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, m;
		cin >> n >> m;

		vector<set<int>> team;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;

			if (team.empty()) {
				set<int> new_t = { a, b };
				team.push_back(new_t);
			}
			else {
				// 완전탐색
				bool ins = false;
				for (int j = 0; j < team.size(); j++) {
					for (int p : team[j]) {
						if (p == a) {
							team[j].insert(b);
							ins = true;
							break;
						}
						else if (p == b) {
							team[j].insert(a);
							ins = true;
							break;
						}
					}
					if (ins) {
						break;
					}
				}
				if (!ins) {
					set<int> new_t = { a, b };
					team.push_back(new_t);
				}
			}
		}

		set<int> check;
		for (int j = 0; j < team.size(); j++) {
			//cout << j + 1 << "team: ";
			for (int p : team[j]) {
				//cout << p << " ";
				check.insert(p);
			}
			//cout << endl;
		}

		cout << "#" << test_case << " " << team.size() + n - check.size() << endl;
		
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
```

---

# 결과 & 근거

**실패 (15분, 로컬 채점 TC 311/2000)**

- 신청서의 두 번호가 이미 서로 다른 조에 있으면 두 조를 합쳐야 하는데, 한쪽 조에만 번호를 넣어서 조 개수가 줄지 않았다. (N = 4, 1 2 / 3 4 / 1 3 → 정답 1, 출력 2)
- a가 속한 조와 b가 속한 조를 각각 끝까지 찾고, 서로 다르면 두 조를 합치는 경우를 추가하면 된다.
- 같은 조 묶기는 연결 요소 개수 세기라서 유니온 파인드로 풀면 더 짧고 안전하다.

```cpp
#include<iostream>
#include <vector>
#include <set>

using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, m;
		cin >> n >> m;

		vector<set<int>> team;   // 지금까지 만들어진 조들

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;

			// a가 속한 조, b가 속한 조를 "각각" 끝까지 찾는다 (-1 = 아직 어느 조에도 없음)
			int ia = -1, ib = -1;
			for (int j = 0; j < team.size(); j++) {
				if (team[j].count(a)) ia = j;
				if (team[j].count(b)) ib = j;
			}

			if (ia == -1 && ib == -1) {
				// 둘 다 처음 → 새 조
				team.push_back({ a, b });
			}
			else if (ia == -1) {
				team[ib].insert(a);          // b의 조에 a 합류
			}
			else if (ib == -1) {
				team[ia].insert(b);          // a의 조에 b 합류
			}
			else if (ia != ib) {
				// 둘이 서로 다른 조에 있었다 → 두 조를 하나로 "합친다" (원래 코드에 없던 경우)
				for (int p : team[ib]) team[ia].insert(p);
				team.erase(team.begin() + ib);
			}
			// ia == ib: 이미 같은 조 → 할 일 없음
		}

		// 조가 있는 사람 수 = 각 조 크기의 합 (조끼리 겹치지 않으므로 그대로 더해도 된다)
		int grouped = 0;
		for (int j = 0; j < team.size(); j++) {
			grouped += team[j].size();
		}

		// 전체 조 = 만들어진 조 + 혼자인 사람
		cout << "#" << test_case << " " << team.size() + (n - grouped) << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
```

> 
> 
> 
> ***한 줄 요약***
> 
> **연결 요소 문제.** 
> 
> 신청서마다 두 번호가 속한 조를 각각 찾아, 둘 다 없으면 새 조, 한쪽만 있으면 합류, 서로 다른 조면 두 조를 합친다. 이미 있는 두 조를 잇는 경우를 합치는 게 핵심.
> 

### 알고리즘 분류

- 그래프 이론
- 분리 집합
- 구현