#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (target > nums[nums.size() - 1]) { return nums.size(); }
        if (target < nums[0]) { return 0; }
        int m, l = 0, r = nums.size() - 1;
        while (l <= r) {
            m = (l + r) / 2;
            cout << "l : " << l << ", r : " << r << ", m : " << m << endl;
            if (nums[m] == target) {
                return m;
            } else if (m > 0 && nums[m - 1] < target && target < nums[m]) {
                cout << "bb";
                return m;
            } else if (m < nums.size() - 1 && nums[m] < target && target < nums[m + 1]) {
                cout << "cc";
                return m + 1;
            } else if (nums[m] > target) {
                r = m - 1;
            } else if (nums[m] < target) {
                l = m + 1;
            }
        }
        cout<<"aa";
        return m;
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 1,3,5 };
    int target = 1;
    int ans = sol.searchInsert(nums, target);
    cout << ans;
}