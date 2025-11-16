#include <bits/stdc++.h>
using namespace std;

int n, sum;

vector<pair<int, int>> pos, lineList;

void input() {

    cin >> n;
    pos = vector<pair<int, int>> (n);

    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        pos[i] = {a, b};
    }
}

bool compare (pair <int,int> p, pair <int,int> p2) {
    return p.second - p.first > p2.second - p2.first;
}

void solution() {

    // 선의 총 길이 출력 -> 1차원임!!!
    // 없으면 추가, 있으면 늘리기.


    // pos 정렬이 필요하면 좋겠다. 제일 큰 라인 구하면 굳이 추가 안되니까 -> 이래도 시간 초과.
    sort(pos.begin(), pos.end(), compare);

    // 일단 추가
    lineList.push_back(pos[0]);

    /*
     * result = 시간초과 ( O(n) 이라 예상했는데, O(n^2) )
     * 내부 계속해서 추가되는 것에 의해 O(n^2) 에 가까워 지는 듯 하다.
     */
    for (int i = 1; i<n; i++) {
        bool checked = false;
        for (int j = 0; j<lineList.size(); j++) {
            if(pos[i].first < lineList[j].first &&  lineList[j].first <= pos[i].second && pos[i].second <= lineList[j].second) {
                // 1. 앞으로 늘리기
                // printf("앞으로 늘립니다\n");
                lineList[j].first = pos[i].first, checked = true;
                break;
            }
            if (pos[i].first >= lineList[j].first && pos[i].second <= lineList[j].second) {
                // 2. 중간 인 경우 continue
                // printf("포함시킵니다.\n");
                checked = true;
                break;
            }
            if (lineList[j].second >=pos[i].first && pos[i].first >= lineList[j].first && pos[i].second > lineList[j].second) {
                // 3. 뒤로 늘리기
                // printf("뒤로 늘립니다\n");
                lineList[j].second = pos[i].second, checked = true;
                break;
            }
            if (pos[i].first < lineList[j].first && pos[i].second > lineList[j].second) {
                // 4. 포함하는 경우
                // printf("앞뒤로 늘립니다\n");
                lineList[j].first = pos[i].first, lineList[j].second = pos[i].second, checked = true;
                break;
            }
        }
        if (!checked) {
            // printf("새로 추가합니다.\n");
            lineList.push_back(pos[i]);
        }
    }
    for (pair<int, int> line: lineList) {
        sum+= line.second - line.first;
    }
    cout << sum << '\n';
}


int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    input();
    solution();
}