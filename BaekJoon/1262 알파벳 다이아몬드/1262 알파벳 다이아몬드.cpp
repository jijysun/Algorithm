#include <algorithm>
#include <iostream>
#include <valarray>
#include <vector>

/**
 * 1262, Alphabet Diamond
 * https://www.acmicpc.net/problem/1262
 */

using namespace std;

int N, R1, C1, R2, C2;

vector<vector<char>> tile;
vector<int> arr;

void makeTile() {
    // 타일은 무조건 홀수 * 홀수, 20,000 * 20,000
    tile = vector(2 * N - 1, vector<char>(2 * N - 1));

    // ACEII: 97 ~
    // 반 ~ 우측 끝 까지 만들고 뒤집기?

    for (int i = 0; i<N; i++) {
        char pos = 96 + N - i;
        cout << "pos: " << pos << endl;
        for (int j = 0; j<=i; j++) { // 범위 오류!!!
            // 알파벳 채우기
            tile[i][N/2+j] = pos - j;
        }
        for (int j = i + 1; j < N; j++) {
            // . 채우기
            tile[i][N/2+j] = '.';
        }
        for (int j = N / 2; j < N; j++) {
            // 뒤집기
            tile[i][N / 2 - j] = tile[i][j];
        }

        printf("pos[%d]: ", i);
        for (int j = 0; j < tile[i].size(); j++) {
            cout << tile[i][j];
        }
        cout << endl;
    }

    for (int i = 0; i < tile.size(); i++) {
        for (int j = 0; j < tile[i].size(); j++) {
            cout << tile[i][j];
        }
        cout << endl;
    }
}

void printRoom() {
    for (int i = R1; i <= C1; i++) {
        for (int j = R2; j <= C2; j++) {
            cout << tile[i][j];
        }
        cout << '\n';
    }
}

void mySolution () {
    makeTile();
    printRoom();
}

void correctsolution () {
    for (int i = R1; i <= R2; i++) {
        for (int j = C1; j<=C2; j++) {

            // 현 i와 j에 대해 타일 크기 안에 있는지 확인
            int temp = abs(i % (2*N-1)- N + 1) + abs(j % (2*N-1)- N + 1);

            if (temp > N-1) cout << '.'; // 나간 경우 .으로
            else {
                char alpha = 'a' + temp%26;
                cout << alpha;
            }
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> N >> R1 >> C1 >> R2 >> C2;

    // mySolution();
    correctsolution();

    return 0;
}