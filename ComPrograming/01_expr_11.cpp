#include <bits/stdc++.h>
using namespace std;

int main() {
    long double fac = 1;
    for (int i = 1;i <= 10;i++) { fac *= i; }
    long double radians = 40 * M_PI / 180;
    long double upper = M_PI - (fac / pow(8, 8)) + pow(log(9.7), (7/sqrt(71) - sin(radians)));
    long double lower = pow(1.2, cbrt(2.3));
    cout << upper/lower;
}