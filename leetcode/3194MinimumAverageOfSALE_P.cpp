#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<double> ans;
        int start = 0, end = nums.size() - 1;
        for (int i = 0;i < nums.size() / 2;i++) {
            for (auto x : nums) {
                cout << x << ", ";
            }cout << endl;
            double minn = nums[start], maxx = nums[end];
            start++; end--;
            double aver = (minn + maxx) / 2;
            ans.push_back(aver);
        }
        sort(ans.begin(), ans.end());
        return ans[0];
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 7,8,3,4,15,13,4,1 };
    double ans = sol.minimumAverage(nums);
    cout << "ans : " << ans;
}