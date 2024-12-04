#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto c : s) {
            if (c == '(' || c == '{' || c == '[') { st.push(c); }
            else if ((c == ')' || c == '}' || c == ']') && !st.empty()) {
                char t = st.top();
                if (c == ')' && t == '(') {
                    st.pop();
                }
                else if (c == '}' && t == '{') {
                    st.pop();
                }
                else if (c == ']' && t == '[') {
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return (st.empty())? true: false;
    }
};

int main() {
    Solution sol;
    string s = "(){}[]";
    bool ans = sol.isValid(s);
    cout << ans;
}