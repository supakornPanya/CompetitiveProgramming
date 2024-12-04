#include <bits/stdc++.h>
using namespace std;

//slow, brute force, O(n + n^2) : loop find diff s and t O(n) -> loop find how long each element can be O(n^2) 
// class Solution {
// public:
//     int equalSubstring(string s, string t, int maxCost) {
//         vector<int> v(s.size());
//         for (int i = 0;i < s.size();i++) {
//             v[i] = abs(s[i] - t[i]);
//         }
//         int ans = 0;
//         for (int i = 0;i < v.size();i++) {
//             int total = 0, maxx = 0;
//             for (int j = i;j < v.size();j++) {
//                 total += v[j];
//                 if (total > maxCost) {
//                     break;
//                 }
//                 if (total <= maxCost) {
//                     maxx++;
//                     if (maxx > ans) { ans = maxx; }
//                 }
//             }
//         }
//         return ans;
//     }
// };

//fastest, slinding window, O(n) : 
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int sum, l, ans;
        sum = l = ans = 0;
        for (int r = 0;r < s.size();r++) { //expand window by incred right
            sum += abs(s[r] - t[r]);
            cout << "- : sum = " << sum << ", l = " << l << ", r = " << r << endl;
            while (sum > maxCost) { //maintain window by incred left
                sum -= abs(s[l] - t[l]);
                l++;
            }
            cout << "-- : sum = " << sum << ", l = " << l << ", r = " << r << endl;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "abcd", t = "cdef";
    int maxCost = 3;
    int ans = sol.equalSubstring(s, t, maxCost);
    cout << ans << endl;
    //show diff ASCII s and t
    for (int i = 0;i < s.size();i++) {
        cout << abs(s[i] - t[i]) << " ,";
    }
}