#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e; cin >> n >> e;
    vector<vector<int>> adj(n);
    vector<bool> flag(n, false);
    for (int i = 0;i < e;i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    for (int i = 0;i < n;i++) {
        if (flag[i]) continue;

        //initial
        int a0 = 0, a1 = 0, a2 = 0;
        bool correct = true;
        queue<int> q; q.push(i);
        flag[i] = true;

        //bfs
        while (!q.empty()) {
            int now = q.front(); q.pop();

            if(adj[now].size() == 0) a0++;
            else if(adj[now].size() == 1) a1++;
            else if(adj[now].size() == 2) a2++;
            else correct = false;
            
            for(int next : adj[now]) {
                if(flag[next]) continue;
                flag[next] = true;
                q.push(next);
            }
        }        
        //check line graph
        // cout << "a : " << a0 << " " << a1 << " " << a2 << '\n';
        if ((a0 == 1 && correct) || (a1 == 2 && correct)) ans++;
    }

    cout << ans;
    return 0;
}