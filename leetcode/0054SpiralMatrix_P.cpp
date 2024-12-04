#include <bits/stdc++.h>
using namespace std;

//slow , O(MxN), using many if and using flag vector
//loop (vertical/horizontal lines) by checking bound and flag
// class Solution {
// public:
//     vector<int> ans;
//     int nowR = 0, nowC = 0; //first = row, second = column

//     void traversal(int T, vector<vector<bool>>& flag, const vector<vector<int>>& matrix, int r, int c) {
//         while (0 <= nowR && nowR < r && 0 <= nowC && nowC < c && !flag[nowC][nowR]) {

//             cout << matrix[nowC][nowR] << ", ";
//             cout << "nowR : " << nowR << ", nowC : " << nowC << endl;

//             ans.push_back(matrix[nowC][nowR]);
//             flag[nowC][nowR] = true;
//             if (T == 0) { nowR++; }
//             if (T == 1) { nowC++; }
//             if (T == 2) { nowR--; }
//             if (T == 3) { nowC--; }
//         }

//         cout<<endl;
//         for(auto xx:flag){
//             for(auto x:xx){
//                 cout<<x<<", ";
//             }cout<<endl;
//         }

//         if (T == 0) { nowR--; nowC++; }
//         if (T == 1) { nowC--; nowR--; }
//         if (T == 2) { nowR++; nowC--; }
//         if (T == 3) { nowC++; nowR++; }

//         cout << "nowR : " << nowR << ", nowC : " << nowC << endl;

//     }

//     vector<int> spiralOrder(vector<vector<int>>& matrix) {
//         int r = matrix[0].size(), c = matrix.size(), T = 0;
//         vector<vector<bool>> flag(c + 1, vector<bool>(r + 1));
//         //loop 4 type (vertical/horizontal lines) 
//         while (0 <= nowR && nowR < r && 0 <= nowC && nowC < c && !flag[nowC][nowR]) {
//             cout << "traversal --" << "  T%4 : " << T%4 << endl;
//             traversal(T%4, flag, matrix, r, c);
//             T++;
//         }
//         cout << "return ans" << endl;
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int top = 0, bottom = matrix.size(), left = 0, right = matrix[0].size();
        while (ans.size() <= (matrix[0].size() * matrix.size())) {
            
            
            if (ans.size() >= (matrix[0].size() * matrix.size())) {break;}
            //* |->some time {(l,r), (t,b)} was overlapped but for can run
            for (int i = left;i < right;i++) {
                //cout << "1-- " << matrix[top][i] << endl;
                ans.push_back(matrix[top][i]);
            }
            top++;


            if (ans.size() >= (matrix[0].size() * matrix.size())) { break; }
            //* |->some time {(l,r), (t,b)} was overlapped but for can run
            for (int i = top;i < bottom;i++) {
                //cout << "2-- " << matrix[i][right - 1] << endl;
                ans.push_back(matrix[i][right - 1]);
            }
            right--;


            if (ans.size() >= (matrix[0].size() * matrix.size())) { break; }
            //* |->some time {(l,r), (t,b)} was overlapped but for can run
            for (int i = right - 1;i >= left;i--) {
                //cout << "3-- " << matrix[bottom - 1][i] << endl;
                ans.push_back(matrix[bottom - 1][i]);
            }
            bottom--;


            if (ans.size() >= (matrix[0].size() * matrix.size())) { break; }
            //* |->some time {(l,r), (t,b)} was overlapped but for can run
            for (int i = bottom - 1;i >= top;i--) {
                //cout << "4-- " << matrix[i][left] << endl;
                ans.push_back(matrix[i][left]);
            }
            left++;
            //cout << "----------------------" << endl;
        }
        //cout << "----------------------" << endl;
        //cout << ans.size() << endl;
        //cout << matrix[0].size() * matrix.size() << endl;
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = { {1,2,3,4} ,{5,6,7,8},{9,10,11,12} };
    vector<int> ans = sol.spiralOrder(matrix);
    cout << "ans : ";
    for (auto x : ans) {
        cout << x << ", ";
    }
}