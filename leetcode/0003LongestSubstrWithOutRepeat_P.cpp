#include <bits/stdc++.h>
using namespace std;

//O(n), using sliding window, main tain window by map of char
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, bool> m;
        int l = 0, ans = 0;
        //vector<char> c; //show substring
        for (int r = 0;r < s.size();r++) {

            // c.push_back(s[r]);
            // cout<<"new r : "<< r<< ", " << s[r] << endl;
            // for (auto x : c) {
            //     cout << x << ", ";
            // }cout << endl;

            if (m[s[r]] == false) { // s[r] is not in substring--
                m[s[r]] = true;
                ans = max(ans, r - l + 1); //longest substring of left now
            } else { // s[r] have in substring--
                while (s[l] != s[r]) { //l++ until before can't use
                    //cout << "--fix1 : " << l << ", " << s[l] << endl;
                    m[s[l]] = false;
                    l++;
                    //c.erase(c.begin()); 
                }
                //cout << "--fix2 : " << l << ", " << s[l] << endl;
                l++; //next of index can't use
                //c.erase(c.begin());
            }
            
            // for(auto x:c){
            //     cout<<x<<", ";
            // }cout << endl;
            // cout<<"---------------------------"<<ans<<endl;

        }
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "pwwkew";
    int ans = sol.lengthOfLongestSubstring(s);
    cout << ans;
}