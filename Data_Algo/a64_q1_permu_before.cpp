#include <bits/stdc++.h>
using namespace std;

void bfs(int n, int now, vector<int>& sol, vector<bool>& flag, const vector<int>& rule) {
    if (now == n) {
        for (int i = 0;i < sol.size();i++) {
            cout << sol[i] << " ";
        } cout << '\n';
        return;
    }
    for (int i = 0;i < n;i++) {
        if (flag[i]) continue;
        int idx = rule[i];
        if (idx != -1 && !flag[idx]) continue;
        sol.push_back(i);
        flag[i] = true;
        bfs(n, now + 1, sol, flag, rule);
        sol.pop_back();
        flag[i] = false;
    }
}

int main() {
    int n, m; cin >> n >> m;
    vector<int> rule(21, -1);
    for (int i = 0;i < m;i++) {
        int x, y; cin >> x >> y;
        rule[y] = x;
    }
    vector<int> sol;
    vector<bool> flag(21, false);
    bfs(n, 0, sol, flag, rule);
}