#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minX = grid.size() + 2, minY = grid[0].size() + 2;
        int maxX = 1, maxY = 1;
        for (int x = 0;x < grid.size();x++) {
            for (int y = 0;y < grid[0].size();y++) {
                if (grid[x][y] == 1) {
                    if (x < minX) { minX = x; }
                    if (y < minY) { minY = y; }
                    if (x + 1 > maxX) { maxX = x + 1; }
                    if (y + 1 > maxY) { maxY = y + 1; }
                }
            }
        }
        cout << grid.size() << ", " << grid[0].size() << endl;
        cout << maxX << ", " << minX << endl;
        cout << maxY << ", " << minY << endl;
        int a = (maxX - minX == 0) ? 1 : maxX - minX;
        int b = (maxY - minY == 0) ? 1 : maxY - minY;
        int ans = a * b;
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = { {0, 1, 0}, {1, 0, 1} };
    int ans = sol.minimumArea(grid);
    cout << "ans : " << ans;
}