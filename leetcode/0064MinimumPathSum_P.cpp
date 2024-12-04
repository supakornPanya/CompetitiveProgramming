#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        cout << grid.size() << ", " << grid[0].size() << endl;
        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                if (i == 0 && j == 0) { 
                    cout << "case0, ";
                    continue; 
                } 
                else if (i == 0) { 
                    cout<<"case1, ";
                    grid[i][j] += grid[i][j - 1]; 
                } //bound
                else if (j == 0) {
                    cout << "case2, ";
                    grid[i][j] += grid[i - 1][j]; 
                } //bound
                else if (grid[i - 1][j] <= grid[i][j - 1]) {
                    cout << "case3, ";
                    grid[i][j] += grid[i - 1][j];
                } else if (grid[i - 1][j] > grid[i][j - 1]) {
                    cout << "case4, ";
                    grid[i][j] += grid[i][j - 1];
                }
            }
            cout<<endl;
        }
        cout << "grid : " << endl;
        for (auto xx : grid) {
            for (auto x : xx) {
                cout << x << ", ";
            }cout << endl;
        }
        return grid[m - 1][n - 1];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = { {1,2,3},{4,5,6} };
    int ans = sol.minPathSum(grid);
    cout << "ans : " << ans;
}