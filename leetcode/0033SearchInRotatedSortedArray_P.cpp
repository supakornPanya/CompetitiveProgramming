#include <bits/stdc++.h>
using namespace std;

//fast O(2*logN) : b-search find index rotated -> select part for b-search -> b-search find target
// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         if (nums.size() == 1 && nums[0] == target) { return 0; }
//         if (nums.size() == 1 && nums[0] != target) { return -1; }
//         //search index rotated
//         int l = 0, r = nums.size() - 1, m;
//         while (l <= r) {
//             m = (l + r) / 2;
//             //cout << "l : " << l << ", r : " << r << ", m : " << m << endl;
//             if (nums[l] == nums[m]) { 
//                 //cout << "++case 0 -- " << "l : " << l << ", r : " << r << ", m : " << m << endl;
//                 break; 
//             }
//             if (nums[l] < nums[m] && nums[m] > nums[r]) { 
//                 if (nums[m-1] < nums[m] && nums[m] > nums[m+1]) {
//                     //cout << "++case 1 -- " << "l : " << l << ", r : " << r << ", m : " << m << endl;
//                     break;
//                 }
//                 if(m-1 < 0 || m+1 >= nums.size()) { 
//                     //cout << "++case 1 -- " << "l : " << l << ", r : " << r << ", m : " << m << endl;
//                     break;
//                 }
//             } //peak in index / max value
//             if (nums[l] > nums[m]) {
//                 r = m - 1;
//             }
//             if (nums[l] < nums[m]) {
//                 l = m + 1;
//             }
//             //cout << "l : " << l << ", r : " << r << ", m : " << m << endl;
//             //cout << "--------------" << endl;
//         }


//         if (target == nums[0]) { 
//             //cout << "case 0" << endl; 
//             return 0; 
//         }
//         if (target < nums[0]) { //lower value
//             l = m + 1;
//             r = nums.size() - 1;
//             //cout << "case 1 -- " << "l : " << l << ", r : " << r << endl;
//         }
//         if (target > nums[0]) { //upper value
//             l = 0;
//             r = m + 1;
//             //cout << "case 2 -- " << "l : " << l << ", r : " << r << endl;
//         }


//         //search target
//         while (l <= r) {
//             m = (l + r) / 2;
//             //cout << "l : " << l << ", r : " << r << ", m : " << m << endl;
//             if (nums[m] == target) {
//                 return m;
//             }
//             if (nums[m] < target) {
//                 l = m + 1;
//             }
//             if (nums[m] > target) {
//                 r = m - 1;
//             }
//             //cout << "l : " << l << ", r : " << r << ", m : " << m << endl;
//             //cout << "--------------" << endl;
//         }
//         //cout << m << endl;
//         if (nums[m] == target) { return m; } else { return -1; }
//     }
// };


//O(logN)
//find range is sorted 
// ->if(target in range sorted) : find in range sorted
// ->elif(target is out of range sorted) : find in another range
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] == target) { return m; }
            // left to mid is sorted 
            else if (nums[l] <= nums[m]) {
                if (nums[l] <= target && target <= nums[m]) { //target is in l to m
                    r = m - 1; //yes -> find in l to m
                } 
                else { //target is not l to m -> find to the another range
                    l = m + 1; //no -> find in m to r
                }
            }
            //mid to right is sorted 
            else {
                if (nums[m] <= target && target <= nums[r]) { //target is in m to r
                    l = m + 1; //yes -> find in m to r
                }
                else { //target is not m to r -> find to the another range
                    r = m - 1; //no -> find in l to m
                }
            }
        }
        return -1;
    }
};


int main() {
    Solution sol;
    vector<int> nums = { 4,5,6,7,0,1,2 };
    int target = 0;
    int ans = sol.search(nums, target);

    cout << "nums : ";
    for (auto x : nums) {
        cout << x << ", ";
    } cout << "   target : " << target << endl;
    cout << ans;
}