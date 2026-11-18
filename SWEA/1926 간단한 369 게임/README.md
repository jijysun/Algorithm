# SWEA 1926, 간단한 369 게임 (성공)

# 문제 소개

[문제 사이트 하이퍼링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=2&problemLevel=3&contestProbId=AV5PTeo6AHUDFAUq&categoryId=AV5PTeo6AHUDFAUq&categoryType=CODE&problemTitle=&orderBy=SUBMIT_COUNT&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=1)

3 6 9 게임을 프로그램으로 제작중이다. 게임 규칙은 다음과 같다.

1. 숫자 1부터 순서대로 차례대로 말하되, **“3” “6” “9”** 가 들어가 있는 수는 말하지 않는다.
2. "3" "6" "9"가 들어가 있는 수를 말하지 않는대신, 박수를 친다. 이 때, 박수는 해당 숫자가 들어간 개수만큼 쳐야 한다.

예를 들어 숫자 35의 경우 박수 한 번, 숫자 36의 경우 박수를 두번 쳐야 한다.

입력으로 정수 N 이 주어졌을 때, 1~N 까지의 숫자를

게임 규칙에 맞게 출력하는 프로그램을 작성하라.

박수를 치는 부분은 숫자 대신, 박수 횟수에 맞게 “-“ 를 출력한다.

**여기서 주의해야 할 것은 박수 한 번 칠 때는 - 이며, 박수를 두 번 칠 때는 - - 가 아닌 -- 이다.** 

**[제약사항]**

N은 10이상 1,000이하의 정수이다. (10 ≤ N ≤ 1,000)

**[입력]**

입력으로 정수 N 이 주어진다.

**[출력]**

1 ~ N까지의 숫자를 게임 규칙에 맞게 출력한다.

```cpp
입력
10

출력
1 2 - 4 5 - 7 8 - 10
```

---

# 풀이 과정

- 3·6·9가 들어갔는지를 숫자의 각 자리를 `% 10`으로 떼어 보며 판단하기로 했다.
- 해당 숫자가 있으면 그 개수만큼 를 붙이고, 없으면 숫자를 그대로 출력했다 (약 15분

```cpp
#include<iostream>

using namespace std;

/*

간단한 369게임
- 1부터 3,6,9 들어간 건 말하지 않고 박수
- 박수는 그 숫자가 들어간 만큼.

입력으로 정수 (10 ≤ N ≤ 1,000) 이 주어졌을 때, 1~N 까지의 숫자를 게임 규칙에 맞게 출력하는 프로그램을 작성
- 박수를 치는 부분은 숫자 대신, 박수 횟수에 맞게 “-“ 를 출력한다.
- 주의해야 할 것은 박수 한 번 칠 때는 - 이며, 박수를 두 번 칠 때는 - - 가 아닌 -- 이다.

3,6,9가 들어가는 건 어떻게 판단할까?
1. 숫자 i로 하되, 각 자릿수 3,6,9로 나누었을 때 나머지가 0인 경우 - 추가
- 6 -> 6 % 10 = 6; -> - 추가
- 3124 -> 3124%10 = 4 = X, 312 %10 -> X, 31 -

2. stirng 으로 하되, 각 자리수가 3,6,9 일때 - 추가. 대신 i
*/

int main(int argc, char** argv)
{

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {

		int num = i;
		string s = "";
		bool slash = false;
		while (true) {

			int one = num % 10;
			if (one == 3 || one == 6 || one == 9) {
				s += '-';
				slash = true;
			}
			if (num / 10 == 0) break;

			num = num / 10;
		}

		if (!slash) {
			cout << i << " ";
		}
		else {
			cout << s << " ";
		}

	}

	cout << endl;
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
```

---

# 결과 & 근거

**성공 (약 15분)**

- 일의 자리부터 `% 10`, `/ 10`으로 한 자리씩 보며 3·6·9 개수만큼 를 붙이면 된다.
- 박수가 두 번이면 `-`가 아니라 `-`처럼 붙여서 출력해야 한다.

```cpp
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	int n;
	cin >> n;   // 이 문제는 테스트 케이스 T가 없다

	for (int i = 1; i <= n; i++) {
		int num = i;
		string s = "";
		bool clap = false;   // 3, 6, 9가 하나라도 있었나

		// 일의 자리부터 한 자리씩 떼어 보기
		while (true) {
			int one = num % 10;
			if (one == 3 || one == 6 || one == 9) {
				s += '-';    // 박수 개수만큼 '-' (붙여서 "--")
				clap = true;
			}
			if (num / 10 == 0) break;   // 마지막 자리까지 봤음
			num = num / 10;
		}

		if (!clap) cout << i << " ";
		else cout << s << " ";
	}
	cout << '\n';
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

```

> 
> 
> 
> ***한 줄 요약***
> 
> **자릿수 분해 구현 문제.** 
> 
> 1부터 N까지 각 수를 %10, /10으로 한 자리씩 보며 3·6·9 개수만큼 `-`를 붙이고, 없으면 숫자를 그대로 출력한다. 자릿수 분해와 출력 형식(`--`) 맞추기가 핵심.
> 

### 알고리즘 분류

- 구현
- 수학