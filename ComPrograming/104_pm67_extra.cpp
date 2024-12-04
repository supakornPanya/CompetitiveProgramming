#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, n, m;  cin >> k >> n >> m;
    vector<int> v(n + 1, INT_MAX);
    for (int i = 0;i < m;i++) {
        int d, val; cin >> d >> val;
        v[d] = val;
    }

    //loop each window
    for (int i = 1;i <= n;i++) {
        int l = i - k, r = i + k;
        int ans, cnt = -1;
        map<int,int> mp; //key : t[i], value : cnt
        while(l <= r) {
            if(n < l) break;
            if(l < 1) { l++; continue; }
            if(v[l] != INT_MAX) {
                mp[v[l]]++;
                if(mp[v[l]] > cnt) { cnt = mp[v[l]]; ans = v[l]; }
                if (mp[v[l]] == cnt && v[l] < ans) { cnt = mp[v[l]]; ans = v[l]; }
            }
            l++;
        }
        if(cnt != -1) cout << ans << " ";
        else cout << "X ";
    }
    cout << endl;

    return 0;
}