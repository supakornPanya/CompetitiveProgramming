#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        //last is a pointer points to last index that add group of answer
        //len is a length of group char
        int last = 0, len = 1;
        char pre = chars[0]; //previous charecter

        for (int i = 1;i < chars.size();i++) { //loop all chars
            if (pre != chars[i]) { //pre != chars[i] -> push ans
                chars[last++] = pre; //add char of group
                if (len != 1) { //add lenght of group
                    stack<char> s; //this solution num is reverse so using stack for reverse a number
                    while (len) {
                        s.push('0' + (len % 10)); //each digit
                        len = len / 10; //next digit
                    }
                    while (!s.empty()) {
                        chars[last++] = s.top(); s.pop(); //add digit from stack by end to begin
                    }
                    len = 1; //new group is start lenght is 1
                }
                pre = chars[i];
            } else { //pre == chars[i]
                len++;
            }
        }

        //add a last group
        if (len != 1) { //add lenght of group
            stack<char> s; //this solution num is reverse so using stack for reverse a number
            while (len) {
                s.push('0' + (len % 10)); //each digit
                len = len / 10; //next digit
            }
            while (!s.empty()) {
                chars[last++] = s.top(); s.pop(); //add digit from stack by end to begin
            }
            len = 1; //new group is start lenght is 1
        }

        return last;
    }
};

int main() {
    Solution sol;
    // vector<char> chars = { 'a','a','b','b','c','c','c' };
    vector<char> chars = { 'a','a','b','b','b','b','b','b','b','b','b','b','b','b', };
    int ans = sol.compress(chars);

    cout << "ans : " << ans << endl;
    for (int i = 0;i < ans;i++) {
        cout << chars[i] << " ";
    }
}