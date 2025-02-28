#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

// https://www.acmicpc.net/problem/9935 , String Explosive!

string s; // 1 <= s.size() <= 1,000,000
string explosive; // 1<= explosive <= 36

stack<char> s_stack, temp_stack;

void print_stack() {
    stack <char> print_s_stack = s_stack, print_temp_stack = temp_stack;
    string print_s, print_temp;

    while (!print_s_stack.empty()) {
        print_s += print_s_stack.top();
        print_s_stack.pop();
    }
    print_s.reserve();

    while (!print_temp_stack.empty()) {
        print_temp += print_temp_stack.top();
        print_temp_stack.pop();
    }
    // printf("s_stack: %s\n temp_stack: %s", &print_s, print_temp);

    cout << "s_stack: " << print_s << "\ntemp_stack: " << print_temp << "\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL);

    cin >> s >> explosive;
    cout << s << ", " << explosive << endl;

    for (char c : s) {
        s_stack.push(c);
    }

    int explo_size = explosive.size() - 1;
    while (!s_stack.empty()) {
        if (explo_size == -1) { // 폭발 문자열 만나서 다 터트린 경우

            printf("explosive! 이동 후 스택: \n");
            while (!temp_stack.empty()) { // 대피 스택에 있던 거 다시 옮기기.
                s_stack.push(temp_stack.top());
                temp_stack.pop();
            }
            print_stack();
            explo_size = explosive.size() - 1; // 원상태로 복구
        }

        if (s_stack.top() == explosive[explo_size]) { // 비교 후 만난 경우
            printf("찾음, %c == %c\n", s_stack.top(), explosive[explo_size]);
            s_stack.pop();
            explo_size--;
        }
        else { // 비교했는데 아닌 경우
            printf("못찾음, %c != %c, to temp_stack\n", s_stack.top(), explosive[explo_size]);
            temp_stack.push(s_stack.top());
            s_stack.pop();
        }
        print_stack();

        printf("---------------\n");
    }


    return 0;
}
