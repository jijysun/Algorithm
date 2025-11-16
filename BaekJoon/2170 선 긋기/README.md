# 2170 선 긋기

# 문제 소개

[문제 사이트 링크](https://www.acmicpc.net/problem/2170)

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞힌 사람 | 정답 비율 |
| --- | --- | --- | --- | --- | --- |
| 1 초 | 192 MB | 34497 | 12970 | 9240 | 36.198% |

## 문제

매우 큰 도화지에 자를 대고 선을 그으려고 한다. 선을 그을 때에는 자의 한 점에서 다른 한 점까지 긋게 된다. 선을 그을 때에는 이미 선이 있는 위치에 겹쳐서 그릴 수도 있는데, 여러 번 그은 곳과 한 번 그은 곳의 차이를 구별할 수 없다고 하자.

이와 같은 식으로 선을 그었을 때, 그려진 선(들)의 총 길이를 구하는 프로그램을 작성하시오. 선이 여러 번 그려진 곳은 한 번씩만 계산한다.

## 입력

첫째 줄에 선을 그은 횟수 N (1 ≤ N ≤ 1,000,000)이 주어진다. 다음 N개의 줄에는 선을 그을 때 선택한 두 점의 위치 x, y (-1,000,000,000 ≤ x < y ≤ 1,000,000,000)가 주어진다.

## 출력

첫째 줄에 그은 선의 총 길이를 출력한다.

---

# 초기 접근 방법

- 뭔가 특별한 알고리즘 방법은 없는 듯 하다.
- 중간 구현에서 정렬 알고리즘이 필요로 하긴 했다.
    - 선 길이가 매우 긴 선 기준으로 정렬한다.
    - 이는 만약 맨 처음부터 “모든 선을 포함할 수 있는 큰 선” 기준으로 순회하면, 선 안에 포함시켜 내부 순회할 리스트 변수의 길이를 줄일 수 있다.

---

# 풀이 과정

```cpp

#include <bits/stdc++.h>
using namespace std;

int n, sum;

vector<pair<int, int>> pos, lineList;

void input() {

    cin >> n;
    pos = vector<pair<int, int>> (n);

    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        pos[i] = {a, b};
    }
}

bool compare (pair <int,int> p, pair <int,int> p2) {
    return p.second - p.first > p2.second - p2.first;
}

void solution() {

    // 선의 총 길이 출력 -> 1차원임!!!
    // 없으면 추가, 있으면 늘리기.

    // pos 정렬이 필요하면 좋겠다. 제일 큰 라인 구하면 굳이 추가 안되니까 -> 이래도 시간 초과.
    sort(pos.begin(), pos.end(), compare);

    // 일단 추가
    lineList.push_back(pos[0]);

    /*
     * result = 시간초과 ( O(n) 이라 예상했는데, O(n^2) )
     * 내부 계속해서 추가되는 것에 의해 O(n^2) 에 가까워 지는 듯 하다.
     */
    for (int i = 1; i<n; i++) {
        bool checked = false;
        for (int j = 0; j<lineList.size(); j++) {
            if(pos[i].first < lineList[j].first &&  lineList[j].first <= pos[i].second && pos[i].second <= lineList[j].second) {
                // 1. 앞으로 늘리기
                // printf("앞으로 늘립니다\n");
                lineList[j].first = pos[i].first, checked = true;
                break;
            }
            if (pos[i].first >= lineList[j].first && pos[i].second <= lineList[j].second) {
                // 2. 중간 인 경우 continue
                // printf("포함시킵니다.\n");
                checked = true;
                break;
            }
            if (lineList[j].second >=pos[i].first && pos[i].first >= lineList[j].first && pos[i].second > lineList[j].second) {
                // 3. 뒤로 늘리기
                // printf("뒤로 늘립니다\n");
                lineList[j].second = pos[i].second, checked = true;
                break;
            }
            if (pos[i].first < lineList[j].first && pos[i].second > lineList[j].second) {
                // 4. 포함하는 경우
                // printf("앞뒤로 늘립니다\n");
                lineList[j].first = pos[i].first, lineList[j].second = pos[i].second, checked = true;
                break;
            }
        }
        if (!checked) {
            // printf("새로 추가합니다.\n");
            lineList.push_back(pos[i]);
        }
    }
    for (pair<int, int> line: lineList) {
        sum+= line.second - line.first;
    }
    cout << sum << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    input();
    solution();
}

```

---

# 결과 & 근거

- 맨 처음은 시간 초과가 발생하였다.
    - 이후 정렬을 통해 내부적으로 순회할 리스트의 “원소 추가” 하는 경우의 수를 줄였는데도 틀렸다.
- 접근은 확실히 좋았던 것 같지만 더 좋은 접근이 존재했다.
    - 실제 펜을 두고 생각하면 편하다.
    - 가장 왼쪽에 있는 점을 기준으로 정렬을 한다.
    - 그대로 순회하면서 펜이 끊기지 않는 점을 갱신하면서, 선분의 총 길이를 구하는 것이다.
- 즉 내부적인 요소를 굳이 새로 만들고, 추가할 필요도 없었다…
    - 쉬운 문제라고 생각했는데 어렵게 푼 것 같다.

### 알고리즘 분류

- 정렬
- 스위핑