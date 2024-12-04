#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int store = 0;
        while (l < r) {
            int h = min(height[r], height[l]);
            cout << height[l] << ", " << height[r] << ", " << (r - l) << ", " << (r - l) * h << endl;
            store = max((r - l) * h, store);
            if (height[l] > height[r]) { r--; } else { l++; }
        }
        return store;
    }
};

int main() {
    Solution sol;
    vector<int> height = { 1,8,6,2,5,4,8,3,7 };
    int ans = sol.maxArea(height);
    cout << ans;
}