#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> pipii;


int main() {
    int r, c; cin >> r >> c;
    vector<vector<int>> g(r, vector<int>(c));
    priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
    vector<vector<int>> dist(r, vector<int> (c, INT_MAX));
    for(int i = 0;i < r;i++) {
        for(int j = 0;j < c;j++) {
            int x; cin >> x;
            g[i][j] = x;
            if(x == 1) {
                pq.push({ 1, {i,j} });
                dist[i][j] = 1;
            }
        }
    }

    int ans = INT_MAX;
    vector<pii> dir = {{1,0},{0,1},{-1,0},{0,-1}};
    while(!pq.empty()) {
        int nowW = pq.top().first;
        pii now = pq.top().second;
        pq.pop();
        // cout << "now : " << now.first << ", " << now.second << ", " << nowW << '\n';

        if(nowW > dist[now.first][now.second]) continue;

        for(int i = 0;i < dir.size();i++) {
            int nexti = now.first + dir[i].first;
            int nextj = now.second + dir[i].second;
            if(nexti >= 0 && nexti < r && nextj >= 0 && nextj < c && g[nexti][nextj] != 3) {
                // cout << "next : " << nexti << ", " << nextj << ", " << '\n';
                if(nowW + 1 < dist[nexti][nextj]) {
                    dist[nexti][nextj] = nowW + 1;
                    pq.push({nowW + 1, {nexti, nextj}});
                    if(g[nexti][nextj] == 2) ans = min(ans, nowW + 1);
                }
            }
        }
        // cout << "-------------------- \n";
    }

    cout << ans;
}