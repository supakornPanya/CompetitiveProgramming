#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        string ans = "";
        for(char c:s){
            if(c == '*'){
                ans.pop_back();
            } else {
                ans.push_back(c);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "leet**code*e";
    string ans = sol.removeStars(s);

    cout<<"ans : "<<ans;
}