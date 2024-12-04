#include <bits/stdc++.h>
using namespace std;

bool cycle;
void dfs(vector<vector<int>>& adj, vector<bool>& flag, int now, int parent) {
    flag[now] = true;
    for(int next : adj[now]) {
        if(flag[next]){
            if(next != parent) cycle = true;
            continue;
        }
        flag[next] = true;
        dfs(adj, flag, next, now);
    }
}

int main() {
    int q; cin >> q;
    while(q--) {
        int n, e; cin >> n >> e;
        vector<vector<int>> adj(n);
        vector<bool> flag(n, false);
        for(int i = 0;i < e;i++) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cycle = false;
        for(int i = 0;i < n;i++) {
            if(!flag[i]) {
                dfs(adj, flag, i, i);
            }
            if(cycle) break; 
        }

        if(cycle) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}