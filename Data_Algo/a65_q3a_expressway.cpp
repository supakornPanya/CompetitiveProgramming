#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
    int n, k; cin >> n >> k;
    vector<vector<pair<int, int>>> adj(n + 1);
    adj[1].push_back({ k, 2 });
    adj[2].push_back({ k, 1 });
    vector<int> dist(n + 1, INT_MAX / 2);
    dist[1] = 0;
    dist[2] = k;
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    //add new node
    for (int i = 3;i <= n;i++) {
        //add new node(many edge) + find best way to new node
        int m; cin >> m;
        int distNew = INT_MAX / 2;
        for (int j = 0;j < m;j++) {
            int v, p; cin >> v >> p;
            adj[i].push_back({ p,v });
            adj[v].push_back({ p,i });
            dist[i] = min(dist[i], dist[v] + p); //best way to new node
            // cout << "dist[i] : " << dist[i] << '\n';
        }
        // cout << "------------------------- \n";

        //dijkstra form new node
        pq.push({ dist[i], i });
        while (!pq.empty()) {
            int nowW = pq.top().first;
            int nowU = pq.top().second;
            pq.pop();

            if (nowW > dist[nowU]) continue;

            // cout << "now | u : " << nowU << ", w : " << nowW << '\n';
            for (pii next : adj[nowU]) {
                int nextW = next.first;
                int nextU = next.second;
                if (nowW + nextW < dist[nextU]) {
                    dist[nextU] = nowW + nextW;
                    pq.push({ dist[nextU], nextU });
                    // cout << "next | u : " << nextU << ", w : " << nextW << '\n';
                }
            }
            // cout << "------------------------- \n";
        }

        //out put
        cout << dist[2] << " ";
        // cout << "new node enddd---------------------------- \n";
    }
}