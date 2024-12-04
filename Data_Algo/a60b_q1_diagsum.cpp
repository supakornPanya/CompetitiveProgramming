#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int ans = INT_MIN;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            cin >> dp[i][j];
            ans = max(ans, dp[i][j]);
        }
    }

    for (int i = 2;i <= n;i++) {
        for (int j = 2;j <= n;j++) {
            dp[i][j] = max(dp[i][j], dp[i][j]+ dp[i - 1][j - 1]);
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
}