#include <bits/stdc++.h>
using namespace std;

//-----------loop each digit(compare with first sting) 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = "";
        for (int i = 0;i < strs[0].size();i++) {//loop each digit in string
            char c1 = strs[0][i];// i digit of first string
            bool conf = false; //conflict
            for (int j = 0;j < strs.size();j++) {//loop  each string in strs
                char c2 = strs[j][i];// i digit of j string
                if (c1 != c2) { // digit conflict
                    conf = true; break;
                }
            }
            if (!conf) {
                s += c1;
            } else {
                return s;
            }
        }
        return s;
    }
};

int main() {
    Solution sol;
    vector<string> strs = { "flower", "flow", "flight" };
    string ans = sol.longestCommonPrefix(strs);
    cout << ans;
}