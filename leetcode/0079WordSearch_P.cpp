#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<pair<int, int>, bool> flag;

    bool find(int i, int j, int idx, vector<vector<int>>& flag,
        const vector<vector<char>>& board, string word) {
        if (!(0 <= i && i < board.size()) //out of bound
            || !(0 <= j && j < board[0].size()) //out of bound
            || (board[i][j] != word[idx]) //word is incorrect
            || (flag[i][j] == 1)) { //ever meet
            return false;
        }
        if (idx == word.size() - 1) {//all correct when end string
            return true;
        }

        // for (int i = 0;i < board.size();i++) {//flag table
        //     for (int j = 0;j < board[0].size();j++) {
        //         if (flag[{i, j}]) { cout << "1 "; } else { cout << "0 "; }
        //     }cout << endl;
        // }
        // cout << board[i][j] << ", " << idx << endl;

        vector<vector<int>> move = { {1,0}, {0,1}, {-1,0}, {0,-1} };
        flag[i][j] = 1;//flag parent
        for (auto& m : move) {
            i = i + m[0]; j = j + m[1];//next position

            if(find(i, j, idx + 1, flag, board, word)){
                return true;
            }

            i = i - m[0]; j = j - m[1];//back track to before position
        }
        flag[i][j] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        // cout << "word : " << endl;
        // for (vector<char> xx : board) {
        //     for (char x : xx) {
        //         cout << x << " ";
        //     }cout << endl;
        // }cout << "--------------" << endl;

        vector<vector<int>> flag(board.size(), vector<int> (board[0].size(), 0));
        bool ans = false;
        for (int i = 0;i < board.size();i++) {
            for (int j = 0;j < board[0].size();j++) {
                if (board[i][j] == word[0]) {
                    if (find(i, j, 0, flag, board, word)) {
                        return true;
                    }
                    //cout << "------------->" << ans << endl;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board = { {'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'} };
    
    string word = "ABCCED";
    bool ans = sol.exist(board, word);
    cout << ans;
}