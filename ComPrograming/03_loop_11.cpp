#include <bits/stdc++.h>
using namespace std;

int main() {
    double long sum = 0; int cnt = 0;
    while (true) {
        double x; cin >> x;
        if (x == -1) break;
        sum += x; cnt++;
    }
    if (cnt == 0) { cout << "No Data"; return 0; } else cout << round((sum / cnt) * 100) / 100;
}