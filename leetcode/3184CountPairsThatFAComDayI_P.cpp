#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        int  count = 0;
        for (int i = 0;i < hours.size() - 1;i++) {
            for (int j = i + 1;j < hours.size();j++) {
                if ((hours[i] + hours[j]) % 24 == 0) {
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> hours = { 12,12,30,24,24 };
    long long ans = sol.countCompleteDayPairs(hours);
    cout << "ans : " << ans;
}