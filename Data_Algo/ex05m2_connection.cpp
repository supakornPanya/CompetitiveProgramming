#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e, k; cin >> n >> e >> k;
    vector<vector<int>> adj(n);

    for(int i = 0;i < e;i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int maxAns = 0;
    for(int i = 0;i < n;i++) {
        //initial
        int ans = 0;
        vector<bool> flag(n, false);
        flag[i] = true;
        queue<pair<int, int>> q; q.push({ i, 0 });

        //bfs
        while(!q.empty()) {
            pair<int,int> now = q.front(); q.pop();
            if(now.second > k) continue;
            // cout << "now--: " << now.first << " " << now.second << '\n';
            ans++;
            for(int next : adj[now.first]) {
                if(flag[next]) continue;
                flag[next] = true;
                // cout << "next : " << next << '\n';
                q.push({next, now.second + 1});
            }
        }
        
        //compare ans
        // cout<< "-------------------  " << ans << '\n';
        maxAns = max(maxAns, ans);
    }
    cout << maxAns;
}