#include <bits/stdc++.h>
using namespace std;

//--------------------slow because i look a groub ex -> III, II, IV
/* 
class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        map<char, int> RToI = { {'I',1}, {'V',5},{'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000} };
        for (int i = 0;i < s.size();) {
            auto j = s.begin() + i;
            if (RToI[*j] < RToI[*(j + 1)]) { // left < right
                ans += RToI[*(j + 1)] - RToI[*j]; i += 2;
                //cout << ans << " ";
            } else if (RToI[*j] == 1 && RToI[*(j + 1)] == 1 && RToI[*(j + 2)] == 1) { //III
                ans += 1 + 1 + 1; i += 3;
                //cout << ans << " ";
            } else if (RToI[*j] == 1 && RToI[*(j + 1)] == 1) { //II
                ans += 1 + 1; i += 2;
                //cout << ans << " ";
            } else if (RToI[*j] == 1) { //I
                ans += 1; i++;
                //cout << ans << " ";
            } else { //a > b
                ans += RToI[*j]; i++;
                //cout << ans << " ";
            }
        }
        return ans;
    }
};
*/

//--------------------fast because i look each digit of roman

class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        map<char, int> RToI = { {'I',1}, {'V',5},{'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000} };
        for (int i = 0;i < s.size();i++) {
            auto j = s.begin() + i;
            if(RToI[*j]< RToI[*(j+1)]){
                ans -= RToI[*j];
            }else {
                ans += RToI[*j];
            }
        }
        return ans;
    }
};

int main() {
    string s = "MCMXCIV";
    Solution sol;
    int ans = sol.romanToInt(s);
    cout << ans;
    return 0;
}