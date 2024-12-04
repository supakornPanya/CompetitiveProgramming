#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string ans = "1";
        for (int i = 2;i <= n;i++) {
            cout<<ans<<endl;
            string temp = "";
            int count = 1;
            for (int j = 0;j < ans.size();j++) {
                if (ans[j] == ans[j + 1]) {
                    count++;
                } else {
                    temp += ('0' + count);
                    temp += ans[j];
                    count = 1;
                }
            }
            ans = temp;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int n = 6;
    string ans = sol.countAndSay(n);
    cout << ans;
}