#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i < haystack.size();i++) { //loop check first needle with each haystack 
            if (haystack[i] == needle[0]) { //first element is correct
                for (int j = 1;j < needle.size(), j < haystack.size();j++) { //check every needle with haystack
                    if (needle[j] != haystack[i+j]) {
                        break;
                    }
                    if (j == needle.size() - 1) { return i; }
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    string haystack = "leetcode", needle = "leeto";
    int ans = sol.strStr(haystack, needle);
    cout << ans;
}