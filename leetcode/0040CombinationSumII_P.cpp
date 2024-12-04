#include <bits/stdc++.h>
using namespace std;\

//!sol1 not fastest
//O(2^N) recursive : f(n) = 2f(n-1) + 1 -> (2^1)*(2^2) *(2^3)...*(2^n)  
//recursive chose or not chose + if(duplicate & before is not chose) continue //from pattern
// class Solution {
// public:
//     vector<vector<int>> SumAns;
//     void comb(const vector<int>& candidates, int target,
//         bool chose, vector<int> ans, int index)
//         //1, 1, 2, 5, 6, 7, 10,
//     {
//         //if (candidates[index - 1] == candidates[index]) { return; }
//         if (target <= 0 || index >= candidates.size()) {
//             for (auto x : ans) {
//                 cout << x << ", ";
//             }cout << endl;
//             if (target == 0) {
//                 SumAns.push_back(ans);
//             }
//             return;
//         }
//         comb(candidates, target, false, ans, index + 1);
//         if (index > 0 && candidates[index - 1] == candidates[index] && !chose) { return; }
//         ans.push_back(candidates[index]);
//         target -= candidates[index];
//         comb(candidates, target, true, ans, index + 1);
//     }

//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         sort(candidates.begin(), candidates.end());
//         for (auto x : candidates) { cout << x << ", "; } cout << endl;
//         comb(candidates, target, true, {}, 0);
//         return SumAns;
//     }
// };

//!sol1 almost fastest
//O(2^N) recursive : f(n) = 2f(n-1) + 1 -> (2^1)*(2^2) *(2^3)...*(2^n)
//loop check element is duplicate -> if(duplicate) continue
class Solution {
public:
    vector<vector<int>> SumAns;
    void comb(const vector<int>& candidates, int target,
        vector<int> ans, int index)
        //1, 1, 2, 5, 6, 7, 10,
    {
        if (target <= 0) {
            if (target == 0) {
                SumAns.push_back(ans);
            }
            return;
        }
        cout<<"test "<<index<<endl;
        for (int i = index;i < candidates.size();i++) {
            if (i > index && candidates[i] == candidates[i - 1]) { continue; }
            ans.push_back(candidates[i]);
            comb(candidates, target-candidates[i], ans, i+1);
            ans.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        comb(candidates, target, {}, 0);
        return SumAns;
    }
};


int main() {
    Solution sol;
    vector<int> candidates = { 10,1,2,7,6,1,5 };
    int target = 8;
    vector<vector<int>> ans = sol.combinationSum2(candidates, target);
    cout << "ans : " << endl;
    for (auto xx : ans) {
        for (auto x : xx) {
            cout << x << ", ";
        }cout << endl;
    }
}