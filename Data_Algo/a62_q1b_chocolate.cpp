#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<long long> s;
    vector<long long> dp(n + 1, 0);
    for(int i = 0;i < k;i++) {
        long long x; cin >> x;
        s.push_back(x);
        dp[x] = 1;
    }

    sort(s.begin(), s.end());
    for(int i = 1;i <= n;i++) {
        for(int j = 0;j < s.size();j++) {
            if(s[j] > i) break;
            // cout << "s[j] : " << s[j] << '\n';
            dp[i] += dp[i - s[j]] % 1000003;
        }
        // cout << "i : " << i << ", dp[i] : " << dp[i] << '\n';
    }
    // cout << '\n';
    cout << dp[n] % 1000003;
}