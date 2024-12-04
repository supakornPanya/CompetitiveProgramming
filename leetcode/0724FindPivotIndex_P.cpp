#include <bits/stdc++.h>
using namespace std;

// //!sol 2 
// //using vector left for get left sum
// //using vector right for get right sum
// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
//         if(nums.size() == 1) return 0;
//         vector<int> left(nums.size()); left[0] = nums[0];
//         vector<int> right(nums.size()); right[nums.size() - 1] = nums[nums.size() - 1];

//         //for (int x : nums) { cout << x << " "; } cout << endl;

//         for (int i = 1;i < nums.size();i++) { //dp for left
//             left[i] = left[i - 1] + nums[i];
//         }

//         //for (int x : left) { cout << x << " "; } cout << endl;

//         for (int i = nums.size() - 2;i >= 0;i--) { //dp for right
//             right[i] = right[i + 1] + nums[i];
//         }

//         //for (int x : right) { cout << x << " "; } cout << endl;

//         if (0 == right[1]) return 0; //case : index == 0
//         for (int i = 1;i <= nums.size() - 2;i++) { //case : [first + 1, last - 1]
//             if (left[i - 1] == right[i + 1]) return i;
//         }
//         if (left[nums.size() - 2] == 0) return nums.size() - 1; //case : index == nums.size() - 1 (last index)
        
//         return -1;
//     }
// };

//!sol 1 best solution??
//using vector dp for get sum left and right
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() == 1) return 0;

        int n = nums.size();
        vector<int> dp(n); dp[0] = nums[0];

        for (int i = 1;i < n;i++) { //create prefix sum
            dp[i] = nums[i] + dp[i - 1];
        }

        for (int x : nums) { cout << x << " "; } cout << endl;
        for (int x : dp) { cout << x << " "; } cout << endl;

        if (0 == dp[n - 1] - dp[0]) return 0; //case : index == 0
        for (int i = 1;i <= n - 2;i++) {
            //dp[i - 1] == left sum
            //dp[n - 1] - dp[i] == right sum
            if (dp[i - 1] == (dp[n - 1] - dp[i])) return i;
        }

        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = { -1,-1,0,1,0,-1 };
    int ans = sol.pivotIndex(nums);

    cout << "ans : " << ans;
}