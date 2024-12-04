#include <bits/stdc++.h>
using namespace std;

// Expand Around Center (O(n^2)) -> loop each digit then expand digit if ans is even or odd.
// can O(n) use algorithm
class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int l, r;
        for (int i = 0;i < s.size();i++) { //loop each digit
            if (((s.size() - 1 - i) * 2) + 2 < ans.size()) { break; }
            //check ans like even ex->axxa
            l = i - 1; r = i;
            string ansEven = "";
            while (0 <= l && r < s.size()) {
                if (s[l] == s[r]) {
                    ansEven = s[l] + ansEven + s[r];
                } else {
                    break;
                }
                l--; r++;
            }
            //check ans like odd ex->axoxa
            l = i - 1; r = i + 1;
            string ansOdd = "";
            ansOdd += +s[i];
            while (0 <= l && r < s.size()) {
                if (s[l] == s[r]) {
                    ansOdd = s[l] + ansOdd + s[r];
                } else {
                    break;
                }
                l--; r++;
            }
            //compare lenght of ans
            if (ansEven.size() >= ansOdd.size() && ansEven.size() >= ans.size()) {
                ans = ansEven;
            }
            if (ansOdd.size() >= ansEven.size() && ansOdd.size() >= ans.size()) {
                ans = ansOdd;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "abccb";
    string ans = sol.longestPalindrome(s);
    cout << ans;
}