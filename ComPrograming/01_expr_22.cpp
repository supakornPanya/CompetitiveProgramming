#include <bits/stdc++.h>
using namespace std;

int main() {
    int Xe, Ye, Re, Rp, Xm, Ym;
    cin >> Xe >> Ye >> Re >> Rp >> Xm >> Ym;

    double A = Xm - Xe;
    double B = Ym - Ye;
    double C = sqrt(pow(A, 2) + pow(B, 2));

    double c = Re - Rp;
    double b = (c * B) / C;
    double a = (c * A) / C;

    cout << round(Xe + a) << " " << round(Ye + b);

    return 0;
}

//50 50 5 1 100 50