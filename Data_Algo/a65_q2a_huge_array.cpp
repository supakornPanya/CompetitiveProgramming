#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q; cin >> n >> q;
    vector<pair<int, int>> v;
    for (int i = 0;i < n;i++) {
        int x, c; cin >> x >> c;
        v.push_back({ x,c });
    }
    sort(v.begin(), v.end());

    vector<int> freq;
    int sum = 0;
    for (int i = 0;i < n;i++) {
        sum += v[i].second;
        freq.push_back(sum);
    }

    while (q--) {
        int x; cin >> x;
        auto it = lower_bound(freq.begin(), freq.end(), x);
        int idx = it - freq.begin();
        cout << v[idx].first << '\n';
    }
}