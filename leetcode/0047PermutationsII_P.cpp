#include <bits/stdc++.h>
using namespace std;

//!add map
//map is using for not call same value in same path of parent
class Solution {
public:
    vector<vector<int>> sumAns;
    void per(const vector<int>& nums, vector<int> ans, vector<bool>& flag) {
        if (ans.size() == nums.size()) {
            sumAns.push_back(ans);
            return;
        }
        map<int, bool> m;
        for (int i = 0;i < nums.size();i++) {
            if (!flag[i] && !m[nums[i]]) {
                ans.push_back(nums[i]); flag[i] = true;
                m[nums[i]] = true;
                per(nums, ans, flag);
                ans.pop_back(); flag[i] = false;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> flag(nums.size());
        sort(nums.begin(), nums.end());
        per(nums, {}, flag);
        return sumAns;
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 1,1,2 };
    vector<vector<int>> ans = sol.permuteUnique(nums);

    cout << "ans : " << endl;
    for (auto xx : ans) {
        for (auto x : xx) {
            cout << x << ", ";
        }cout << endl;
    }
}