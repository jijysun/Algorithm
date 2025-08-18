#include <algorithm>
#include <iostream>

using namespace std;

int t;
int n;

int pre_tree[1001];
int in_tree[1001];

void get_tree (int left, int right, int index) {

    // index�� �������� ã�� ��Ʈ�� ��ǥ.

    for (int i = left; i<right; i++) { // ������� ��Ʈ ã��.
        if ( pre_tree[index] == in_tree[i]) { // ��Ʈ�� ã�Ҵٸ�?

            // ���� ���� Ʈ�� ���� ��Ʈ�� �� ��Ʈ���� ���ʴ�� ������ ��.
            get_tree(left, i, index+1);

            // ���� ���� Ʈ�� ���� ��Ʈ�� �� ��Ʈ���� ���� ����Ʈ�� ���� ��ŭ �ǳʶ� ��.
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