# 11722 가장 긴 감소하는 부분 수열 (실패)

# 문제 소개

[문제 사이트 링크](https://www.acmicpc.net/problem/11722)

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞힌 사람 | 정답 비율 |
| --- | --- | --- | --- | --- | --- |
| 1 초 | 256 MB | 43047 | 26477 | 21788 | 62.414% |

## 문제

수열 A가 주어졌을 때, 가장 긴 감소하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 30, 10, 20, 20, 10} 인 경우에 가장 긴 감소하는 부분 수열은 A = {10, **30**, 10, **20**, 20, **10**}  이고, 길이는 3이다.

## 입력

첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

## 출력

첫째 줄에 수열 A의 가장 긴 감소하는 부분 수열의 길이를 출력한다.

---

# 초기 접근 방법

- dp로 접근해야 하는 것을 깨달았으나, 어떻게 접근해야 할 지 모르겠다.
    - dp[i] = 어…..
- 또한 중간 가장 긴 감소 수열 로직을 정확하게 구현하는 것이 중요하다,.

---

# 풀이 과정

- 첫 번째 틀린 코드
    
    ```cpp
    
    #include <bits/stdc++.h>
    using namespace std;
    
    /*
     * https://www.acmicpc.net/problem/11722
     * Longest decreasing partial sequence
     */
    
    // double a, b;
    
    int n;
    vector<int> arr;
    
    void input() {
        cin >> n;
        arr = vector<int> (n);
        for (int i = 0; i<n; i++) {
            cin >> arr[i];
        }
    }
    
    void solution() {
    
        int  max_sqe_size=0;
        for (int i = 0; i<n; i++) {
            int pos=i, sqe_size = 1;
    
            for (int j=i; j<n; j++) {
                if (arr[pos] -1 == 0) { // 더이상 감소 불가능.
                    break;
                }
                if (arr[pos] > arr[j]) {
                    if (j+1<n && arr[j] < arr[j+1]  && arr[j+1] <= arr[pos]) {
                        continue;
                    }
                    pos = j; sqe_size++;
                }
            }
            max_sqe_size = max(sqe_size, max_sqe_size);
            // cout << sqe_size << '\n';
        }
    
        cout << /*"\n------\n" <<*/ max_sqe_size << '\n';
    
    }
    
    int main() {
        ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        input();
        solution();
    }
    
    ```
    
- 두 번째 틀린 코드
    
    ```cpp
    #include <bits/stdc++.h>
    using namespace std;
    
    /*
     * https://www.acmicpc.net/problem/11722
     * Longest decreasing partial sequence
     */
    
    // double a, b;
    
    int n;
    vector<int> arr;
    pair<int, int> dp [1001];
    
    void input() {
        cin >> n;
        arr = vector<int> (n);
        for (int i = 0; i<n; i++) {
            cin >> arr[i];
        }
    }
    
    void solution() {
        if (n == 1) {
            cout << 1 << '\n';
            return;
        }
    
        int max_sqe_size=0;
        dp[n-1] = {arr[n-1], 1};
    
        for (int i = n-2; i>=0; i--) {
            int pos=i, sqe_size = 1;
    
            for (int j=i; j<n; j++) {
                if (arr[pos] -1 == 0) { // 더이상 감소 불가능.
                    break;
                }
                if (arr[pos] > arr[j]) {
                    if (j+1<n && arr[j] <= arr[j+1]  && arr[j+1] < arr[pos] ) {
                        continue;
                    }
                    pos = j; sqe_size++;
                }
            }
    
            // int max_ele = * max_element(arr.begin()+i, arr.end());
            dp[i] = {arr[i], sqe_size};
    
            int pre = 0;
            for (int j = i; j<n; j++) {
                if (arr[i] > dp[j].first, sqe_size < dp[j].second) {
                    pre = dp[j].second;
                }
            }
    
            max_sqe_size = max(max(sqe_size, pre+1), max_sqe_size);
            // cout << sqe_size << '\n';
        }
    
        cout << /*"\n------\n" <<*/ max_sqe_size << '\n';
    
    }
    
    int main() {
        ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        input();
        solution();
    }
    ```
    

---

# 결과 & 근거

- DP 점화식을 아직 제대로 세우지 못하는 것 같다.
    - DP[i]는 i 번 인덱스 까지의 최대 길이이다.
    - 이제 보면 잘 세웠는데…?
- 핵심 고민 요소는 잘 짚었으나순서를 고민하는 것과 DP 갱신에서
    - 현재 인덱스 값 < 더 작은 인덱스 값?
    - 현재 비교하는 인덱스 값이 최대가 될 수 있는가에 대한 비교.
- 이 2 가지 고민이 핵심이고, 잘 짚었는데 코드로 잘 표현하지 못한 것 같다.

https://yabmoons.tistory.com/112

### 알고리즘 분류

- 다이나믹 프로그래밍