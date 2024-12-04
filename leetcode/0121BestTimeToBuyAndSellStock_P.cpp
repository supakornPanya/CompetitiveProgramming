#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxValue = 0, minValue = prices[0];
        for (int i = 1;i < prices.size();i++) {
            minValue = min(prices[i], minValue);
            maxValue = max(prices[i] - minValue, maxValue);
        }
        return maxValue;
    }
};

int main() {
    Solution sol;
    vector<int> prices = { 7,1,5,3,6,4 };
    int ans = sol.maxProfit(prices);
    cout << ans;
}