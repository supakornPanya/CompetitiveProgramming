#include <bits/stdc++.h>
using namespace std;

//!sol : 
//same code permutation but each digits of answer is from idx of string digits
class Solution {
public:
    vector<string> sumAns;
    void dfs(string digits, int idx, string ans, const vector<vector<char>>& v) {
        if (idx == digits.size()) {
            cout << "ending" << endl;
            sumAns.push_back(ans);
            return;
        }
        int num = digits[idx] - '0';
        for (int i = 0;i < v[num].size();i++) {
            cout << "test : " << i << endl;
            ans += v[num][i];
            dfs(digits, idx + 1, ans, v);
            ans.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) { return {}; }
        vector<vector<char>> v(10);
        v[2] = { {'a'},{'b'},{'c'} };
        v[3] = { {'d'},{'e'},{'f'} };
        v[4] = { {'g'},{'h'},{'i'} };
        v[5] = { {'j'},{'k'},{'l'} };
        v[6] = { {'m'},{'n'},{'o'} };
        v[7] = { {'p'},{'q'},{'r'},{'s'} };
        v[8] = { {'t'},{'u'},{'v'} };
        v[9] = { {'w'},{'x'},{'y'},{'z'} };
        cout<<"digits.size() : "<<digits.size()<<endl;
        dfs(digits, 0, "", v);
        return sumAns;
    }
};

int main() {
    Solution sol;
    string digits = "23";
    vector<string> ans = sol.letterCombinations(digits);

    cout << "ans : " << ans.size() << endl;
    for (string s : ans) {
        cout << s << endl;
    }
}