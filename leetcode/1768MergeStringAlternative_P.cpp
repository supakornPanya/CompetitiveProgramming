#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0, j = 0;
        string ans = "";
        while (i < word1.size() && j < word2.size()) {
            ans += word1[i]; ans += word2[j];
            i++; j++;
        }
        while (i < word1.size()) { ans += word1[i]; i++; }
        while (j < word2.size()) { ans += word2[j]; j++; }
        cout<<ans.size()<<endl;
        return ans;
    }
};

int main() {
    Solution sol;
    string word1 = "abc";
    string word2 = "pqr";
    string ans = sol.mergeAlternately(word1, word2);
    cout << "ans : " << ans;
}