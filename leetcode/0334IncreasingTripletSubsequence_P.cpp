#include <bits/stdc++.h>
using namespace std;

//!sol speed up
// class Solution {
// public:
//     bool increasingTriplet(vector<int>& nums) {
//         int min1 = INT_MAX, min2 = INT_MAX; //min1 < min2 
//         for (int i = 0;i < nums.size();i++) {
//             if (nums[i] > min2) {
//                 return true;
//             } else {
//                 if (nums[i] < min1) {
//                     min1 = nums[i];
//                 } else if (min1 < nums[i]) {
//                     min2 = nums[i];
//                 }
//             }
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min1 = INT_MAX, min2 = INT_MAX; //min1 < min2 
        for (int i = 0;i < nums.size();i++) {
            if (nums[i] > min2 && nums[i] > min1) {
                return true;
            } else { 
                if(nums[i] < min1 && nums[i] < min2){
                    min1 = nums[i];
                } else if(min1 < nums[i] && nums[i] < min2){
                    min2 = nums[i];
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,3,4,5};
    bool ans = sol.increasingTriplet(nums);

    cout<<"ans : "<<ans;
}