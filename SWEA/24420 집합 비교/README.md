# SWEA 24420, 집합 비교 (성공)

# 문제 소개

[문제 사이트 하이퍼링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=2&problemLevel=3&contestProbId=AZcKaddqidnHBITY&categoryId=AZcKaddqidnHBITY&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=2)

자연수로 구성된 두 집합 A와 B가 주어진다. 두 집합 사이의 관계를 아래 네 개 중 하나로 구분하는 프로그램을 작성하라. 

- ‘=’: 두 집합 A와 B가 서로 같다.
- ‘<’: A와 B는 서로 다르고, A가 B의 부분집합이다.
- ‘>’: A와 B는 서로 다르고, B가 A의 부분집합이다.
- ‘?’: 위의 세 분류에 모두 해당하지 않는다.

**[입력]**

첫 번째 줄에 테스트 케이스의 수 T가 주어진다. 

각 테스트 케이스는 세 개의 줄로 이루어진다.

이 중 첫 번째 줄에는 집합 A의 크기와 집합 B의 크기가 공백 하나를 사이로 두고 주어진다.

두 번째 줄에는 집합 A의 원소들이 공백 하나씩을 사이로 두고 주어진다.

세 번째 줄에는 집합 B의 원소들이 공백 하나씩을 사이로 두고 주어진다.

집합의 크기는 집합의 원소의 개수를 의미하며, 1 이상 50 이하이다.

집합의 원소는 모두 1 이상 100 이하의 자연수이며, 한 집합 내에서 모든 원소는 서로 다르다.

**[출력]**

각 테스트 케이스마다, 집합 A와 B 사이의 관계를 나타내는 문자를, 한 줄에 하나씩 출력한다.

```cpp
입력
4
3 3
1 2 3
3 2 1
2 4
7 1
1 3 5 7
4 3
2 9 3 5
3 5 2
3 3
1 2 3
3 2 4

출력
=
<
>
?
```

---

# 풀이 과정

- 두 집합을 map으로 입력받고, 크기가 작은 쪽을 돌면서 큰 쪽에 전부 있는지 확인했다.
- 하나라도 없으면 `?`, 전부 있으면서 크기가 같으면 `=`, 아니면 어느 쪽이 작은지에 따라 `<`나 `>`로 판단했다.

```cpp
#include<iostream>
#include <map>

using namespace std;

/*
두 집합 A, B 사이 관계를 네 관계 중 하나로 구분하는 프로그램을 만들어라.
-  ‘=’: 두 집합 A와 B가 서로 같다.
-  ‘<’: A와 B는 서로 다르고, A가 B의 부분집합이다.
-  ‘>’: A와 B는 서로 다르고, B가 A의 부분집합이다.
-  ‘?’: 위의 세 분류에 모두 해당하지 않는다.
- 집합 크기:  1 이상 50 이하
- 집합의 원소는 모두 1 이상 100 이하의 자연수이며, 한 집합 내에서 모든 원소는 서로 다르다.

vector<int> a, b;
- 입력 받은 걸 인덱스 접근 + 증가 연산
- 사이즈 작은 쪽 기준으로 순회
- - 만약 모두 있으면 부분 집합. 하나라도 틀리면 해당되지 않는다. -> flag

- flag == true -> ?
- flag == flase && size가 서로 같다면 =,
- 아니면 > or <

*/
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int n, m;

		cin >> n >> m;
		//vector<int> a(n + 1, 0), b(m + 1, 0);
		map<int, int> a, b;

		int num;
		for (int i = 0; i < n; i++) {
			cin >> num;
			a[num]++;
		}
		for (int i = 0; i < m; i++) {
			cin >> num;
			b[num]++;
		}

		bool flag = false;
		/*for (auto p : a) {
			if (b[p.first] == 0){
				flag = true; break;
			}
		}*/

		bool aorb = false; // a가 작으면 false, b가 작으면 true;
		if (a.size() <= b.size()) {
			for (auto p : a) {
				if (b[p.first] == 0) {
					flag = true; break;
				}
			}
		}
		else {
			aorb = true;
			for (auto p : b) {
				if (a[p.first] == 0) {
					flag = true; break;
				}
			}
		}

		if (flag) {
			cout << "?" << endl;
		}
		else {
			if (a.size() == b.size()) {
				cout << "=" << endl;
			}
			else if (aorb) {
				cout << ">" << endl;
			}
			else {
				cout << "<" << endl;
			}
		}

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
```

---

# 결과 & 근거

**성공**

- 작은 쪽 원소가 큰 쪽에 전부 있으면 부분집합이고, 크기까지 같으면 같은 집합이다.
- map에서 존재 여부는 키를 새로 만드는 `map[]`이 아니라 `count()`로 확인하는 게 안전하다.

```cpp
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int n, m;
		cin >> n >> m;
		map<int, int> a, b;   // 원소 → 등장 횟수 (집합이라 사실상 존재 표시)

		int num;
		for (int i = 0; i < n; i++) { cin >> num; a[num]++; }
		for (int i = 0; i < m; i++) { cin >> num; b[num]++; }

		// 작은 쪽의 원소가 큰 쪽에 전부 있는지 확인
		// count(): 없는 키를 조회해도 새로 만들지 않는다 (map[]은 만든다)
		bool flag = false;   // true = 작은 쪽 원소 중 큰 쪽에 없는 게 있음
		bool aorb = false;   // false = A가 작은 쪽, true = B가 작은 쪽
		if (a.size() <= b.size()) {
			for (const auto& p : a) {
				if (!b.count(p.first)) { flag = true; break; }
			}
		}
		else {
			aorb = true;
			for (const auto& p : b) {
				if (!a.count(p.first)) { flag = true; break; }
			}
		}

		if (flag) cout << "?" << '\n';                  // 어느 쪽도 부분집합 아님
		else if (a.size() == b.size()) cout << "=" << '\n';   // 크기 같고 포함 → 같은 집합
		else if (aorb) cout << ">" << '\n';             // B ⊂ A
		else cout << "<" << '\n';                       // A ⊂ B
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

```

> 
> 
> 
> ***한 줄 요약***
> 
> **해시(map) 집합 판별 문제.** 
> 
> 크기가 작은 집합의 원소가 큰 집합에 모두 있는지 count로 확인하고, 포함 여부와 크기 비교로 =, <, >, ?를 정한다. 작은 쪽 기준으로 포함을 확인하는 게 핵심.
> 

### 알고리즘 분류

- 해시 (map)
- 구현