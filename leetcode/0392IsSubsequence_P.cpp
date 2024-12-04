#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for (char c : t) {
            if (c == s[i]) {
                cout << s[i] << " ";
                i++;
            }
        }
        cout<<i<<" ";
        return (i == s.size()) ? true : false;
    }
};

int main() {
    Solution sol;
    string s = "abc", t = "ahbgdc";
    bool ans = sol.isSubsequence(s, t);

    cout << "ans : " << ans;
}