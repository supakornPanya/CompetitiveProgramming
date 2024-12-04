#include <bits/stdc++.h>
using namespace std;

//sol : find sum product left and right -> ans[i] = left[i-1] * right[i+1] 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size() + 5); left[0] = 1;
        vector<int> right(nums.size() + 5); right[nums.size()] = 1;
        //shifting 1 index, ans[0] use left[0] [0,nums.size()-1]
        //because can't set index -1
        for (int i = 1;i < nums.size();i++) {
            left[i] = left[i - 1] * nums[i - 1];
        }
        for (int i = nums.size() - 1;i > 0;i--) {
            right[i] = right[i + 1] * nums[i];
        }

        // for (int i = 0;i < nums.size();i++) {
        //     cout << i << " : " << left[i] << endl;
        // }
        // cout << "----------------" << endl;
        // for (int i = 0;i < nums.size() + 1;i++) {
        //     cout << i << " : " << right[i] << endl;
        // }

        vector<int> ans(nums.size());
        for (int i = 0;i < nums.size();i++) {
            ans[i] = left[i] * right[i + 1];
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 1,2,3,4 };
    vector<int> ans = sol.productExceptSelf(nums);

    cout << "ans : " << endl;
    for (int x : ans) {
        cout << x << ", ";
    }
}