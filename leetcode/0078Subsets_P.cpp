#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    void com(const vector<int>& nums, vector<int>& sol, int start) {

        cout << "sol : ";
        for (int x : sol) { cout << x << ", "; }
        cout << "start : " << start << endl;

        for (int i = start;i < nums.size();i++) {
            //chose-->
            sol.push_back(nums[i]); 

            cout << "sol : ";
            for (int x : sol) { cout << x << ", "; } cout << endl;

            ans.push_back(sol);//sol have new data so add this sol in ans
            com(nums, sol, i + 1);

            //not chose-->
            sol.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sol;
        ans.push_back({});
        com(nums, sol, 0);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 1,2,3,4 };
    vector<vector<int>> ans = sol.subsets(nums);

    cout << "ans.size() : " << ans.size() << endl;
    for (vector<int> xx : ans) {
        for (int x : xx) {
            cout << x << ", ";
        }cout << endl;
    }
}