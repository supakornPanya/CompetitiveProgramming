#include <bits/stdc++.h>
using namespace std;

//using two pointer
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size()-1; // left, right
        int ans = 0;
        while (l < r) {
            if ((nums[l] + nums[r]) == k) {
                ans++;
                l++; r--;
            } else if ((nums[l] + nums[r]) < k) {
                l++;
            } else if ((nums[l] + nums[r]) > k) {
                r--;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 1,2,3,4 };
    int k = 5;
    int ans = sol.maxOperations(nums, k);

    cout << "ans : " << ans;
}