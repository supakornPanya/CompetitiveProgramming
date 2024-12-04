//round2 -------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    map<string,int> mapp;
    for(int i = 0;i < n;i++) {
        string name; cin >> name;
        mapp[name] += 1;
    }

    priority_queue<int> pq;
    for(auto &it : mapp) {
        pq.push(it.second);
    }

    int ans, cnt = 0;
    while(!pq.empty() && cnt < m) {
        ans = pq.top(); pq.pop();
        cnt++;
    }

    cout << ans;
}






//round1 -------------------------------------------------------------
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int n, k; cin >> n >> k;
//     map<string, int> m;
//     for(int i = 0;i < n;i++) {
//         string s; cin >> s;
//         m[s]++;
//     }

//     priority_queue<int> pq;
//     for(auto it = m.begin();it != m.end();it++) {
//         pq.push(it->second);
//         // cout << "val : " << it->second << '\n';
//     }

//     int cnt = 0, ans;
//     while(!pq.empty() && cnt < k) {
//         ans = pq.top(); pq.pop(); cnt++;
//         while(!pq.empty() && ans == pq.top()) {
//             pq.pop(); cnt++;
//         }
//     }

//     cout << ans << '\n';
// }