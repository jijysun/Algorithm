# SWEA 4047, 영준이의 카드 카운팅 (성공)

# 문제 소개

[문제 사이트 하이퍼링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=2&problemLevel=3&contestProbId=AWIsY84KEPMDFAWN&categoryId=AWIsY84KEPMDFAWN&categoryType=CODE&problemTitle=&orderBy=INQUERY_COUNT&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=10)

최근 영준이는 카드 게임에 꽂혀 있다.

영준이가 하는 카드 게임에는 한 덱의 카드가 필요한데 여기서 얘기하는 “한 덱”이란 스페이드, 다이아몬드, 하트, 클로버 무늬 별로 각각 A, 2~10, J, Q, K의 라벨 즉 4개의 무늬 별로

각각 13장씩 총 52장의 카드가 있는 모음을 의미한다.

편의상 A는 1, J, Q, K는 11, 12, 13으로 하여 1~13의 숫자가 카드에 적혀있다고 하자.

영준이는 몇 장의 카드를 이미 가지고 있는데 게임을 하기 위해서 몇 장의 카드가 더 필요한지 알고 싶어 한다.

그리고 이미 겹치는 카드를 가지고 있다면 오류를 출력하고자 한다.

지금 가지고 있는 카드의 정보가 주어지면 이 작업을 수행하는 프로그램을 작성하라.

**[입력]**

맨 위 줄에 테스트케이스의 개수가 주어진다.

각 테스트케이스 별로 순서대로 첫 번째 줄에 지금 영준이가 가지고 있는 카드에 대한 정보 S (1 ≤ |S| ≤ 1000)가 주어진다.

S는 각각 3자리로 표현되는 카드들의 정보를 붙여서 만든 하나의 문자열인데 각 카드는 TXY 꼴로 표현되며,

T는 카드의 무늬(S, D, H, C)이며 XY는 카드의 숫자 (01 ~ 13)이다.

**[출력]**

각 테스트케이스 별로 순서대로 한 줄씩 답을 출력하는데, 문자열 S를 보고 지금 무늬 별로(S, D, H, C 순서로) 몇 장의 카드가 부족한지 출력하여라.

이미 겹치는 카드가 있다면 문자열 “ERROR” (쌍따옴표는 출력하지 않는다)를 출력한다

```cpp
입력
3
S01D02H03H04
H02H10S11H02
S10D10H10C01

출력
#1 12 12 11 13
#2 ERROR
#3 12 12 12 12
```

---

# 풀이 과정

- 카드 정보가 문자열로 이어서 주어지니까, 3글자씩 끊어서 `map<string, int>`로 가진 카드를 기록했다.
- 이미 1인 카드가 나오면 ERROR를 출력하고 끝냈다.
- 다 넣은 뒤 map을 돌면서 무늬별 13장에서 하나씩 뺐다 (11분 40초).

```cpp
#include<iostream>
#include <map>

using namespace std;
/*
 * 카드 게임
 * - 카드가 필요! 스페이드, 다이아몬드, 하트, 클로버 * (A 1, 2~10, J 11, Q 12, K 13) = 52
 * - 영준이는 몇 장의 카드를 이미 가지고 있는데 게임을 하기 위해서 몇 장의 카드가 더 필요한지 알고 싶어 한다.
 * - 이미 겹치는 카드를 가지고 있다면 오류를 출력하고자 한다.
 * - 지금 가지고 있는 카드의 정보가 주어지면 이 작업을 수행하는 프로그램을 작성하라.
 *
 * 문자열로 입력됨.
 * - map<string, int>으로 있는 지 없는 지 확인?
 * S01D02H03H04에 대해
 * -> S01 ++
 * -> D02 ++
 * -> H03 ++
 * -> H04 ++;
 *
 * - 만약 이미 1 이라면 ERROR + Break;
 * 연산 후 map을 순회해서 각 무늬 당 13 start 해서 -- 연산
 * 
 * 11분 40초 제출 완료 및 성공. 이게 D3 난이도 문제라고? D2 여도 어려운 게 있는데 난이도 차이가 큰 거 같아.
 */

map <string, int> card;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case) {
		card.clear();
		int spade = 13, diamond = 13, heart = 13, clover = 13;
		bool flag = false;
		string s;
		cin >> s;

		for (int i = 0; i<s.length(); i+=3) {
			string cur_card = "";
			for (int j = i; j<i+3; j++) {
				cur_card += s[j];
			}
			if (card[cur_card] == 1) {
				flag = true;
				break;
			}
				card[cur_card]++;
		}

		if (flag) {
			cout << "#" << test_case << " ERROR"  << endl;
			continue;
		}

		for (auto [c, val] : card) {
			// cout << c << ": " << val << endl;
			if (c[0] == 'S') {
				spade--;
			}
			else if (c[0] == 'D') {
				diamond--;
			}else if (c[0] == 'H') {
				heart--;
			}else if (c[0] == 'C') {
				clover--;
			}
		}

		cout << "#" << test_case << " " << spade << " " << diamond << " " << heart  << " " << clover << endl;
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
```

---

# 결과 & 근거

**성공 (11분 40초)**

- 카드 3글자를 키로 쓰면 중복 검사와 무늬별 개수 세기를 map 하나로 처리할 수 있다.
- 존재 여부는 조회만 해도 키가 생기는 `map[]`보다 `count()`로 확인하는 게 의도에 맞다.

> 
> 
> 
> ***한 줄 요약***
> 
> **문자열 파싱 + 해시 구현 문제.** 
> 
> 카드 문자열을 3글자씩 잘라 map에 기록하며 중복이면 ERROR를 내고, 아니면 무늬별 13장에서 가진 수를 뺀다. 3칸씩 끊어 읽는 파싱과 count로 중복을 확인하는 게 핵심.
> 

### 알고리즘 분류

- 문자열
- 해시 (map)