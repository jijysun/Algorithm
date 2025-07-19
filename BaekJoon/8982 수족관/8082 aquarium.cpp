#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// https://www.acmicpc.net/problem/8982

int aquarium [5001][5001];

int n, m, water=0;
int preX , preY, lastX, lastY;  // 이전좌표, 맨 처음은 0,0 & 마지막 X, Y
int x1, y1, x2, y2; // 수직선, 수평선, 구멍 입력 받을 좌표

vector<pair<pair<int, int>, int>> hole; // 구멍 좌표

bool compare (pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    return a.second > b.second;
}

int getWater () {

    // 구멍 기준 물 빼기
    return 0;
}

int main() {

    cin >> n;


    cin >> preX >> preY; // 0 0
    for (int i = 0; i<n/2-1; i++) {
        cin >> x1 >> y1; // 수직
        cin >> x2 >> y2; // 수평

        water += y1 * (x2-x1);
    }
    cin >> lastX >> lastY;
    printf("전체 물 양: %d\n", water);

    cin >> m;
    for (int i=0; i<m; i++) {
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        hole.push_back({{x1, x2}, y1});
    }

    // 정렬
    sort(hole.begin(), hole.end(), compare);

    printf("높이 내림차순 정렬 구멍 출력\n");
    for (int i =0; i<m; i++) {
        printf("%d, %d / %d, %d\n", hole[i].first.first, hole[i].second, hole[i].first.second,hole[i].second);
    }


    cout << getWater() << '\n';

    return 0;
}