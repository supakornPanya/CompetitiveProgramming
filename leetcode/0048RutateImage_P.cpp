#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0;i < n;i++) { //transpose matrix
            for (int j = 0;j < i;j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        cout << "-----------1st ----------" << endl;
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                cout<<matrix[i][j]<<", ";
            } cout<<endl;
        }
        cout << "--------expect matrix-------" << endl;
        vector<vector<int>> a = { {7, 4, 1}, {8, 5, 2}, {9, 6, 3} };
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                cout << a[i][j] << ", ";
            } cout << endl;
        }
        for (int i = 0;i < n;i++) { //swap column
            for (int j = 0;j < n/2;j++) {
                swap(matrix[i][j], matrix[i][(n-1)-j]);
            }
        }

        cout << "---------2nd swap-----------" << endl;
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                cout << matrix[i][j] << ", ";
            } cout << endl;
        }
        cout << "--------------------" << endl;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} }; // NxN
    sol.rotate(matrix);
    for (auto xx : matrix) {
        for (auto x : xx) {
            cout << x << ", ";
        }
        cout << endl;
    }
}