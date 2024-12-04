#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, c, t; cin >> r >> c >> t;
    vector<vector<int>> gph(r, vector<int>(c));
    queue<pair<int, int>> q;
    int ans = 0;
    for (int i = 0;i < r;i++) {
        for (int j = 0;j < c;j++) {
            int x; cin >> x;
            gph[i][j] = x;
            if (x == 1) {
                q.push({ i,j });
                ans++;
            }
        }
    }

    vector<pair<int, int>> dir = { {1,0},{0,1},{-1,0},{0,-1} };
    int cnt = 0;
    //loop level i in t
    for (int i = 0;i < t;i++) {
        int sizee = q.size();

        //loop every node in level i
        for (int j = 0;j < sizee && !q.empty();j++) {

            pair<int, int> now = q.front(); q.pop();
            // cout << "now : " << now.first << " " << now.second << '\n';

            for (int d = 0;d < dir.size();d++) { //go every direction
                int nexti = now.first + dir[d].first;
                int nextj = now.second + dir[d].second;
                //!!! bug access gph out of bound
                // cout << "next : " << nexti << " " << nextj << " " << gph[nexti][nextj] << '\n';
                if ((0 <= nexti && nexti < r) && (0 <= nextj && nextj < c)) {
                    if (gph[nexti][nextj] == 0) {
                        // cout << "next-- : " << nexti << " " << nextj << " " << gph[nexti][nextj] << '\n';
                        gph[nexti][nextj] = 1;
                        q.push({ nexti, nextj });
                        ans++;
                    }
                }
            }

        }
    }

    cout << ans;
}