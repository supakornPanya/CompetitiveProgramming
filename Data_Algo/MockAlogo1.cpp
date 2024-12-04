#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0;i < m;i++) {
        int w, u, v; cin >> w >> u >> v;
        adj[u].push_back({ w,v });
        adj[v].push_back({ w,u });
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0,1});
    vector<bool> inTree(n + 1, false);
    int cost = 0;

    while(!pq.empty()) {
        int nowW = pq.top().first;
        int nowU = pq.top().second;
        pq.pop();

        if(inTree[nowU]) continue;

        inTree[nowU] = true;
        cost += nowW;
        for(pair<int,int>& next : adj[nowU]) {
            int nextW = next.first;
            int nextU = next.second;
            if(inTree[nextU]) continue;
            pq.push({nextW, nextU});
        }
    }
    cout << cost;
}