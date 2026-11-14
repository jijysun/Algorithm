# SWEA 1213, String (성공)

# 문제 소개

[문제 사이트 하이퍼링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=2&problemLevel=3&contestProbId=AV14P0c6AAUCFAYi&categoryId=AV14P0c6AAUCFAYi&categoryType=CODE&problemTitle=&orderBy=LASTEST_COMMENT&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=1)

주어지는 영어 문장에서 특정한 문자열의 개수를 반환하는 프로그램을 작성하여라.

Starteatingwellwiththeseeighttipsforhealthyeating,whichcoverthebasicsofahealthydietandgoodnutrition.위 문장에서 ti 를 검색하면, 답은 4이다.

**[제약 사항]**총 10개의 테스트 케이스가 주어진다.문장의 길이는 1000자를 넘어가지 않는다. 한 문장에서 검색하는 문자열의 길이는 최대 10을 넘지 않는다. 

한 문장에서는 하나의 문자열만 검색한다. 

**[입력]**

각 테스트 케이스의 첫 줄에는 테스트 케이스의 번호가 주어지고 그 다음 줄에는 찾을 문자열, 그 다음 줄에는 검색할 문장이 주어진다.

**[출력]**

#부호와 함께 테스트 케이스의 번호를 출력하고, 공백 문자 후 테스트 케이스의 답을 출력한다.

```cpp
입력
1
ti
Starteatingwellwiththeseeighttipsforhealthyeating,whichcoverthebasics ...
2
ing
Thedoublehelixformsthestructuralbasisofsemi-conservativeDNAreplication.1,2Less ...
...

**출력**
#1 4
#2 2...
```

---

# 풀이 과정

- 문장에서 찾을 문자열 길이만큼 `substr`로 한 칸씩 밀면서 잘라 비교했다.
- `substr(n, m)`이 n부터 m개를 자른다는 걸 먼저 확인했다 (6분).

```cpp
#include<iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;   // 테스트 케이스 수가 입력으로 안 주어지고 항상 10개

	for (test_case = 1; test_case <= T; ++test_case) {
		int tc, answer = 0;
		string word, s;
		cin >> tc;      // 테스트 케이스 번호 (출력엔 test_case를 써도 같다)
		cin >> word;    // 찾을 문자열
		cin >> s;       // 검색할 문장 (공백 없이 주어짐)

		// 시작점 i에서 word 길이만큼 잘라 비교.
		// i + word.size() <= s.size() 형태로 쓰면 unsigned 뺄셈 언더플로가 없다
		for (int i = 0; i + word.size() <= s.size(); i++) {
			if (s.substr(i, word.size()) == word) answer++;
		}

		cout << "#" << test_case << " " << answer << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

```

---

# 결과 & 근거

**성공 (6분)**

- 시작점을 한 칸씩 옮기며 단어 길이만큼 잘라 비교하면 된다.
- `size()`는 unsigned라서, 반복 조건은 뺄셈 대신 `i + word.size() <= s.size()`로 쓰는 게 안전하다.

```cpp
// 더 안전한 코드
#include<iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;   // 테스트 케이스 수가 입력으로 안 주어지고 항상 10개

	for (test_case = 1; test_case <= T; ++test_case) {
		int tc, answer = 0;
		string word, s;
		cin >> tc;      // 테스트 케이스 번호 (출력엔 test_case를 써도 같다)
		cin >> word;    // 찾을 문자열
		cin >> s;       // 검색할 문장 (공백 없이 주어짐)

		// 시작점 i에서 word 길이만큼 잘라 비교.
		// i + word.size() <= s.size() 형태로 쓰면 unsigned 뺄셈 언더플로가 없다
		for (int i = 0; i + word.size() <= s.size(); i++) {
			if (s.substr(i, word.size()) == word) answer++;
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
> **문자열 검색 문제.** 
> 
> 시작점을 한 칸씩 옮기며 찾을 문자열 길이만큼 substr로 잘라 같은지 세어 등장 횟수를 구한다. substr의 두 번째 인자가 길이라는 점과 unsigned 범위 처리가 핵심.
> 

### 알고리즘 분류

- 문자열
- 브루트포스