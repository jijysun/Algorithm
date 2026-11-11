# SWEA 1859, 백만 장자 프로젝트 (실패)

# 문제 소개

[문제 사이트 하이퍼링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=2&problemLevel=3&contestProbId=AV5LrsUaDxcDFAXc&categoryId=AV5LrsUaDxcDFAXc&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=11)

25년 간의 수행 끝에 원재는 미래를 보는 능력을 갖게 되었다. 이 능력으로 원재는 사재기를 하려고 한다.

다만 당국의 감시가 심해 한 번에 많은 양을 사재기 할 수 없다.

다음과 같은 조건 하에서 사재기를 하여 최대한의 이득을 얻도록 도와주자.

1. 원재는 연속된 N일 동안의 물건의 매매가를 예측하여 알고 있다.
2. 당국의 감시망에 걸리지 않기 위해 하루에 최대 1만큼 구입할 수 있다.
3. 판매는 얼마든지 할 수 있다.

예를 들어 3일 동안의 매매가가 1, 2, 3 이라면 처음 두 날에 원료를 구매하여 마지막 날에 팔면 3의 이익을 얻을 수 있다.

**[입력]**

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스 별로 첫 줄에는 자연수 N(2 ≤ N ≤ 1,000,000)이 주어지고,

둘째 줄에는 각 날의 매매가를 나타내는 N개의 자연수들이 공백으로 구분되어 순서대로 주어진다.

각 날의 매매가는 10,000이하이다.

**[출력]**

각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고, 최대 이익을 출력한다.

**[예제 풀이]**

1번째 케이스는 아무 것도 사지 않는 것이 최대 이익이다.

2번째 케이스는 1,2일에 각각 한 개씩 사서 세 번째 날에 두 개를 팔면 10의 이익을 얻을 수 있다.

---

# 풀이 과정

- 미래 가격을 다 알고 있으니까, 지금 가격보다 큰 값이 뒤에 있으면 사고 없으면 판다고 생각했다.
- 손 예제 5개로 규칙을 확인했다 (`1 1 3 1 2`, `5 7 1 6 3`, `8 7 1 2 6 3 4 5 7` 등).
- 전체 최댓값을 찾아서 그 전까지 사고, 최댓값에서 팔고, 다음 최댓값을 `max_element`로 다시 찾는 방식으로 구현했다.
- 23분 만에 7/10이 나왔다. 결과는 다 나와서 TLE는 아니라고 봤는데, input 파일로 채점하면 전혀 다른 값이 나왔다.

```cpp
#include<iostream>
#include <bits/stdc++.h>

using namespace std;

/*
 * 한 번에 많은 양 사재기를 통한 최대한의 이득을 보기.
 *  1. 원재는 연속된 N일 동안의 물건의 매매가를 예측하여 알고 있다.
 *  2. 당국의 감시망에 걸리지 않기 위해 하루에 최대 1만큼 구입할 수 있다.
 *  3. 판매는 얼마든지 할 수 있다.
 *
 *  3일 동안의 매매가가 1, 2, 3 이라면 처음 두 날에 원료를 구매하여 마지막 날에 팔면 3의 이익을 얻을 수 있다.
 *
 *
 *  구매 결정 및 큰 값을 만났을 때 매매, 매도 결정이 중요해,
 * - 미래를 보는 능력에서 힌트?
 * - 지금 값 기준 더 큰값이 존재? 구매.
 * - 지금 값 기준 작은 값 밖에 없다? 판매.
 *
 * ㅁ
 */

/*1 1 3 1 2 기준
 * 1 -> 더 큰값이 있다. 구매
 * 1 -> 구매
 * 3 -> 판매 4 이득
 * -> upper_bound 였나? 그거 활용하면 좋을 거 같은데.
 *
 * 3 5 9 기준
 * - 3 때 파는게 제일 큼!
 * - 5 때 파는게 제일 큼!
 *
 *
 * 5 3 1 7 2 8 6
 * - 5 -> 8 때 파는 게 좋음 구매
 *
 *
 *
 * 5 7 1 6 3 기준
 * 5 구매
 * 7 판매 -> 2이득
 * 1 구매
 * 6 판매 -> 5이득
 * 3 X -> 총 7
 *
 * 8 7 1 2 6 3 4 5 7 라는 값이 있다 치자
 * 8 -> 제일 큼 -> 패스
 * 7 -> 패스?
 * 1 -> 구매
 * 2 -> 구매
 * 6 -> 구매
 * 3 -> 구매
 * 4 -> 구매
 * 5 -> 구매
 * 7 -> 판매? 21의 이득? 이게 맞나?
 */

vector<int> arr;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	vector<int> v = {1, 2, 5, 4, 3};

	// cout << max_element(v.begin()+5, v.end())-v.begin() << endl;

	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;
		arr.assign(n, 0); // 최대 1,000,000

		int max_val=0, max_idx=0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];

			if (max_val < arr[i]) {
				max_val = arr[i];
				max_idx = i;
			}
		}
		// cout << "첫 최대치 및 위치: " << max_val << ", " << max_idx << endl;

		vector<int> v;
		int answer = 0;
		for (int i = 0; i < n; i++) {

			// 만약 지금이 최대치라면? 팔고 다음 최대치 찾기.
			if (max_idx == i) {

				for (int j = 0; j<v.size(); j++) { // 팔기
					answer += max_val - v[j];
				}
				v.clear();

				// 다음 최대치 찾기
				// if (i == n-2) break;
				max_val = *max_element(arr.begin()+i+1, arr.end());
				max_idx = max_element(arr.begin()+i+1, arr.end())-arr.begin();

				if (max_idx > arr.size()) break;

				// cout << "다음 최대치 및 위치: " << max_val << ", " << max_idx  << endl;

			}
			else {
				v.push_back(arr[i]);// 최대치가 아니라면, 그동안은 사기.
			}
		}

		cout << "#" << test_case << " " << answer << endl;
	}

	/*
	 * 23분 채점 결과 7/10
	 * - TLE는 아닌게, 모든 입력값에 대해 결과는 뱉음
	 *
	 * 하지만 input 파일로 채점한 결과 전혀 다른 값을 뱉음. 아마 범위와 접근에서 잘못된 거 같아.
	 *
	 */

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
```

---

# 결과 & 근거

**실패 (23분, 7/10)**

- 이익이 최대 N(10⁶) × 가격(10⁴) = 10¹⁰이라서 `int answer`가 오버플로났다. 이게 "전혀 다른 값"의 원인이다.
- 최댓값을 만날 때마다 남은 구간을 `max_element`로 다시 훑어서, 내림차순 입력에선 O(N²)이 된다.
- 뒤에서부터 "이후 최고가"를 갱신하며 한 번만 돌면 같은 아이디어가 O(N)이 된다.

```cpp
#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	// N이 최대 100만 → 입력이 많으니 입출력 가속
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_case;
	int T;

	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; i++) cin >> arr[i];

		// 이익 최대 ≈ N(10^6) × 가격(10^4) = 10^10 → int(약 2.1×10^9) 초과 → long long 필수
		long long answer = 0;

		// 뒤에서부터 보면 max_val = "오늘 이후(오늘 포함)의 최고가"
		int max_val = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (arr[i] > max_val) {
				// 오늘이 이후 최고가 → 오늘은 사지 않는다 (산다면 이 날 팔 뿐, 이득 0)
				// 앞날들은 이제 이 가격에 팔면 된다 → 최고가 갱신
				max_val = arr[i];
			} else {
				// 오늘보다 비싼 날이 뒤에 있다 → 오늘 1개 사서 그 최고가에 판다
				answer += max_val - arr[i];
			}
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
> 역방향 그리디 문제. 
> 
> 뒤에서부터 "이후 최고가"를 갱신하며, 그보다 싼 날은 하나 사서 그 최고가에 판 이익을 더한다. 뒤집어서 한 번만 순회하는 것과 이익 합을 long long으로 받는 게 핵심.
> 

### 알고리즘 분류

- 그리디
- 구현