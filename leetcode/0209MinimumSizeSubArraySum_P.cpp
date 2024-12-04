#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, ans = INT_MAX, l = 0, r;
        for (r = 0;r < nums.size();r++) {
            sum += nums[r];
            if (sum >= target) { ans = min(ans, r - l + 1); }
            /*show before maintain window*/ cout << "ans : " << ans << ", sum : " << sum << ", l : " << l << ", r : " << r << endl;
            while (sum >= target) {
                sum -= nums[l];
                l++;
            }
            /*show after maintain window*/ cout << "ans : " << ans << ", sum : " << sum << ", l : " << l << ", r : " << r << endl;
            if (l - 1 >= 0 && sum + nums[l - 1] >= target) { ans = min(ans, r - (l - 1) + 1); }
            /*show window can use */cout << "ans : " << ans << ", sum+nums[l-1] : " << sum + nums[l - 1] << ", l-1 : " << l - 1 << ", r : " << r << endl;//
            //show nums
            for (auto x : nums) {
                cout << x << " ,";
            }cout << endl;
            cout << "------------------" << endl;
            //show nums
        }
        return (ans == INT_MAX) ? 0 : ans;
    }
};

int main() {
    Solution sol;
    int target = 213;
    vector<int> nums = { 12,28,83,4,25,26,25,2,25,25,25,12 };
    int ans = sol.minSubArrayLen(target, nums);
    //show ans
    cout << ans;
}