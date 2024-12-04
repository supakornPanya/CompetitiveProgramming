#include <bits/stdc++.h>
using namespace std;

//very slow because using a erase( O(n) )
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         map<int, bool> m;
//         int count = 0;
//         for (int i = 0;i < nums.size();i++) {
//             int v = nums[i];
//             if (m.find(v) == m.end()) {
//                 m[v] = true;
//                 count++;
//             } else {
//                 nums.erase(nums.begin() + i);
//                 i--;
//             }
//         }
//         return count;
//     }
// };

//fasted becase set a new value
//can compare by i with i-1 because array is sorted
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!= nums[i-1]){
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 1,1,2 };
    int ans = sol.removeDuplicates(nums);
    cout << ans << endl;
    for (auto x : nums) {
        cout << x << " ";
    }
}