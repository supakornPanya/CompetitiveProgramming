#include <bits/stdc++.h>
using namespace std;

//best solution (add condition(c=='0') and remove loop remove 0 front)
class Solution {
public:
    int myAtoi(string s) {
        //convert sting to int
        string SAns = "";
        bool flag = false;
        for (int i = 0;i < s.size();i++) {
            char c = s[i];
            if ('0' <= c && c <= '9') {
                flag = true;
                if (c == '0' && (SAns.size() == 0)){
                    continue;
                }
                if (c == '0' && (SAns.size() == 1 && (c == '-' || c == '+'))) {
                    continue;
                }
                SAns += c; 
            }
            if ((c == '-' || c == '+') && SAns.size() == 0) {
                if (flag) { break; }
                SAns += c;
                flag = true;
            }
            else if (c == ' ') {
                if (flag) { break; }
            }
            else if (!('0' <= c && c <= '9')){
                break;
            }
        }

        //string to int
        double long ans = 0, j = 1;
        for (int i = SAns.size() - 1; i >= 0;i--) {
            if (SAns[i] == '-') {
                ans *= -1;
            }
            if ('0' <= SAns[i] && SAns[i] <= '9') {
                ans += (SAns[i] - '0') * j;
            }
            //cout << "ans : " << fixed << ans << endl;
            if (ans > INT_MAX) {
                if (SAns[0] == '-') { return -2147483648; } else { return 2147483647; }
            }
            j *= 10;
        }
        return ans;
    }
};


/*--------------runing was passed
class Solution {
public:
    int myAtoi(string s) {
        //convert sting to int
        string SAns = "";
        bool flag = false;
        for (int i = 0;i < s.size();i++) {
            char c = s[i];
            if ('0' <= c && c <= '9') {
                flag = true;
                SAns += c;
                continue;
            } else { // !('0' <= c && c <= '9')
                if (c == ' ') {
                    if (flag) { break; }
                } else if ((c == '-' || c == '+') && SAns.size() == 0) {
                    if (flag) { break; }
                    SAns += c;
                    flag = true; continue;
                } else { // !('0' <= c && c <= '9') && c != " , -, +"
                    break;
                }
            }
        }
        //reduce 0 in front
        if (SAns[0] == '0') {
            int i;
            for (i = 0;i < SAns.size();i++) {
                if (SAns[i] != '0') {
                    break;
                }
            }
            SAns.erase(SAns.begin() + 0, SAns.begin() + i);
        }
        if ((SAns[0] == '+' || SAns[0] == '-') && SAns[1] == '0') {
            int i;
            for (i = 1;i < SAns.size();i++) {
                if (SAns[i] != '0') {
                    break;
                }
            }
            SAns.erase(SAns.begin() + 1, SAns.begin() + i);
        }

        //string to int
        double long ans = 0, j = 1;
        for (int i = SAns.size() - 1; i >= 0;i--) {
            if (SAns[i] == '-') {
                ans *= -1;
            }
            if ('0' <= SAns[i] && SAns[i] <= '9') {
                ans += (SAns[i] - '0') * j;
            }
            cout << "ans : " << fixed << ans << endl;
            if (ans > INT_MAX) {
                if (SAns[0] == '-') { return -2147483648; } else { return 2147483647; }
            }
            cout << "ans : " << fixed << ans << endl;
            j *= 10;
            cout << "ans : " << fixed << ans << endl;
        }
        return ans;
    }
};
*/

int main() {
    Solution sol;
    string s = "2147483646";
    int ans = sol.myAtoi(s);
    cout << ans;
}