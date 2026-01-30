# 7571 점 모으기 (실패)

# 문제 소개

[문제 사이트 링크](https://www.acmicpc.net/problem/7571)

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞힌 사람 | 정답 비율 |
| --- | --- | --- | --- | --- | --- |
| 1 초 | 256 MB | 5285 | 1853 | 1462 | 37.574% |

## 문제

행의 크기와 열의 크기가 각각 N인 격자공간에 M개의 점이 있다. N = 4이고 M = 4인 경우의 예가 아래에 있다. 격자공간 왼쪽의 숫자는 행 번호이며, 위의 숫자는 열 번호를 나타낸다. 그리고 격자공간내의 각 사각형의 위치는 (행 번호, 열 번호)로 표시한다

[](https://upload.acmicpc.net/6bcf9e42-6550-4fa6-bd0e-c18fc51637fd/-/preview/)

이제 격자공간에 있는 모든 점들을 하나의 사각형 안으로 모으려고 한다. 어떤 점을 움직일 때는 그 점이 들어있는 사각형에서 상하좌우로 인접한 사각형으로만 움직일 수 있다.

여기에서는 격자공간내의 한 사각형으로 모든 점들을 모을 때 각 점이 움직인 거리의 합을 고려한다. 예를 들어, 위의 점들을 (3,2)에 있는 사각형으로 모을 때 최단거리로 점들을 이동시킨다면 (1,2)에 있는 점의 이동거리는 2이고, (3,1)과 (4,2)에 있는 점의 이동거리는 각각 1이며, (1,4) 에 있는 점의 이동거리는 4이므로 점들이 움직인 거리의 합은 8이다. 또, 위의 모든 점들을 (1,2)의 위치로 모을 때도 점들이 이동한 거리의 합이 8 임을 알 수 있다. 위의 예에서는 점들을 어떤 하나의 사각형으로 모을 때 이동거리의 합이 8보다 작게 되는 사각형은 없다.

이 문제는 주어진 격자공간에 있는 모든 점들을 하나의 사각형으로 모을 때 드는 이동거리의 합의 최솟값을 구하는 것이다. 주어진 격자공간에서는 하나의 사각형에 여러 개의 점들이 들어 있을 수도 있고, 점들을 모을 때는 어떤 점이 들어 있는 사각형으로도 모을 수 있다고 가정한다.

## 입력

첫 줄에는 격자공간의 크기와 점들의 개수를 나타내는 두 정수 N과 M이 하나의 공백을 사이에 두고 주어진다. 다음의 M줄에는 각 줄마다 격자공간내의 점의 위치를 나타내는 두 개의 정수가 하나의 공백을 사이에 두고 주어진다. 단, N의 크기는 1이상 10,000이하이고, M의 크기는 1이상 100,000이하이다.

## 출력

여러분은 모든 점들을 하나의 사각형으로 모을 때 드는 이동거리의 합의 최솟값을 출력해야 한다.

## 예제 입력 1

```
4 4
1 2
1 4
3 1
4 2

```

## 예제 출력 1

```
8
```

---

# 초기 접근 방법

- 뭔가 다른 알고리즘 방법이 떠오르지 않았다.
- 단순 평균을 구해서 빠르게 풀이를 했다.

---

# 풀이 과정

```cpp
#include <bits/stdc++.h>
using namespace std;
// https://www.acmicpc.net/problem/7571

int n, m;

int row_avg, col_avg;

vector<pair<int, int>> dot;
vector<vector<int>> graph;

vector<int> row, col;

void input() {
    cin >> n >> m;

    graph = vector<vector<int>>(n, vector<int>());
    int a, b, row_sum, col_sum;
    for (int i = 0; i<m; i++) {
        cin >> a >> b;
        dot.push_back({a, b});
        row.push_back(a);
        col.push_back(b);
        row_sum += a, col_sum += b;
    }

    row_avg = row_sum / m, col_avg = col_sum / m;
}
bool compare (pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}bool compare2 (pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

void solution() {

    /*sort(dot.begin(), dot.end(), compare);

    for (pair<int, int> a : dot)
    {
        cout << a.first << " " << a.second << endl;
    }

    sort(dot.begin(), dot.end(), compare2);
    for (pair<int, int> a : dot)
    {
        cout << a.first << " " << a.second << endl;
    }*/

    // sort(row.begin(), row.end());
    // sort(col.begin(), col.end());

    /*int x = upper_bound(row.begin(), row.end(), row_avg) - row.begin();
    int y = upper_bound(col.begin(), col.end(), col_avg) - col.begin();*/

    /*cout << x << " " << y << endl;

    for (int i = 0; i < row.size(); i++)
    {
        cout << row[i] << " " ;
    }
    cout << endl;
    for (int i = 0; i < col.size(); i++)
        cout << col[i] << " " ;
    cout << endl;*/

    int sum = 0;
    for (pair<int, int> a : dot)
    {
        sum += abs(a.first - row_avg) + abs(a.second - col_avg);
    }
    cout << sum << '\n';

}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    input();
    solution();

    /*
     *  문제는 주어진 격자공간에 있는 모든 점들을 하나의 사각형으로 모을 때 드는 이동거리의 합의 최솟값을 구하는 것
     *
     *  출발지와 목적지가 정해져있다 = Dijkstra -> 근데 가중치가 없는데?
     *  목적지의 사각형은 어떻게 구할 것 인가?
     *  점의 개수: 최대 10만개 -> 브루트포스는 힘듦.
     *
     *  약간 이분 탐색? 근데 평균으로도 풀리지 않나? 행 기준 정렬, 열 기준 정렬해서 평균을 넘는 점
     *
     *  1 + 2 + 2 + 4 = 9 / 4 = 2.25
     *  1 + 1 + 3 + 4 = 9 / 4 = 2.25
     * -> 버리고 나는 점에 대한 모든 점의 거리 인 듯 하다.
     */

    return 0;
}
```

---

# 결과 & 근거

- 중앙값이어야 하나, 평균으로 착각했다.
    - 정확히는 머릿속으로는 중앙값이네? 라고 생각했으나 몸으로는 평균으로 풀었다.
- 풀이는 다음과 같다
    - 행과 열의 정보값을 배열에 정렬하여 저장한다.
    - 그 다음 각 중앙값을 구하고, 좌표를 구하여 거리를 계산한다.
        - M이 짝수인 경우 중앙 기준 양 옆에 있는 좌표 간 평균을 구하면 그게 중앙점이다.
        - M이 홀수인 경우 M/2 에 있는 좌표가 중앙값이다.
- 간단한 문제였는데 너무 간단하게 생각해버렸다…

### 알고리즘 분류

- 수학
- 정렬