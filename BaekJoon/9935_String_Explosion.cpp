#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

// https://www.acmicpc.net/problem/9935 , String Explosive!

// 문자열이 폭발 문자열을 포함하고 있는 경우에, 모든 폭발 문자열이 폭발하게 된다. 남은 문자열을 순서대로 이어 붙여 새로운 문자열을 만든다.
// 새로 생긴 문자열에 폭발 문자열이 포함되어 있을 수도 있다.
// 폭발은 폭발 문자열이 문자열에 없을 때까지 계속된다.
// 모든 폭발이 끝난 후에 어떤 문자열이 남는지 구해본다. 남아있는 문자가 없는 경우는 "FRULA"를 출력한다.
// 폭발 문자열은 같은 문자를 두 개 이상 포함하지 않는다.
// 두 문자열은 모두 알파벳 소문자와 대문자, 숫자 0, 1, ..., 9로만 이루어져 있다.


int explo_size;

string s; // 1 <= s.size() <= 1,000,000
string explosive; // 1<= explosive <= 36
string result; // 못터트린 나머지 문자열 출력 변수

stack<char> s_stack; // 터트릴 문자열 스택
stack<char> temp_stack; // 임시 저장소 스택
stack<char> explo_stack; // 폭발 문자열 스택


int main() {
    cin >> s >> explosive;

    /*for (char c: s) {
        s_stack.push(c);
    }*/

    explo_size = explosive.size();


    int explo_pos = 0;

    // temp_stack 만 쓰는 방식으로
    while (true) {
        bool explosion = false;

        for (int i = 0; i < s.size(); i++) { // 검사문
            temp_stack.push(s[i]);
            printf("검사: %c - %c, ", temp_stack.top(), explosive[explo_pos]);

            if (s[i] == explosive[explo_pos]) { // 현 폭발 문자열의 값과 같다면?
                printf("equal ");
                if (explo_pos == explosive.size() - 1) { // 끝까지 검사했다면?
                    string s2;
                    for (int j = 0; j < explosive.size(); j++) { // 폭발 문자열 만큼 pop
                        s2 += temp_stack.top();
                        temp_stack.pop();
                    }
                    reverse(s2.begin(), s2.end());
                    stack<char>print_s_stack = temp_stack;
                    string print_s;
                    while (!print_s_stack.empty()) {
                        print_s += print_s_stack.top();
                        print_s_stack.pop();
                    }
                    reverse(print_s.begin(), print_s.end());
                    cout << "to end, **explosion**: " << s2 << ", 중간 출력: " << print_s << endl;

                    explosion = true, explo_pos = 0; // explosive! & 초기화
                }

                else { // 중간 검사면?
                    explo_pos++; // 인덱스 증가로 다음 값 검사
                    printf("to middle, explo_pos++: %d\n", explo_pos);
                }
            }
            else if (s[i] == explosive[0]) { // 다른데 explosive 처음과 같다면?
                printf("연장\n");
                explo_pos = 1; // 연장해서 explosive[1] 부터 검사 시작 -> 무조건 1 부터가 아닌,
            }
            else { // 완잔히 끊긴 수준이면?
                printf("끊김\n");
                explo_pos = 0;
            }
        }

        stack<char>print_s_stack = temp_stack;
        string print_s;
        while (!print_s_stack.empty()) {
            print_s += print_s_stack.top();
            print_s_stack.pop();
        }
        reverse(print_s.begin(), print_s.end());
        cout << "temp_stack: " << print_s << endl;

        if (!explosion) break; // 터지지 않았으면 break, 터졌으면 continue

        printf("explosion 확인됨!\n-----------------\n");
        s = print_s; // 검사할 문자열 초기화
        explo_pos = 0;
        while (!temp_stack.empty()) temp_stack.pop();
    }

    if (!temp_stack.empty()) {
        stack<char>print_s_stack = temp_stack;
        string print_s;
        while (!print_s_stack.empty()) {
            print_s += print_s_stack.top();
            print_s_stack.pop();
        }
        reverse(print_s.begin(), print_s.end());
        cout << print_s << endl;
    }
    else {
        cout << "FRULA" << '\n';
    }

    return 0;
}


/*
 *
//이전 코드
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

int explo_size;

string s; // 1 <= s.size() <= 1,000,000
string explosive; // 1<= explosive <= 36
string result; // 못터트린 나머지 문자열 출력 변수

stack<char> s_stack; // 터트릴 문자열 스택
stack<char> temp_stack; // 임시 저장소 스택
stack<char> explo_stack; // 폭발 문자열 스택

void print_stack() {
    stack<char> print_s_stack = s_stack, print_temp_stack = temp_stack, print_explo_stack = explo_stack;
    string print_s, print_temp, print_explo;

    while (!print_s_stack.empty()) {
        print_s += print_s_stack.top();
        print_s_stack.pop();
    }
    print_s.reserve();

    while (!print_temp_stack.empty()) {
        print_temp += print_temp_stack.top();
        print_temp_stack.pop();
    }

    while (!print_explo_stack.empty()) {
        print_explo += print_explo_stack.top();
        print_explo_stack.pop();
    }

    cout << "s_stack: " << print_s << "\ttemp_stack: " << print_temp << "\texplo_stack: " << print_explo << endl;
}

void explosive_check() {
    if (!explo_size) {
        // 폭발 문자열 만나서 다 터트린 경우
        printf("explosive! \n");
        while (!temp_stack.empty()) {
            s_stack.push(temp_stack.top()); // 대피 스택에 있던 거 다시 옮기기.
            temp_stack.pop();
        }
        print_stack();
        explo_size = explosive.size(); // 원상태로 복구
        while (!explo_stack.empty()) {
            explo_stack.pop();
        }
    }
}

int main() {
    cin >> s >> explosive;

    for (char c : s) {
        s_stack.push(c);
    }

    explo_size = explosive.size();

    while (true) {
        if (s_stack.empty()) {
            printf("===로직 종료===\n");
            explosive_check();
            break;
        }

        if (s_stack.top() == explosive[explo_size - 1]) { // 비교 후 만난 경우
            printf("찾음, %c == %c, pop!\n", s_stack.top(), explosive[--explo_size]);
            explo_stack.push(s_stack.top());
            s_stack.pop();
        }
        else { // 비교했는데 아닌 경우
            printf("못찾음, %c != %c, to temp_stack\n", s_stack.top(), explosive[explo_size]);
            temp_stack.push(s_stack.top());
            s_stack.pop();
        }

        explosive_check();
        print_stack();
        printf("---------------\n");
    }

    printf("프로그램 종료\ns_stack.size: %d, temp_stack.size: %d, explo_size: %d, explo_stack.size: %d\n", s_stack.emplace(), temp_stack.size(), explo_size, explo_stack.size());

    if (temp_stack.size() == 0) {
        if (explo_stack.empty()) {
            printf("FRULA\n");
        }
        else {
            while (!temp_stack.empty()) {
                result += temp_stack.top();
                temp_stack.pop();
            }
            cout << "1, " << result << endl;
        }
    }
    else { // 남은 경우 이므로 남은 문자열 출력
        while (!temp_stack.empty()) {
            result += temp_stack.top();
            temp_stack.pop();
        }
        cout << "2, " << result << endl;

        string expl;
        while (!explo_stack.empty()) {
            expl += explo_stack.top();
            explo_stack.pop();
        }
        cout << "2, " << expl << endl;
    }


    // FRULA = (s_stack, temp_stack) = 0, explo_size = explosive_string (초기화 시켜버림)
    // explo_stack 이 존재 = 문자열 미폭발

    return 0;
}

*/