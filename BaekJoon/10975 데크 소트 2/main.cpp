#include <iostream>
#include <queue>
#include <regex>

using namespace std;

int n; // N<= 50

int top, end, cnt; // deque의 양 끝을 저장하는 게.
queue<int> num;
// vector<pair<int, int>> deque_info;
vector<deque<int> > dequeList;
map<int, int> visited;


void input() {
    cin >> n;

    int a;
    for (int i = 0; i < n; i++) {
        // 뭔가 입력에서 끝날 거 같은데
        cin >> a;
        num.push(a);
        visited[a] = 1;
    }
}


void solution() {
    // 뭔가 그리디 느낌도 나는 거 같은데...

    deque<int> new_deque; // 넣기
    new_deque.push_back(num.front());
    dequeList.push_back(new_deque);
    cnt ++;
    num.pop();

    while (!num.empty()) {
        int a = num.front();

        // 삽입될 때, 이전 데크의 back과 삽입 대상 사이에 숫자가 리스트에 있는 지 알아야 함.
        bool isInserted = false;
        for (deque<int> q: dequeList) {

            // 사이에 들어갈 수 있으면 continue. 사이에 들어갈 것이 없으면 insert
            // 여기서 뭔가 최선의 선택을 할 수 있어야 해.
            if (q.back() < a) {
                // 찾기!
                bool check = false;
                for (int i = q.back(); i<a; i++) {
                    if (visited[i]) { // 만약 사이에 들어갈 것이 있다면
                        check = true;
                        break; // 그냥 넘겨버리기
                    }
                }
                if (!check) {
                    q.push_back(a);
                    isInserted = true;
                }
            }
            else if (q.front() > a) {
                // 찾기!
                bool check = false;
                for (int i = a; i<q.front(); i++) {
                    if (visited[i]) { // 만약 사이에 들어갈 것이 있다면
                        check = true;
                        break; // 그냥 넘겨버리기
                    }
                }
                if (!check) {
                    q.push_front(a);
                    isInserted = true;
                }
            }

        }

        if (!isInserted) { // 넣어진 경우가 없는 경우 새로 만들기
            deque<int> new_deque; // 넣기
            new_deque.push_back(a);
            dequeList.push_back(new_deque);
            cnt++;
        }
        num.pop();
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    input();
    solution();


    for (deque<int> q : dequeList) {
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop_front();
        }
        cout << '\n';
    }

    cout << cnt << '\n';
    return 0;
}
