#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<vector<int>> dir = { {-1,0},{0,1},{1,0},{0,-1} };
        int row = entrance[0], col = entrance[1];
        queue<pair<int, int>> q; q.push({ row,col }); maze[row][col] = '+';
        int n, round = -1;

        while (!q.empty()) {
            n = q.size();
            round++;

            cout << "round : " << round << ", n : " << n << "--------------------" << endl;
            for (vector<char> xx : maze) {
                for (char x : xx) {
                    cout << x << " ";
                }cout << endl;
            }

            for (int i = 0;i < n;i++) {
                pair<int, int> node = q.front(); q.pop();
                for (int j = 0;j < 4;j++) {
                    row = node.first + dir[j][0];
                    col = node.second + dir[j][1];

                    if ((0 <= row && row < maze.size())
                        && (0 <= col && col < maze[0].size()))
                    {
                        if (maze[row][col] == '.')
                        {
                            cout << "row : " << row << ", col : " << col << endl;
                            q.push({ row,col }); maze[row][col] = '+';
                        }
                    } else {
                        //out bound so return round and if out of bound form start is can not an answer
                        if (round != 0) {
                            return round;
                        }
                    }
                }
            }

        }
        //it mean can't go another node from start/ can't go case out site of maze
        return -1;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> maze = { {'+','+','.','+'} ,{'.','.','.','+'},{'+','+','+','.'} };
    vector<int> entrance = { 1,2 };
    int ans = sol.nearestExit(maze, entrance);

    cout << "ans : " << ans;
}