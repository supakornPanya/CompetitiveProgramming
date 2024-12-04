#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 5);
        dp[1] = 1;
        dp[2] = 2;
        if (n == 1) { return 1; }
        if (n == 2) { return 2; }
        for (int i = 3;i <= n;i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

int main(){
    Solution sol;
    int n = 10;
    int ans = sol.climbStairs(n);
    cout<<ans;
}