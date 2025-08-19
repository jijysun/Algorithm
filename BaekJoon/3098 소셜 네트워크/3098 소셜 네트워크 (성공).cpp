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
 * �����غ�������, ģ�� ���踦 ����� �Լ�.
 * @return null;
 */
void update_friends() {
    int make_friend_cnt = 0;
    while (!update.empty()) {
        pair<int, int> value = update.front();

        if (table[value.first][value.second] == 1 || table[value.second][value.first] == 1) {
            update.pop(); // �̹� ģ�� ���� ���� �� ��� skip
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

            if (size == n - 1) continue; // �̹� ��� ���� ������ �� ���

            for (int j = 0; j < size; j++) { // make friend!

                int cur_freind = friends[i][j]; // �� ���ΰ��� ģ���� ����
                for (int k = 0; k < friends[cur_freind].size(); k++) { // �� ���ΰ��� ģ���� ģ���� ����

                    if (i == friends[cur_freind][k])  continue; // �� �ڽ��� skip

                    if (table[i][friends[cur_freind][k]] != 1 || table[friends[cur_freind][k]][i] != 1) { // �� ���ΰ��� ģ���� ģ�� ã��.
                        update.push({i, friends[cur_freind][k]});
                        isMakingFriend = true; // ģ�� ���� �ƴ� ���ʸ� ģ���� ģ����.
                    }
                }
            }
        }
        if (!isMakingFriend) {
            return day;
        }

        // ��� ������Ʈ�� ��¥�� ���� ���� �� ���� ģ�� ��û ������ �Ǿ�� �Ѵ�.
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
