#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, one = 0, start = 0;
        for (int x : nums) {
            if (x == 0) { zero++; } else if (x == 1) { one++; }
        }
        while (start < zero) { nums[start] = 0; start++; }
        while (start < zero + one) { nums[start] = 1; start++; }
        while (start < nums.size()) { nums[start] = 2; start++; }
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 2,0,2,1,1,0 };
    sol.sortColors(nums);

    cout << "ans : " << endl;
    for (int x : nums) {
        cout << x << ", ";
    }
}