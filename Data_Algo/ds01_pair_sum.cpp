// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int n, m; cin >> n >> m; 
//     set<int> s;
//     for(int i = 0;i < n;i++) {
//         int x; cin >> x;
//         s.insert(x);
//     }
//     for(int i = 0;i < m;i++) {
//         int x; cin >> x;
//         bool found = false;
//         for(auto it = s.begin();it != s.end();it++) {
//             // cout << "*it : " << *it << ", x : " << x << ", " << *it - x << endl;
//             if(s.find(abs(*it - x)) != s.end() && *it <= x && s.find(abs(*it - x)) != it){
//                 // cout << "found  : *it : " << *it << ", x : " << x << ", " << *it - x << endl;
//                 found = true; break;
//             }
//         }
//         if(!found) cout << "NO" << endl;
//         else cout << "YES" << endl;
//     }
// }
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;cin >> n >> m;
    bitset<2000005> cnt, ans;
    for (int i = 1;i <= n;i++) {
        int x;cin >> x;
        ans |= (cnt << x);
        cnt[x] = 1;
    }
    while (m--) {
        int x;cin >> x;
        cout << (ans[x] == 1 ? "YES\n" : "NO\n");
    }
    return 0;
}