#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e; cin >> n >> e;
    vector<vector<int>> adj(n+1);
    for(int i = 0;i < e;i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    vector<bool> flag(n + 1, false);
    //loop every node
    for(int i = 1;i <= n;i++) {
        if(!flag[i]) {
            ans++;
            //bfs
            queue<int> q; q.push(i);
            flag[i] = true;
            while(!q.empty()) {
                int now = q.front(); q.pop();
                for(int next : adj[now]) {
                    if(flag[next]) continue;
                    flag[next] = true;
                    q.push(next);
                }
            }

        }
    }
    cout << ans;
}