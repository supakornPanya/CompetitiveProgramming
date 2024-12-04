#include <bits/stdc++.h>
using namespace std;

//slow because using erase
// class Solution {
// public:
//     string clearDigits(string s) {
//         for (int i = 0;i < s.size();i++) {
//             if ('0' <= s[i] && s[i] <= '9') {
//                 s.erase(s.begin() + i);
//                 s.erase(s.begin() + i - 1);
//                 i -= 2;
//             }
//         }
//         return s;
//     }
// };

//fast because using push_back and pop_back
class Solution {
public:
    string clearDigits(string s) {
        string ans;
        for(int i=0;i<s.size();i++){
            if(!('0' <= s[i] && s[i] <= '9')){
                ans += s[i];
            } else if(ans.size() != 0){
                ans.pop_back();
            }
        }
        return ans;
    }
};


int main() {
    Solution sol;
    string s = "abc";
    string ans = sol.clearDigits(s);
    cout << "ans : " << ans;
}