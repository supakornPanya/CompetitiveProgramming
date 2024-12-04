#include <bits/stdc++.h>
using namespace std;

// fastest, binary search, O(logN + logM) = O(logNM)
// sol : b-search range column -> b-search row in colunm-found
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int SizeCol = matrix.size(), SizeRow = matrix[0].size();
        int m, l = 0, r = SizeCol - 1;
        while (l <= r) {
            m = (l + r) / 2;
            if (matrix[m][0] <= target && target <= matrix[m][SizeRow - 1]) {
                break;
            }
            if (matrix[m][SizeRow - 1] <= target) {
                l = m + 1;
            }
            if (target <= matrix[m][0]) {
                r = m - 1;
            }
        }
        cout << "l : " << l << ", r : " << r << ", m : " << m << endl;
        int MCol = m;
        l = 0, r = SizeRow - 1;
        while (l <= r) {
            m = (l + r) / 2;
            if (matrix[MCol][m] == target) {
                return true;
            }
            if (matrix[MCol][m] < target) {
                l = m + 1;
            }
            if (matrix[MCol][m] > target) {
                r = m - 1;
            }
        }
        if (matrix[MCol][m] == target) { return true; } else { return false; }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = { {1,3,5,7} ,{10,11,16,20},{23,30,34,60} };
    int target = 33;
    bool ans = sol.searchMatrix(matrix, target);
    cout << ans;
}