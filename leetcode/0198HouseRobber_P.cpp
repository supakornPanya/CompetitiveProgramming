#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) { return nums[0]; }
        if (nums.size() == 2) { return max(nums[0], nums[1]); }
        int n = nums.size();
        for (int i = 2;i < n;i++) {
            //nums[i] have previous robbed house is nums[i - 2](can't nums[i-1] because adjacent) to nums[0]
            //but we don't use nums[i - 4] to nums[0] because if nums[i - 4] to nums[0] is the best answer
            //nums[i - 2] or nums[i - 3] will chose it first
            nums[i] += (i >= 3 && nums[i - 3] > nums[i - 2]) ? nums[i - 3] : nums[i - 2];
            cout << nums[i] << " ";
        }
        return (nums[n - 1] > nums[n - 2]) ? nums[n - 1] : nums[n - 2];
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 1,2,3,1 };
    int ans = sol.rob(nums);

    cout << "ans : " << ans;
}