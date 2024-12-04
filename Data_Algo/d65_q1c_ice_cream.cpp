#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    vector<int> v(200100);
    vector<pair<int,int>> mark;
    int n, m, start; cin >> n >> m >> start;
    v[0] = start; mark.push_back({0,start});
    for (int i = 0;i < n;i++) {
        int a,s; cin >> a >> s;
        mark.push_back({a,s});
    }

    sort(mark.begin(), mark.end());
    int idx = 0;
    for(size_t i = 1;i < v.size();i++) {
        if(i == mark[idx + 1].first) idx++;
        v[i] = v[i - 1] + mark[idx].second;
    }
    
    // for(int i = 0;i < 8;i++) {cout << i << " : " << v[i] << endl;}

    for (int i = 0;i < m;i++) {
        int price, x; cin >> price >> x;
        // cout << "price : " << price << ", x : " << x << " | ";
        vector<int>::iterator ans;
        if(v[x] >= price) {
            ans = lower_bound(v.begin(), v.begin() + x, price);
        } else {
            ans = lower_bound(v.begin() + x, v.end(), price + v[x]);
        }
        if(price > *ans) cout << ans - v.begin() + 1 << " "; 
        else cout << ans - v.begin() << " ";
        // cout << " value : " << *ans << '\n';
    }

    return 0;
}