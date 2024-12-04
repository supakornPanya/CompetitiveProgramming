#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string ans = "";
        int idx = 0;
        //find the longest ans possible
        while (idx < str1.size() && idx < str2.size()) {
            if (str1[idx] != str2[idx]) { break; }
            ans += str1[idx];
            idx++;
        }
        //check string ans is gcd str1 and str2
        while (ans.size() > 0) {
            //cout << "ans : " << ans << endl;
            int size = ans.size();
            bool ans1 = true, ans2 = true;
            if (str1.size() % size != 0 || str2.size() % size != 0) { ans.pop_back(); continue; }
            //cout << "pass" << endl;
            //?check ans is in str1--->
            for (int i = 0;i < str1.size();i++) {
                //cout << "1 : " << ans[i % size] << ", " << i % size << ", " << str1[i] << endl;
                if (ans[i % size] != str1[i]) { ans1 = false; break; }
            }
            //cout << "===========================" << endl;
            //?check ans is in str1--->
            for (int i = 0;i < str2.size();i++) {
                //cout << "2 : " << ans[i % size] << ", " << i % size << ", " << str2[i] << endl;
                if (ans[i % size] != str2[i]) { ans2 = false; break; }
            }
            if (ans1 && ans2) { return ans; } else { ans.pop_back(); }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string str1 = "ABCABC";
    string str2 = "ABC";
    string ans = sol.gcdOfStrings(str1, str2);
    cout << "ans : " << ans;
}