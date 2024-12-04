#include <bits/stdc++.h>
using namespace std;

//!sol1
//f(N) = N*f(N) + 1 BigO??????
//get all possible : call loop every element then -> call every element starting myself
// class Solution {
// public:
//     vector<vector<int>> sumAns;
//     void comb(const vector<int>& candidates, int target, 
//             vector<int> ans, int index) {
//         for(auto x:ans) {
//             cout<<x<<", ";
//         }cout<<endl;
//         if (target < 0) { return; }
//         if (target == 0) {
//             sumAns.push_back(ans);
//             return;
//         }
//         for (int i = index;i < candidates.size();i++) {
//             //chose candidates[i]
//             int val = candidates[i];
//             target -= val;
//             ans.push_back(val);
//             comb(candidates, target, ans, i); 
//             //|->index = i : protect duplicate answer because don't call before element but can call myself

//             //don't chose candidates[i]
//             ans.pop_back();
//             target += val;
//         }
//     }

//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         sort(candidates.begin(), candidates.end());
//         comb(candidates, target, {}, 0);
//         return sumAns;
//     }
// };

//!sol1
//call myself(can duplicate element) and next element(not add next element)
//x--->1-->1...
// |   |
// |   |->2...
// |
// x-->2-->2
//  |
//  |->x-->3
//      |
//      |->x
//

class Solution {
public:
    vector<vector<int>> sumAns;
    void comb(const vector<int>& candidates, int target,
        vector<int> ans, int index) {
        for (auto x : ans) {
            cout << x << ", ";
        }cout << endl;
        if (target < 0 || index == candidates.size()) { return; }
        if (target == 0) {
            sumAns.push_back(ans);
            return;
        }
        //---call this element + add this element 
        //|->for case duplicate element
        ans.push_back(candidates[index]); target -= candidates[index];
        comb(candidates, target, ans, index);
        
        //---call next element + not add any element
        //|->for case start next element 
        //|->not add any element because can starter by next element
        ans.pop_back(); target += candidates[index];
        comb(candidates, target, ans, index + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        comb(candidates, target, {}, 0);
        return sumAns;
    }
};

int main() {
    Solution sol;
    vector<int> candidates = { 2, 3, 6, 7 };
    int target = 7;
    vector<vector<int>> ans = sol.combinationSum(candidates, target);

    cout << "ans : " << endl;
    for (auto xx : ans) {
        for (auto x : xx) {
            cout << x << ", ";
        }cout << endl;
    }
}