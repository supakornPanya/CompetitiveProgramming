#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        for (int i = 0;i < s.size();i++) {
            if (s[i] == ' ') {
                continue;
            } else {
                string str = "";
                while (s[i] != ' ' && i < s.size()) {
                    str += s[i]; i++;
                }
                v.push_back(str);
            }
        }
        string ans = "";
        for (int i = v.size() - 1;i >= 0;i--) {
            ans += v[i]; ans += ' ';
        }
        ans.pop_back();
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "the sky is blue";
    string ans = sol.reverseWords(s);
    cout << "ans : " << ans;
}