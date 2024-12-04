#include <bits/stdc++.h>
using namespace std;

int main() {
    long double w, h; cin >> w >> h;
    long double mm = sqrt(w * h) / 60;
    long double hh = 0.024265 * pow(w, 0.5378) * pow(h, 0.3964);
    long double bb = 0.0333 * pow(w, 0.6157 - (0.0188 * log10(w))) * pow(h, 0.3);
    cout << setprecision(15) << mm << endl << setprecision(15) << hh << endl << setprecision(15) << bb << endl;
}