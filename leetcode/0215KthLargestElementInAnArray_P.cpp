#include <bits/stdc++.h>
using namespace std;

//O(N*logN), using sort std
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end());
//         return nums[nums.size() - k];
//     }
// };

//O(N*logK), loop each element is O(N) -> push is logK because in pq will push max k element
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0;i < k;i++) {
            pq.push(nums[i]);
        }
        for (int i = k;i < nums.size();i++) {
            if(nums[i]>pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};

//it have another solution is Quick Select algorithm
//Best and Average Case: O(N)
//Worst Case : O(N^2)

int main() {
    Solution sol;
    vector<int> nums = { 3,2,1,5,6,4 };
    int k = 2;
    int ans = sol.findKthLargest(nums, k);
    cout << ans;
}