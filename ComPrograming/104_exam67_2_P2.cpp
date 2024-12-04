#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; string opr; cin >> n >> opr;
    vector<pair<float,float>> v;
    for(int i = 0;i < n;i++) {
        float x, y; cin >> x >> y;
        v.push_back({x,y});
    }

    float xy = 0, x = 0, y = 0, xx = 0;
    for (int i = 0;i < n;i++) { xy += v[i].first * v[i].second; }
    for (int i = 0;i < n;i++) { x += v[i].first; }
    for (int i = 0;i < n;i++) { y += v[i].second; }
    for (int i = 0;i < n;i++) { xx += v[i].first * v[i].first; }
    float m = ((n * xy) - (x * y)) / ((n * xx) - (x * x));
    float b = (y - (m * x)) / n;

    if(opr == "mb") {
        cout << round(m * 1e3) / 1e3 << '\n' << round(b * 1e3) / 1e3 << '\n';
    } else {
        cout << "y = ";
        
        if(m == 0 && b == 0) { cout << "0"; return 0;}

        if (round(m * 1e3) / 1e3 != 0) {
            if (round(m * 1e3) / 1e3 == 1) cout << "x";
            else if (round(m * 1e3) / 1e3 == -1) cout << "-x";
            else cout << round(m * 1e3) / 1e3 << "x";

            if (b == 0) return 0;
            if (b < 0) cout << " - ";
            else cout << " + ";
            cout << abs(round(b * 1e3) / 1e3);
        } else {
            if (round(b * 1e3) / 1e3 < 0) cout << "-";
            cout << abs(round(b * 1e3) / 1e3);
        }
    }
}