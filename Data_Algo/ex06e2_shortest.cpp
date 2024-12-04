    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        int n, e, s; cin >> n >> e >> s;
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0;i < e;i++) {
            int u, v, w; cin >> u >> v >> w;
            adj[u].push_back({ w,v });
        }

        vector<int> dist(n, INT_MAX);
        dist[s] = 0;

        //find shortest path
        for (int i = 0;i < n - 1;i++) {
            for (int u = 0;u < n;u++) {
                for (pair<int, int> v : adj[u]) {
                    int vW = v.first;
                    int vU = v.second;
                    if (dist[u] != INT_MAX && vW + dist[u] < dist[vU]) {
                        dist[vU] = vW + dist[u];
                    }
                }
            }
        }

        //check negative edge cycle
        bool found = false;
        for (int u = 0;u < n;u++) {
            for (pair<int, int> v : adj[u]) {
                int vW = v.first;
                int vU = v.second;
                if (dist[u] != INT_MAX && vW + dist[u] < dist[vU]) {
                    found = true;
                }
            }
        }

        if (found) cout << "-1";
        else {
            for(int i = 0;i < n;i++) {
                cout << dist[i] << " ";
            }
        }
    }