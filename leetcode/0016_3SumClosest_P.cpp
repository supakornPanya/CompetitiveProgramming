#include <bits/stdc++.h>
using namespace std;

//fastest O(logN + n^2 = logN + n^2/2)
//sort O(logN) -> loop start i O(n) then while loop l++ or r-- O(n)
//principle : like a loop all posible in combination but we use l++ or r-- 
//            for total convergence to target because nums is sorted 
//            if total little : l++ -> nums[l] increase
//            if total a lot : r-- -> nums[r] decrease
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0;i < nums.size() - 2;i++) {
            if (i != 0 && nums[i] == nums[i - 1]) { continue; } //don't do anything repeat (i)
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int total = nums[i] + nums[l] + nums[r];
                if (total == target) { 
                    return total; 
                    cout << nums[i] << ", " << nums[l] << ", " << nums[r] << endl;
                }
                if (total < target) {
                    if (abs(target - total) < abs(target - ans)) { ans = total; }
                    cout << nums[i] << ", " << nums[l] << ", " << nums[r] << endl;
                    l++;
                }
                if (total > target) {
                    if (abs(target - total) < abs(target - ans)) { ans = total; }
                    cout << nums[i] << ", " << nums[l] << ", " << nums[r] << endl;
                    r--;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = { -1,2,1,-4 };
    int target = 1;
    int ans = sol.threeSumClosest(nums, target);
    //show sorted nums
    sort(nums.begin(), nums.end());
    cout<<"nums sorted : ";
    for(auto x:nums){
        cout<<x<<", ";
    }cout<<endl;
    cout << ans;
}