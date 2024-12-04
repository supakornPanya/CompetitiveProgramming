#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m + 1, vector<int>(n + 1));
        grid[1][0] = 1;
        cout << grid.size() << ", " << grid[0].size() << endl;
        for (int i = 1;i <= m;i++) {
            for (int j = 1;j <= n;j++) {
                grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
            }
        }
        return grid[m][n];
    }
};

int main() {
    Solution sol;
    int m = 3, n = 7;
    int ans = sol.uniquePaths(m, n);
    cout << "ans : " << ans;
}