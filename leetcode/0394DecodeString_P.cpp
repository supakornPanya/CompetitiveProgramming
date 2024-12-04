#include <bits/stdc++.h>
using namespace std;

//!sol : 
//when found "[" is can keep component of encoding
//when found "]" is can encode by OldString + (round * NowString) 
//  then OldString = OldString + (round * NowString) 
class Solution {
public:
    string decodeString(string s) {
        stack<string> stStr;
        stack<int> stInt;
        string str = "";
        int num = 0;

        for (char c : s) {
            //**complete component for encode = {OldString, round} -> push to stack 
            if (c == '[') {
                cout<<"case1---------"<<endl;
                cout<<"str : "<<str<<", num : "<<num<<endl;
                stStr.push(str); str = "";
                stInt.push(num); num = 0;
            } else if (c == ']') {
                cout << "case2---------" << endl;
                string result = stStr.top(); stStr.pop(); //OldString
                int round = stInt.top(); stInt.pop(); //round for repeated NowString

                for (int i = 0;i < round;i++) { result += str; }//OldString + (round * NowString)

                str = result;
            } else if ('a' <= c && c <= 'z') {//**add char to NowString
                cout << "case3" << endl;
                str += c;
            } else if ('0' <= c && c <= '9') {//**add char(number) to num 
                cout << "case4" << endl;
                num = (num * 10) + int(c-'0');
            }
        }

        return str;
    }
};

int main() {
    Solution sol;
    //string s = "3[z]2[2[y]pq4[2[jk]e1[f]]]ef";
    string s = "3[a2[c]]";
    string ans = sol.decodeString(s);
    cout << "ans : " << ans;
}