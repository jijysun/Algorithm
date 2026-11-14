# SWEA 1208, Flatten (성공)

# 문제 소개

[문제 사이트 하이퍼링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=2&problemLevel=3&contestProbId=AV139KOaABgCFAYh&categoryId=AV139KOaABgCFAYh&categoryType=CODE&problemTitle=&orderBy=RECOMMEND_COUNT&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=1)

한 쪽 벽면에 다음과 같이 노란색 상자들이 쌓여 있다.높은 곳의 상자를 낮은 곳에 옮기는 방식으로 최고점과 최저점의 간격을 줄이는 작업을 평탄화라고 한다.평탄화를 모두 수행하고 나면, 가장 높은 곳과 가장 낮은 곳의 차이가 최대 1 이내가 된다.평탄화 작업을 위해서 상자를 옮기는 작업 횟수에 제한이 걸려있을 때, 제한된 횟수만큼 옮기는 작업을 한 후 최고점과 최저점의 차이를 반환하는 프로그램을 작성하시오.

![image.png](image.png)

가장 높은 곳에 있는 상자를 가장 낮은 곳으로 옮기는 작업을 덤프라고 정의한다.

위의 예시에서 제1회 덤프를 수행한 이후 화면은 다음과 같다.

![image.png](image%201.png)

A부분의 상자를 가장 낮은 B부분에 덤프하였으며, A대신 A’부분의 상자를 사용해도 무방하다.

다음은 제2회 덤프를 수행한 이후의 화면이다.

![image.png](image%202.png)

A’부분의 상자를 옮겨서, C부분에 덤프하였다. 이때 C 대신 C’부분에 덤프해도 무방하다.

2회의 덤프 후, 최고점과 최저점의 차이는 8 – 2 = 6 이 되었다 (최초덤프 이전에는 9 – 1 = 8 이었다).

덤프 횟수가 2회로 제한된다면, 이 예시 문제의 정답은 6이 된다.

**[제약 사항]**

가로 길이는 항상 100으로 주어진다.

모든 위치에서 상자의 높이는 1이상 100이하로 주어진다.

덤프 횟수는 1이상 1000이하로 주어진다.

주어진 덤프 횟수 이내에 평탄화가 완료되면 더 이상 덤프를 수행할 수 없으므로 그 때의 최고점과 최저점의 높이 차를 반환한다 (주어진 data에 따라 0 또는 1이 된다).

**[입력]**

총 10개의 테스트 케이스가 주어지며, 각 테스트 케이스의 첫 번째 줄에는 덤프 횟수가 주어진다. 그리고 다음 줄에 각 상자의 높이값이 주어진다.

**[출력]**

#부호와 함께 테스트 케이스의 번호를 출력하고, 공백 문자 후 테스트 케이스의 최고점과 최저점의 높이 차를 출력한다.

---

# 풀이 과정

- 최고점이나 최저점이 여러 개면 아무거나 잡아도 된다고 해서 `max_element`, `min_element`를 쓰기로 했다.
- 덤프 최대 1000번 × 최고/최저 찾기 100 × 2라서 단순 반복으로 충분하다고 판단했다.
- 25분에 구현하고 예제를 통과했는데, 바뀐 IDE와 헤더(`bits/stdc++.h` 없음)에 적응하느라 36분에 성공했다.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>   // max_element, min_element

using namespace std;

int main(int argc, char** argv)
{
	int test_case;

	for (test_case = 1; test_case <= 10; ++test_case) {   // 항상 10개
		int dump;
		cin >> dump;   // 1 ~ 1000

		vector<int> v(100);
		for (int i = 0; i < 100; i++) cin >> v[i];

		for (int i = 0; i < dump; i++) {
			// 최고점·최저점 위치 (여러 개면 아무거나 → 첫 번째 것)
			vector<int>::iterator max_it = max_element(v.begin(), v.end());
			vector<int>::iterator min_it = min_element(v.begin(), v.end());

			// 차이가 1 이하면 평탄화 완료 → 더 옮겨도 변하지 않으니 멈춘다
			if (*max_it - *min_it <= 1) break;

			(*max_it)--;   // 가장 높은 곳에서 하나 빼서
			(*min_it)++;   // 가장 낮은 곳에 하나 얹기
		}

		// 덤프가 끝난 뒤(또는 평탄화 완료 시점)의 최고 - 최저
		int answer = *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end());
		cout << "#" << test_case << " " << answer << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

```

---

# 결과 & 근거

**성공 (36분)**

- 매번 최고점에서 하나 빼서 최저점에 얹는 걸 덤프 횟수만큼 반복하면 된다.
- 차이가 1 이하가 되면 더 옮겨도 변하지 않으니 멈추고, 마지막에 최고 − 최저를 한 번만 계산하면 분기가 필요 없다.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>   // max_element, min_element

using namespace std;

int main(int argc, char** argv)
{
	int test_case;

	for (test_case = 1; test_case <= 10; ++test_case) {   // 항상 10개
		int dump;
		cin >> dump;   // 1 ~ 1000

		vector<int> v(100);
		for (int i = 0; i < 100; i++) cin >> v[i];

		for (int i = 0; i < dump; i++) {
			// 최고점·최저점 위치 (여러 개면 아무거나 → 첫 번째 것)
			vector<int>::iterator max_it = max_element(v.begin(), v.end());
			vector<int>::iterator min_it = min_element(v.begin(), v.end());

			// 차이가 1 이하면 평탄화 완료 → 더 옮겨도 변하지 않으니 멈춘다
			if (*max_it - *min_it <= 1) break;

			(*max_it)--;   // 가장 높은 곳에서 하나 빼서
			(*min_it)++;   // 가장 낮은 곳에 하나 얹기
		}

		// 덤프가 끝난 뒤(또는 평탄화 완료 시점)의 최고 - 최저
		int answer = *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end());
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
> **시뮬레이션 문제.** 
> 
> 덤프 횟수만큼 max_element로 찾은 최고점에서 하나를 빼 min_element로 찾은 최저점에 얹고, 차이가 1 이하면 멈춘 뒤 최고 − 최저를 출력한다. iterator로 위치와 값을 한 번에 다루는 게 핵심.
> 

### 알고리즘 분류

- 구현
- 시뮬레이션