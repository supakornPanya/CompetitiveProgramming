#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0;i < n;i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    //initial
    vector<bool> flag(n, false); flag[0] = true;
    vector<int> w(n); w[0] = 0;
    stack<pair<int, int>> q; q.push({ 0, 0 });

    //bfs
    while (!q.empty()) {
        pair<int, int> now = q.top(); q.pop();
        flag[now.first] = true;

        // cout << "now--: " << now.first << ", w : " << now.second << '\n';

        for (int next : adj[now.first]) {
            if (flag[next]) {
                ans = max(ans, abs(w[now.first] - w[next]) + 1);
                continue;
            }
            w[next] = now.second + 1;
            // cout << "next : " << next << ", w : " << now.second << '\n';
            q.push({ next, now.second + 1 });
        }
    }

    // cout << "--------------------------  " << ans << '\n';

    cout << ans;
}