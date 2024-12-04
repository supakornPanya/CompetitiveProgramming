#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
const int inf = INT_MAX / 2;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<char>> g1(n, vector<char>(m));
    vector<vector<int>> dist(n, vector<int>(m, inf));
    priority_queue<piii, vector<piii>, greater<piii>> pq;
    for (int i = 0;i < n;i++) {
        string s; cin >> s;
        for(int j = 0;j < m;j++) {
            g1[i][j] = s[j];
            if (s[j] == 'X') pq.push({ 0, {i,j} });
        }
    }


    pair<int, int> ans = { 0,0 };
    vector<pair<int, int>> dir = { {0,1},{1,0},{-1,0},{0,-1} };
    while (!pq.empty()) {
        int nW = pq.top().first;
        pair<int, int> nU = pq.top().second;
        pq.pop();

        if (g1[nU.first][nU.second] == 'A' && dist[nU.first][nU.second] != inf) {
            ans.first++;
            ans.second += dist[nU.first][nU.second] * 2;
            g1[nU.first][nU.second] = 'E';
        }
        for (int i = 0;i < dir.size();i++) {
            int nexti = nU.first + dir[i].first;
            int nextj = nU.second + dir[i].second;
            if (nexti >= 0 && nexti < n && nextj >= 0 && nextj < m) {
                if (nW + 1 < dist[nexti][nextj] && g1[nexti][nextj] != 'W') {
                    dist[nexti][nextj] = nW + 1;
                    pq.push({ nW + 1, {nexti, nextj} });
                }
            }
        }
    }

    // for (int i = 0;i < n;i++) {
    //     for (int j = 0;j < m;j++) {
    //         if(dist[i][j] == inf) cout << "x ";
    //         else cout << dist[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    cout<< ans.first << " " << ans.second;
}