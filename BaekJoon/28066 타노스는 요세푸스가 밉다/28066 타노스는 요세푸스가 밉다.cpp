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
        if (squirrel.size() < k) { // 첫 번째 청설모 제외 제거 = 첫 번째 청설모가 답
            break;
        }
        int first_squ = squirrel.front(); // 첫 청설모 추출
        squirrel.pop_front(); // 해당 첫 청설모 제외
        for (int i = 0; i<k-1; i++) { // K 만큼 타노스 연산 = 큐 연산
            squirrel.pop_front();
        }
        squirrel.push_back(first_squ); // 추출한 청설모 맨 뒤로 보낸다 = 스택 연산
    }

    cout << squirrel.front() << '\n';


    return 0;
}