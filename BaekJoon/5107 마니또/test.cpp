#include <bits/stdc++.h>
using namespace std;

int n;
map<string, string> manito;
vector<pair<string, string>> manitoList;

void input() {
    cin >> n;
    manitoList = vector<pair<string, string>>(n);

    string a, b;
    for (int i = 0; i<n; i++) {
        cin >> manitoList[i].first >> manitoList[i].second;
        manito[manitoList[i].first] = manitoList[i].second;
    }
    int ab;
    cin >> ab;
}


void solution() {
    int cnt= 0;


    for (int i = 0; i<n; i++) {

        string fst  = manitoList[i].first;

        // cout << "fst: " << fst << '\n';
        string s = manitoList[i].second;
        vector<string> cmpList;
        cmpList.push_back(fst);
        while(true) {
            s = manito[s];
            // cout << "비교: " << s << '\n';
            if (s.empty()) {
                break;
            }
            if (fst.compare(s) == 0) {
                // cout << "같습니다: " << fst << ", " << s << '\n'; // 이러면 map 비우는 거 처리를 어떻게?

                cout << ++cnt << " ";

                for (string s2 : cmpList) { // null 처리로 스킵하게
                    manito[s2] = "";
                }

                // cnt ++;
                break;
            }
            cmpList.push_back(s);
        }
    }
    cout <<'\n';
    // cout << cnt << '\n';
}


int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    input();
    solution();
}