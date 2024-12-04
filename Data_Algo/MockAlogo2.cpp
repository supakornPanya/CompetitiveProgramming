#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int, pair<int,int>> piii;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int r, c; cin >> r >> c;
    vector<vector<int>> g(r, vector<int> (c));
    vector<pair<int,int>> chest;
    for(int i = 0;i < r;i++) {
        for(int j = 0;j < c;j++) {
            int x; cin >> x;
            g[i][j] = x;
            if(x == 2) chest.push_back({i,j});
        }
    }

    vector<pair<int, int>> dir = { {0,1},{1,0},{-1,0},{0,-1} };
    vector<vector<int>> dist(r, vector<int> (c, INT_MAX));
    dist[0][0] = 0;
    priority_queue<piii, vector<piii>, greater<piii>> pq;
    pq.push({0, {0,0}});

    while(!pq.empty()) {
        int nowW = pq.top().first;
        pii nowU = pq.top().second;
        pq.pop();
        
        if(nowW > dist[nowU.first][nowU.second]) continue;
        for (int i = 0;i < dir.size();i++) {
            int nexti = nowU.first + dir[i].first;
            int nextj = nowU.second + dir[i].second;
            if(nexti >=0 && nexti < r && nextj >= 0 && nextj < c) {
                if(nowW + 1 < dist[nexti][nextj] && g[nexti][nextj] != 0) {
                    dist[nexti][nextj] = nowW + 1;
                    pq.push({dist[nexti][nextj], {nexti, nextj}});
                }
            }
        }
    }

    // for (int i = 0;i < r;i++) {
    //     for (int j = 0;j < c;j++) {
    //        cout << dist[i][j] <<  " ";
    //     }
    //     cout << '\n';
    // }

    int ans = 0;
    for(int i = 0;i < chest.size();i++) {
        int x = chest[i].first;
        int y = chest[i].second;
        ans += (dist[x][y]) * 2;
    }
    cout << ans;
}