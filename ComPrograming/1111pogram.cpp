#include <bits/stdc++.h>
using namespace std;

int maxx = 0;
void dfs(vector<vector<pair<int, int>>>& adj, int u, int len, vector<bool>& flag) {
    // cout << "u : " << u << ", len : " << len << endl;
    flag[u] = true;
    for (pair<int, int> vw : adj[u]) {
        if (flag[vw.first]) continue;
        len += vw.second;
        maxx = max(len, maxx);
        dfs(adj, vw.first, len, flag);
        len -= vw.second;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    vector<vector<pair<int, int>>> adj(n + 10);
    vector<bool> flag(n + 10, false);
    for (int i = 0;i < n - 1;i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }

    dfs(adj, 1, 0, flag);

    cout << maxx;
    return 0;
}