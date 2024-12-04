#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int const n = 2010;
    int m; cin >> m;
    set<int> s;
    for (int i = 0;i < m;i++) {
        int x; cin >> x;
        s.insert(x);
    }

    ull cost = 0;
    priority_queue < pair<ull, int>> pq;
    pq.push({ 0,*s.begin() });
    
    while (!pq.empty() && s.size() != 0) {
        int nowW = pq.top().first;
        int nowU = pq.top().second;
        pq.pop();
        // cout << "now : " << nowU << ", " << nowW << '\n';

        auto del = s.find(nowU);
        //-------bug------- because : erase node ever used but still find path from this node
        // if (s.find(nowU) != s.end()) {
        //     s.erase(del);
        // }
        //-------bug-------
        if (s.find(nowU) == s.end()) continue;
        s.erase(del);
        cost += nowW;

        for (auto it : s) {
            if(s.find(it) == s.end()) continue;
            int val = nowU ^ it;
            // cout << "next : " << nowU << "^" << it << " = " << (nowU^it) << '\n';
            pq.push({ val, it });
        }
        // cout << "----------------------- \n";
    }

    cout << cost;
}