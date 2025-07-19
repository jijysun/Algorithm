#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// https://www.acmicpc.net/problem/8982

int aquarium [5001][5001];

int n, m, water=0;
int preX , preY, lastX, lastY;  // ������ǥ, �� ó���� 0,0 & ������ X, Y
int x1, y1, x2, y2; // ������, ����, ���� �Է� ���� ��ǥ

vector<pair<pair<int, int>, int>> hole; // ���� ��ǥ

bool compare (pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    return a.second > b.second;
}

int getWater () {

    // ���� ���� �� ����
    return 0;
}

int main() {

    cin >> n;


    cin >> preX >> preY; // 0 0
    for (int i = 0; i<n/2-1; i++) {
        cin >> x1 >> y1; // ����
        cin >> x2 >> y2; // ����

        water += y1 * (x2-x1);
    }
    cin >> lastX >> lastY;
    printf("��ü �� ��: %d\n", water);

    cin >> m;
    for (int i=0; i<m; i++) {
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        hole.push_back({{x1, x2}, y1});
    }

    // ����
    sort(hole.begin(), hole.end(), compare);

    printf("���� �������� ���� ���� ���\n");
    for (int i =0; i<m; i++) {
        printf("%d, %d / %d, %d\n", hole[i].first.first, hole[i].second, hole[i].first.second,hole[i].second);
    }


    cout << getWater() << '\n';

    return 0;
}