    // //using INT_MAX --------------------------------------------------------------
    // #include <bits/stdc++.h>
    // using namespace std;

    // int main() {
    //     int n; cin >> n;
    //     vector<vector<int>> adj(n, vector<int>(n, INT_MAX));
    //     for (int i = 0;i < n;i++) {
    //         for (int j = 0;j < n;j++) {
    //             int x; cin >> x;
    //             if(x != -1) adj[i][j] = x;
    //         }
    //     }

    //     int ans = -1;
    //     for (int k = 0;k < n;k++) {
    //         for (int i = 0;i < n;i++) {
    //             for (int j = 0;j < n;j++) {
    //                 if (adj[i][k] != INT_MAX && adj[k][j] != INT_MAX) {
    //                     adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
    //                     //ans is fartest from set:{0 to x that shortest}
    //                     if (i == 0 && k == n - 1) ans = max(ans, adj[i][j]);
    //                 }
    //             }
    //         }
    //     }

    //     // for (int i = 0;i < n;i++) {
    //     //     for (int j = 0;j < n;j++) {
    //     //         cout << adj[i][j] << " ";
    //     //     }
    //     //     cout << '\n';
    //     // }

    //     bool notFound = false;
    //     for(int i = 1;i < n;i++) {
    //             cout << adj[0][i] << '\n';
    //         if(adj[0][i] == INT_MAX) notFound = true;    
    //     }
    //
    //     if(notFound) cout << "-1";
    //     else cout << ans;
    //     return 0;
    // }


    //using -1 --------------------------------------------------------------
    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        int n; cin >> n;
        vector<vector<int>> adj(n, vector<int>(n));
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                int x; cin >> x;
                adj[i][j] = x;
            }
        }

        int ans = -1;
        for (int k = 0;k < n;k++) {
            for (int i = 0;i < n;i++) {
                for (int j = 0;j < n;j++) {
                    if (adj[i][k] != -1 && adj[k][j] != -1) {
                        if (adj[i][j] == -1) adj[i][j] = adj[i][k] + adj[k][j]; //maybe adj[i][j] == -1 then using ans adj[i][j] = -1 instead of i->k->j
                        else adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                        //ans is fartest from set:{0 to x that shortest}
                        if (i == 0 && k == n - 1) ans = max(ans, adj[i][j]);
                    }
                }
            }
        }

        // for (int i = 0;i < n;i++) {
        //     for (int j = 0;j < n;j++) {
        //         cout << adj[i][j] << " ";
        //     }
        //     cout << '\n';
        // }

        bool notFound = false;
        for (int i = 1;i < n;i++) {
            // cout << adj[0][i] << '\n';
            if (adj[0][i] == -1) notFound = true;
        }

        if (notFound) cout << "-1";
        else cout << ans;
        return 0;
    }
