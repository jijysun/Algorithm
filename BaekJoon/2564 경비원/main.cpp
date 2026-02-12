#include <bits/stdc++.h>

using namespace std;
// https://www.acmicpc.net/problem/2564

int x, y, store, answer;
vector<pair<int, int>> pos;
pair<int, int> p;

void input() {

    cin  >> x >> y;
    cin >> store;

    pos.resize(store);

    int a, b;
    for (int i = 0; i < store; i++) {
        // 상점

        cin >> a >> b;
        if (a == 1) {
            pos[i].first = y, pos[i].second = b;
        }
        else if (a == 2) {
            pos[i].first = b, pos[i].second = 0;
        }
        else if (a == 3) {
            pos[i].first = 0, pos[i].second = y-b;
        }
        else if (a == 4) {
            pos[i].first = x, pos[i].second = y-b;
        }
        cout << a << "," << b <<" -> " << pos[i].first << " " << pos[i].second << endl;

        // 좌표를 바로 치환?
        // 북 -> y, n  / 남 = n, 0
        // 서 -> 0, y-n  / 동 = x, y-n
    }

    // 동근
    cin >> a >> b;
    if (a == 1) {
        p.first = y, p.second = b;
    }
    else if (a == 2) {
        p.first= b, p.second = 0;
    }
    else if (a == 3) {
        p.first = 0, p.second = y-b;
    }
    else if (a == 4) {
        p.first = x, p.second = y-b;
    }
    cout << a << "," << b <<" -> " << p.first << " " << p.second << endl;
}

void solution() {

    /*
     * first = 1,북 2,남 3,서 4,동
     * second = 1,2 -> 왼 경계 / 3,4 -> 위 경계
     *
     */

    for (int i = 0; i < pos.size(); i++) {

        // 각 경우 수 보다 시계 vs 반시계 하는 게 나을 듯
        // 꼭짓점 기준 순환...?
        // 1.1  / x.1
        // 시계, 반시계 표현을 어떻게?

        // 솔직히 그냥 입력 수가 작아서 if 문 엄청 하면 되는 거 같은데


        // 전체 테두리로만 이동.

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input(), solution();
    return 0;
}