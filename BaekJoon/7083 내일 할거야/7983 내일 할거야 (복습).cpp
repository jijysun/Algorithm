#include <algorithm>
#include <iostream>

using namespace std;

int n, d, t;
int can_play_day; // ���� �ƹ� �͵� �� �ص� ������ ������ �� �� �ִ� ����� �������� ����ȴ�. ������ 0���̴�.
pair<int, int> task[1000002];

bool compare (pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> d >> t;
        task[i] = {d, t}; // d�� �ɸ��� ������ t�� ���Ҿ��!
    }
    sort(task, task + n, compare);
    can_play_day = task[n-1].second - task[n-1].first; // �ִ�� �� �� �ְ� ����.

    for (int i = n-2; i>=0; i--) {
        if (task[i].second < can_play_day) { // ���� ������ ���� �ִ� ��� ���� �� ��ٸ� �ٲٱ�
            can_play_day = task[i].second;
        }
        can_play_day -= task[i].first; // �ٲٰ�, ���� �� ��ŭ ����
    }

    cout << can_play_day << '\n';
    return 0;
}