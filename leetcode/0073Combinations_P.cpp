#include <bits/stdc++.h>
using namespace std;

//!sol1 : it work but memory exceed
//time : O(2^n)
//space : ans=O(k * (n,k)), recursion stack=O(n) deep stack 
//Sol : add if in condition chose is not over k
// class Solution {
// public:
//     vector<vector<int>> ans;
//     void com(int n, int k, int now,
//         vector<int> sol, int chosen) {

//         for (auto x : sol) {
//             cout << x << ", ";
//         }cout << endl;

//         if (chosen == k) {
//             ans.push_back(sol);
//             return;
//         }
//         if (now < n) {
//             cout << "not chose : now  = " << now << endl;
//             com(n, k, now + 1, sol, chosen);
//         }
//         if (chosen < k && now <= n) {
//             cout << "chose : now = " << now << endl;
//             sol.push_back(now);
//             com(n, k, now + 1, sol, chosen + 1);
//         }
//     }

//     vector<vector<int>> combine(int n, int k) {
//         com(n, k, 1, {}, 0);
//         return ans;
//     }
// };

//!sol2 
//Sol : for every element then have 2 sol is chose or not chose this element
class Solution {
public:
    vector<vector<int>> ans;
    void com(int n, int k, int start, vector<int> sol) {
        if (sol.size() == k) {
            ans.push_back(sol);
            return;
        }

        cout << "sol : "; 
        for (int x : sol) { cout << x << ", "; } 
        cout << "start : " << start << endl;

        for (int i = start;i <= n;i++) {

            //chose this element 
            sol.push_back(i);
            com(n, k, i + 1, sol);
            cout << "sol in : "; for (int x : sol) { cout << x << ", "; } cout << endl;
            
            //not chose this element then work with next element
            sol.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> sol; //useful for runtime because can pass by reference in sol
        com(n, k, 1, sol);
        return ans;
    }
};

int main() {
    Solution sol;
    int n = 4, k = 2;
    vector<vector<int>> ans = sol.combine(n, k);

    cout << "ans : " << endl;
    for (auto xx : ans) {
        for (auto x : xx) {
            cout << x << ", ";
        }cout << endl;
    }
}