#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumChairs(string s) {
        int count = 0, ans = 0;
        for (auto x : s) {
            if (x == 'E') {
                count++;
            }
            if (x == 'L') {
                count--;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "EEEEEEE";
    int ans = sol.minimumChairs(s);
    cout << ans << endl;
}