#include <iostream>
#include <regex>

using namespace std;

int n, m, a, b, answer, checked=false;

bool visited[100001];
int sector [100001];
vector<pair<int, int>> arr; // 어쨌든 피해야 하는 요소임.

void input() {
    cin >> n >> m >> a >> b;

    for (int i = 0; i<m; i++) {
        int a1, a2;
        cin >> a1 >> a2;

        /*for (int j = a1; j<=a2; j++) { // 이게 엄청 많아서 시간초과되는 듯?
            sector[j] = 1;
        }*/

        arr.push_back({a1, a2});
    }

    if (a>b) {
        int temp = a;
        a = b;
        b = temp;
    }
}

void dfs (int dog, int cnt) {
    // cout << "dog: " << dog <<'\n';

    if (dog == n) {
        answer = cnt;
        checked = true;
        return;
    }
    if (dog + a > n) { // 작은 수 더해서 넘어가면 지금 경로는 쓸모 없다.
        return;
    }
    if (dog + b <= n) {
        // 검사 로직
        bool search = false;
        for (int j = 0; j<arr.size(); j++) {
            if (arr[j].first <= sector[dog+b] && sector[dog+b] <= arr[j].second ) {
                search = true;
            }
        }
        if (!search) {
            visited[dog+b] = true;
            dfs(dog+b, cnt+1);
        }
    }
    if (dog + a <= n) { // not else if
        bool search = false;
        for (int j = 0; j<arr.size(); j++) {
            if (arr[j].first <= sector[dog+a] && sector[dog+a] <= arr[j].second ) {
                search = true;
            }
        }
        if (!search) {
            visited[dog+a] = true;
            dfs(dog+a, cnt+1);
        }
    }
}

void solution() {
    dfs(0, 0);
    // 일단 이전 값 활용하는 DP가 보여


    // 최소 횟수이어야 되니까 큰 수 위주로 더해가는 느낌
    // cout <<"\n\n\n-------\n"<<'\n';
    if (checked) {
        cout << answer << '\n';
    }
    else {
        cout << "-1" <<'\n';
    }

}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    input();
    solution();

    return 0;
}
