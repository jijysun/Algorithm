#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

// https://www.acmicpc.net/problem/9935 , String Explosive!

// ���ڿ��� ���� ���ڿ��� �����ϰ� �ִ� ��쿡, ��� ���� ���ڿ��� �����ϰ� �ȴ�. ���� ���ڿ��� ������� �̾� �ٿ� ���ο� ���ڿ��� �����.
// ���� ���� ���ڿ��� ���� ���ڿ��� ���ԵǾ� ���� ���� �ִ�.
// ������ ���� ���ڿ��� ���ڿ��� ���� ������ ��ӵȴ�.
// ��� ������ ���� �Ŀ� � ���ڿ��� ������ ���غ���. �����ִ� ���ڰ� ���� ���� "FRULA"�� ����Ѵ�.
// ���� ���ڿ��� ���� ���ڸ� �� �� �̻� �������� �ʴ´�.
// �� ���ڿ��� ��� ���ĺ� �ҹ��ڿ� �빮��, ���� 0, 1, ..., 9�θ� �̷���� �ִ�.


int explo_size;

string s; // 1 <= s.size() <= 1,000,000
string explosive; // 1<= explosive <= 36
string result; // ����Ʈ�� ������ ���ڿ� ��� ����

stack<char> s_stack; // ��Ʈ�� ���ڿ� ����
stack<char> temp_stack; // �ӽ� ����� ����
stack<char> explo_stack; // ���� ���ڿ� ����


int main() {
    cin >> s >> explosive;

    /*for (char c: s) {
        s_stack.push(c);
    }*/

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


/*
 *
//���� �ڵ�
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

int explo_size;

string s; // 1 <= s.size() <= 1,000,000
string explosive; // 1<= explosive <= 36
string result; // ����Ʈ�� ������ ���ڿ� ��� ����

stack<char> s_stack; // ��Ʈ�� ���ڿ� ����
stack<char> temp_stack; // �ӽ� ����� ����
stack<char> explo_stack; // ���� ���ڿ� ����

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
        // ���� ���ڿ� ������ �� ��Ʈ�� ���
        printf("explosive! \n");
        while (!temp_stack.empty()) {
            s_stack.push(temp_stack.top()); // ���� ���ÿ� �ִ� �� �ٽ� �ű��.
            temp_stack.pop();
        }
        print_stack();
        explo_size = explosive.size(); // �����·� ����
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
            printf("===���� ����===\n");
            explosive_check();
            break;
        }

        if (s_stack.top() == explosive[explo_size - 1]) { // �� �� ���� ���
            printf("ã��, %c == %c, pop!\n", s_stack.top(), explosive[--explo_size]);
            explo_stack.push(s_stack.top());
            s_stack.pop();
        }
        else { // ���ߴµ� �ƴ� ���
            printf("��ã��, %c != %c, to temp_stack\n", s_stack.top(), explosive[explo_size]);
            temp_stack.push(s_stack.top());
            s_stack.pop();
        }

        explosive_check();
        print_stack();
        printf("---------------\n");
    }

    printf("���α׷� ����\ns_stack.size: %d, temp_stack.size: %d, explo_size: %d, explo_stack.size: %d\n", s_stack.emplace(), temp_stack.size(), explo_size, explo_stack.size());

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
    else { // ���� ��� �̹Ƿ� ���� ���ڿ� ���
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


    // FRULA = (s_stack, temp_stack) = 0, explo_size = explosive_string (�ʱ�ȭ ���ѹ���)
    // explo_stack �� ���� = ���ڿ� ������

    return 0;
}

*/