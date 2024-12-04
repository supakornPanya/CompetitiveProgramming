#include <bits/stdc++.h>
using namespace std;

int recur(int a, int k, int m) {
    if(k == 0) return 1;
    if(k % 2 == 0) return int(pow(recur(a, k/2, m), 2)) % m;
    if(k % 2 == 1) return a * int(pow(recur(a, k/2, m), 2)) % m;
}

int main() {
    int a, k, m; cin >> a >> k >> m;
    cout << recur(a, k, m);
}