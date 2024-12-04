#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k, n, e; cin >> k >> n >> e;
    vector<vector<int>> adj(n + 1);
    vector<int> dpW(n + 1, -1);
    for (int i = 0;i < e;i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    queue<pair<int, int>> q;
    q.push({ k,1 });
    int ans = 0;

    while (!q.empty()) {
        int w = q.front().first;
        int u = q.front().second;
        q.pop();
        // cout << "u : " << u << ", w : " << w << '\n';

        ans = max(ans, u);
        if (w <= 0 || w <= dpW[u]) continue;
        dpW[u] = max(dpW[u], w);
        for (int v : adj[u]) {
            // cout << "v : " << v << ", newW : " << w -1 << '\n';
            q.push({ w - 1, v });
        }
        // cout << '\n';
    }

    cout << ans;
}