#include <algorithm>
#include <iostream>

using namespace std;

int n, d, t;
int can_play_day; // 오늘 아무 것도 안 해도 과제를 마무리 할 수 있는 방법이 존재함이 보장된다. 오늘은 0일이다.
pair<int, int> task[1000002];

bool compare (pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> d >> t;
        task[i] = {d, t}; // d일 걸리는 과제가 t일 남았어요!
    }
    sort(task, task + n, compare);
    can_play_day = task[n-1].second - task[n-1].first; // 최대로 놀 수 있게 지정.

    for (int i = n-2; i>=0; i--) {
        if (task[i].second < can_play_day) { // 만약 마감일 보다 최대 노는 날이 더 길다면 바꾸기
            can_play_day = task[i].second;
        }
        can_play_day -= task[i].first; // 바꾸고, 과제 일 만큼 빼기
    }

    cout << can_play_day << '\n';
    return 0;
}