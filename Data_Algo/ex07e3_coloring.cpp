#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, vector<int>& colors, vector<bool>& flag, int now) {
    //find color this node
    vector<bool> check(adj.size(), false); //colors that used by adjacent node of now
    for (int u : adj[now]) { //find all colors that used by adjacent node
        if(colors[u] == -1) continue;
        check[colors[u]] = true;
    }

    int idx;
    for (idx = 0;idx < check.size();idx++) { //find colors not yet used
        if (check[idx] == false) break;
    }
    colors[now] = idx;
    // cout << now << " : ans : " << idx << '\n';
    ans = max(ans, idx);

    // dfs next node
    for (int u : adj[now]) {
        if (flag[u]) continue;

        flag[u] = true;
        dfs(adj, colors, flag, u);
    }
}



int main() {
    int n, e; cin >> n >> e;
    vector<int> colors(n, -1);
    vector<vector<int>> adj(n);
    vector<bool> flag(n + 10, false);
    for (int i = 0;i < e;i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ans = 0;
    for (int i = 0;i < n;i++) {
        if (!check(i)) break;
        ans = i;
    }

    cout << ans; //start color is 0
}



//------------P = 90% using dfs---------------------------------------------------------------------------------------------------
// #include <bits/stdc++.h>
// using namespace std;

// int ans = 0;
// void dfs(vector<vector<int>>& adj, vector<int>& colors, vector<bool>& flag, int now) {
//     //find color this node
//     vector<bool> check(adj.size(), false); //colors that used by adjacent node of now
//     for (int u : adj[now]) { //find all colors that used by adjacent node
//         if(colors[u] == -1) continue;
//         check[colors[u]] = true;
//     }

//     int idx;
//     for (idx = 0;idx < check.size();idx++) { //find colors not yet used
//         if (check[idx] == false) break;
//     }
//     colors[now] = idx;
//     // cout << now << " : ans : " << idx << '\n';
//     ans = max(ans, idx);
    
//     // dfs next node
//     for (int u : adj[now]) {
//         if (flag[u]) continue;

//         flag[u] = true;
//         dfs(adj, colors, flag, u);
//     }
// }

// int main() {
//     int n, e; cin >> n >> e;
//     vector<int> colors(n, -1);
//     vector<vector<int>> adj(n);
//     vector<bool> flag(n + 10, false);
//     for (int i = 0;i < e;i++) {
//         int a, b; cin >> a >> b;
//         adj[a].push_back(b);
//         adj[b].push_back(a);
//     }

//     for (int i = 0;i < n;i++) {
//         if (colors[i] == -1) {
//             dfs(adj, colors, flag, i);
//         }
//     }

//     cout << ans + 1; //start color is 0
// }