#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector<long long> ans(n, 1);
        int mod = 1000000000 + 7;
        for (int i = 0;i < k;i++) {
            for (int j = 1;j < n;j++) {
                ans[j] = ans[j] + ans[j - 1];
                ans[j] %= (mod);
            }
        }
        return (int)(ans[n - 1] % (mod));
    }
};

int main() {
    Solution sol;
    int n = 4, k = 5;
    int ans = sol.valueAfterKSeconds(n, k);
    cout << "ans : " << ans;
}