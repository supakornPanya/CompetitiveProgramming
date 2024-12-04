#include <bits/stdc++.h>
using namespace std;

//O(2logN) : find lower bound of ans by when found ans then b-search ans range (l,mid)
//           find upper bound of ans by when found ans then b-search ans range (mid,r)
class Solution {
public:
    int search(const vector<int>& nums, int l, int r, int target, bool boundR) {
        int mid, ans = -1;
        cout << "B-search------------------------" << endl;
        cout << l << ", " << r << endl;
        while (l <= r) {
            mid = (l + r) / 2;
            cout << "mid : " << mid << ", nums[mid] : " << nums[mid] << endl;
            if (nums[mid] < target) {
                cout << "->case1" << endl;
                l = mid + 1;
            }
            if (nums[mid] > target) {
                cout << "->case2" << endl;
                r = mid - 1;
            }
            if (nums[mid] == target) {
                cout << "->case3" << endl;
                ans = mid;
                //case find lower bound : find new range that nums[mid] == target index lower index found
                if (boundR) {
                    r = mid - 1;
                }
                //case find upper bound : find new range that nums[mid] == target index upper index found
                 else {
                    l = mid + 1;
                }
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        //find lower bound of ans
        int ansL = search(nums, l, r, target, true);
        //find upper bound of ans
        int ansR = search(nums, l, r, target, false);
        return { ansL, ansR };
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 5,7,7,8,8,10 };
    int target = 6;
    vector<int> ans = sol.searchRange(nums, target);
    cout << "ans : " << ans[0] << ", " << ans[1];
}