#include <bits/stdc++.h>
using namespace std;

bool found = false;
int last = -1;
void dfs(map<int,int>& warp, vector<bool>& obs, int n, int now, vector<bool>& flag) {
    last = max(last, now);
    //check base case
    if(flag[now]) return;
    if(now == n) {
        found = true;
        return;
    }

    flag[now] = true;
    //go next
    if(warp.find(now) != warp.end()) {
        dfs(warp, obs, n, warp[now], flag);
    }
    if(!obs[now]) {
        dfs(warp, obs, n, now + 1, flag);
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m, k; cin >> n >> m >> k;

    map<int,int> warp;
    for(int i = 0;i < m;i++) {
        int u, v; cin >> u >> v;
        warp[u] = v;
    }

    vector<bool> obs(n + 10, false);
    for (int i = 0;i < k;i++) {
        int x; cin >> x;
        obs[x] = true; 
    }

    vector<bool> flag(n + 1, false);
    dfs(warp, obs, n, 1, flag);
    if(found) cout << "1";
    else cout << "0 " << last;
}