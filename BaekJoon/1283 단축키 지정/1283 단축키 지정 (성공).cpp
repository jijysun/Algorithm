#include <bits/stdc++.h>
using namespace std;

/*
 * https://www.acmicpc.net/problem/1283
 * Specifying Shortcut Key
 */

int n;
map<char, int> dic;
vector<string> arr;

void input() {

    cin >> n;
    cin.ignore();

    string s;
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        arr.push_back(s);
    }
}

void solution() {
    for (string s : arr) {
        vector<string> word;
        string temp;

        for (int i = 0; i<s.size(); i++) {
            if(s[i] == ' ') {
                word.push_back(temp);
                temp = "";
            }
            else {
                temp+=s[i];
            }
        }
        word.push_back(temp);


        int index=-1;
        bool first = false;
        for (int i = 0; i<word.size(); i++) { // 각 단어 별
            if (dic[tolower(word[i][0])] == 0) {
                dic[tolower(word[i][0])] = 1, first = true;

                index = 0;
                for (int j = 0; j<i; j++) {
                    index += word[j].size()+1;
                }

                for (int j = 0; j<s.size(); j++) {
                    if (j==index) {
                        cout << "[" << s[j] << "]";
                    }
                    else {
                        cout << s[j];
                    }
                }
                cout <<'\n';
                break;
            }
        }
        if (!first) {
            for (int i = 0; i<s.size(); i++) {
                if (s[i] == ' ') {
                    continue;
                }
                if (dic[tolower(s[i])] == 0) {
                    dic[tolower(s[i])] = 1;
                    index = i;
                    break;
                }
            }
            for (int i = 0; i<s.size(); i++) {
                if (i==index) {
                    cout << "[" << s[i] << "]";
                }
                else {
                    cout << s[i];
                }
            }
            cout <<'\n';
        }
    }
}


int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    input();

    solution();
}