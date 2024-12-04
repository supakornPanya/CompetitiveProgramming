#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, e; cin >> n >> e;
    vector<int> ci;
    vector<int> co;
    for (int i = 0;i < n;i++) {
        int x; cin >> x;
        ci.push_back(x);
    }
    for (int i = 0;i < n;i++) {
        int x; cin >> x;
        co.push_back(x);
    }

    // cout << "ci : ";
    // for (int i = 0;i < n;i++) { cout << ci[i] << " "; } cout << '\n';
    // cout << "co : ";
    // for (int i = 0;i < n;i++) { cout << co[i] << " "; } cout << '\n';

    vector<vector<int>> adj(n);
    for (int i = 0;i < e;i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({ 0,0 });
    vector<int> dist(n, INT_MAX / 2);
    dist[0] = 0;

    while (!pq.empty()) {
        int nowW = pq.top().first;
        int nowU = pq.top().second;
        pq.pop();
        // cout << "now : " << nowU << ", " << nowW << '\n';

        if (nowW > dist[nowU]) continue;

        for (int next : adj[nowU]) {
            int w = co[nowU] + ci[next];
            // cout << "next : " << next << ", " << w << ", co: " << co[nowU] << ", co: " << ci[next] << '\n';
            if (nowW + w < dist[next]) {
                dist[next] = nowW + w;
                pq.push({ dist[next], next });
            }
        }
        // cout << "------------------ \n";
    }

    for (int i = 0;i < n;i++) {
        if (dist[i] == INT_MAX / 2) cout << "-1 ";
        else cout << dist[i] << " ";
    }
}