#include <bits/stdc++.h>
using namespace std;

/*
 * https://www.acmicpc.net/problem/2502
 * tiger eatting Dduck
 */

int d, k;

vector<pair<int, int>> dp;


void input() {
    cin >> d >> k;

    dp = vector<pair<int,int >>(d);

    dp[0] = {1, 0}, dp[1] = {0, 1};

    for (int i = 2; i<d; i++) {
        dp[i] = {dp[i-1].first+dp[i-2].first ,dp[i-1].second+dp[i-2].second};
    }

    /*for (int i = 0; i<d; i++) {
        printf("dp %d: %d, %d\n",i, dp[i].first, dp[i].second);
    }*/
}

void solution() {
    int first_day = dp[d-1].first, second_day = dp[d-1].second, i = 1;
    while (true) {
        if ((k-first_day*i)%second_day == 0) {
            cout << i << '\n' << (k-first_day*i)/second_day <<'\n';
            break;
        }
        i++;
    }
}


int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    input();

    solution();
}