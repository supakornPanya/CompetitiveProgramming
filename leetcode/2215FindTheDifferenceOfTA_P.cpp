#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<bool> n1(2001);
        vector<bool> n2(2001);
        vector<vector<int>> ans(2);

        for (int i = 0;i < nums1.size();i++) { //mark index in n1
            n1[nums1[i] + 1000] = true;
        }
        for (int i = 0;i < nums2.size();i++) { //mark index in n2
            n2[nums2[i] + 1000] = true;
        }

        for (int i = 0;i <= 2000;i++) {
            if (n1[i] && !n2[i]) { //have in n1 but not have in n2
                ans[0].push_back(i - 1000);
            }
            if (n2[i] && !n1[i]) { //have in n2 but not have in n1
                ans[1].push_back(i - 1000);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = { 1,2,3 };
    vector<int> nums2 = { 2,4,6 };

    vector<vector<int>> ans = sol.findDifference(nums1, nums2);
    cout << "ans : " << endl;
    for (vector<int> xx : ans) {
        for (int x : xx) {
            cout << x << " ";
        }
        cout << endl;
    }
}