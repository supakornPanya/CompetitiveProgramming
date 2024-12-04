#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int> row = { 1,0,-1,0 }; //num for change index in row
        vector<int> col = { 0,1,0,-1 }; //num for change index in column
        queue<pair<int, int>> q;
        //find a rotting orange
        for (int i = 0;i < grid.size();i++) {
            for (int j = 0;j < grid[0].size();j++) {
                if (grid[i][j] == 2) { q.push({ i,j }); }
            }
        }

        cout << "----------------------------" << endl;
        for (vector<int> xx : grid) {
            for (int x : xx) {
                cout << x << " ";
            }cout << endl;
        }
        //bfs
        int n, round = -1;
        while (!q.empty()) {
            //loop in each level
            round++;
            n = q.size();
            cout << n << " : ----------------------------" << endl;
            for (int i = 0;i < n;i++) {
                pair<int, int> node = q.front(); q.pop(); //.first = row, .second = col
                for (int i = 0;i < 4;i++) {
                    int r = node.first + row[i]; //new index of row
                    int c = node.second + col[i]; //nex index of column
                    if ((0 <= r && r < grid.size())
                        && (0 <= c && c < grid[0].size())
                        && (grid[r][c] == 1)) {
                        cout << "r : " << r << ", c : " << c << endl;
                        q.push({ r,c });
                        grid[r][c] = 2;
                    }
                }
            }

            for (vector<int> xx : grid) {
                for (int x : xx) {
                    cout << x << " ";
                }cout << endl;
            }

        }

        //check have any fresh orange ??
        for (vector<int> xx : grid) {
            for (int x : xx) {
                if (x == 1) return -1;
            }
        }

        //when round is -1 is mean not through in while(!q.empty())
        //so is not have any round
        return (round == -1) ? 0 : round;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = { {2,1,1} ,{1,1,0},{0,1,1} };
    int ans = sol.orangesRotting(grid);

    cout << "ans : " << ans;
}