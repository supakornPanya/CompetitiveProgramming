#include <bits/stdc++.h>
using namespace std;

//2loop with 2 pointer
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0;i < n - 3;i++) { //loop i
            if (i > 0 && nums[i] == nums[i - 1]) { continue; }
            for (int j = i + 1;j < n - 2;j++) { //loop j
                if (j - 1 != i && j > 0 && nums[j] == nums[j - 1]) { continue; }
                int l = j + 1, r = n - 1;
                long long Ntarget = (long long)target - (long long)nums[i] - (long long)nums[j]; //using long long for prevent overflow
                while (l < r) { //loop left and right
                    long long sumLR = (long long)nums[l] + (long long)nums[r]; //using long long for prevent overflow

                    //show each solution
                    for (auto x : nums) {
                        cout << x << ", ";
                    }cout << endl;
                    cout << i << ", " << j << ", " << l << ", " << r << endl;
                    cout << "n[i] " << nums[i] << ", n[j] " << nums[j] << ", n[l] " << nums[l] << ", n[r] " << nums[r] << endl;
                    cout << "Ntarget : " << Ntarget << "sumLR : " << sumLR << endl;
                    cout << "---------------------" << endl;
                    //show each solution
                    
                    //2 pointer
                    if (Ntarget == sumLR) {
                        ans.push_back({ nums[i], nums[j], nums[l], nums[r] });
                        l++;
                        while (l<r && nums[l] == nums[l - 1]) { l++; } //prevent duplicate index left
                    }
                    if (Ntarget < sumLR) {
                        r--;
                    }
                    if (Ntarget > sumLR) {
                        l++;
                    }
                    //2 pointer
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = { -3,-2,-1,0,0,1,2,3 };
    int target = 0;
    vector<vector<int>> ans = sol.fourSum(nums, target);
    //show nums sorted
    cout << "show nums sorted-----------" << endl;
    sort(nums.begin(), nums.end());
    for (auto x : nums) {
        cout << x << ", ";
    }cout << endl;
    //show ans
    cout << "ans.size : " << ans.size() << endl;
    for (auto xx : ans) {
        for (auto x : xx) {
            cout << x << ", ";
        }
        cout << endl;
    }
}