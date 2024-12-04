#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, double> m;
    m["A"] = 4, m["B+"] = 3.5, m["B"] = 3, m["C+"] = 2.5;
    m["C"] = 2, m["D+"] = 1.5, m["D"] = 1, m["F"] = 0;

    double sum = 0, cnt = 0;
    int n; cin >> n;
    while (n--) {
        string a; int b; cin >> a >> b;
        sum += m[a] * b;
        cnt += b;
    }

    cout << round((sum / cnt) * 100) / 100;
}