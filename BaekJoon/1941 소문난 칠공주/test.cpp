#include <bits/stdc++.h>
using namespace std;
// https://www.acmicpc.net/problem/1941

char classRoom [5][5];

vector<pair<int,int>> v;

void input() {

    for (int i = 0; i<5; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j<5; j++)
        {
            classRoom[i][j] = s[j];

            if (classRoom[i][j] == 'S') {
                v.push_back(pair<int,int>(i,j));
            }
        }
    }
}


void solution() {


    vector<bool> temp(v.size(), false);


    // 적어도 4명 이상... 잘못 생각했다.

    /*
     * v[0] 냅두기, sum = 0
     * v[1] 부터 고려
     * 만약 x축이 같으면 선분 계산하듯이 계산 sum+= abs(현재 꼭짓점 - 비교 꼭짓점);
     * 만약 달라졌다면? y축 차이 더한 후 현 꼭짓점 갱신 + 반복
     *
     *
     */


    for(int i = 0; i < 4; i ++)
        temp[i] = true;

    do {
        int sum = 0;
        vector<pair<int,int>> com;
        com.push_back(v[0]);
        for (int i = 1; i < v.size(); ++i) {

        }
    } while (prev_permutation(temp.begin(), temp.end()));

}



int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    /*
     * 여학생반의 자리 배치도가 주어졌을 때, ‘소문난 칠공주’를 결성할 수 있는 모든 경우의 수를 구하는 프로그램을 작성하시오.
     *
     * 경우의 수가 적은 편에 속한다 = 브루트포스가 가능해보인다.
     * 7명의 학생 중 ‘이다솜파’의 학생이 적어도 4명 이상은 반드시 포함되어 있어야 한다. -> 그냥 S 간 조합?
     * 뭔가 그냥 S만 모아놓고 DFS + 백트래킹 -> 라기 보다는 가로 + 세로 이어야 한다. = 가로 세로 간 조합 + 무조건 7명
     *
     */

    /*
     * 풀이 = 2초라 넉넉
     * 1. 입력
     * 2. 입력 도중 S 검색 -> 해당 줄의 가로 세로 모두 경우의 숭에 추가
     * 3. solution -> 모든 조합 검색
     *
     */

    input();
    solution();
}