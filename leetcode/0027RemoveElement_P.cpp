#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0, tsize = nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val){
                nums.erase(nums.begin()+i);
                count++;
                i--;
            }
        }
        cout << nums.size() << " " << count <<endl;
        return tsize - count;
    }
};

int main(){
    Solution sol;
    vector<int> nums = { 3,2,2,3 };
    int val = 3;
    int ans = sol.removeElement(nums, val);
    cout<<ans;
}