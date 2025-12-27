#include <bits/stdc++.h>

using namespace std;

int n, m, i, j;


struct station {
    int pre, cur, next;
};

vector<station> arr(0);

map<int, int> hashStation;


void input() {
    cin >> n >> m;
    string s;

    for (int i1 = 0; i1 < n; i1++) {
        station temp;

        cin >> temp.cur;
        hashStation[temp.cur] = i1;

        arr.push_back(temp);
    }

    // connect
    for (int i = 1; i < n - 1; i++) {
        arr[i].pre = arr[i - 1].cur, arr[i].next = arr[i + 1].cur;
    }
    arr[0].pre = arr[n - 1].cur, arr[0].next = arr[1].cur;
    arr[n - 1].pre = arr[n - 2].cur, arr[n - 1].next = arr[0].cur;


    /*
     * BN, BP: 리스트 사이에 끼워넣는다.
     * CP, CN: 리스트 이전, 다음 값을 삭제한다.
     *
     * 그 즉슨, 일반 알고리즘으로 구현하면 데이터 이동에 대한 시간 초과가 발생한다.
     * 양방향 연결 리스트 느낌으로 구현해야 한다.
     * struct 배열?
     */

    for (int i1 = 0; i1 < m; i1++) {
        cin >> s;

        // 고유 번호 어떻게 이렇게 빨리 찾지?
        // map을 도입해야 하나?
        // map[i] = arr의 인덱스?   j는 상관 없어.


        if (s == "BN") {
            // i에 대한 다음 역 고유 번호 출력 + 다음 역 설립
            cin >> i >> j;
            int cur_index = hashStation[i];

            cout << arr[cur_index].next << '\n';

            station temp;
            temp.cur = j, temp.pre = arr[cur_index].cur, temp.next = arr[cur_index].next;
            arr.push_back(temp);

            int nextStation = hashStation[arr[cur_index].next];
            arr[nextStation].pre = j;

            arr[cur_index].next = j;

            hashStation[j] = arr.size() - 1;
        } else if (s == "BP") {
            cin >> i >> j;
            int cur_index = hashStation[i];

            cout << arr[cur_index].pre << '\n';

            station temp;
            temp.cur = j, temp.pre = arr[cur_index].pre, temp.next = arr[cur_index].cur;
            arr.push_back(temp);


            // 현재 역의 이전 역 갱신
            int preStation = hashStation[arr[cur_index].pre];
            arr[preStation].next = j;
            arr[cur_index].pre = j;

            hashStation[j] = arr.size() - 1;
        } else if (s == "CP") {
            cin >> i;
            int cur_index = hashStation[i];
            // 이전 역 폐쇄

            station temp = arr[hashStation[arr[cur_index].pre]];

            cout << temp.cur << '\n';

            int pre_index = hashStation[temp.cur];
            int pre_pre_index = hashStation[arr[pre_index].pre];

            arr[pre_pre_index].next = arr[cur_index].cur;
            arr[cur_index].pre = arr[pre_pre_index].cur;
        } else if (s == "CN") {
            cin >> i;
            int cur_index = hashStation[i];
            // 다음 역 폐쇄

            station closeStation = arr[hashStation[arr[cur_index].next]];

            cout << closeStation.cur << '\n';

            int next_index = hashStation[arr[cur_index].next];
            int next_next_index = hashStation[arr[next_index].next];

            arr[next_next_index].pre = closeStation.pre;
            arr[cur_index].next = closeStation.next;
        }

        /*for (int j = 0; j<arr.size(); j++) {
            printf("%d <- %d -> %d\t", arr[j].pre, arr[j].cur, arr[j].next);
        }
        printf("\n");*/
    }
}

void solution() {
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input(), solution();
    return 0;
}
