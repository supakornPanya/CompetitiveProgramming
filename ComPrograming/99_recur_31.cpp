#include <bits/stdc++.h>
using namespace std;

set<string> ans;

void dfs(string s, string sol, vector<bool> flag, int n){
    if(n == 0) {
        ans.insert(sol);
        return;
    }

    for(int i = 0;i < s.size();i++) {
        if(flag[i]) continue;
        sol += s[i];
        flag[i] = true;
        // cout << "sol : "; for (char c : sol) { cout << c; } cout << endl;
        dfs(s, sol, flag, n - 1);
        flag[i] = false;
        sol.pop_back();
    }

    return;
}

int main() {
    string s; cin >> s;
    string sol = "";
    vector<bool> flag(s.size(), false);
    dfs(s, sol, flag, s.size());

    for(auto it = ans.begin();it != ans.end();it++) {
        cout << *it << " ";
    }

    return 0;
}