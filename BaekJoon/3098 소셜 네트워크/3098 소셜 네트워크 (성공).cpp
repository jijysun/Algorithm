#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;

int table[52][52];

vector<vector<int> > friends;
vector<int> make_friend_each_day;

queue<pair<int, int> > update;

/**
 * 복잡해보이지만, 친구 관계를 만드는 함수.
 * @return null;
 */
void update_friends() {
    int make_friend_cnt = 0;
    while (!update.empty()) {
        pair<int, int> value = update.front();

        if (table[value.first][value.second] == 1 || table[value.second][value.first] == 1) {
            update.pop(); // 이미 친구 관계 형성 된 경우 skip
            continue;
        }

        table[value.first][value.second] = 1, table[value.second][value.first] = 1;
        friends[value.first].push_back(value.second), friends[value.second].push_back(value.first);
        update.pop(),  make_friend_cnt++;
    }
    make_friend_each_day.push_back(make_friend_cnt);
}

int make_friends() {
    int day = 0;
    while (true) {
        bool isMakingFriend = false;

        for (int i = 1; i <= n; i++) {
            int size = friends[i].size();

            if (size == n - 1) continue; // 이미 모든 관계 형성이 된 경우

            for (int j = 0; j < size; j++) { // make friend!

                int cur_freind = friends[i][j]; // 현 주인공의 친구에 대해
                for (int k = 0; k < friends[cur_freind].size(); k++) { // 현 주인공의 친구의 친구에 대해

                    if (i == friends[cur_freind][k])  continue; // 내 자신은 skip

                    if (table[i][friends[cur_freind][k]] != 1 || table[friends[cur_freind][k]][i] != 1) { // 현 주인공의 친구의 친구 찾기.
                        update.push({i, friends[cur_freind][k]});
                        isMakingFriend = true; // 친구 관계 아닌 저너머 친구를 친구로.
                    }
                }
            }
        }
        if (!isMakingFriend) {
            return day;
        }

        // 대신 업데이트는 날짜가 지난 이후 한 번에 친추 요청 수락이 되어야 한다.
        day++, update_friends();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m;

    friends = vector<vector<int> >(n + 1);

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        friends[a].push_back(b), friends[b].push_back(a);
        table[a][b] = 1, table[b][a] = 1;
    }

    cout << make_friends() << '\n';
    for (int i: make_friend_each_day) {
        cout << i << '\n';
    }
    return 0;
}
