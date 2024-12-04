#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int left = 0, right = n-1, top = 0, bottom = n-1, count = 1;
        while (count-1 < n * n) {
            for(int i=left;i<=right;i++){
                ans[top][i] = count++;
                cout << "1-- " << top << ", " << i << ", " << ans[top][i] << endl;
            }
            top++;

            if (count > n * n) { break; }
            for (int i = top;i <= bottom;i++) {
                ans[i][right] = count++;
                cout << "2-- " << i << ", " << right << ", " << ans[i][right] << endl;
            }
            right--;

            if (count > n * n) { break; }
            for (int i = right;i >= left;i--) {
                ans[bottom][i] = count++;
                cout << "3-- " << bottom << ", " << i << ", " << ans[bottom][i] << endl;
            }
            bottom--;

            if (count > n * n) { break; }
            for (int i = bottom;i >= top;i--) {
                ans[i][left] = count++;
                cout << "4-- " << i << ", " << left << ", " << ans[i][left] << endl;
            }
            left++;
        }
        return ans;
    }
};

int main(){
    Solution sol;
    int n = 2;
    vector<vector<int>> ans = sol.generateMatrix(n);
    for(auto xx:ans){
        for(auto x:xx){
            cout<<x<<", ";
        }
        cout<<endl;
    }
}