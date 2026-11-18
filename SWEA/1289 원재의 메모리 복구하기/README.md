# SWEA 1289, 원재의 메모리 복구하기 (성공)

# 문제 소개

[문제 사이트 하이퍼링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=2&problemLevel=3&contestProbId=AV19AcoKI9sCFAZN&categoryId=AV19AcoKI9sCFAZN&categoryType=CODE&problemTitle=&orderBy=SUBMIT_COUNT&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=4)

원재가 컴퓨터를 만지다가 실수를 저지르고 말았다. 메모리가 초기화된 것이다.

다행히 원래 메모리가 무슨 값이었는지 알고 있었던 원재는 바로 원래 값으로 되돌리려고 했으나 메모리 값을 바꿀 때 또 문제가 생겼다.

메모리 bit중 하나를 골라 0인지 1인지 결정하면 해당 값이 메모리의 끝까지 덮어씌우는 것이다.

예를 들어 지금 메모리 값이 0100이고, 3번째 bit를 골라 1로 설정하면 0111이 된다.

원래 상태가 주어질 때 초기화 상태 (모든 bit가 0) 에서 원래 상태로 돌아가는데 최소 몇 번이나 고쳐야 하는지 계산해보자.

**[입력]**

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스는 한 줄로 이루어져 있으며, 메모리의 원래 값이 주어진다.

메모리의 길이는 1이상 50이하이다.

**[출력]**

각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고,

초기값(모든bit가 0)에서 원래 값으로 복구하기 위한 최소 수정 횟수를 출력한다.

```cpp
입력
2
0011
100

출력
#1 1
#2 2
```

---

# 풀이 과정

- 재귀로 풀려다가 문자열 인덱스에서 out of bound 오류가 나서, 함수 안 반복문으로 바꿨다.
- 모두 0인 문자열을 만들고, 앞에서부터 원래 값과 다른 자리를 만나면 그 뒤를 전부 뒤집고 횟수를 셌다 (약 20분).

```cpp
#include<iostream>

using namespace std;

/*
실수로 컴퓨터 만지다 메모리 초기화됨.
- 원래 메모리가 무슨 값이었는지 알고 있었던 원재는 바로 원래 값으로 되돌리기
- but 메모리 값을 바꿀 때 또 문제

메모리 bit중 하나를 골라 0인지 1인지 결정하면 해당 값이 메모리의 끝까지 덮어씌우는 것!
- 지금 메모리 값이 0100이고, 3번째 bit를 골라 1로 설정하면 0111
- 원래 상태가 주어질 때 초기화 상태 (모든 bit가 0) 에서 원래 상태로 돌아가는데 최소 몇 번으로 가능!?
- 메모리의 길이는 1이상 50이하

0000 -> 0011 이면 앞 쪽에서 1번이면 끝남

100 -> (1) 111 -> (2) 100 으로 끝남.

11 0111 0101 임의 예시 기준
(1) 11 1111 1111
(2) 스킵
(3) 11 0000 0000
(4) 11 0111 1111
(5) 스킵
(6) 스킵
(7) 11 0111 0000
(8) 11 0111 0111
(9) 11 0111 0100
(10) 11 0111 0101 총7번

재귀 호출 (int idx, int change_cnt)
2. 매번 비교
- 완전히 같아요? 바로 flag = true, return
3. false 시
- 현 자리 비교,
- 같으면 (i+1, change_cnt) 호출, 다르면 (i+1, change_cnt+1) 호출
*/

bool check = false;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		string memory, nm = "";
		cin >> memory;
		for (int i = 0; i < memory.size(); i++) {
			nm += "0";
		}

		//cout << "memory: \t" << memory << endl;

		int idx = 0, cnt = 0;
		for (int i = 0; i < memory.size(); i++) {
			//cout << "idx: " << idx << ", cnt: " << cnt << "......." << endl;
			//cout << "new: \t" << nm << endl;
			if (nm == memory) {
				check = true;
				break;
			}
			else {
				if (memory[i] != nm[i]) {
					for (int j = i; j < nm.size(); j++) {
						if (nm[j] == '0') nm[j] = '1';
						else nm[j] = '0';
					}
					cnt++;
				}
			}
		}

		cout << "#" << test_case << " " << cnt << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
```

---

# 결과 & 근거

**성공 (약 20분)**

- 한 자리를 고치면 뒤가 전부 같은 값으로 덮이니까, 왼쪽부터 "지금 덮인 값"과 다른 자리마다 한 번씩 고치면 된다.
- 결국 답은 '0'에서 시작해 값이 바뀌는 횟수라서, 실제로 뒤집지 않아도 O(N)에 끝난다.

```cpp
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		string memory;
		cin >> memory;

		// 한 자리를 고치면 그 뒤가 전부 같은 값으로 덮인다.
		// → 왼쪽부터 보면서 "지금 덮여 있는 값(prev)"과 원래 값이 다를 때만 고치면 된다.
		// 처음엔 전부 0으로 덮여 있는 상태.
		char prev = '0';
		int cnt = 0;
		for (char c : memory) {
			if (c != prev) {   // 원래 값과 다르다 → 여기서 한 번 고침 (뒤가 전부 c로 바뀜)
				cnt++;
				prev = c;
			}
		}

		cout << "#" << test_case << " " << cnt << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

```

> 
> 
> 
> ***한 줄 요약***
> 
> **그리디 문자열 문제.** 
> 
> 처음 '0'에서 시작해 왼쪽부터 원래 값이 직전 값과 달라지는 지점마다 한 번씩 고친 횟수를 센다. 고친 값이 끝까지 덮인다는 점에서 "값이 바뀌는 횟수 = 답"이라는 관찰이 핵심.
> 

### 알고리즘 분류

- 그리디
- 문자열