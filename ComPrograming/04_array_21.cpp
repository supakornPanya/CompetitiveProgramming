#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<double long> v;
    int n; cin >> n;
    for (int i = 0;i < n;i++) {
        double long x; cin >> x; v.push_back(x);
        if(i == 0) { cout << x << endl; continue; }
        double long ans = 1/v[i];
        for (int j = i - 1;j >= 1;j--) {
            ans = v[j] + ans;
            ans = 1 / ans;
        }
        ans += v[0];
        cout << setprecision(10) << ans << endl;
    }
}