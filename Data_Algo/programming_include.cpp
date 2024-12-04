#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, vector<bool>& flag, int u, bool& boom) {
    flag[u] = true;
    for(int v : adj[u]) {
        if(flag[v]) {
            boom = false;
            return;
        }
        dfs(adj, flag, v, boom);
    }
}

//check pass node that passed
//check cycle
int main() {
    int n; cin >> n;
    vector<vector<int>> adj(n + 1); 
    for(int i = 1;i <= n;i++) {
        int m; cin >> m;
        for(int j = 0;j < m;j++) {
            int x; cin >> x;
            adj[i].push_back(x);
        }
    }

    for(int i = 1;i <= n;i++) {
        bool boom = true;
        vector<bool> flag(n + 1, false);
        if(!flag[i]) {
            dfs(adj, flag, i, boom);
        }
        if (boom) cout << "NO\n";
        else cout << "YES\n";
    }
}