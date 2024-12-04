#include <bits/stdc++.h>
using namespace std;

//O(n!) 
//sol : for call every index that !flag(never use in ans) then flag and call per  
class Solution {
public:
    vector<vector<int>> sumAns;
    void per(const vector<int>& nums, vector<bool>& flag, vector<int> ans) {
        for(int x:ans) {
            cout<<x<<", ";
        }cout<<endl;
        if (ans.size() == nums.size()) {
            sumAns.push_back(ans);
            return;
        }
        for (int i = 0;i < nums.size();i++) { 
            if(!flag[i]) {
                flag[i] = true; ans.push_back(nums[i]);
                per(nums, flag, ans);
                flag[i] = false; ans.pop_back();
            }  
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> flag(nums.size());
        per(nums, flag, {});
        return sumAns;
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 1,2,3 };
    vector<vector<int>> ans = sol.permute(nums);
    cout << "ans : " << endl;
    for (auto xx : ans) {
        for (auto x : xx) {
            cout << x << ", ";
        }cout << endl;
    }
}