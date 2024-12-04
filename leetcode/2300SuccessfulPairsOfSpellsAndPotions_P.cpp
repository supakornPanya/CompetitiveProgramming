#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;

        for (int i = 0;i < spells.size();i++) {
            int l = 0, r = potions.size() - 1, mid;
            int idx = potions.size(); //for case doesn't thought case : spells[i]) * potions[mid] >= success

            for (auto x : potions) {
                cout << spells[i] * x << ", ";
            }cout << endl;

            while (l <= r) {
                mid = (l + r) / 2;
                cout << "mid : " << mid << ", val : " << spells[i] * potions[mid] << endl;
                if ((long long)(spells[i]) * potions[mid] < success) {
                    l = mid + 1;
                }
                //when spells[i]) * potions[mid] >= success == this mid can use but may be a best answer
                if ((long long)(spells[i]) * potions[mid] >= success) {
                    r = mid - 1;
                    idx = mid;
                }
            }
            cout << "idx : " << idx << endl;
            cout << "potions.size() - idx : " << potions.size() - idx << endl;
            ans.push_back(potions.size() - idx);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> spells = { 1,2,3,4,5 };
    vector<int> potions = { 1,2,3,4,5 };
    long long success = 7;
    vector<int> ans = sol.successfulPairs(spells, potions, success);

    cout << "ans : " << endl;
    for (int x : ans) {
        cout << x << ", ";
    }
}