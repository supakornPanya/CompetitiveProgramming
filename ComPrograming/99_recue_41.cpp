#include <bits/stdc++.h>
using namespace std;

set<vector<int>> ans;
void dfs(int now, int end, map<int, vector<int>>& m, vector<int>& sol) {
    //cout << now << endl;
    if (now > end) return;
    if (now == end) {
        ans.insert(sol);  
        return ;
    }
    for (int i = 0;i < m[now].size();i++) {
        sol.push_back(m[now][i]); //push back next door
        dfs(m[now][i], end, m, sol);
        sol.pop_back();
    }
}

int main() {
    map<int, vector<int>> m;
    vector<int> sol;
    
    //input
    int n, a, b; cin >> n >> a >> b;
    for (int i = 0;i < n;i++) {
        int start, des; cin >> start >> des; //start, destiny
        m[start].push_back(des);
    }
    sol.push_back(a); //push back first do
    dfs(a, b, m, sol);

    //out put
    if(ans.size() == 0) {cout << "no"; return 0;}
    for(auto v:ans) {
        for(int i = 0;i < v.size();i++){
            cout << v[i];
            if (i != v.size() - 1) { cout << " -> "; }
        }
        cout << endl;
    }
    
    return 0;
}