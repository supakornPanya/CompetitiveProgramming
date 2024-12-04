#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, mid = 0;
        //l <= r is incorrect because, in the case where nums.size() = 1, l = 0 and r = 0, which leads to a runtime error.
        while (l < r) {
            mid = (r + l) / 2;
            // This mid is the answer (it must be, because in the case where mid < mid + 1 but mid - 1 < mid too)
            if (mid > 0 && mid < nums.size() - 1 && (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])) {
                return mid;
            }
            // The right is greater than the mid, so the peak may be to the right of the mid.
            else if (mid < nums.size() - 1 && nums[mid] < nums[mid + 1]) {
                cout << "mid : " << mid << ", nums[mid] : " << nums[mid] << endl;
                l = mid + 1; 
            }
            // The left is greater than the mid, so the peak may be to the left of the mid.
            else if (mid > 0 && nums[mid - 1] > nums[mid]) {
                cout << "mid : " << mid << ", nums[mid] : " << nums[mid] << endl;
                r = mid - 1;
            }
            // In the case where nums.size() == 2 and mid < mid + 1, this case will pass all the if conditions above, causing the binary search to loop infinitely.
            // Therefore, this mid is the answer."
            else { return mid; }
        }
        return l;
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 1,2,3,1 };
    int ans = sol.findPeakElement(nums);

    cout << "ans : " << ans;
}