#include <bits/stdc++.h>
using namespace std;
/*-----------------------slow BigO(n+ n/2), loop get digit -> dq left and right*/
/*
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) { return false; }
        deque<int> dq; 
        while (x) { //get digit and push to dq
            int digit = x % 10;
            dq.push_back(digit);
            x = x / 10;
        }
        while (!dq.empty()) { //check left and right of x
            int back;
            int front = dq.front(); dq.pop_front();
            if (!dq.empty()) {
                back = dq.back(); dq.pop_back();
            } else {
                return true;
            }
            if (front != back) {
                return false;
            }
        }
        return true;
    }
};
*/
/*-----------------------fastest BigO(n/2), 2Pointer(left hand, right hand) */
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) { return false; }
        string s = to_string(x);
        int lh = 0, rh = s.size() - 1;
        while (true) {
            if (lh >= rh) {
                return true;
            }
            if (s[lh] != s[rh]) {
                return false;
            }
            lh++; rh--;
        }
    }
};

int main()
{
    Solution sol;
    int x = 11211;

    // check the result
    bool ans = sol.isPalindrome(x);
    cout << ans;
    return 0;
}