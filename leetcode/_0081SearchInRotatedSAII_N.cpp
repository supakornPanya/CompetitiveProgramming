#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int BSearch(const vector<int> nums, int target, bool leftSide) {
        int l = 0, r = nums.size(), mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else if (nums[mid] == target) {
                if (leftSide) {
                    jj
                } else {
                    j
                }   
            }
        }
        return mid;
    }
    bool search(vector<int>& nums, int target) {
        int l = BSearch(nums, target, true);
        int r = BSearch(nums, target, false);

    }
};

int main() {
    Solution sol;
    vector<int> nums = { 2,5,6,0,0,1,2 };
    int target = 0;
    bool ans = sol.search(nums, target);
    cout << "ans : " << ans;
}