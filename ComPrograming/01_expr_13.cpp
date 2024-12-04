#include <bits/stdc++.h>
using namespace std;

int main() {
    long double a, b, c; cin >> a >> b >> c;
    long double t = (sqrt(pow(b, 2) - (4 * a * c)))/(2 * a);
    long double tt = (-1 * b) / (2 * a);
    cout << round((tt - t) * 1e3) / 1e3 << " " << round((tt + t) * 1e3) / 1e3;
}