#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> grid(m + 1, vector<int>(n + 1));
        grid[1][0] = 1;
        cout << grid.size() << ", " << grid[0].size() << endl;
        for (int i = 1;i <= m;i++) {
            for (int j = 1;j <= n;j++) {
                if(obstacleGrid[i-1][j-1] == 0){
                    grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
                }
            }
        }
        return grid[m][n];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    int ans = sol.uniquePathsWithObstacles(obstacleGrid);
    cout << "ans : " << ans;
}