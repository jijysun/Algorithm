#include <deque>
#include <iostream>

using namespace std;

int n, k;
deque<int> squirrel;

int main() {

    cin >> n >> k;
    for (int i = 0; i<n; i++) {
        squirrel.push_back(i+1);
    }

    while (true) {
        if (squirrel.size() < k) { // ù ��° û���� ���� ���� = ù ��° û���� ��
            break;
        }
        int first_squ = squirrel.front(); // ù û���� ����
        squirrel.pop_front(); // �ش� ù û���� ����
        for (int i = 0; i<k-1; i++) { // K ��ŭ Ÿ�뽺 ���� = ť ����
            squirrel.pop_front();
        }
        squirrel.push_back(first_squ); // ������ û���� �� �ڷ� ������ = ���� ����
    }

    cout << squirrel.front() << '\n';


    return 0;
}