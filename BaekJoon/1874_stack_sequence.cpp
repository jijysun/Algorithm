#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// https://www.acmicpc.net/problem/1874

int n, numCount = 1;
stack<int> num_stack;
vector<string> cal;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        while (numCount <= a) {
            num_stack.push(numCount);
            numCount += 1;
            cal.push_back("+");
        }

        if (num_stack.top() == a) {
            num_stack.pop();
            cal.push_back("-");
        }
        else {
            printf("NO\n");
            return 0;
        }
    }

    for (int i = 0; i < cal.size(); i++) {
        cout << cal[i] << '\n';
    }

    return 0;
}
