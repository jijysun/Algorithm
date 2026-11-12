# SWEA 4406, 모음이 보이지 않는 사람 (성공)

# 문제 소개

[문제 사이트 하이퍼링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=2&problemLevel=3&contestProbId=AWNcD_66pUEDFAV8&categoryId=AWNcD_66pUEDFAV8&categoryType=CODE&problemTitle=&orderBy=INQUERY_COUNT&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=10)

불의의 교통사고를 당한 당신은 얼마 후 자신의 인식 속에서 모음이라는 것이 사라진 것을 알게 되었다.

알파벳 소문자 만으로 이루어진 단어를 당신은 어떤 식으로 보게 될까?

알파벳에서 모음은 ‘a’, ‘e’, ‘i’, ‘o’, ‘u’의 다섯가지로 예를 들어 “congratulation”이라는 단어를 당신이 보게 되면 “cngrtltn”으로 인식하게 될 것이다.

**[입력]**

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 길이가 50이하이고 알파벳 소문자만으로 이루어진 단어가 주어진다. 이 단어에 모음이 아닌 문자(자음)이 적어도 하나는 들어있다는 것이 보장된다.

**[출력]**

테스트 케이스 T에 대한 결과는 “#T ”을 찍고,  각 테스트 케이스마다 주어진 단어를 당신이 어떻게 인식하는지를 출력한다.

**입력/출력**

```cpp
3
congratulation
synthetic
fluid

----
#1 cngrtltn
#2 synthtc
#3 fld
```

---

# 풀이 과정

- 문자열을 입력받고 모음이면 출력하지 않으면 된다고 생각했다. map이나 stack/queue는 필요 없었다 (3분 20초).

```cpp
#include<iostream>

using namespace std;

/*
 * 모음이 사라짐.
 * - 알파벳 소문자만 있는 단어 기준  ‘a’, ‘e’, ‘i’, ‘o’, ‘u’ 가 없어진 것
 * - “congratulation”이라는 단어를 당신이 보게 되면 “cngrtltn”이 됨.
 * - 길이가 50이하이고 알파벳 소문자만으로 이루어진 단어가 주어진다.
 *
 * 그냥 string s 입력 받고, 모음이면 출력 안해버리면 되는 거 아닌가?
 * - 뭐 map이나 stack/queue 할 것도 없음
 *
 * 3분 20초 클리어. 이게 D3라고....? 이전 난이도와 천차만별인데.
 */

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case) {
		string s;
		cin>>s;

		cout << "#" << test_case <<  " ";

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
				continue;
			}
			cout << s[i];
		}
		cout << '\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
```

---

# 결과 & 근거

**성공 (3분 20초)**

- 글자 하나씩 보며 모음만 건너뛰고 나머지를 바로 출력하면 된다.

> 
> 
> 
> ***한 줄 요약***
> 
> **문자열 필터링 구현 문제.** 
> 
> 단어를 한 글자씩 보며 모음(a, e, i, o, u)이면 건너뛰고 나머지만 출력한다. 자료구조 없이 조건 하나로 거르는 게 핵심.
> 

### 알고리즘 분류

- 문자열
- 구현