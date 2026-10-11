# SWEA 26389, 여행 (성공)

# 문제 소개

[문제 사이트 링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=2&problemLevel=3&problemLevel=4&contestProbId=AZyNUDmaATzHBIRj&categoryId=AZyNUDmaATzHBIRj&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=4&pageSize=10&pageIndex=1)

세준이는 무한한 이차원 평면 위에서 살고 있다.

세준이의 집은 원점이며, 자신의 집에서 출발하여 N일 동안 여행을 한 후, 다시 자신의 집으로 돌아가려 한다.

세준이의 여행 계획을 자세하게 말하면 다음과 같다

-  여행의 첫 번째 날은 집에서 출발한다.

-  i (1 ≤ i ≤ N)번째 날에는 동서남북 중 Ai 방향으로 양의 정수 거리만큼 이동한다. 거리는 양의 정수이기만 하면 마음대로 정할 수 있다.

-  N번째 날에는 이동을 끝낸 순간 집에 도착하여야 한다.

길이 N의 문자열 A가 주어질 때, 여행의 마지막 날에 집에 돌아올 수 있도록, 각 날의 이동 거리를 정할 수 있는지 판별하는 프로그램을 작성하시오.

**[입력]**

첫 번째 줄에 테스트 케이스의 수 TC가 주어진다.

이후 TC개의 테스트 케이스가 새 줄로 구분되어 주어진다.

각 테스트 케이스는 다음과 같이 구성되었다.

-  첫 번째 줄에 문자열 A가 주어진다. 문자열 A는 네 개의 문자 ‘N’, ‘W’, ‘S’, ‘E’ 로 이루어져 있으며, 이는 각각 ‘북쪽’, ‘서쪽’, ‘남쪽’, ‘동쪽’ 을 의미한다. 문자열 A의 길이는 1 이상 1000 이하이다.

**[출력]**

각 테스트 케이스 마다 한 줄씩, 정할 수 있다면 “Yes”, 없다면 “No” 를 출력하라.

---

# 풀이 과정

- 양의 정수로써, 방향에 대한 가는 거리는 내 마음이다.
    - 즉 거리와는 상관 없다는 뜻이다
- "반대 문자가 있어야 한다"는 직관으로 알고리즘을 풀었다.
    - 20분 컷

```cpp
string m;

vector<bool> v (4, false);
int travel (string m) {

	// 0 = Yes, 1 == No
	for (int i = 0; i < m.length(); i++) {
		if (m[i] == 'N' && v[2] == false) {
			return 1;
		}
		if (m[i] == 'W' && v[3] == false) {
			return 1;
		}
		if (m[i] == 'S' && v[0] == false) {
			return 1;
		}
		if (m[i] == 'E' && v[1] == false) {
			return 1;
		}
	}
	return 0;

}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> m;
		v.assign(4, false);

		for (int i = 0; i < m.length(); i++) {
			char move = m[i];

			//  거리에는 제한이 없어
			// 단순하게 돌아올 수만 있다면 ㅇㅋ
			// 그냥 반대끼리만 있음 되나?

			if (move == 'N') {
				v[0] = true;
			}
			else if (move == 'W') {
				v[1] = true;
			}
			else if (move == 'S') {
				v[2] = true;
			}
			else if (move == 'E') {
				v[3] = true;
			}
		}

		int answer = travel(m);
		if (answer == 1) {
			cout<<"No"<<endl;
		}
		else {
			cout<<"Yes"<<endl;
		}

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
```

---

# 결과 & 근거

- 예제 EEWEEEW 를 EENEEEN 으로 잘못 읽었다. 그래서 "x/y 양쪽으로 멀어지기만 하는데
어떻게 돌아오지?"로 오해했다.
- *"문제가 이상하다"는 생각이 들면 99% 내가 오독했다는 것….*

### 알고리즘 분류

- 구현
- 문자열
- 애드혹 / 수학적 관찰
- 그리디 (거리 조절로 상쇄)