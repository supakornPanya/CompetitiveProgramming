#include <bits/stdc++.h>
using namespace std;

// O(n^2) -> code complicated

class Solution {
public:
    void deep(const string& s
        , int& PS
        , const int& numRows
        , vector<queue<char>>& PatZZ) {
        for (int j = 0;j < numRows;j++) {
            if (PS == s.size()) {
                break;
            }
            char c = s[PS];
            PatZZ[j].push(c);
            PS++;
        }
    }
    void between(const string& s
        , int& PS
        , const int& numRows
        , vector<queue<char>>& PatZZ) {
        for (int j = numRows - 2;j > 0;j--) {
            if (PS == s.size()) {
                break;
            }
            char c = s[PS];
            PatZZ[j].push(c);
            PS++;
        }
    }

    string convert(string s, int numRows) {
        vector<queue<char>> PatZZ(numRows);//patern zigzag
        string ans = "";
        int PS = 0; //Position of string s
        //push each digit of string s in vector queue pattern like zigzag
        while (PS < s.size()) {
            deep(s, PS, numRows, PatZZ);
            if (PS > s.size()) {
                break;
            }
            between(s, PS, numRows, PatZZ);
        }
        //pop each digit from vector queue for add to ans
        for (int i = 0;i < numRows;i++) {
            while(!PatZZ[i].empty()){
                char TAns = PatZZ[i].front(); PatZZ[i].pop();
                ans += TAns;
            }
        }
        return ans;
    }
};


// O(n^2) -> code not complicated 
//------------non finish
/*
class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> res(numRows, "");
        const int slen = s.size();
        for (auto c = 0; c < slen;) {
            for (int i = 0; i < numRows && c < slen; i++) {
                res[i] += s[c++];
                cout << s[c++]<<endl;
            }
            for (int k = numRows - 2; k > 0 && c < slen; k--) {
                res[k] += s[c++];
                cout << s[c++]<<endl;
            }
        }
        return accumulate(res.begin(), res.end(), std::string());
    }
};
*/


int main() {
    Solution sol;
    string s = "PAYPALISHIRING";
    int numRows = 3;
    string ans = sol.convert(s, numRows);
    cout << ans;
}
