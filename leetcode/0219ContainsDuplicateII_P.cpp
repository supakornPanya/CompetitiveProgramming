#include <bits/stdc++.h>
using namespace std;

//using hash table
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> m;
        for (int i = 0;i < nums.size();i++) {
            int v = nums[i];//value
            if (m.find(v) == m.end()) {
                cout<<"false"<<endl;
                m[v] = i;
            } else {
                cout << "true" << endl;
                if (abs(i - m[v]) <= k) { return true; }
                m[v] = i;
                cout<<i<<" "<<m[v]<<endl;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 1,2,3,1,2,3 };
    int k = 2;
    bool ans = sol.containsNearbyDuplicate(nums, k);
    cout << ans;
}