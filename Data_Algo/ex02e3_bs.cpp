#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q; cin >> n >> q;
    vector<int> v;
    for(int i = 0;i < n;i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    while(q--) {
        int x; cin >> x;
        int l = 0, r = v.size() - 1, mid, ans;
        while(l <= r) {
            mid = (l + r) / 2;
            if(v[mid] == x) {
                ans = mid;
                break;
            } else if(v[mid] > x) {
                r = mid - 1;
            } else if(v[mid] < x) {
                ans = mid;
                l = mid + 1;
            }
        }

        if(x < v[0]) { //out of bound(lower)
            cout << "-1" << '\n';
        } else  {
            while(ans < v.size() - 1 && v[ans] == v[ans+1]){
                ans++;
            } 
            cout << ans << '\n';
        }
    }
}