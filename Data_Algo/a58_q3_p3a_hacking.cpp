#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
    int n, e, k; cin >> n >> e >> k;

    //start
    set<int> s;
    for (int i = 0;i < k;i++) {
        int x; cin >> x;
        s.insert(x);
    }

    //time to go index i
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> val(n);
    vector<int> dist(n, INT_MAX);
    for (int i = 0;i < n;i++) {
        int x; cin >> x;
        val[i] = x;
        if (s.find(i) != s.end()){
            pq.push({ x,i });
            dist[i] = x;
        }
    }

    //edge
    vector<vector<int>> adj(n);
    for (int i = 0;i < e;i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    while (!pq.empty()) {
        int nowW = pq.top().first;
        int nowU = pq.top().second;
        pq.pop();
        // cout << "now | u :" << nowU << ", w : " << nowW << '\n';

        if (nowW > dist[nowU]) continue;

        for (int next : adj[nowU]) {
            int nextU = next;
            int nextW = val[nextU];
            if (nowW + nextW < dist[nextU]) {
                dist[nextU] = nowW + nextW;
                pq.push({ dist[nextU], nextU });
                // cout << "next | u : " << nextU << ", w : " << nextW << ", dist[nextU] : " << dist[nextU] << '\n';
            }
        }
        // cout << "-------------------------- \n";
    }

    int ans = 0;
    for (int i = 0;i < n;i++) {
        // cout << dist[i] << " ";
        if (s.find(i) == s.end()) ans = max(ans, dist[i]);
    }
    // cout << '\n';

    cout << ans;
}