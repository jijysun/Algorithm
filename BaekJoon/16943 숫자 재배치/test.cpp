#include <bits/stdc++.h>
using namespace std;

// https://www.acmicpc.net/problem/16943

// int a, b;

string s1, s2, answer;
vector<int> a, b;
map<int, int> checked;
bool findAnswer = false;

// 문자열 그대로 사용?

void input() {
    cin >> s1 >> s2;

    for (int i = 0; i<s1.size(); i++) {
        a.push_back(s1[i]);
    }
    for (int i = 0; i<s2.size(); i++) {
        b.push_back(s2[i]);
    }
}

// c = ...........
void permutation (int depth, string c) {
    cout << c << '\n';

    if (findAnswer) {
        return;
    }

    if (depth == s1.size()) {
        if (s2 > c) {
            answer = c;
        }
        cout << c << '\n';
        findAnswer = true;
        return;
    }


    for (int i = s1.size()-1; i>=0; i--) {
        int a = s1[i], b = s2[depth];
        if (b < a) {
            continue;
        }

        // cout << "depth, a: " << depth << ", " << s1[i] << '\n';
        if (depth == 0 && s1[i] == '0') {
            // cout << "0! continue!" << '\n';
            continue;;
        }

        if(checked[a] == 0) {
            checked[a] = 1;
            c[depth] = s1[i];
            permutation(depth +1, c);
            checked[a] = 0;
        }
    }

}

bool compare (int a, int b) {
    return a > b;
}

void solution() {
    if (s1.size() > s2.size()) {
        cout << -1 << '\n';
        return;
    }
    if (*min_element(a.begin(), a.end()) >= b.front() ) {
        cout << -1 << '\n';
        return;
    }

    sort(a.begin(), a.end(), compare);
    /*string new_s1="";
    for (int i = 0; i<a.size(); i++) {
        // cout << a[i] <<'\n';
        char c = a[i] + '0';
        new_s1.append(c);
    }*/

    sort(a.begin(), a.end(), compare);
    string new_s1(a.begin(), a.end());
    s1 = new_s1;


    cout << s1 << '\n';

    string s;
    for (int i = 0; i<s1.size(); i++) {
        s.append(".");
    }
    permutation(0, s);

    // 모든 경우의 수 검색해야 함.
    // 약간 DFS 로 내려 가면서?

    // 그 순열 조합을 어떻게 구현하더라...

}


int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    input();
    solution();

    /*bool answer = "1234" < "5678";
    cout << answer << '\n';*/
}