#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, flip = 0, maxx = 0;
        
        if (k == 0) { //case k == 0
            int count = 0;
            for (int x : nums) {
                if (x == 1) { count++; maxx = max(maxx, count); } else { count = 0; }
            }
            return maxx;
        }
        
        while (r < nums.size()) {

            for (int i = 0;i < nums.size();i++) {
                cout << nums[i] << " ";
            }cout << endl;
            for (int i = 0;i < nums.size();i++) {
                cout << i << " ";
            }cout << endl;
            cout << "l : " << l << ", r : " << r << ", flip : " << flip;

            if (nums[r] == 1) {

                cout << ", case 1" << endl;

            } else if (flip < k) { //nums[i] == 0 and you can flip

                cout << ", case 2" << endl;
                
                flip++;
            } else { //nums[i] == 0 and you can't flip -> shrink window until found 0(can flip)
                
                cout << ", case 3" << endl;
                
                while (nums[l] != 0) { //shrink window until window can use with new r
                    l++;
                } l++; 
                
                cout << "l : " << l << ", r : " << r << endl;
            
            }
            maxx = max(r - l + 1, maxx);

            cout << "r - l + 1 : " << r - l + 1 << endl;
            cout << "-------------------------------" << endl;

            r++;
        }
        return maxx;
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 1,1,1,0,0,0,1,1,1,1,0 };
    int k = 2;
    int ans = sol.longestOnes(nums, k);

    cout << "ans : " << ans;
}