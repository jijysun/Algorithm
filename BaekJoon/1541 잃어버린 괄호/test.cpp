#include <bits/stdc++.h>
using namespace std;

/*
 * https://www.acmicpc.net/problem/1541
 * Lost parentheses
 */

string s, num;
int answer = 0;
bool isMinus = false;

void input () {
    cin >> s;
}

void solution() {
    for (int i = 0; i <= s.size(); i++) {
        if (s[i] == '-' || s[i] == '+' || i==s.size()) {
            if (isMinus) {
                answer -= stoi(num);
                num = "";
            }
            else {
                answer += stoi(num);
                num = "";
            }
        }
        else {
            num += s[i];
        }

        if (s[i] == '-') {
            isMinus = true;
        }
    }

    cout << answer;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    input();
    solution();
}
