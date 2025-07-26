#include <iostream>

using namespace std;

int n;
int arr [101];

int main() {
    cin >> n;

    int cnt = 0;
    for (int i = n/2+1; i<=n; i++) {
        // 홀수자리에 각각 할당.
        arr [2*cnt] = i, cnt++;
    }

    cnt = n%2 == 0 ? n-1 : n-2;

    for (int i = 1; i<=n/2; i++) arr [cnt] = i, cnt-=2;

    for (int i = 0; i<n; i++) printf("%d ", arr[i]);

    return 0;
}