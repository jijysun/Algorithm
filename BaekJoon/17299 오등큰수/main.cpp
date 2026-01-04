#include <bits/stdc++.h>

using namespace std;
// https://www.acmicpc.net/problem/17299

int n;
vector<int>arr;

int checking[1000001];

stack<int>s;

void solution();


void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
        checking[x]++;
        s.push(x);
    }
}

void solution() {



    for (int i = 0; i<arr.size()-1; i++) {




        /*
         * 문제
         * - 내 기준 우측에 있는 모든 큰 수를 확인해야 한다.
         * - upper bound로 빠르게 탐색할 수 있나? -> 정렬이 필요 = x
         * - 뭔가 이분 탐색이 필요한데
         *
         * 삽입 하면서 할 수 있나?
         * 근데 지금 보면 해당 되는 오등큰수를 모두 출력 중.
         *
         */

    }

    stack<int>s;
    s.push(checking[arr[arr.size()-1]]);
    for (int i = n-2;  i>=0; i--) {

        int checkingNum = checking[arr[i]];
        while (!s.empty() && checkingNum >= checking[s.top()]) { // 등장 횟수 크고, 가장 왼쪽
            s.pop();
        }

        if (s.empty()) {
            // print용 변수에 -1 추가
        }
        else {
            // print용 변수에 stack.top 추가
        }
        s.push(arr[i]);
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input(), solution();
    return 0;
}
