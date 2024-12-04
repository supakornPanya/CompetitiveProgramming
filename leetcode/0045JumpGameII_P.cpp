#include <bits/stdc++.h>
using namespace std;

//O(n) : find a index that give furthest in range from the minimum jump
//find index that give furthest because furthest is give big opportunity
//prove : -->
//define : have 1 index(wonder index) is the best path that give minimum jump to end!!!!,
//         have 1 index(good index) from my range can go wonder index 
//problem : in range what is index can jump to wonder index ???
//visualize : start{----index1----good index----index2----}end ----wonder index
//sol : find index that can jump further than wonder index -> if(>= wonder index) is mean you can go wonder index 
class Solution {
public:
    int jump(vector<int>& nums) {
        int near = 0, far = 0, jump = 0;
        while (far < nums.size() - 1) {
            cout << near << ", " << far << ", " << jump << endl;
            int furthest = far;
            for (int i = near;i <= far;i++) {
                furthest = max(nums[i] + i, furthest);
            }
            near = far + 1;
            far = furthest;
            jump++;
        }
        return jump;
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 0 };
    int ans = sol.jump(nums);
    cout << "ans : " << ans;
}