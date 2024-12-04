#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 0;i <= n;i++) {
        dp[i][0] = 1;
    }
    for (int i = 0;i <= n;i++) {
        dp[i][i] = 1;
    }
    for (int i = 1;i <= n;i++) {
        // cout << dp[i][0] << " ";
        for (int j = 1;j <= i;j++) {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            // cout << dp[i][j] << " ";
        }
        // cout << '\n';
    }

    cout << dp[n][k];
}