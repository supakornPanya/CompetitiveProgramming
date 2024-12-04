#include <bits/stdc++.h>
using namespace std;

//!sol1 fast
//O(N*MlogM)
// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         map<string, vector<string>> m;
//         //hash key by sorting and keep value of str(using vector<string>)
//         //O(N*MlogM)
//         for (string key : strs) {
//             string value = key;
//             sort(key.begin(), key.end());//O(MlogM)
//             m[key].push_back(value);
//         }
//         vector<vector<string>> sumAns;
//         //loop each key or set of ans
//         //O(N)
//         for (auto i = m.begin();i != m.end();i++) {
//             vector<string> ans;
//             auto vString = i->second;
//             //loop each string to push in each vector
//             for(auto str:vString) {
//                 ans.push_back(str);   
//             }
//             sumAns.push_back(ans);
//         }
//         return sumAns;
//     }
// };

//!sol2 fastest
//O(N*MlogM)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        //hash key by sorting and keep value of str(using vector<string>)
        //O(N*MlogM)
        for (string key : strs) {
            string value = key;
            sort(key.begin(), key.end());//O(MlogM)
            m[key].push_back(value);
        }
        vector<vector<string>> sumAns;
        //loop each key or set of ans
        //O(N)
        for (auto x : m) {
            sumAns.push_back(x.second);
        }
        return sumAns;
    }
};

int main() {
    Solution sol;
    vector<string> strs = { "eat","tea","tan","ate","nat","bat" };
    vector<vector<string>> ans = sol.groupAnagrams(strs);

    cout << "ans : " << endl;
    for (vector<string> ss : ans) {
        for (string s : ss) {
            cout << s << ", ";
        }cout << endl;
    }
}