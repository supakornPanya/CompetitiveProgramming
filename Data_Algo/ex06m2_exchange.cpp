#include <bits/stdc++.h>
using namespace std;

int main() {
    int q; cin >> q;
    while (q--) {
        int n; cin >> n;
        vector<vector<double long>> dist(n, vector<double long>(n));
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                double long x; cin >> x;
                dist[i][j] = x;
            }
        }

        bool found = false;
        for (int k = 0;k < n;k++) {
            for (int i = 0;i < n;i++) {
                for (int j = 0;j < n;j++) {
                    dist[i][j] = max(dist[i][j], dist[i][k] * dist[k][j]);
                    // if (k == n - 1) cout << dist[i][j] << '\n';
                    if (dist[i][j] > 1 && i == j) found = true;
                }
            }
        }

        if (found) cout << "YES\n";
        else cout << "NO\n";
    }
}