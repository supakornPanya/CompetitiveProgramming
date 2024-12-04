#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    long long n, q, k; cin >> n >> q >> k;
    vector<long long> dp(n + 1);
    for(int i = 0;i < n;i++) {
        long long x; cin >> x;
        dp[i + 1] = x + dp[i];
    }

    // for(int i = 0;i < n + 1;i++) { cout << dp[i] << " "; } cout << '\n';

    //--binary search for select end of used(mid) (start = s -> end = mid)
    while(q--) {
        long long s, val; cin >> s >> val;
        long long l = s + 1, r = dp.size() - 1, mid, ans = 0;
        while(l <= r) {
            mid = (l + r) / 2;
            long long sum = (dp[mid] - dp[(s + 1) - 1]) + ((mid - s) * k); //value that used => s to mid
            // cout << "sum :" << sum << ", s+1 :" << s+1 << ", mid :" << mid << ", l :" << l << ", r :" << r << '\n';
            // cout << "dp : " << dp[mid] - dp[(s + 1) - 1] + ((mid - s) * k) << ", ans :" << dp[mid] - dp[(s + 1) - 1] << '\n';
            if(sum == val) {
                ans = dp[mid] - dp[(s + 1) - 1]; //ans can use
                break;
            } else if(sum > val) {
                r = mid - 1;
            } else if(sum < val) {
                ans = dp[mid] - dp[(s + 1) - 1]; //ans can use
                l = mid + 1;
            }
        }
        cout << ans << '\n';
        // cout << (dp[mid] - dp[s - 1 + 1]) + ((mid - l + 1) * k) << '\n';
    }
}