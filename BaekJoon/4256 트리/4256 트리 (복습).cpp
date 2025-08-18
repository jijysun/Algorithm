#include <algorithm>
#include <iostream>

using namespace std;

int t;
int n;

int pre_tree[1001];
int in_tree[1001];

void get_tree (int left, int right, int index) {

    // index는 다음으로 찾을 루트의 좌표.

    for (int i = left; i<right; i++) { // 순서대로 루트 찾기.
        if ( pre_tree[index] == in_tree[i]) { // 루트를 찾았다면?

            // 좌측 서브 트리 다음 루트는 현 루트에서 차례대로 증가한 값.
            get_tree(left, i, index+1);

            // 우측 서브 트리 다음 루트는 현 루트에서 왼족 서브트리 개수 만큼 건너뛴 값.
            get_tree(i+1, right, index-left+i+1);

            cout << pre_tree[index] << ' ';
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> pre_tree[j];
        }
        for (int j = 0; j < n; j++) {
            cin >> in_tree[j];
        }
        get_tree(0, n,0);
        cout << '\n';
    }

    return 0;
}