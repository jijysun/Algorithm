# SWEA, 26502 쉬운 삼각형 (성공)

# 문제 소개

[문제 사이트 링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=2&problemLevel=3&problemLevel=4&contestProbId=AZz7DObKASzHBIRj&categoryId=AZz7DObKASzHBIRj&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=4&pageSize=10&pageIndex=1)

2차원 평면 위에 N개의 서로 다른 점이 있다. 각 점의 x, y 좌표는 정수이다. 당신은 이 중 서로 다른 3개의 점을 골라서 삼각형을 만들려고 한다. 이 때 삼각형의 한 변은 x축에 평행해야 하고, 다른 한 변은 y축에 평행해야 한다.

당신이 만들 수 있는 삼각형의 최대 넓이는 얼마인가? 넓이에 2를 곱하면 정수가 되니, 최대 넓이에 2를 곱해 출력하라.

만들 수 있는 삼각형이 최소 하나 존재한다.

**[입력]**

첫 번째 줄에 테스트 케이스의 수 TC가 주어진다.

이후 TC개의 테스트 케이스가 새 줄로 구분되어 주어진다.

각 테스트 케이스는 다음과 같이 구성되었다.

- 첫 번째 줄에 점의 수 N이 주어진다. (3 ≤ N ≤ 100)
- 이후 N개의 줄에 점의 좌표 xi, yi 가 주어진다. 모든 좌표는 서로 다르고, 좌표는 절댓값이 10000 이하인 정수이다.

**[출력]**

각 테스트 케이스 마다 한 줄씩, 문제의 정답을 출력하라.

```cpp
1
4
0 0
0 1
1 0
1 2
-> 2
```

---

# 풀이 과정

- 전체 좌표 수가 100개 밖에 되지 않는다.
    - 이는 nC3을 고려해보아도 충분히 1초를 넘기지 않는다.
    - 그렇기에 조합을 떠올렸다
- 한 변은 x축 평행, 다른 한 변은 y축 평행이므로 세 점은 (a,b),(c,b),(a,d) 형태다.
- 넓이에 2를 곱하라고 했으므로 삼각형 공식이 필요 없다. 두 변 길이의 곱이 곧 답이다.
- C(100,3) = 161,700 이므로 조합 완전탐색으로 충분하다.
- 세 점을 뽑고 세 변을 돌며, x 같으면 y축 평행(길이 |dy|), y 같으면 x축 평행(길이 |dx|).
    - 양쪽이 모두 존재하면 x * y 가 넓이×2 다.

```cpp

vector<pair<int, int>> pos;
vector<pair<int, int>> tri;

int max_size = 0;

void combi (int start) {
	
	if (tri.size() == 3) {
		int x = 0, y = 0;

		for (int i =0; i<3; i++) {
			pair<int, int> p1 = tri[i], p2 = tri[(i+1)%3]; // 다음

			if (p1.first == p2.first && p1.second != p2.second) {
				y = max(y, abs(p2.second - p1.second));
			}
			if (p1.first != p2.first && p1.second == p2.second) {
				x = max(x, abs(p2.first - p1.first)); // x 축 평행
			}

		}

		if (x != 0 && y != 0) { // 36분 평행이 여러 경우 있을 때 해결
			max_size = max(max_size, x*y); // ANSWER
		}
		return;
	}

	for (int i = start; i<pos.size(); i++) {
		tri.push_back(make_pair(pos[i].first, pos[i].second));
		combi(i+1);
		tri.pop_back();
	}

}

int main(int argc, char** argv)
{
	int test_case;
	int T, tc;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		
		cin >> tc;

		for (int i = 0; i < tc; i++) {
			int x = 0, y = 0;
			cin >> x >> y;
			pos.push_back(make_pair(x,y));
		}
		combi (0);
		cout << max_size << endl;
		pos.clear();
		max_size = 0;
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
```

---

# 결과 & 근거

- 코딩 이슈로 시간이 좀 끌리긴 했으나, 43분 클리어
- 사실 직각 꼭짓점을 고정하면 두 변이 서로 독립이다.
    - 그러면 조합이 필요 없다.
    - 각 점 (a,b) 를 직각 꼭짓점으로 두고 x_len = 같은 y 를 가진 점들 중 나와 가장 먼 거리 
    = max(a - minX[b], maxX[b] - a) y_len 
    = 같은 x 를 가진 점들 중 나와 가장 먼 거리 
    = max(b - minY[a], maxY[a] - b) 넓이×2 
    = x_len * y_len

```cpp
int solve(vector<pair<int,int>>& p) {
    unordered_map<int,int> minX, maxX, minY, maxY;

    // y별 x 범위, x별 y 범위를 한 번 순회로 구한다
    for (auto& [x, y] : p) {
        if (!minX.count(y)) { minX[y] = maxX[y] = x; }
        else { minX[y] = min(minX[y], x); maxX[y] = max(maxX[y], x); }

        if (!minY.count(x)) { minY[x] = maxY[x] = y; }
        else { minY[x] = min(minY[x], y); maxY[x] = max(maxY[x], y); }
    }

    int best = 0;
    for (auto& [x, y] : p) {              // 각 점을 "직각 꼭짓점"으로 가정
        int xlen = max(x - minX[y], maxX[y] - x);   // 같은 행에서 가장 먼 거리
        int ylen = max(y - minY[x], maxY[x] - y);   // 같은 열에서 가장 먼 거리
        if (xlen > 0 && ylen > 0)                   // 양쪽에 동료 점이 있어야 삼각형
            best = max(best, xlen * ylen);
    }
    return best;
}
```

### 알고리즘 분류

> 조합 완전탐색 기하 문제. 
`C(N,3)`으로 세 점을 뽑아 x축 평행 변과 y축 평행 변이 각각 하나씩 존재하면 두 변 길이의 곱이 넓이×2가 되는 알고리즘. 세 점이 서로 다르면 각 방향 평행 변은 최대 1개뿐이므로 `x != 0 && y != 0` 한 줄로 직각 판정이 끝나고, 더 나아가 **직각 꼭짓점을 고정하면 두 변이 독립**이라 행·열별 최소/최대 좌표만으로 `O(N)`에 풀리는 게 핵심.
> 
-