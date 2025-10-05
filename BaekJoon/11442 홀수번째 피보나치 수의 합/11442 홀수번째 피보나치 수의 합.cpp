#include <bits/stdc++.h>
using namespace std;

long long n; //  1,000,000,000,000,000,000

vector<long long>dp;

void input() {
    cin >> n;

    dp = vector<long long> (n+1);

    dp[0] = 0, dp[1] = 1;
    for (long long i = 2; i<=n; i++) {
        dp [i] = (dp[i-1]+dp[i-2])%1000000007;
    }

}

void solution() {
    long long sum=0;

    for (long long i=1; i<=n; i+=2) { // dp의 홀수만
        sum+=dp[i];
    }

    cout << sum << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    input();
    solution();
    return 0;
}
