#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        map<int, int> flag;
        long long count = 0;
        for (int i = 0;i < hours.size();i++) {
            int temp = hours[i] % 24;
            int comp = 24 - temp;
            if (comp == 24) { comp = 0; }
            if (flag[comp]) {
                count += flag[comp];
            }
            flag[temp]++;
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