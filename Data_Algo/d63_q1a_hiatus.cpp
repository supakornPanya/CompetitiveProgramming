//round 2--------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q; cin >> n >> q;
    vector<pair<int,int>> v;
    for(int i = 0;i < n;i++) {
        int a, b; cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end());
    while(q--) {
        int a, b; cin >> a >> b;
        pair<int,int> beginn = v[0];
        if ((a < beginn.first) || (a == beginn.first && b < beginn.second)) {
            cout << "-1 -1 ";
        } else {
            pair<int,int> pii = make_pair(a,b);
            auto it = lower_bound(v.begin(), v.end(), pii);
            if(it->first == a && it->second == b) {
                cout << "0 0 ";
            } else {
                it--;
                cout << it->first << " " << it->second << " "; 
            }
        }
    }
}






//round 1---------------------------------------------------------------
// #include <bits/stdc++.h>
// using namespace std;

// bool found(const vector<pair<int,int>>& v, pair<int,int> val) {
//     int l = 0, r = v.size(), mid;
//     while(l <= r) {
//         mid = (l + r) / 2;
//         if(val == v[mid]) {
//             return true;
//         } else if(val < v[mid]) {
//             r = mid - 1;
//         } else if(val > v[mid]) {
//             l = mid + 1;
//         }   
//     }
//     return v[mid] == val;
// }

// int main() {
//     int n, m; cin >> n >> m;
//     vector<pair<int, int>> v;
//     pair<int,int> minn = {INT_MAX, INT_MAX};
//     for (int i = 0;i < n;i++) {
//         int a, b; cin >> a >> b;
//         v.push_back({ a,b });
//         minn = min(minn, {a,b}); 
//     }

//     sort(v.begin(), v.end());

//     // for(auto x : v) {cout << x.first << " " << x.second << '\n'; }
    
//     for (int i = 0;i < m;i++) {
//         int a, b; cin >> a >> b;
//         pair<int,int> pii = {a,b};
//         if(pii < minn) {
//             cout << "-1 -1 ";
//         } else if(found(v, pii)) {
//             cout << "0 0 ";
//         } else {
//             auto ans = upper_bound(v.begin(), v.end(), pii);
//             ans = (ans == v.begin())? ans : ans - 1;
//             cout << ans->first << " " << ans->second << " ";    
//         }
//     }
// }