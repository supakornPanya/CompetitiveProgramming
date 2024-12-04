#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> v(n);
    for (int i = 0;i < n;i++) {
        int x; cin >> x;
        v[i] = x;
    }

    while (m--) {
        int q; cin >> q;
        int l = 0, r = v.size() - 1, mid;

        //binary search
        while (l <= r) {
            mid = (l + r) / 2;
            // cout << "l : " << l << ", r : " << r << ", mid : " << mid << ", val : " << v[mid] << '\n';
            if (v[mid] == q) {
                break;
            } else if (v[mid] > q) {
                r = mid - 1;
            } else if (v[mid] < q) {
                l = mid + 1;
            }
        }
        // cout << "end : " << mid << '\n';

        //case
        if (q < v[0]) { //out of bound(lower)
            cout << "-1" << '\n';
        } else if (q >= v[v.size() - 1]) { //out of bound(upper)
            cout << v[v.size() - 1] << '\n';
        } else if (v[mid] == q) { //mid is answer
            cout << v[mid] << '\n';
        } else if (v[mid] > q) { //
            cout << v[mid - 1] << '\n';
        } else {
            cout << v[mid] << '\n';
        }
    }
}