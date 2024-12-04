#include <bits/stdc++.h>
using namespace std;

//very slow -> O(logN + n + n^2)
//sort O(logN) -> loop map value O(n) -> loop 2 index check sum with map value O(n^2)
// class ijx {
// public:
//     int i;
//     int j;
//     int x;
//     ijx(int i, int j, int x) : i(i), j(j), x(x) {}
//     bool operator<(const ijx& other) const {
//         if (i != other.i) return i < other.i;
//         if (j != other.j) return j < other.j;
//         return x < other.x;
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         map<int, int> m; //int int
//         for (int i = 0;i < nums.size();i++) {
//             int x = nums[i];
//             m[x] = i + 1;
//         }
//         map<ijx, bool> ck;
//         vector<vector<int>> ans;
//         for (int i = 0;i < nums.size() - 2;i++) {
//             for (int j = i + 1;j < nums.size() - 1;j++) {
//                 int x = (nums[i] + nums[j]) * -1;
//                 if (m[x] && m[x] - 1 > i && m[x] - 1 > j) {
//                     //cout << nums[i] << " " << nums[j] << " " << x << endl;
//                     if (!ck[ijx(nums[i], nums[j], x)]) {
//                         ans.push_back({ nums[i], nums[j], x });
//                         ck[ijx(nums[i], nums[j], x)] = true;
//                         //cout << nums[i] << " " << nums[j]<< " "<< x<< endl;
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };

//fastest O(logN + n^2 = logN + n^2/2)
//sort O(logN) -> loop start i O(n) then while loop l++ or r-- O(n)
//principle : like a loop all posible in combination but we use l++ or r-- 
//            for total convergence to 0 because nums is sorted 
//            if total little : l++ -> nums[l] increase
//            if total a lot : r-- -> nums[r] decrease
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0;i < nums.size() - 2;i++) {
            if (i != 0 && nums[i] == nums[i - 1]) { continue; } //don't do anything repeat (i)
            cout<<" i "<<endl;
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int total = nums[i] + nums[l] + nums[r];
                if (total == 0) {
                    if (l - 1 != -1 && r + 1 != nums.size()) { // check bound l, r
                        if (nums[l - 1] != nums[l] || nums[r] != nums[r + 1]) { //don't do anything repeat(l,r)
                            ans.push_back({ nums[i], nums[l], nums[r] });
                        }
                    }else { // not out of bound == it not repeat 
                        ans.push_back({ nums[i], nums[l], nums[r] });
                    }
                    l++; r--;
                }
                if (total < 0) {
                    l++;
                }
                if (total > 0) {
                    r--;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    //vector<int> nums = { -1, 0, 1, 2, -1, -4 };
    vector<int> nums = { 0,0,0,0 };
    vector<vector<int>> ans = sol.threeSum(nums);
    //show sorted vector
    sort(nums.begin(), nums.end());
    cout << "sorted nums : ";
    for (auto x : nums) {
        cout << x << ", ";
    }cout << endl;
    //show ans
    for (auto anss : ans) {
        for (auto x : anss) {
            cout << x << ", ";
        }
        cout << endl;
    }
}