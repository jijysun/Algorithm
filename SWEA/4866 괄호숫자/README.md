# SWEA 4866, 괄호검사 (실패)

# 문제 소개

[문제 사이트 하이퍼링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=2&problemLevel=3&contestProbId=AWTQVdd6QToDFAVT&categoryId=AWTQVdd6QToDFAVT&categoryType=CODE&problemTitle=&orderBy=INQUERY_COUNT&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=8)

> Python 코드용 제출이라…
> 

주어진 입력에서 괄호 {}, ()가 제대로 짝을 이뤘는지 검사하는 프로그램을 만드시오.

예를 들어 {( )}는 제대로 된 짝이지만, {( })는 제대로 된 짝이 아니다. 입력은 한 줄의 파이썬 코드일수도 있고, 괄호만 주어질 수도 있다.

정상적으로 짝을 이룬 경우 1, 그렇지 않으면 0을 출력한다.

print(‘{‘) 같은 경우는 입력으로 주어지지 않으므로 고려하지 않아도 된다.

**[입력]**

첫 줄에 테스트 케이스 개수 T가 주어진다.  1≤T≤50

다음 줄부터 테스트 케이스 별로 온전한 형태이거나 괄호만 남긴 한 줄의 코드가 주어진다.

**[출력]**

각 줄마다 "#T" (T는 테스트 케이스 번호)를 출력한 뒤, 답을 출력한다.

```cpp
입력

3
print('{} {}'.format(1, 2))
N, M = map(int, input().split())
print('#{} {}'.format(tc, find())

출력
#1 1
#2 1
#3 0
```

---

# 풀이 과정

- 가장 마지막에 만난 여는 괄호가 먼저 닫혀야 하니까 스택을 쓰기로 했다.
- 문자열이 끝났는데 스택에 남거나, 짝이 안 맞으면 바로 0으로 판단했다.
- `cin >> s`로 받다가 공백 때문에 줄이 잘린다는 걸 25분에 알아챘고, 검색해서 `cin.ignore()`와 `getline`을 추가해 예제를 통과했다 (28분).

```cpp

#include<iostream>
#include <stack>

using namespace std;

/*
 * 괄호가 제대로 짝을 이뤘는지 검사하는 프로그램!
 * -  {( )}는 제대로 된 짝
 * -  {( })는 제대로 된 짝 X
 * - 정상적으로 짝을 이룬 경우 1, 그렇지 않으면 0을 출력한다.
 *
 * -> stack을 쓸까?
 * - 가장 마지막으로 만난 ({ 우측을 보는 괄호가 제일 빨리 만난 애와 닫혀야 하니까?
 * - 0 출력 기준: 문자열이 끝났는데, stack에 남는 경우, 또는 일치하지 않는 경우 발생 시 즉시
 * print('{} {}'.format(1, 2)) 기준
 * ( -> push
 * { -> stack
 * } -> 일치! pop
 * { -> stack
 * } -> 일치! pop
 * ( -> push
 * ) -> pop
 * ) -> pop
 *
 * print('#{} {}'.format(tc, find())
 * ( push
 * { push
 * } pop
 * { push
 * } pop
 * ( push
 * ( push
 * ) pop
 * ) pop
 *
 * = ( 가 남게 됨!
 *
 */

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case) {
		stack<char> st;
		string s;
		bool flag = false;
		// cin>>s; // 25분에 알아차렸다. 띄어쓰기가 반영이 안된다. 그래서 python으로만 코드를 제한한거였나?

		cin.ignore();
		getline(cin,s); // -> 이거 어떻게 하드라

		string ns="";
		for (int i = 0; i < s.length(); ++i) {
			char c = s[i];
			if (c == '(' || c == '{' || c == '[' || c == ')' || c == '}' || c == ']') {
				ns+=c;
			}
		}

		// cout << ns << endl;

		for (int i = 0; i<ns.length(); ++i) {

			stack<char> nst = st;
			/*while (!nst.empty()) {
				char c = nst.top();
				nst.pop();
				cout << c << " ";
			} cout << endl;*/

			if (ns[i] == '(' || ns[i] == '{' || ns[i] == '[') {
				st.push(ns[i]);
			}
			else if (ns[i] == ')') {
				if (st.top() == '(') {
					st.pop();
				}
				else {
					// cout << st.top() << " " << ns[i] << "로 같지 않습니다.\n";
					flag = true;
					break;
				}
			}
			else if (ns[i] == '}') {
				if (st.top() == '{') {
					st.pop();
				}
				else {
					// cout << st.top() << " " << ns[i] << "로 같지 않습니다.\n";
					flag = true;
					break;
				}
			}
			else if (ns[i] == ']') {
				if (st.top() == '[') {
					st.pop();
				}
				else {
					// cout << st.top() << " " << ns[i] << "로 같지 않습니다.\n";
					flag = true;
					break;
				}
			}
		}

		/*for (int i = 0; i < s.length(); ++i) {
			char c = s[i];
			if (c == '(' || c == '{' || c == '[' || c == ')' || c == '}' || c == ']') {
				if (c == '(' || c == '{' || c == '[') {
					cout << s[i] << " ";
					st.push(c);
					continue;
				}
				if (c == ')' && st.top() == '(') {
					st.pop();
				}
				else if (c == '}' && st.top() == '{') {
					st.pop();
				}
				else if (c == ']' && st.top() == '[') {
					st.pop();
				}
				else {
					flag = true; // 일치하지 않는 경우
					break;
				}
			}

		}*/

		// 일치하지 않는 경우
		if (flag || !st.empty()) {
			cout << "#" << test_case << " 0" << endl;
		}
		else {
			cout << "#" << test_case << " 1" << endl;
		}

		cout << endl;
		
		/*
		 * 
		 * 25분에 문자열에 공백이 있어서 넘어가버린다는 걸 늦게 깨닫게 됨.
		 * - 그동안 헛된 디버깅
		 * 
		 * 28분 웹 자료 검색으로 도움을 받아서 cin.ignore(), getline 추가 후 예제 풀이는 성공
		 */

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
```

---

# 결과 & 근거

**가채점 예제 통과 (28분). 실제로는 괄호만 있는 입력에서 크래시**

- `cin.ignore()`가 루프 안에 있어서 두 번째 줄부터 첫 글자를 먹는다. `cin >> T` 직후 한 번만 해야 한다.
- 닫는 괄호가 먼저 오면 빈 스택에서 `top()`을 불러 크래시가 난다. `empty()`를 먼저 확인해야 한다.

> 
> 
> 
> ***한 줄 요약***
> 
> **스택 괄호 짝 맞추기 문제.** 
> 
> 공백이 있는 한 줄을 getline으로 받아 여는 괄호는 push, 닫는 괄호는 스택 맨 위와 짝을 확인해 pop하고, 끝에 스택이 비어야 성공이다. cin.ignore()는 한 번만, top() 전엔 empty() 확인이 핵심.
> 

### 알고리즘 분류

- 스택
- 문자열