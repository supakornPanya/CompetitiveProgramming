#include <bits/stdc++.h>
using namespace std;

int main() {
    int d, m, y; cin >> d >> m >> y;
    vector<int> v(13);
    v[1] = 31, v[2] = 28, v[3] = 31, v[4] = 30, v[5] = 31, v[6] = 30;
    v[7] = 31, v[8] = 31, v[9] = 30, v[10] = 31, v[11] = 30, v[12] = 31;
    int ans = 0;
    ans += d;
    for (int i = 0;i < m;i++) {
        ans += v[i];
    }
    if (m > 2 && ((y - 543) % 400 == 0 || (y - 543) % 4 == 0 && (y - 543) % 100 != 0)) ans++;
    cout << ans << endl;
    return 0; 
}