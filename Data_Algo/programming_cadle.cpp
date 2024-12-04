#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& g, int i, int j, vector<pair<int, int>>& dir) {
    queue<pair<int, int>> q;
    q.push({ i,j });
    while (!q.empty()) {
        int nowi = q.front().first;
        int nowj = q.front().second;
        q.pop();
        // cout << "now : " << nowi << ", " << nowj << '\n';
        if (g[nowi][nowj] == 0) continue;
        g[nowi][nowj] = 0;
        for (int ii = 0;ii < dir.size();ii++) {
            int nexti = nowi + dir[ii].first;
            int nextj = nowj + dir[ii].second;
            if (nexti >= 0 && nexti < g.size() && nextj >= 0 && nextj < g[0].size()) {
                q.push({ nexti,nextj });
            }
        }
    }
}

int main() {
    int r, c; cin >> r >> c;
    vector<vector<int>> g(r, vector<int>(c));

    for (int i = 0;i < r;i++) {
        string s; cin >> s;
        for (int j = 0;j < c;j++) {
            if (s[j] == '1') g[i][j] = 1;
            else g[i][j] = 0;
        }
    }

    vector<pair<int, int>> dir = { {1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1} };
    int cnt = 0;
    for (int i = 0;i < r;i++) {
        for (int j = 0;j < c;j++) {
            if (g[i][j] == 1) {
                dfs(g, i, j, dir);
                cnt++;
                // for (int i = 0;i < r;i++) {
                //     for (int j = 0;j < c;j++) {
                //         cout << g[i][j] << " ";
                //     }
                //     cout << '\n';
                // }
            }
        }
    }
    cout << cnt;
}