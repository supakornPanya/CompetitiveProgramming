#include <bits/stdc++.h>
using namespace std;

int main() {
    int d, m, y; cin >> d >> m >> y;
    y = y - 543;
    int n = 31;

    if (m == 4 || m == 6 || m == 9 || m == 11) { // m ลงท้าย = ยน
        n = 30;
    } else if (m == 2) {
        n = 28;
        if (y % 400 == 0) { n = 29; }
        if (y % 4 == 0 && y % 100 != 0) { n = 29; }
    }

    d = d + 15;
    if (d > n) {
        d = d - n;
        m++;
    }
    if (m > 12) {
        m = m - 12;
        y++;
    }

    y = y + 543;
    cout << d << "/" << m << "/" << y;
}