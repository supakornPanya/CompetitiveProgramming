#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        deque<int> dq;

        //find all vowel
        for (int i = 0;i < s.size();i++) {
            if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' ||
                s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                dq.push_back(i);
            }
        }

        //reverse vowel
        while (dq.size() >= 2) {
            swap(s[dq.front()], s[dq.back()]); //swap 2 index
            dq.pop_back(); dq.pop_front();
        }

        return s;
    }
};


int main() {
    Solution sol;
    string s = "leetcode";
    string ans = sol.reverseVowels(s);

    cout << "ans : " << ans;
}