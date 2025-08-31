#include <algorithm>
#include <iostream>
#include <valarray>
#include <vector>

using namespace std;

int n, cnt=0;

vector<int> arr;


bool insert_check () {

    printf("---�迭 �˻� �ǽ�---\n");

    int check_size = 2;

    for (int i = 0; check_size<=arr.size(); i++) {
        check_size += i * 2;

        if (check_size > arr.size()) return true;

        for (int j = 0; j<arr.size(); j++) { // ������ ���� �˻�.

            if (j+check_size>arr.size()) {
                // printf("j+check_size: %d, arr.size: %d\n", j+check_size, arr.size());
                break; // �迭�� �Ѿ�� ��� �� �̻��� �˻� X
            }

            vector<int> v1, v2;
            copy(arr.begin()+j, arr.begin()+j+check_size/2, back_inserter(v1));
            copy (arr.begin()+j+check_size/2, arr.begin()+j+check_size, back_inserter(v2));

            if (v1 == v2) {
                printf("�����ϴ�! ");
                for (int k = 0; k<v1.size(); k++) {
                    printf("%d", v1[k]);
                }
                printf(" <-> ");
                for (int k = 0; k<v2.size(); k++) {
                    printf("%d", v2[k]);
                }
                printf("\n");
                return false;
            }
        }
    }
    return true;
}

int main() {
    // ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> n;

    while (cnt < n) {

        for (int i = 1; i<=3; i++) {

            arr.push_back(i);
            for (int i = 0; i<arr.size(); i++) {
                cout << arr[i];
            }
            cout << '\n';

            if (!insert_check()) {
                arr.pop_back();
            }
            else {
                printf("---�迭 �˻� ����---\n\n");
                break;
            }
        }
        cnt ++;
    }

    for (int i = 0; i<arr.size(); i++) {
        cout << arr[i];
    }
    cout << '\n';


    return 0;
}
