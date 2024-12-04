#include <bits/stdc++.h>
using namespace std;

void dfs(int level, int len, vector<vector<int>>& g, vector<pair<int, int>>& dir, vector<int> sol, vector<vector<bool>>& flag) {
    if (g[level][len] == 1) return;
    if (flag[level][len]) return;
    if (level == g.size() - 1) {
        if (g[level][len] == 0) {
            // cout << "ans : " << '\n';
            for (int i = 0;i < sol.size();i++) {
                cout << sol[i] << '\n';
            }
        }
        return;
    }

    flag[level][len] = true;
    for (int i = 0;i < dir.size();i++) {
        int nextLen = len + dir[i].second;
        if (nextLen < 1 || nextLen >= g[0].size()) continue;
        sol.push_back(dir[i].first);
        dfs(level + 1, nextLen, g, dir, sol, flag);
        sol.pop_back();
    }
}

int main() {
    int c; cin >> c;
    int s; cin >> s;
    int r; cin >> r;
    vector<vector<int>> g(r + 1, vector<int>(c + 1));
    vector<vector<bool>> flag(r + 1, vector<bool>(c + 1, false));
    for (int i = 1;i <= r;i++) {
        for (int j = 1;j <= c;j++) {
            int x; cin >> x;
            g[i][j] = x;
        }
    }

    vector<pair<int, int>> dir = { {1, -1},{2,1},{3,0} };
    vector<int> sol;
    dfs(0, s, g, dir, sol, flag);
}