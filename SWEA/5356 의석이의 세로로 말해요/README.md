# SWEA 5356, 의석이의 세로로 말해요 (성공)

# 문제 소개

[문제 사이트 하이퍼링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=2&problemLevel=3&contestProbId=AWVWgkP6sQ0DFAUO&categoryId=AWVWgkP6sQ0DFAUO&categoryType=CODE&problemTitle=&orderBy=INQUERY_COUNT&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=8)

아직 글을 모르는 의석이가 벽에 걸린 칠판에 자석이 붙어있는 글자들을 붙이는 장난감을 가지고 놀고 있다.이 장난감에 있는 글자들은 영어 대문자 ‘A’부터 ‘Z’, 영어 소문자 ‘a’부터 ‘z’, 숫자 ‘0’부터 ‘9’이다. 의석이는 칠판에 글자들을 수평으로 일렬로 붙여서 단어를 만든다.다시 그 아래쪽에 글자들을 붙여서 또 다른 단어를 만든다. 이런 식으로 다섯 개의 단어를 만든다. 아래에 의석이가 칠판에 붙여 만든 단어들의 예가 있다.

A A B C D D
a f z z
0 9 1 2 1
a 8 E W g 6
P 5 h 3 k x

만들어진 다섯 개의 단어들의 글자 개수는 서로 다를 수 있다.

심심해진 의석이는 칠판에 만들어진 다섯 개의 단어를 세로로 읽으려 한다.세로로 읽을 때, 각 단어의 첫 번째 글자들을 위에서 아래로 세로로 읽는다. 다음에 두 번째 글자들을 세로로 읽는다.이런 식으로 왼쪽에서 오른쪽으로 한 자리씩 이동 하면서 동일한 자리의 글자들을 세로로 읽어 나간다.위의 그림 1의 다섯 번째 자리를 보면 두 번째 줄의 다섯 번째 자리의 글자는 없다. 이런 경우처럼 세로로 읽을 때 해당 자리의 글자가 없으면, 읽지 않고 그 다음 글자를 계속 읽는다.그림 1의 다섯 번째 자리를 세로로 읽으면 D1gk로 읽는다.위에서 의석이가 세로로 읽은 순서대로 글자들을 공백 없이 출력하면 다음과 같다:

Aa0aPAf985Bz1EhCz2W3D1gkD6x

칠판에 붙여진 단어들이 주어질 때, 의석이가 세로로 읽은 순서대로 글자들을 출력하는 프로그램을 작성하라.

**[입력]**

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스는 총 다섯 줄로 이루어져 있다.각 줄에는 길이가 1이상 15이하인 문자열이 주어진다. 각 문자열은 영어 대문자 ‘A’부터 ‘Z’, 영어 소문자 ‘a’부터 ‘z’, 숫자 ‘0’부터 ‘9’만으로 이루어져 있다.

**[출력]**

각 테스트 케이스마다 #T를 출력하고 한 칸을 띄운 후, 의석이가 세로로 읽은 순서대로 글자들을 출력한다.

**입력**

| 2
ABCDE
abcde
01234
FGHIJ
fghij
AABCDD
afzz
09121
a8EWg6
P5h3kx | //Test Case 갯수
//Test Case #1의 시작

//Test Case #2의 시작

 |
| --- | --- |

**출력**

#1 Aa0FfBb1GgCc2HhDd3IiEe4Jj
#2 Aa0aPAf985Bz1EhCz2W3D1gkD6x

---

# 풀이 과정

- 다섯 단어를 입력받으면서 가장 긴 길이를 저장했다.
- 0번째 자리부터 하나씩 늘려가며 다섯 단어를 돌고, 그 자리에 글자가 있으면 정답 문자열에 붙이고 없으면 건너뛰었다 (9분 45초 원트).

```cpp
#include<iostream>
#include <bits/stdc++.h>

using namespace std;

/*
 * 자석 장난감, 영어 [대문자,소문자], 숫자 가 있음.
 * - 5개의 단어를 만든 후, 세로로 읽기!
 * - 여기서 단어 간 문자열 차이로 인해, 같은 자리의 글자가 없는 경우 읽지 않는다!
 * - 칠판에 붙여진 단어들이 주어질 때, 의석이가 세로로 읽은 순서대로 글자들을 출력하는 프로그램을 작성하라.
A A B C D D

a f z z

0 9 1 2 1

a 8 E W g 6

P 5 h 3 k x

- Aa0aP
- Af985
- Bz1Eh
- Cz2W3
- D1gk
- D6x

1. 일단 입력 받고, 최대 문자열 길이를 저장
- answer용 string answer 하나 놔두기
2. 모든 vector 계속 순회. 대신 0부터 점차 증가하는 식으로
- 만약 증가한 값에 대한 자리가 존재하지 않는 경우 skip
- 아닌 경우 answer += v[i][cur_index] 이런식으로?
 */

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case) {
		// 5 단어는 동일.

		string s, answer;

		vector<string> v;
		int idx = 0;

		for (int i = 0; i< 5; i++) {
			cin>>s;
			v.push_back(s);
			if (idx <= s.size()) {
				idx = s.size();
			}
		}

		for (int i = 0; i<idx; i++) {

			for (string word : v) {
				// if (word.size() < i) continue;

				if (word.size () > i) {
					answer += word[i];
				}

			}
		}

		cout << "#" << test_case << " " << answer << endl;

	}
	
	// 9분 45초 원트 클

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
```

---

# 결과 & 근거

**성공 (9분 45초)**

- 가장 긴 단어 길이만큼 자리를 돌고, 각 자리에서 다섯 단어를 위에서 아래로 보며 글자가 있을 때만 붙이면 된다.
- 범위 for문에서 `const string&`로 받으면 매번 문자열을 복사하지 않는다.

> 
> 
> 
> ***한 줄 요약***
> 
> **2차원 문자열 순회 구현 문제.** 
> 
> 가장 긴 단어 길이만큼 자리를 돌며, 각 자리에서 다섯 단어를 위에서 아래로 보고 글자가 있을 때만 이어 붙인다. 행·열 순회 순서를 뒤집어 "열 우선"으로 읽는 게 핵심.
> 

### 알고리즘 분류

- 문자열
- 구현