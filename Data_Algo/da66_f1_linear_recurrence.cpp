#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll>> cr(1010, vector<ll>(1010, -1));

ll R(ll n, ll k, vector<ll>& c, vector<ll>& a) {
    if (n >= k) {
        ll sum = 0;
        for (int i = 1;i <= k;i++) {
            if (cr[i][n - 1] == -1) {
                cr[i][n - i] = (c[i] * R(n - i, k, c, a)) % 32717;
            }
            sum += cr[i][n - i];
        }
        return sum % 32717;
    } else {
        return a[n];
    }
}

int main() {
    ll k, n; cin >> k >> n;
    vector<ll> c; c.push_back(0);
    vector<ll> a;
    for (ll i = 0;i < k;i++) {
        ll x; cin >> x;
        c.push_back(x);
    }
    for (ll i = 0;i < k;i++) {
        ll x; cin >> x;
        a.push_back(x);
    }

    ll ans = R(n, k, c, a) % 32717;
    cout << ans;
}