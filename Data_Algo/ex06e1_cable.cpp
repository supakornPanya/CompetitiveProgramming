#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0;i < n - 1;i++) {
        for (int j = i + 1;j < n;j++) {
            int x; cin >> x;
            // cout << "i : " << i << ",   j : " << j << '\n';
            adj[i].push_back({ x,j });
            adj[j].push_back({ x,i });
        }
    }

    priority_queue<pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>> pq;
    pq.push({ 0,0 });
    vector<bool> inTree(n, false);
    int cost = 0;

    while (!pq.empty()) {
        int nowW = pq.top().first;
        int nowU = pq.top().second;
        pq.pop();
        // cout << "now : " << nowU << ", " << nowW << ", cost : " << cost << '\n';

        if (inTree[nowU]) continue;

        inTree[nowU] = true;
        cost += nowW;

        for (pair<int, int> next : adj[nowU]) {
            int nextW = next.first;
            int nextU = next.second;
            if (inTree[nextU]) continue;
            // cout << "next : " << nextU << ", " << nextW << '\n';
            pq.push({   nextW,nextU });
        }
        // cout << "------------------ \n";
    }

    cout << cost;
}