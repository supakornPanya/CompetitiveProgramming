#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q; cin >> n >> q;
    vector<int> vec;
    for (int i = 0;i < n;i++) {
        int x; cin >> x;
        vec.push_back(x);
    }
    while(q--) {
        int x; cin >> x;
        int ans = 0;
        for(int i = 0;i < n;i++) {
            if(vec[i] == x) break;
            if(vec[i] > x) ans++;
        }
        cout << ans << '\n';
    }

}