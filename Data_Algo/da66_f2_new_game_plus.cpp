#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int r, c; cin >> r >> c;
    vector<vector<int>> g(r, vector<int>(c));
    for (int i = 0;i < r;i++) {
        for (int j = 0;j < c;j++) {
            int x; cin >> x;
            g[i][j] = x;
        }
    }

    vector<vector<ll>> dp1(r, vector<ll>(c, 0));
    vector<vector<ll>> dp2(r, vector<ll>(c, 0));
    vector<vector<ll>> dp3(r, vector<ll>(c, 0));
    for (int i = 0;i < r;i++) {
        if (i == 0) {
            if (g[i][0] == 0) dp2[i][1] = 1;
            if (g[i + 1][0] == 0) dp3[i][1] = 1;
        } else if (i == r - 1) {
            if (g[i - 1][0] == 0) dp1[i][1] = 1;
            if (g[i][0] == 0) dp2[i][1] = 1;
        } else {
            if (g[i - 1][0] == 0) dp1[i][1] = 1;
            if (g[i][0] == 0) dp2[i][1] = 1;
            if (g[i + 1][0] == 0) dp3[i][1] = 1;
        }
    }

    for (int i = 2;i < c;i++) {
        for (int j = 0;j < r;j++) {
            // cout << "now : " << j << ", " << i << '\n';
            if (g[j][i] == 1) continue;
            if (j - 1 >= 0 && g[j - 1][i - 1] != 1) {
                // cout << "j-1 : " << j - 1 << ", i-1 : " << i - 1 << '\n';
                dp1[j][i] += dp2[j - 1][i - 1] % 100000007;
                dp1[j][i] += dp3[j - 1][i - 1] % 100000007;
            }
            if (g[j][i - 1] != 1) {
                // cout << "j : " << j << ", i-1 : " << i - 1 << '\n';
                dp2[j][i] += dp1[j][i - 1] % 100000007;
                dp2[j][i] += dp3[j][i - 1] % 100000007;
            }
            if (j + 1 < r && g[j + 1][i - 1] != 1) {
                // cout << "j+1 : " << j + 1 << ", i-1 : " << i - 1 << '\n';
                dp3[j][i] += dp1[j + 1][i - 1] % 100000007;
                dp3[j][i] += dp2[j + 1][i - 1] % 100000007;
            }

            // cout << '\n';
        }
    }

    // for(int i = 0;i < r;i++) {
    //     for(int j = 0;j < c;j++) {
    //         cout << (dp1[i][j] + dp2[i][j] + dp3[i][j]) << " ";
    //     }
    //     cout << '\n';
    // }

    ll ans = 0;
    for (int i = 0;i < r;i++) {
        ans += dp1[i][c - 1] % 100000007;
        ans += dp2[i][c - 1] % 100000007;
        ans += dp3[i][c - 1] % 100000007;
    }
    cout << ans % 100000007;
}