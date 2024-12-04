#include <bits/stdc++.h>
using namespace std;

//if now price compare with past price is increase you should buy past price and sell now price
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1;i < prices.size();i++) {
            if(prices[i] > prices[i-1]) {
                profit += prices[i] - prices[i-1];
            }
        }
        return profit;
    }
};

int main() {
    Solution sol;
    vector<int> prices = {};
    int ans = sol.maxProfit(prices);
    cout << ans;
}