#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;

struct dir {
    bool u, r, d, l;
    //up right down left
    dir() {
        u = false, r = false, d = false, l = false;
    }
};

struct idx { //parent and child
    int pi, pj, ni, nj;
};

int main() {
    int n, m; cin >> n >> m;
    vector<vector<dir>> grid(n, vector<dir>(m));
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            int x; cin >> x;
            if (x == 1) {
                grid[i][j].l = true;
                grid[i][j].r = true;
            } else if (x == 2) {
                grid[i][j].u = true;
                grid[i][j].d = true;
            } else if (x == 3) {
                grid[i][j].u = true;
                grid[i][j].r = true;
            } else if (x == 4) {
                grid[i][j].r = true;
                grid[i][j].d = true;
            } else if (x == 5) {
                grid[i][j].l = true;
                grid[i][j].d = true;
            } else if (x == 6) {
                grid[i][j].l = true;
                grid[i][j].u = true;
            }
        }
    }



    vector<vector<int>> flag(n, vector<int>(m, 0));
    int group = 1;
    int cycle = 0, longestCycle = 0;

    //bfs every node
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (flag[i][j] == 0) {
                int path = 0;
                bool foundCycle = false;

                //bfs
                queue<idx> q;
                q.push({ i,j,i,j });
                while (!q.empty()) {
                    //set up
                    auto now = q.front();
                    q.pop();
                    if (flag[now.ni][now.nj] == group) {
                        foundCycle = true;
                        continue;
                    }
                    path++;
                    flag[now.ni][now.nj] = group;


                    //go up-----------
                    if (grid[now.ni][now.nj].u)
                        if (now.ni - 1 >= 0 && grid[now.ni - 1][now.nj].d)  //up node can go d?
                            if (now.ni - 1 != now.pi) //not go to parent
                                q.push({ now.ni, now.nj, now.ni - 1, now.nj });
                    //go right-----------
                    if (grid[now.ni][now.nj].r)
                        if (now.nj + 1 < m && grid[now.ni][now.nj + 1].l)  //right node can go l?
                            if (now.nj + 1 != now.pj) //not go to parent 
                                q.push({ now.ni, now.nj, now.ni, now.nj + 1 });
                    //go down-----------
                    if (grid[now.ni][now.nj].d)
                        if (now.ni + 1 < n && grid[now.ni + 1][now.nj].u)  //down node can go u?
                            if (now.ni + 1 != now.pi) //not go to parent 
                                q.push({ now.ni, now.nj, now.ni + 1, now.nj });
                    //go left-----------
                    if (grid[now.ni][now.nj].l)
                        if (now.nj - 1 >= 0 && grid[now.ni][now.nj - 1].r)  //left node can go r?
                            if (now.nj - 1 != now.pj) //not go to parent 
                                q.push({ now.ni, now.nj, now.ni, now.nj - 1 });
                }
                //bfs

                group++;
                if (foundCycle) {
                    cycle++;
                    longestCycle = max(longestCycle, path);
                }
            }
        }
    }

    // check code
    // for (int i = 0;i < n;i++) {
    //     for (int j = 0;j < m;j++) {
    //         cout << flag[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    // cout << "---------------\n";
    // for (int i = 0;i < n;i++) {
    //     for (int j = 0;j < m;j++) {
    //         cout << grid[i][j].u << "|" << grid[i][j].r << "|" << grid[i][j].d << "|" << grid[i][j].l << "| ";
    //     }
    //     cout << '\n';
    // }

    cout << cycle << " " << longestCycle;
}