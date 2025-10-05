# 1283 단축키 지정

# 문제 소개

[문제 사이트 링크](https://www.acmicpc.net/problem/1283)

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞힌 사람 | 정답 비율 |
| --- | --- | --- | --- | --- | --- |
| 2 초 | 128 MB | 8443 | 3590 | 2891 | 43.169% |

## 문제

한글 프로그램의 메뉴에는 총 N개의 옵션이 있다. 각 옵션들은 한 개 또는 여러 개의 단어로 옵션의 기능을 설명하여 놓았다. 그리고 우리는 위에서부터 차례대로 각 옵션에 단축키를 의미하는 대표 알파벳을 지정하기로 하였다. 단축키를 지정하는 법은 아래의 순서를 따른다.

1. 먼저 하나의 옵션에 대해 왼쪽에서부터 오른쪽 순서로 단어의 첫 글자가 이미 단축키로 지정되었는지 살펴본다. 만약 단축키로 아직 지정이 안 되어있다면 그 알파벳을 단축키로 지정한다.
2. 만약 모든 단어의 첫 글자가 이미 지정이 되어있다면 왼쪽에서부터 차례대로 알파벳을 보면서 단축키로 지정 안 된 것이 있다면 단축키로 지정한다.
3. 어떠한 것도 단축키로 지정할 수 없다면 그냥 놔두며 대소문자를 구분치 않는다.
4. 위의 규칙을 첫 번째 옵션부터 N번째 옵션까지 차례대로 적용한다.

## 입력

첫째 줄에 옵션의 개수 N(1 ≤ N ≤ 30)이 주어진다. 둘째 줄부터 N+1번째 줄까지 각 줄에 옵션을 나타내는 문자열이 입력되는데 하나의 옵션은 5개 이하의 단어로 표현되며, 각 단어 역시 10개 이하의 알파벳으로 표현된다. 단어는 공백 한 칸으로 구분되어져 있다.

## 출력

N개의 줄에 각 옵션을 출력하는데 단축키로 지정된 알파벳은 좌우에 `[]` 괄호를 씌워서 표현한다.

---

# 초기 접근 방법

- 어… 따로 접근 방법이 있을 거라 생각이 들지는 않았다.
- 문자열 문제이고, 문자열 인덱싱에 대한 접근 방법이 주 문제 풀이가 될 거라 생각되어 바로 풀기 시작했다.

---

# 풀이 과정

```cpp
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
```

---

# 결과 & 근거

- 개행 문자 때문에 좀 헤맸지만 풀긴 했다.
    - cin.ignore() 과 getLine(cin, String 변수)을 기억해두자.

### 알고리즘 분류

- 구현
- 문자열