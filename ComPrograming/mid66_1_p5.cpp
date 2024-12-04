#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v(1444, 0);
    int n; cin >> n;
    while(n--) {
        int s, e; cin >> s >> e;
        v[s]++; v[e]--;
    }
    int maxx = INT_MIN;
    for(int i = 1;i <= 1440;i++) {
        v[i] = v[i - 1] + v[i];
        if(v[i] > maxx) {
            maxx = v[i];
        }
    }
    cout << maxx;
}