#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    map<long long, long long> m;
    for(int i = 0;i < n;i++) {
        long long x1, x2; cin >> x1 >> x2;
        m[x2] = x1;
    }

    while(q--) {
        long long x1, x2; cin >> x1 >> x2;
        if(x1 == x2
            || m.find(x1) == m.end() || m.find(x2) == m.end()
            || m.find(m[x1]) == m.end() || m.find(m[x2]) == m.end()
            || m[m[x1]] != m[m[x2]]) {
            // cout << (x1 == x2) << endl;
            // cout << (m.find(x1) == m.end() || m.find(x2) == m.end()) << endl;
            // cout << (m.find(m[x1]) == m.end() || m.find(m[x2]) == m.end()) << endl;
            // cout << (m[m[x1]] != m[m[x2]]) << endl;
            cout << "NO" << endl;
        }else {
            cout << "YES" << endl;  
        }
        // cout << "---------------------------------------" << endl;
    }
}