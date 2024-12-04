#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, m; cin >> n >> m;
    vector<ll> t(m);
    for (int i = 0;i < m;i++) {
        ll x; cin >> x;
        t[i] = x;
    }

    //time
    ll l = 0, r = LONG_LONG_MAX, mid;
    ll ans;
    while (l <= r) {
        mid = (l + r) / 2;
        ll sum = 0;
        for (int i = 0;i < m;i++) {
            sum += mid / t[i];
        }
        if (sum < n) {
            l = mid + 1;
        } else if (sum >= n) {
            ans = mid;
            r = mid - 1;
        }
    }

    cout << ans;
}