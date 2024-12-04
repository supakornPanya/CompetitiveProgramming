#include <bits/stdc++.h>
using namespace std;

int main() {
    double long x1, x2, a, b, x3; cin >> x1 >> x2 >> a >> b >> x3;
    double long sum = 0;
    int m = (b - a) / x3;
    for (int k = 0;k <= m;k++) {
        double long ans = 1 / (x2 * sqrt(2 * M_PI));
        ans = ans * pow(M_E, (-1 * pow(a + (k * x3) - x1, 2)) / (2 * pow(x2, 2)));
        ans = ans * x3;
        sum += ans;
    }

    cout << round(sum * 1e4) / 1e4;
}
, 