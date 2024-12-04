#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> pipii;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            int x; cin >> x;
            matrix[i][j] = x;
        }
    }

    priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
    pq.push({ 0,{0,0} }); // {weight , {i,j}}
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX/2));
    vector<pair<int, int>> dir = { {0,1}, {1,0}, {-1,0}, {0,-1} };

    while (!pq.empty()) {
        int nowW = pq.top().first;
        pair<int, int> nowij = pq.top().second;
        pq.pop();

        if (nowW > dist[nowij.first][nowij.second]) continue;

        // cout << "now : " << nowW << ", i : " << nowij.first << ", j : " << nowij.second << '\n'; 
        for (int i = 0;i < dir.size();i++) {
            int nexti = nowij.first + dir[i].first;
            int nextj = nowij.second + dir[i].second;
            
            if(nexti < 0 || nexti >= n || nextj < 0 || nextj >= m) continue;
            int nextW = matrix[nexti][nextj];
            // cout << "next | W : " << nextW << ", i : " << nexti << ", j : " << nextj << '\n';
            if (nowW + nextW < dist[nexti][nextj]) {
                // cout << "push \n";
                dist[nexti][nextj] = nowW + nextW;
                pq.push({ dist[nexti][nextj], {nexti, nextj} });
            }
        }
        // cout << "------------------ \n";
    }

    dist[0][0] = 0;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            cout << dist[i][j] << " ";
        }
        cout << '\n';
    }
}