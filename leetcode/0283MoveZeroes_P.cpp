#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int place = 0;
        for (int i = 0;i < nums.size();i++) {
            for (auto x : nums) { cout << x << ", "; }cout << endl;
            if (nums[i] != 0) {
                nums[place] = nums[i];
                place++;
            }
        }
        while (place < nums.size()) {
            nums[place++] = 0;
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 0,1,0,3,12 };
    sol.moveZeroes(nums);

    cout << "ans : " << endl;
    for (int x : nums) {
        cout << x << ", ";
    }
}