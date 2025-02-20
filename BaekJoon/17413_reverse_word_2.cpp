#include <iostream>
#include<stack>
#include<string>
using namespace std;

// https://www.acmicpc.net/problem/17413

string s;
stack<char> string_stack;
string result;

int main() {

    getline(cin, s);
    s += ' ';

    int i = 0, string_size = s.length();

    while (i <= string_size) {
        if (s[i] == '<') {
            if (!string_stack.empty()) {
                while (!string_stack.empty()) {
                    result += string_stack.top();
                    string_stack.pop();
                }
                result += '<', i++;
            }

            while (s[i] != '>') {
                result += s[i];
                i++;
            }
            result += s[i];
            i++;
        }

        else {
            string_stack.push(s[i]);

            if (s[i] == ' ') {
                string_stack.pop();

                while (!string_stack.empty()) {
                    result += string_stack.top();
                    string_stack.pop();
                }
                result += ' ';
            }
            i++;
        }
    }

    for (int j = 0; j < string_size; j++) {
        cout << result[j];
    }
    return 0;
}