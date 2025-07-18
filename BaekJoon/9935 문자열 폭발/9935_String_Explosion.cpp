#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

stack<char> string_stack; // 문자열 하나 씩 담을 스택
string s; // 폭발시킬 문자열
string explo_s; // 폭발 문자열

// https://www.acmicpc.net/problem/9935  , String Explosive!

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    cin >> s >> explo_s;

    char last = explo_s[explo_s.size()-1]; // 마지막 문자열 기준으로 검사

    for (char c : s) {
        string_stack.push(c);

        if (c == last && string_stack.size() >= explo_s.size()) { // 검사 기준이며, 스택 크기가 충분히 크다면
            string temp;
            for (int i = 0; i<explo_s.size(); i++) { // 폭발 문자열 크기 만큼 스택에서 빼기
                temp+=string_stack.top();
                string_stack.pop();
            }
            reverse(temp.begin(), temp.end());
            if (temp.compare(explo_s)) { // 1-> 다름, 0 -> 같음!
                for (int i=0; i<temp.size(); i++) { // 다시 넣기
                    string_stack.push(temp[i]);
                }
            }
        }
    }

    string result;
    while (!string_stack.empty()) {
        result.push_back(string_stack.top());
        string_stack.pop();
    }
    reverse(result.begin(), result.end());

    if (!result.empty()) {
        cout << result << '\n';
    }
    else {
        cout << "FRULA" << '\n';
    }
    return 0;
}


// 이전 시간초과 코드
/*

#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

// https://www.acmicpc.net/problem/9935 , String Explosive!


int explo_size;

string s; // 1 <= s.size() <= 1,000,000
string explosive; // 1<= explosive <= 36
string result; // ����Ʈ�� ������ ���ڿ� ��� ����

stack<char> s_stack; // ��Ʈ�� ���ڿ� ����
stack<char> temp_stack; // �ӽ� ����� ����
stack<char> explo_stack; // ���� ���ڿ� ����


int main() {
    cin >> s >> explosive;

    explo_size = explosive.size();


    int explo_pos = 0;

    // temp_stack �� ���� �������
    while (true) {
        bool explosion = false;

        for (int i = 0; i < s.size(); i++) { // �˻繮
            temp_stack.push(s[i]);
            printf("�˻�: %c - %c, ", temp_stack.top(), explosive[explo_pos]);

            if (s[i] == explosive[explo_pos]) { // �� ���� ���ڿ��� ���� ���ٸ�?
                printf("equal ");
                if (explo_pos == explosive.size() - 1) { // ������ �˻��ߴٸ�?
                    string s2;
                    for (int j = 0; j < explosive.size(); j++) { // ���� ���ڿ� ��ŭ pop
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
                    cout << "to end, **explosion**: " << s2 << ", �߰� ���: " << print_s << endl;

                    explosion = true, explo_pos = 0; // explosive! & �ʱ�ȭ
                }

                else { // �߰� �˻��?
                    explo_pos++; // �ε��� ������ ���� �� �˻�
                    printf("to middle, explo_pos++: %d\n", explo_pos);
                }
            }
            else if (s[i] == explosive[0]) { // �ٸ��� explosive ó���� ���ٸ�?
                printf("����\n");
                explo_pos = 1; // �����ؼ� explosive[1] ���� �˻� ���� -> ������ 1 ���Ͱ� �ƴ�,
            }
            else { // ������ ���� �����̸�?
                printf("����\n");
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

        if (!explosion) break; // ������ �ʾ����� break, �������� continue

        printf("explosion Ȯ�ε�!\n-----------------\n");
        s = print_s; // �˻��� ���ڿ� �ʱ�ȭ
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

*/