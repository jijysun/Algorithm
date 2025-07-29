#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int input[22][4], coordinate [102][102];
vector<int> dir;
vector<pair<int, int>> direction = { {1, 0}, { 0, -1}, {-1, 0} , {0, 1}};
// R   U   L   D

void makingDot(int num) {

    /*
     * 만든 방향 만큼 용 그려가면서 점 찍기
     */
    int x = input[num][0], y = input[num][1];

    coordinate[x][y] = 1;
    // cout << "making dot...  (" << x << "," << y << ")"<< '\t';
    for (int i = 0; i<dir.size(); i++) {
        x += direction[dir[i]].first, y+=direction[dir[i]].second;
        coordinate[x][y] = 1;
        // cout <<"(" << x << "," << y << ")"<< '\t';
    }
    // cout << '\n';
}


void drawDragon (int num) {

    dir.clear();
    dir.push_back(input[num][2]); // 첫 방향 넣고

    // dequue 방식의 방향 만들기
    for (int i = 0; i < input[num][3]; i++) {
        int s = dir.size();
        for (int j = s-1; j>=0; j--) {
            dir.push_back((dir[j]+1)%4);
        }
    }

    /*for (int i = 0; i< dir.size(); i++) {
        cout << dir[i] << " ";
    }
    cout << '\n';*/

    makingDot(num);

    // cout <<'\n';
}

int main() {

    cin >> n;

    for (int i = 0; i<n; i++) {
        // cin >> x >> y >> direct >> generation;
        cin >> input[i][0] >> input[i][1] >> input[i][2] >> input[i][3];

        // dragon.push_back({x, y});
        // curve.push_back({direct, generation});
    }

    for (int i = 0; i< n ; i++) {
        drawDragon(i);
    }

    // 전체 데이터 수가 작으므로 이중 반복을 사용해도 시간 안에 Ok
    int square_cnt = 0;
    for (int i = 0; i<101; i++) {
        for (int j = 0; j<101; j++) {
            if (coordinate[i][j] && coordinate[i][j+1] && coordinate[i+1][j] && coordinate[i+1][j+1]) {
                // printf("can make square! (%d %d) ~ (%d %d)\n", i, j, i+1, j+1);
                square_cnt++;
            }
        }
    }
    cout << square_cnt << '\n';

}