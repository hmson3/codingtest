#include <bits/stdc++.h>
using namespace std;

int dp[1002][1002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= 1000; i++) {
        dp[i][0] = dp[i][i] = 1;
        for (int j = 1; j < i; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
        }
    }
    cout << dp[n][k];
}