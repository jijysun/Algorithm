#include <bits/stdc++.h>
using namespace std;

/*
 * https://www.acmicpc.net/problem/1111
 * IQ Test
 */

int n;
int arr[51]; // -100 ~ 100
bool ret = false;
pair<int, int > p;

void input() {
    cin >> n;
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }
}

void solution() {

    int a = 1;
    int b = 0;
    while (arr[0] * a <= arr[1]) {
        b = arr[1] - arr[0]*a;
        if (arr[1]*a+b == arr[2]) {

            if (ret) {
                cout << "A" << '\n';
                return;
            }

            ret = true;
            p = {a, b};
            cout << "a: " << a << ", b: " << b << '\n';
        }
        a++;
    }

    a = -1, b=0;
    while (arr[0]*a <= arr[1]) {
        b = arr[1] - arr[0]*a;
        if (arr[1]*a+b == arr[2]) {

            if (ret) {
                cout << "A" << '\n';
                return;
            }

            ret = true;
            p = {a, b};
            cout << "a: " << a << ", b: " << b << '\n';
        }
        a--;
    }

    cout << arr[n-1]*p.first + p.second;

}



int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    input();
    solution();
}