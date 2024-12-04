#include <bits/stdc++.h>
using namespace std;

//!sol : sliding window
//for loop right of window by 0 to nums.size() -> {check used del 0? -> find maxx window}
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, maxx = 0, used = -1;

        for (int x : nums) { cout << x << " "; } cout << endl;
        for (int i = 0;i < nums.size();i++) { cout << i << " "; } cout << endl;

        for (int r = 0;r < nums.size();r++) {
            if (nums[r] == 0) {
                if (used == -1) { //never ues delete 0 in this sub array
                    used = r; // mark index use del 0
                } else { //ever use delete 0 in this sub array
                    l = used + 1; //re range window by start l next index del 0(now window have '0' 1 index) 
                    used = r; //mark index use del 0
                }
            }
            //used == -1 -> never use del 0 -> size of window == size of window
            //used != -1 -> ever use del 0 -> size of window == size of window - 1(index value 0) 
            maxx = (used == -1) ? max(r - l + 1, maxx) : max(r - l, maxx);
            cout << "l : " << l << ", r : " << r << ", maxx : " << maxx << ", used : " << used << endl;
        }

        //in case used == -1 is never del 0 -> never have 0 in nums -> problem must del 1 index -> maxx window -1
        return (used == -1) ? maxx - 1 : maxx;
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 0,1,1,1,0,1,1,0,1 };
    int ans = sol.longestSubarray(nums);

    cout << "ans : " << ans;
}