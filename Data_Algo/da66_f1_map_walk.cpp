#include <bits/stdc++.h>
using namespace std;

vector<string> ans;
vector<pair<int, int>> dir = { {0,1},{1,0},{-1,0} };
vector<char> dirc = {'A','B','C'};
void dfs(int r, int c, vector<vector<int>>& g, string s, int x, int y) {
    if (x == r - 1 && y == c - 1) {
        cout << s << '\n';
        // ans.push_back(s);
        return;
    }
    // cout << "now : " << x << ", " << y << '\n';
    g[x][y] = 1;
    for (int i = 0;i < dir.size();i++) {
        int nextx = x + dir[i].first;
        int nexty = y + dir[i].second;
        if (nextx >= 0 && nextx < r && nexty >= 0 && nexty < c && g[nextx][nexty] != 1) {
            // cout << "next : " << nextx << ", " << nexty << '\n';
            dfs(r, c, g, s + dirc[i], nextx, nexty);
        }
    }
    if(x >= 0 && x < r && y >= 0 && y < c) {
        g[x][y] = 0;
    }
}

int main() {
    int r, c; cin >> r >> c;
    vector<vector<int>> g(r, vector<int>(c));
    for (int i = 0;i < r;i++) {
        for (int j = 0;j < c;j++) {
            int x; cin >> x;
            g[i][j] = x;
        }
    }

    dfs(r, c, g, "", 0, 0);

    // cout << "ans : " << ans.size() << '\n';
    // for (int i = 0;i < ans.size();i++) {
    //     cout << ans[i] << '\n';
    // }
    cout << "DONE";
}














// #include <bits/stdc++.h>
// using namespace std;

// void bfs(vector<vector<bool>>& table, int r, int c, vector<char>& ans, vector<vector<bool>>& flag) {
//     if (flag[r][c] || table[r][c]) return; //been here before
//     if (r == table.size() - 1 && c == table[0].size() - 1) {
//         for (int i = 0;i < ans.size();i++) {
//             cout << ans[i];
//         } cout << '\n';
//         return;
//     }

//     flag[r][c] = true;

//     if(c + 1 < table[0].size()) {
//         ans.push_back('A');
//         bfs(table, r, c + 1, ans, flag);
//         ans.pop_back();
//     }

//     if(r + 1 < table.size()) {
//         ans.push_back('B');
//         bfs(table, r + 1, c, ans, flag);
//         ans.pop_back();
//     }

//     if(r - 1 >= 0) {
//         ans.push_back('C');
//         bfs(table, r - 1, c, ans, flag);
//         ans.pop_back();
//     }

//     flag[r][c] = false;
// }

// int main() {
//     int r, c; cin >> r >> c;
//     vector<vector<bool>> table;
//     for (int i = 0;i < r;i++) {
//         vector<bool> row;
//         for (int i = 0;i < c;i++) {
//             int x; cin >> x;
//             bool temp = (x == 1) ? true : false;
//             row.push_back(temp);
//         }
//         table.push_back(row);
//     }

//     // cout << "size : " << table.size() << ", " << table[0].size() << '\n';
//     vector<char> ans;
//     vector<vector<bool>> flag(11, vector<bool>(11, false));
//     bfs(table, 0, 0, ans, flag);

//     cout << "DONE";
// }