#include <bits/stdc++.h>
using namespace std;

int main() {
    int m; cin >> m;
    vector<double> c(m + 1);
    for (int i = 0;i <= m;i++) {
        cin >> c[i];
    }

    double l = -1.0, r = 1.0;
    while (l <= r) {
        double mid = (l + r) / 2;
        double val = 0;
        for (int i = 0;i <= m;i++) { val += c[i] / pow(1 + mid, i); }
        // cout << "val : " << val << ", mid : " << mid << endl;
        if (abs(val) <= 1e-8) {
            cout << setprecision(8) << mid << endl;
            return 0;
        } else if (val > 0) {
            l = mid + 1e-15;
        } else if (val < 0) {
            r = mid - 1e-15;
        }
    }
}