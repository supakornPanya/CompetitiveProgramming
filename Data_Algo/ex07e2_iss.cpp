#include <bits/stdc++.h>
using namespace std;

//top -> botton : don'tewwevb 
int ans = 0;
void f(int n, int prev, int sum) {
    // cout << prev << " ";
    if (sum > n) return;
    if (sum == n) {
        ans++;
        return;
    }
    //call all less than or equal now
    for (int i = 1;i <= prev;i++) {
        f(n, i, sum + i);
    }
}

int main() {
    int n; cin >> n;
    for (int i = 1;i <= n;i++) {
        // cout << i << " : ";
        f(n, i, i);
        // cout << '\n';
    }
    cout << ans;
    // cout << "ans : " << ans;
    return 0;
}