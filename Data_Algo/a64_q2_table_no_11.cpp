#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    if (n == 1) {
        cout << "3";
        return 0;
    }

    long long p1 = 1, p2 = 2, n1, n2;
    for (int i = 2;i <= n;i++) {
        n1 = (p1 + p2);
        n2 = ((p1 * 3) + (p2 * 2)) - (p1 + p2);
        n1 = n1 % (long long)(1e8 + 7);
        n2 = n2 % (long long)(1e8 + 7);
        p1 = n1;
        p2 = n2;
    }
    cout << (n1 + n2) % (long long)(1e8 + 7);
}