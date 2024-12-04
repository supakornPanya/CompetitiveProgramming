#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;


//'.' = -1 ->grass/water
//'x' = 0 ->house
// -1 = grass
// 0  = house never go
// 1  = water
// 2  >= house ever go
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0;i < n;i++) {
        string s; cin >> s;
        for (int j = 0;j < m;j++) {
            if (s[j] == '.') grid[i][j] = -1;
            else grid[i][j] = 0;
        }
    }

    //flood fill
    vector<pii> dir = { {1,0},{0,1},{-1,0},{0,-1} };
    queue<pii> q;
    q.push({ 0,0 });
    grid[0][0] = 1;
    while (!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();
        for (int i = 0;i < dir.size();i++) {
            int nexti = now.first + dir[i].first;
            int nextj = now.second + dir[i].second;
            if (nexti >= 0 && nexti < n && nextj >= 0 && nextj < m)
                if (grid[nexti][nextj] == -1){
                    grid[nexti][nextj] = 1;
                    q.push({ nexti, nextj });
                }
        }
    }

    int longestWall = 0;
    int group = 2;
    for (int i = 1;i < n;i++) {
        for (int j = 1;j < m;j++) {
            if (grid[i][j] == 0) {
                int wall = 0;
                grid[i][j] = group;

                //bfs
                queue<pii> q; q.push({ i,j });
                while (!q.empty()) {
                    pii now = q.front();
                    q.pop();
                    // cout << "\n now " << now.first << ", " << now.second << '\n';
                    //check to create wall && go next node 
                    for (int i = 0;i < dir.size();i++) {
                        int nexti = now.first + dir[i].first;
                        int nextj = now.second + dir[i].second;
                        if (grid[nexti][nextj] == 1) //check for create wall
                            // cout << "wall"<<nexti<<","<<nextj<<" ", wall++;
                            wall++;
                        if (grid[nexti][nextj] == 0) { //go next node
                            grid[nexti][nextj] = group;
                            q.push({ nexti,nextj });
                        }  
                    }
                }
                //bfs

                group++;
                longestWall = max(longestWall, wall);
            }
        }
    }


    // for (int i = 0;i < n;i++) {
    //     for (int j = 0;j < m;j++) {
    //         if(grid[i][j] == -1) cout << "x ";
    //         else cout << grid[i][j] << " ";
    //     } cout << '\n';
    // }
    cout << longestWall;
}