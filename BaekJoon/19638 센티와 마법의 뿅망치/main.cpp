#include <iostream>
#include <queue>
#include <functional>    // greater, less
using namespace std;

int n; // 1 ~ 100000
int height;  // 1~ 2 * 1,000,000,000
int hammer_cnt; // 1 ~ 100000

priority_queue<int> pq;

void input() {
    cin >> n >> height >> hammer_cnt;

    for (int i = 0; i<n; i++) { // 애초에 센티보다 작은 키들은 버릴까..
        int giant_height;
        cin >> giant_height;
        if (height <= giant_height) { // 그래도 모든 경우가 다 크다는 전제 하에
            pq.push(giant_height);
        }
    }
}

void solution() {
    int init = hammer_cnt;
    while (hammer_cnt > 0) {

        if (pq.top() < height) {
            cout << "YES\n" << init-hammer_cnt << '\n';
            return;
        }

        int top = pq.top();
        pq.pop();
        if (top/2 >= height) {
            pq.push(top/2);
        }

        if (pq.empty()) {
            int var = top/2 == 0 ? 1 : top/2;
            cout << "NO\n" << var << '\n';
            return;
        }

        // 출력용
        /*priority_queue<int> new_pq = pq;
        while (new_pq.size() != 0) {
            cout << new_pq.top() << " ";
            new_pq.pop();
        }
        cout << '\n';*/

        hammer_cnt -- ;
    }

    if (pq.top() < height || pq.empty()) { // 만약 모두 작아져서 출력 가능한 경우
        cout << "YES\n" << init - hammer_cnt << '\n';
    }
    else { // top 이 더 크거나, 큐가 비어있지 않은 경우
        cout << "NO\n" << pq.top() << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    input();
    solution();
    // cout << i;
    return 0;
}
