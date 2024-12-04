#include <bits/stdc++.h>
using namespace std;

//O(N) : for each element to farthest possible
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;
        for (int i = 0;i < nums.size();i++) {
            if (i <= farthest) {//can come here
                farthest = max(i + nums[i], farthest);//this position can give farthest?
            } else {//can't go here so another position is can't go too
                break;
            }
        }
        cout<<farthest<<endl;
        return (farthest >= nums.size() - 1) ? true : false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 2,0,0 };
    bool ans = sol.canJump(nums);
    cout << "ans : " << ans;
}