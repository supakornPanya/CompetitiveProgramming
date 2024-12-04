#include <bits/stdc++.h>
using namespace std;


//solution ex->eeemmpppp, pppeeeemm
//1)count each character
//  is eee mm pppp = 3 2 4
//  is ppp eeee mm = 3 4 2 = 3 2 4(operator 1:change in any order)
//2)both of string have setChar : "e, m, p" ( (1), (2))
//  so we can set -> {3 * setChar + 2 * setChar + 4 * setChar} (3)

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) { return false; }
        
        //**(1)mark each char to vector
        vector<int> char1(26);
        vector<int> char2(26);
        for (char c : word1) {
            char1[c - 'a']++;
        }
        for (char c : word2) {
            char2[c - 'a']++;
        }
        
        //**(2)have all same char type
        for(int i=0;i<26;i++){
            //**word1 have but word2 not have || word2 have but word1 not have
            if ((char1[i] && !char2[i]) || (!char1[i] && char2[i])){
                return false;
            }
        }

        //**(3)all set of char is same(is same can change char of set)
        sort(char1.begin(), char1.end());
        sort(char2.begin(), char2.end());
        for(int i=0;i<26;i++){
            if(char1[i] != char2[i]){
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution sol;
    string word1 = "abc";
    string word2 = "bca";
    bool ans = sol.closeStrings(word1, word2);

    cout << "ans : " << ans;
}