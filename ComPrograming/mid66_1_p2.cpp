#include <bits/stdc++.h>
using namespace std;

int main() {
    double long u, o, t, g = 10; cin >> u >> o >> t;
    o = o * 3.14159 / 180;
    double long h = t - ((u * sin(o)) / g); 
    h *= ((u * sin(o)) + (0.5 * g * (t - (3 * ((u * sin(o)) / g)))));
    double long r = u * cos(o) * t;
    cout << round(h * 10) / 10 << " " << round(r * 10) / 10;
}