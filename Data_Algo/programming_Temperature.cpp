#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int m; cin >> m;
    int si, sj; cin >> sj >> si;
    vector<vector<int>> g(m, vector<int>(m));
    for (int i = 0;i < m;i++) {
        for (int j = 0;j < m;j++) {
            int x; cin >> x;
            g[i][j] = x;
        }
    }

    queue<pair<int, int>> q;
    q.push({ si - 1,sj - 1 });
    vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
    int ans = -1;
    vector<vector<bool>> flag(m, vector<bool> (m, false));

    while(!q.empty()) {
        int nowi = q.front().first;
        int nowj = q.front().second;
        q.pop();
        // cout << "now : " << nowi << ", " << nowj << '\n';
        ans = max(ans, g[nowi][nowj]);
        flag[nowi][nowj] = true;
        for(int i = 0;i < dir.size();i++) {
            int nexti = nowi + dir[i].first;
            int nextj = nowj + dir[i].second;
            if(nexti >= 0 && nexti < m && nextj >= 0 && nextj < m) {
                if (!flag[nexti][nextj] && g[nexti][nextj] != 100 && g[nexti][nextj] > g[nowi][nowj]) {
                    // cout << "next : " << nexti << ", " << nextj << '\n';
                    q.push({nexti, nextj});
                }
            }
        }
        // cout << '\n';
    }

    cout << ans;
}