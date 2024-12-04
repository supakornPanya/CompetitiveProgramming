#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> ans;
    void gen(int open, int close, string s) {
        if (close == 0 && open == 0) {
            ans.push_back(s);
            return;
        }
        if (open > 0) gen(open - 1, close, s + "(");
        if (close > open) gen(open, close - 1, s + ")");
    }
    vector<string> generateParenthesis(int n) {
        gen(n, n, "");
        return ans;
    }
};
int main() {
    Solution sol;
    int n = 3;
    vector<string> ans = sol.generateParenthesis(n);
    for (auto x : ans) {
        cout << x << endl;
    }
}