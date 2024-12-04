#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<bool>> g(n, vector<bool>(m));
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            int x; cin >> x;
            g[i][j] = x;
        }
    }

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (g[i][j] == true) {
                //find start index
                int ii = i; int jj = j; //jj = mid for dept
                while (g[ii][jj]) jj++;
                jj = ((jj - j) / 2) + 1;
                vector<int> ck; //each index is how long of index jj
                while(g[ii][jj]) { //loop dept
                    int l = jj, r = jj;
                    while (g[ii][ll]) { //loop breath find left
                        
                    }
                    ii++; //next dept
                }
            }
        }
    }
}