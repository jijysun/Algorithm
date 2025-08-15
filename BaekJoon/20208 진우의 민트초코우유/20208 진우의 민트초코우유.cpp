#include <iostream>
#include <vector>

using namespace std;

int n, m, h, answer;

int village [11][11];
vector<pair <int, int>> mint_choco;
bool visit [11];

pair<int, int> home;

void dfs (int x, int y, int hp, int depth) {
    if (hp >= abs(x-home.first) + abs (y-home.second)) {
        answer = max (depth, answer);
    }
    if (depth == mint_choco.size()) return;

    for (int i = 0; i< mint_choco.size(); i++) {
        if (visit[i]) continue;

        int dist = abs (x-mint_choco[i].first) + abs (y-mint_choco[i].second);

        if (hp < dist) continue;

        visit[i] = true;
        dfs(mint_choco[i].first, mint_choco[i].second, hp+h-dist, depth+1);
        visit[i] = false;
    }

}
int main() {
    cin >> n >> m >> h;

    for (int i = 0; i<n; i++) {
        for (int j =0; j<n; j++) {
            cin >> village[i][j];
            if (village[i][j] == 1) {
                home.first = i, home.second = j;
            }
            else if (village[i][j] == 2) {
                mint_choco.push_back({i, j});
            }
        }
    }

    dfs(home.first, home.second, m, 0);

    cout << answer << endl;

    return 0;
}