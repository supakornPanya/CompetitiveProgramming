#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> m;
        //mark row
        for (vector<int> row : grid) {
            m[row]++;
        }
        //loop column
        int count = 0;
        for (int i = 0;i < grid[0].size();i++) {
            vector<int> temp;
            for (int j = 0;j < grid.size();j++) { //loop each row from column i
                temp.push_back(grid[j][i]);
            }
            count += m[temp];
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = { {3,2,1},{1,7,6},{2,7,7} };
    int ans = sol.equalPairs(grid);

    cout << "ans : " << ans;
}