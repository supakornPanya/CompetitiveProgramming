#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    vector<ll> dp(4);
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 5;
    if(n <= 3) {
        cout << dp[n];
        return 0;
    }
    ll mod = 1000000000 + 7;
    ll a = 3;
    ll b = 5;
    ll c;

    for(int i = 4;i <= n;i++) {
        // cout << "i : " << i << ", c "<< c << ", b " << b << ", a " << a  << '\n';
        c = b % mod;
        c += (a * 2) % mod;
        a = b;
        b = c;
    }
    cout << c % mod;
}