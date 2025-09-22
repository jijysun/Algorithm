#include <algorithm>
#include <iostream>
#include <valarray>
#include <vector>

/**
 * 2469, ladder game
 * https://www.acmicpc.net/problem/2469
 */

using namespace std;

int N, K;
int questionMark;
vector<string> arr;
string result;

void input () {
    cin >> N;
    cin >> K;
    cin >>result;

    arr = vector<string>(K);

    for (int i = 0; i<K; i++) {
        cin >> arr[i];
        if (arr[i].at(0) == '?') {
            // printf("?: %d", i);
            questionMark = i;
        }
    }
}

void solution() {

    // Top - down
    vector<char> topDown (N), bottomUp (N);

    for (int i = 0; i<N; i++) {
        int pos = i;
        for (int j = 0; j<questionMark; j++) {
            if (pos-1 >= 0 && arr[j][pos-1] == '-') {
                pos--;
            }
            else if (pos < N && arr[j][pos] == '-') {
                pos++;
            }
        }
        topDown.at(pos) = 65+i;
    }

    for (int i = 0; i<N; i++) {
        int pos = i;
        for (int j = K-1; j>questionMark; j--) {
            if (pos < N && arr[j][pos] == '-') {
                pos++;
            }
            else if (pos-1 >= 0 && arr[j][pos-1] == '-') {
                pos--;
            }
        }
        bottomUp.at(pos) = result[i];
    }

    /*printf("Top-down: ");
    for (char c : topDown) {
        printf("%c", c);
    }
    printf("\n");

    printf("Bottom-up: ");
    for (char c : bottomUp) {
        printf("%c", c);
    }
    printf("\n");*/

    vector<char>ques;
    bool isPreDiff = topDown[0] != bottomUp[0];

    for (int i = 1; i<topDown.size(); i++) {
        if (topDown[i] != bottomUp[i]) {
            if (isPreDiff == true) {
                if ((topDown[i-1] == bottomUp[i]) && (topDown[i] && bottomUp[i-1]) ) {
                    ques.push_back('-');
                    isPreDiff = false;
                }
                else {
                    // printf("return!\n");

                    for (int j = 0; j<topDown.size()-1; j++) {
                        cout << 'x';
                    }
                    cout << '\n';
                    return;
                }
            }
            else {
                ques.push_back('*'), isPreDiff = true;
            }
        }

        else {
            // if (i == 0) continue;
            ques.push_back('*');
        }
    }

    for (char c : ques) {
        cout << c;
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    input ();

    solution();

    return 0;
}