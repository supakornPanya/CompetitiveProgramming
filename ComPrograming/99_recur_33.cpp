#include <bits/stdc++.h>
using namespace std;

bool pass = false;
set<vector<int>> ans;

void dfs(int now, int end, map<int, vector<int>>& m) {
    //cout << now << endl;
    if (now > end) return;
    if (now == end) {
        pass = true;
        return;
    }
    for (int i = 0;i < m[now].size();i++) {
        dfs(m[now][i], end, m);
    }
}

int main() {
    map<int, vector<int>> m;

    //input
    int n, a, b; cin >> n >> a >> b;
    for (int i = 0;i < n;i++) {
        int start, des; cin >> start >> des; //start, destiny
        m[start].push_back(des);
    }
    dfs(a, b, m);

    //out put
    if(pass) cout << "yes";
    else cout << "no";

    return 0;
}