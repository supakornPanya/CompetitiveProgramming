#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int l = 0, r = k, count = 0, maxx;
        //**find vowel in first window 
        for (int i = l;i < r;i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                count++;
            }
            maxx = count;
        }
        while (r < s.size()) {
            if (s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u') {
                count--;
            }
            if (s[r] == 'a' || s[r] == 'e' || s[r] == 'i' || s[r] == 'o' || s[r] == 'u') {
                count++;
            }
            l++; r++;
            maxx = max(count, maxx);
        }
        return maxx;
    }
};

int main() {
    Solution sol;
    string s = "abciiidef";
    int k = 3;
    int ans = sol.maxVowels(s, k);

    cout << "ans : " << ans;
}