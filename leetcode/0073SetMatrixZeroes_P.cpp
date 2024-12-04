#include <bits/stdc++.h>
using namespace std;

//!sol1 : mark by map
//time : O(M*N*log(M*N))
//space : O(M+N)
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int r = matrix.size(), c = matrix[0].size();
//         map<int, bool> mR, mC; //space : O(M+N)
//         //O(M*N*log(M*N))
//         for (int i = 0;i < r;i++) {
//             for (int j = 0;j < c;j++) {
//                 if (matrix[i][j] == 0) {
//                     mR[i] = true; mC[j] = true; //logMN
//                 }
//             }
//         }
//         //O(M*N*log(M*N))
//         for (int i = 0;i < r;i++) {
//             for (int j = 0;j < c;j++) {
//                 if(mR[i] || mC[j]){
//                     matrix[i][j] = 0;
//                 }
//             }
//         }    
//     }
// };

//!sol2 : mark by vector
//time : O(M*N*1)
//space : O(M+N)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        vector<bool> vR(r), vC(c); //space : O(M+N)
        //O(M*N*1)
        for (int i = 0;i < r;i++) {
            for (int j = 0;j < c;j++) {
                if (matrix[i][j] == 0) {
                    vR[i] = true; vC[j] = true; //O(1)
                }
            }
        }
        //O(M*N*1)
        for (int i = 0;i < r;i++) {
            for (int j = 0;j < c;j++) {
                if (vR[i] || vC[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = { {1,1,1} ,{1,0,1},{1,1,1} };

    cout << "ans : " << endl;
    for (auto xx : matrix) {
        for (auto x : xx) {
            cout << x << ", ";
        }cout << endl;
    }
}