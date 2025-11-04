#include <bits/stdc++.h>
using namespace std;

/*
 * https://www.acmicpc.net/problem/16938
 * prepare camping
 */

int n, L, R, x, cnt = 0;

vector<int> problem;


void input () {
    cin >> n >> L >> R >> x;

    problem = vector<int>(n);

    for (int i = 0; i <n; i++) { // 난이도 입력
        cin >> problem[i];
    }
    // L <= 문제 난이도 합 <= R
    // max (난이도) - min (난이도) >= x

}
void combination(vector<int> arr, bool visited [], int start, int n, int r) {
    if (r == 0) {
        vector<int> new_arr;

        for (int i = 0; i<n; i++) {
            if (visited[i]) {
                // cout << arr[i] << ' ';
                new_arr.push_back(arr[i]);
            }
        }
        // cout << endl;

        int min_ele = * min_element(new_arr.begin(),new_arr.end());
        int max_ele = * max_element(new_arr.begin(),new_arr.end());

        int diff = max_ele- min_ele, difficulty=0;

        for (int j : new_arr) {
            difficulty+=j;
        }

        // cout <<"diff: " << diff << ", difficulty: " << difficulty << '\n';
        // cout << "L: " << L << ", R: " << R << '\n';

        if ((L <= difficulty && difficulty <= R) && diff >= x ) {
            // cout << "cnt ++ \n";
            cnt ++;
        }

        return;
    }

    for (int i = start; i < n; i++) {
        visited[i] = true;
        combination(arr, visited, i + 1, n, r - 1);
        visited[i] = false;
    }
}



void solution() {

    // 캠프에 사용할 문제를 고르는 방법의 수를 출력한다.

    // 경우의 수 == 브루트포스

    /*
     * 1. N만큼 입력된 문제 난이도 정렬
     * 2. O(N^2) 만큼 순회 + 누적하면서 경우의 수 ++?
     */


    for (int i = 2; i <=n; i++) {
        bool visited[16] = {false};
        // cout << n  << " 개 중에서 "  << i  <<  " 개 뽑기" << '\n';
        combination(problem, visited,0, n, i);
    }

    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    input();
    solution();
}
