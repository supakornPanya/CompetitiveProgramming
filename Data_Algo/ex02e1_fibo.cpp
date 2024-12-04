#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    if (n == 0 || n == 1) { cout << n; return 0; }
    int f1 = 0, f2 = 1;
    for (int i = 1;i < n;i++) {
        int f3 = f2 + f1;
        // cout << f3 << " " << f2  << " "<< f1<< '\n';
        f1 = f2;
        f2 = f3;
    }
    cout << f2;
}