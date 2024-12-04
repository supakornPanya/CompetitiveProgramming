#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, c; cin >> r >> c;
    vector<vector<double>> v(r + 5, vector<double>(c + 5, 0));
    //create prefix sum
    for (int i = 1;i <= r;i++) {
        for (int j = 1;j <= c;j++) {
            double x; cin >> x;
            v[i][j] = x + v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
            // cout << v[i][j] << " ";
        }
        // cout << endl;
    }

    for (int i = 3;i <= r;i++) {
        for (int j = 3;j <= c;j++) {
            double ans = (v[i][j] - v[i - 3][j] - v[i][j - 3] + v[i - 3][j - 3]) / 9;
            cout << round(ans * 100) / 100.0 << " ";
        }
        cout << endl;
    }

    return 0;
}