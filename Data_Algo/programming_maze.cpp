#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> piii;
typedef pair<int, int> pii;

const int inf = INT_MAX / 2;
vector<vector<int>> g(150, vector<int>(150));
vector<pair<int, int>> dir = { {0,1},{1,0},{-1,0},{0,-1} };
set<pair<int, int>> uesdBomb;
int n, m, re, ce;
struct idx {
    int i,j;
    bool b;
};
void bfs(int ni, int nj, vector<vector<int>>& dist) {
    queue<idx> q;
    q.push({ni,nj,false});

    while(!q.empty()){
        idx now = q.front();
        q.pop();

        for (int i = 0;i < dir.size();i++) {
            int nexti = now.i + dir[i].first;
            int nextj = now.j + dir[i].second;
            if (nexti >= 0 && nexti < n && nextj >= 0 && nextj < m) { //in graph
                if (dist[now.i][now.j] + 1 < dist[nexti][nextj]) { // good to go
                    dist[nexti][nextj] = dist[now.i][now.j] + 1;
                    if(g[nexti][nextj] == 1) { //no bomb
                        q.push({ nexti,nextj,false });
                    } else if (g[nexti][nextj] == 1 && now.b == false) { //have bomb
                        q.push({ nexti,nextj,true });
                    }
                }
            }
        }
    }    
}

int main() {
    cin >> n >> m;
    int rs, cs; cin >> rs >> cs;
    cin >> re >> ce;
    rs--; cs--; re--; ce--;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            int x; cin >> x;
            g[i][j] = x;
        }
    }

    //bfs from start
    vector<vector<int>> dist1(n, vector<int>(m, inf));
    dist1[rs][cs] = 1;
    bfs(rs, cs, dist1);
    //bfs from end
    vector<vector<int>> dist2(n, vector<int>(m, inf));
    dist2[re][ce] = 1;
    bfs(re, ce, dist2);
    //check node obs
    int useBomb = 0, shortest = inf;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (g[i][j] == 0 && dist1[i][j] != inf && dist2[i][j] != inf){
                useBomb++;
                shortest = min(shortest, dist1[i][j] + dist2[i][j] - 1);
            }   
        }
    }

    //check
    // for (int i = 0;i < n;i++) {
    //     for (int j = 0;j < m;j++) {
    //         if(dist1[i][j] == inf) cout << "x ";
    //         else cout << dist1[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    // cout << "------------\n";
    // for (int i = 0;i < n;i++) {
    //     for (int j = 0;j < m;j++) {
    //         if (dist2[i][j] == inf) cout << "x ";
    //         else cout << dist2[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    cout << useBomb << '\n' << shortest;
}