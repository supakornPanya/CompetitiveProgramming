#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> sumAns;
    void dfs(int k, int n, vector<int>& sol, vector<bool>& flag, int start) {
        //k now = k - used
        //n now = n - sum
        //sol = this combination
        //flag = mark this number is used?
        //start = start for add new combination(protect using same all number but different pattern)
        //        because can't use number that value less than last pick number
        //        ex : 123 can't 132 because next pick from number 3 is 4 can't 2

        cout << "n : " << n << ", k : " << k << ", start : " << start << ", sol : ";
        for (int x : sol) {
            cout << x << ", ";
        }cout << endl;

        if (k <= 0 || n <= 0) {
            cout << "pass this case" << endl;
            if (n == 0 && k == 0) sumAns.push_back(sol);
            return;
        }

        for (int i = start;i <= 9;i++) {
            if (!flag[i]) {
                sol.push_back(i);
                flag[i] = true;
                dfs(k - 1, n - i, sol, flag, i + 1);
                sol.pop_back();
                flag[i] = false;
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> sol;
        vector<bool> flag(10);
        dfs(k, n, sol, flag, 1);
        return sumAns;
    }
};

int main() {
    Solution sol;
    int k = 3;
    int n = 9;
    vector<vector<int>> ans = sol.combinationSum3(k, n);

    cout << "ans : " << endl;
    for (vector<int> xx : ans) {
        for (int x : xx) {
            cout << x << ", ";
        }cout << endl;
    }
}