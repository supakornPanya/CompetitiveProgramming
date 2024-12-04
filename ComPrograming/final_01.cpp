#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    while (n--) {
        int x; cin >> x;
        int minn = INT_MAX, ans = 0;
        for (int i = 0;i < x;i++) {
            int t; cin >> t;
            ans += t;
            minn = min(minn, t);
        }
        cout << ans - minn << endl;
    }
}